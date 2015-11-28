#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Player.h"

enum Spells
{
	SPELL_APOKALYPSE = 53210,
	SPELL_GOTTESSCHILD = 41367,
	SPELL_PHANTOMSCHLAG = 68982,
	SPELL_ENRAGE = 59707,
	SPELL_BLISTERING_COLD = 70123,
	SPELL_CORRUPTED_FLESH = 72363,
	SPELL_BLIZZARD = 49034,
	SPELL_SPALTEN = 40504,
	SPELL_FLEISCH_EINAESCHERN = 66237

};

enum Events
{
	EVENT_APOKALYPSE = 1,
	EVENT_GOTTESSCHILD = 2,
	EVENT_PHANTOMSCHLAG = 3,
	EVENT_ENRAGE = 4,
	EVENT_BLIZZARD = 5,
	EVENT_BLISTERING_COLD = 6,
	EVENT_CORRUPTED_FLESH = 7,
	EVENT_SPALTEN = 8,
	EVENT_SUMMONS = 9,
	EVENT_FLEISCH_EINAESCHERN = 10



};

enum Phases
{
	PHASE_ONE = 1,
	PHASE_TWO = 2,
	PHASE_THREE = 3
};

enum Summons
{
	NPC_ADD = 800097
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

class therakin : public CreatureScript
{
public:
	therakin() : CreatureScript("therakin") { }

	struct therakinAI : public ScriptedAI
	{
		therakinAI(Creature* creature) : ScriptedAI(creature), Summons(me) { }

		uint32 kills = 0;
		void Reset() override
		{
			_events.Reset();
			Summons.DespawnAll();

		}

		void EnterCombat(Unit* /*who*/) override
		{
			Talk(SAY_AGGRO);
			_events.SetPhase(PHASE_ONE);
			_events.ScheduleEvent(EVENT_APOKALYPSE, 1000);
			_events.ScheduleEvent(EVENT_SPALTEN, 10000);
			_events.ScheduleEvent(EVENT_BLIZZARD, 20000);
			_events.ScheduleEvent(EVENT_SUMMONS, 30000);

		}

		void DamageTaken(Unit* /*attacker*/, uint32& damage) override
		{
			if (me->HealthBelowPctDamaged(75, damage) && _events.IsInPhase(PHASE_ONE))
			{
				_events.SetPhase(PHASE_TWO);
				_events.ScheduleEvent(EVENT_CORRUPTED_FLESH, 10000);
				_events.ScheduleEvent(EVENT_SUMMONS, 15000);
				_events.ScheduleEvent(EVENT_APOKALYPSE, 30000);

			}

			if (me->HealthBelowPctDamaged(35, damage) && _events.IsInPhase(PHASE_TWO))
			{
				_events.SetPhase(PHASE_THREE);
				_events.ScheduleEvent(EVENT_APOKALYPSE, 5000);
				_events.ScheduleEvent(EVENT_ENRAGE, 100000);
				_events.ScheduleEvent(EVENT_BLISTERING_COLD, 16000);
				_events.ScheduleEvent(EVENT_GOTTESSCHILD, 20000);
				_events.ScheduleEvent(EVENT_BLIZZARD, 45000);
			}
		}

		void JustSummoned(Creature* summon) override
		{
			Summons.Summon(summon);

			switch (summon->GetEntry())
			{
			case NPC_ADD:
				if (Unit* target = SelectTarget(SELECT_TARGET_BOTTOMAGGRO, 0, 300.0f))
					summon->AI()->AttackStart(target); // I think it means the Tank !
				break;
			}
		}


		void JustDied(Unit* pPlayer)
		{
			char msg[250];
			snprintf(msg, 250, "|cffff0000[Boss System]|r Boss|cffff6060 Therakin|r wurde getoetet! Respawn in 6h 33min.");
			sWorld->SendGlobalText(msg, NULL);
		}


