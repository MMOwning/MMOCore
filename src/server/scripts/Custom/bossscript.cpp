
#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Spells
{
	SPELL_OOZE_MERGE = 69889,
	SPELL_BEBENDE_ERDE = 6524,
	SPELL_BLISTERING_COLD = 70123,
	SPELL_BERSERK = 26662,
	SPELL_ENRAGE = 64487,
	SPELL_TOXIC_WASTE = 69024;
};

enum Events
{
	EVENT_VISUAL_NETHER_PORTAL = 1,
	EVENT_BEBENDE_ERDE = 2,
	EVENT_BLADESTORM = 3,
	EVENT_SUMMONS = 4,
	EVENT_BERSERK = 5,
	EVENT_ENRAGE = 6
};

enum Phases
{
	PHASE_ONE = 1,
	PHASE_TWO = 2,
	PHASE_THREE = 3
};

enum Summons
{
	NPC_FEUERTEUFEL = 150004
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

class boss_two : public CreatureScript
{
public:
	boss_two() : CreatureScript("boss_two") { }

	struct boss_twoAI : public ScriptedAI
	{
		boss_twoAI(Creature* creature) : ScriptedAI(creature), Summons(me) { }

		void Reset() override
		{
			_events.Reset();
			Summons.DespawnAll();
		}

		void EnterCombat(Unit* /*who*/) override
		{
			Talk(SAY_AGGRO);
			_events.SetPhase(PHASE_ONE);
			_events.ScheduleEvent(EVENT_VISUAL_NETHER_PORTAL, 1000);
			_events.ScheduleEvent(EVENT_BEBENDE_ERDE, 30000);
		}

		void DamageTaken(Unit* /*attacker*/, uint32& damage) override
		{
			if (me->HealthBelowPctDamaged(75, damage) && _events.IsInPhase(PHASE_ONE))
			{
				_events.SetPhase(PHASE_TWO);
				_events.ScheduleEvent(EVENT_BLADESTORM, 10000);
			}

			if (me->HealthBelowPctDamaged(35, damage) && _events.IsInPhase(PHASE_TWO))
			{
				_events.SetPhase(PHASE_THREE);
				_events.ScheduleEvent(EVENT_SUMMONS, 5000);
				_events.ScheduleEvent(EVENT_BERSERK, 10000);
				_events.ScheduleEvent(EVENT_ENRAGE, 120000); //In phase 3 the player have 2 minutes to defeat the Boss or all will die !
			}
		}

		void JustSummoned(Creature* summon) override
		{
			Summons.Summon(summon);

			switch (summon->GetEntry())
			{
			case NPC_FEUERTEUFEL:
				if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 300.0f))
					summon->AI()->AttackStart(target); // I think it means the Tank !
				break;
			}
		}

		void JustDied(Unit* /*killer*/) override
		{
			Talk(SAY_DEAD);
			Summons.DespawnAll();
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
				case EVENT_VISUAL_NETHER_PORTAL:
					DoCast(me, VISUAL_NETHER_PORTAL);
					break;
				case EVENT_BEBENDE_ERDE:
					DoCastVictim(SPELL_BEBENDE_ERDE);
					_events.ScheduleEvent(EVENT_BEBENDE_ERDE, 8000);
					break;
				case EVENT_BLADESTORM:
					Talk(SAY_RANDOM);
					DoCastVictim(SPELL_BLISTERING_COLD);
					_events.ScheduleEvent(EVENT_BLADESTORM, 30000);
					break;
				case EVENT_SUMMONS:
					Talk(SAY_HELP);
					me->SummonCreature(NPC_FEUERTEUFEL, me->GetPositionX() + 5, me->GetPositionY(), me->GetPositionZ() + 5, 0, TEMPSUMMON_CORPSE_DESPAWN, 600000);
					me->SummonCreature(NPC_FEUERTEUFEL, me->GetPositionX() + 5, me->GetPositionY(), me->GetPositionZ() + 5, 0, TEMPSUMMON_CORPSE_DESPAWN, 600000);
					me->SummonCreature(NPC_FEUERTEUFEL, me->GetPositionX() + 5, me->GetPositionY(), me->GetPositionZ() + 5, 0, TEMPSUMMON_CORPSE_DESPAWN, 600000);
					break;
				case EVENT_BERSERK:
					Talk(SAY_BERSERK);
					DoCast(me, SPELL_BERSERK);
					_events.ScheduleEvent(EVENT_BERSERK, 120000);
					break;
				case EVENT_ENRAGE:
					Talk(SAY_ENRAGE);
					DoCast(me, SPELL_ENRAGE);
					_events.ScheduleEvent(EVENT_ENRAGE, 10000);
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
		return new boss_twoAI(creature);
	}
};

void AddSC_boss_two()
{
	new boss_two();
}