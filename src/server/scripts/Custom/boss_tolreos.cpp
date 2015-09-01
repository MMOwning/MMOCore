#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Player.h"

enum Spells
{
	SPELL_CORRUPTION = 65810,
	SPELL_ENRAGE = 68335,
	SPELL_CRIPPLE = 31477,
	SPELL_ARCANE_BARRAGE = 65799,
	SPELL_DOMINATE_MIND = 63713,
	SPELL_EARTH = 30129,
	SPELL_HEX = 66054,
	SPELL_PSYCHOSIS = 63795,
	SPELL_ARCANE_DEVASTION = 34799,
	SPELL_ARMY_OF_DEAD = 67761
	
};

enum Events
{
	EVENT_CURRUPTION = 1,
	EVENT_ENRAGE = 2,
	EVENT_CRIPPLE = 3,
	EVENT_ARCANE_BARRAGE = 4,
	EVENT_DOMINATE_MIND = 5,
	EVENT_EARTH = 6,
	EVENT_HEX = 7,
	EVENT_PSYCHOSIS = 8,
	EVENT_ARCANE_DEVASTION = 9,
	EVENT_ARMY_OF_DEAD = 10



};

enum Phases
{
	PHASE_ONE = 1,
	PHASE_TWO = 2,
	PHASE_THREE = 3
};

enum Summons
{
	NPC_PUSTELIGER_SCHRECKEN = 31139
};

enum Texts
{
	SAY_AGGRO = 0,
	SAY_RANDOM = 1,
	SAY_HELP = 2,
	SAY_BERSERK = 3,
	SAY_ENRAGE = 4,
	SAY_DEAD = 5
};

class tolreos : public CreatureScript
{
public:
	tolreos() : CreatureScript("tolreos") { }

	struct tolreosAI : public ScriptedAI
	{
		tolreosAI(Creature* creature) : ScriptedAI(creature), Summons(me) { }

		void Reset() override
		{
			_events.Reset();
			Summons.DespawnAll();
		}

		void EnterCombat(Unit* ) override
		{
			Talk(SAY_AGGRO);
			_events.SetPhase(PHASE_ONE);
			_events.ScheduleEvent(EVENT_CURRUPTION, 8000);
			_events.ScheduleEvent(EVENT_CRIPPLE, 10000);
			_events.ScheduleEvent(EVENT_ARCANE_BARRAGE, 8000);
			_events.ScheduleEvent(EVENT_DOMINATE_MIND, 15000);

		}

		void DamageTaken(Unit* /*attacker*/, uint32& damage) override
		{
			if (me->HealthBelowPctDamaged(75, damage) && _events.IsInPhase(PHASE_ONE))
			{
				_events.SetPhase(PHASE_TWO);
				_events.ScheduleEvent(EVENT_EARTH, 10000);
				_events.ScheduleEvent(EVENT_HEX, 8000);
				_events.ScheduleEvent(EVENT_ARCANE_DEVASTION, 12000);
				_events.ScheduleEvent(EVENT_PSYCHOSIS, 10000);

			}

			if (me->HealthBelowPctDamaged(35, damage) && _events.IsInPhase(PHASE_TWO))
			{
				_events.SetPhase(PHASE_THREE);
				_events.ScheduleEvent(EVENT_ARMY_OF_DEAD, 5000);
				_events.ScheduleEvent(EVENT_CURRUPTION, 6000);
				_events.ScheduleEvent(EVENT_DOMINATE_MIND, 15000);
				_events.ScheduleEvent(EVENT_ENRAGE, 25000);
				_events.ScheduleEvent(EVENT_HEX, 12000);
			}
		}

		void JustSummoned(Creature* summon) override
		{
			Summons.Summon(summon);

			switch (summon->GetEntry())
			{
			case NPC_PUSTELIGER_SCHRECKEN:
				if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 300.0f))
					summon->AI()->AttackStart(target); // I think it means the Tank !
				break;
			}
		}

		void JustDied(Unit* pPlayer)
		{
			char msg[250];
			snprintf(msg, 250, "|cffff0000[Boss System]|r Boss|cffff6060 Tolreos|r wurde getoetet! Respawn in 4h 33min.");
			sWorld->SendGlobalText(msg, NULL);
		}


		void SpellHit(Unit* caster, SpellInfo const* spell)
		{
			
			if (caster == me)
				return;
			uint32 id = spell->Id;
			if (id == 355){
				DoCastToAllHostilePlayers(SPELL_ARMY_OF_DEAD);
			}
		}



		void UpdateAI(uint32 diff) override
		{
			if (!UpdateVictim())
				return;

			_events.Update(diff);

			while (uint32 eventId = _events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_CURRUPTION:
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1)){
						DoCastVictim(SPELL_CORRUPTION);		
					}
					_events.ScheduleEvent(EVENT_CURRUPTION, 10000);
					break;
				case EVENT_ENRAGE:
					DoCastToAllHostilePlayers(SPELL_ENRAGE);
					break;
				case EVENT_CRIPPLE:
					Talk(SAY_RANDOM);
					DoCastToAllHostilePlayers(SPELL_CRIPPLE);
					_events.ScheduleEvent(EVENT_CRIPPLE, 25000);
					break;
				case EVENT_ARCANE_BARRAGE:
					DoCastToAllHostilePlayers(SPELL_ARCANE_BARRAGE);
					_events.ScheduleEvent(EVENT_ARCANE_BARRAGE, 5000);
					break;
				case EVENT_DOMINATE_MIND:
					Talk(SAY_BERSERK);
					if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO,0)){
						DoCastVictim(SPELL_DOMINATE_MIND);
					}
					_events.ScheduleEvent(EVENT_DOMINATE_MIND, 25000);
					break;
				case EVENT_EARTH:
					Talk(SAY_ENRAGE);
					DoCastAOE(SPELL_EARTH);
					_events.ScheduleEvent(EVENT_EARTH, 10000);
					break;
				case EVENT_PSYCHOSIS:
					DoCast(me, SPELL_PSYCHOSIS);
					_events.ScheduleEvent(EVENT_PSYCHOSIS, 18000);
					break;
				case EVENT_HEX:
					DoCast(SPELL_HEX);
					_events.ScheduleEvent(EVENT_HEX, 10000);
					break;
				case EVENT_ARCANE_DEVASTION:
					DoCastVictim(SPELL_ARCANE_DEVASTION);
					_events.ScheduleEvent(EVENT_ARCANE_DEVASTION, 12000);
					break;
				case EVENT_ARMY_OF_DEAD:
					DoCastToAllHostilePlayers(SPELL_ARMY_OF_DEAD);
					_events.ScheduleEvent(EVENT_ARMY_OF_DEAD, 20000);
					break;



				default:
					break;
				}
			}

			DoMeleeAttackIfReady();
		}

	private:
		EventMap _events;
		SummonList Summons;
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return new tolreosAI(creature);
	}






};

void AddSC_tolreos()
{
	new tolreos();
}