		void KilledUnit(Unit* victim) override
		{

			if (victim->GetTypeId() != TYPEID_PLAYER)
				return;
			char msg[250];

			++kills;
			snprintf(msg, 250, "|cffff0000[Boss System]|r |cffff6060 Therakin|r hat einen Spieler getoetet! Was fuer eine Schmach. Insgesamt steht der Killcounter seit dem letzten Restart bei: %u", kills);
			sWorld->SendGlobalText(msg, NULL);
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
				case EVENT_APOKALYPSE:
					DoCastAOE(SPELL_APOKALYPSE);
					_events.ScheduleEvent(EVENT_APOKALYPSE, 75000);
					break;
				case EVENT_SPALTEN:
					DoCastToAllHostilePlayers(SPELL_SPALTEN);
					_events.ScheduleEvent(EVENT_SPALTEN, 10000);
					break;
				case EVENT_ENRAGE:
					Talk(SAY_RANDOM);
					DoCast(SPELL_ENRAGE);
					break;
				case EVENT_BLIZZARD:
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0)){
						DoCastVictim(SPELL_BLIZZARD);
					}
					_events.ScheduleEvent(EVENT_BLIZZARD, 15000);
					break;
				case EVENT_SUMMONS:
					Talk(SAY_HELP);
					me->SummonCreature(NPC_ADD, me->GetPositionX() + 5, me->GetPositionY(), me->GetPositionZ() + 5, 0, TEMPSUMMON_CORPSE_DESPAWN, 600000);
					break;
				case EVENT_BLISTERING_COLD:
					Talk(SAY_BERSERK);
					DoCastVictim(SPELL_BLISTERING_COLD);
					_events.ScheduleEvent(EVENT_BLISTERING_COLD, 20000);
					break;
				case EVENT_CORRUPTED_FLESH:
					DoCastVictim(SPELL_CORRUPTED_FLESH);
					_events.ScheduleEvent(EVENT_CORRUPTED_FLESH, 30000);
					break;
				case EVENT_GOTTESSCHILD:
					DoCastToAllHostilePlayers(SPELL_GOTTESSCHILD);
					_events.ScheduleEvent(EVENT_GOTTESSCHILD, 25000);
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
		return new therakinAI(creature);
	}



};


class therakinadd : public CreatureScript
{
public:
	therakinadd() : CreatureScript("therakinadd") { }

	struct therakinaddAI : public ScriptedAI
	{
		therakinaddAI(Creature* creature) : ScriptedAI(creature), Summons(me) { }

		uint32 kills = 0;
		void Reset() override
		{
			_events.Reset();
			Summons.DespawnAll();

		}

		void EnterCombat(Unit* /*who*/) override
		{
			Talk(SAY_AGGRO);
			_events.SetPhase(PHASE_ONE);
			_events.ScheduleEvent(EVENT_FLEISCH_EINAESCHERN, 45000);
			

		}

		void DamageTaken(Unit* /*attacker*/, uint32& damage) override
		{
			if (me->HealthBelowPctDamaged(75, damage) && _events.IsInPhase(PHASE_ONE))
			{
				_events.SetPhase(PHASE_TWO);
				_events.ScheduleEvent(EVENT_FLEISCH_EINAESCHERN, 45000);

			}

			if (me->HealthBelowPctDamaged(35, damage) && _events.IsInPhase(PHASE_TWO))
			{
				_events.SetPhase(PHASE_THREE);
				_events.ScheduleEvent(EVENT_FLEISCH_EINAESCHERN, 45000);
		
			}
		}

		

		void JustDied(Unit* pPlayer)
		{
			
		}


		void KilledUnit(Unit* victim) override
		{

			if (victim->GetTypeId() != TYPEID_PLAYER)
				return;
			char msg[250];

			++kills;
			snprintf(msg, 250, "|cffff0000[Boss System]|r |cffff6060 Therakin|r hat einen Spieler getoetet! Was fuer eine Schmach. Insgesamt steht der Killcounter seit dem letzten Restart bei: %u", kills);
			sWorld->SendGlobalText(msg, NULL);
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
				case EVENT_FLEISCH_EINAESCHERN:
					DoCastAOE(SPELL_FLEISCH_EINAESCHERN);
					_events.ScheduleEvent(EVENT_FLEISCH_EINAESCHERN, 30000);
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
		return new therakinaddAI(creature);
	}



};

void AddSC_therakin()
{
	new therakin();
	new therakinadd();

}