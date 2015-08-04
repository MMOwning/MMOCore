#include "ScriptPCH.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Player.h"

enum Spells
{
	SPELL_MANA_DESTRUCTION = 59374,
	SPELL_BRAIN_LINK_DAMAGE = 63803,
	SPELL_NECROTIC_AURA = 55593,
	SPELL_CRYSTAL_CHAINS = 50997,
	SPELL_NECROTIC_POISON = 28776,
	SPELL_MANGLING_SLASH = 48873,
	SPELL_PIERCING_SLASH = 48878,
	SPELL_BLOOD_MIRROR_DAMAGE = 70821,
	SPELL_ANNOYING_YIPPING = 31015,
	SPELL_SARGERAS = 28342,
	SPELL_BURN = 46218
};

enum Events
{
	EVENT_MANA_DESTRUCTION = 1,
	EVENT_BRAIN_LINK_DAMAGE = 2,
	EVENT_NECROTIC_AURA = 3,
	EVENT_CRYSTAL_CHAINS = 4,
	EVENT_NECROTIC_POISON = 5,
	EVENT_MANGLING_SLASH = 6,
	EVENT_PIERCING_SLASH = 7,
	EVENT_BLOOD_MIRROR_DAMAGE = 8,
	EVENT_ANNOYING_YIPPING = 9,
	EVENT_SARGERAS = 10,
	EVENT_BURN = 11

};

enum Phases
{
	PHASE_ONE = 1,
	PHASE_TWO = 2,
	PHASE_THREE = 3
};

enum Summons
{
	NPC_SCHMORRSCHUPPEN = 40421
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

class tyranium : public CreatureScript
{
public:
	tyranium() : CreatureScript("tyranium") { }

	struct tyraniumAI : public ScriptedAI
	{
		tyraniumAI(Creature* creature) : ScriptedAI(creature), Summons(me) { }

		void Reset() override
		{
			_events.Reset();
			Summons.DespawnAll();
		}

		void EnterCombat(Unit* /*who*/) override
		{
			Talk(SAY_AGGRO);
			_events.SetPhase(PHASE_ONE);
			_events.ScheduleEvent(EVENT_MANA_DESTRUCTION, 1000);
			_events.ScheduleEvent(EVENT_BRAIN_LINK_DAMAGE, 10000);
			_events.ScheduleEvent(EVENT_MANGLING_SLASH, 8000);
			_events.ScheduleEvent(EVENT_SARGERAS, 5000);

		}

		void DamageTaken(Unit* /*attacker*/, uint32& damage) override
		{
			if (me->HealthBelowPctDamaged(75, damage) && _events.IsInPhase(PHASE_ONE))
			{
				_events.SetPhase(PHASE_TWO);
				_events.ScheduleEvent(EVENT_MANA_DESTRUCTION, 10000);
				_events.ScheduleEvent(EVENT_PIERCING_SLASH, 20000);
				_events.ScheduleEvent(EVENT_BRAIN_LINK_DAMAGE, 10000);
				_events.ScheduleEvent(EVENT_BLOOD_MIRROR_DAMAGE, 10000);

			}

			if (me->HealthBelowPctDamaged(35, damage) && _events.IsInPhase(PHASE_TWO))
			{
				_events.SetPhase(PHASE_THREE);
				_events.ScheduleEvent(EVENT_CRYSTAL_CHAINS, 5000);
				_events.ScheduleEvent(EVENT_PIERCING_SLASH, 10000);
				_events.ScheduleEvent(EVENT_NECROTIC_POISON, 12000); 
				_events.ScheduleEvent(EVENT_ANNOYING_YIPPING, 25000);
				_events.ScheduleEvent(EVENT_BURN, 35000);
			}
		}

		void JustSummoned(Creature* summon) override
		{
			Summons.Summon(summon);

			switch (summon->GetEntry())
			{
			case NPC_SCHMORRSCHUPPEN:
				if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 300.0f))
					summon->AI()->AttackStart(target); // I think it means the Tank !
				break;
			}
		}

		void JustDied(Unit* pPlayer)
		{
			char msg[250];
			snprintf(msg, 250, "|cffff0000[Boss System]|r Boss|cffff6060 Tyranium|r wurde getoetet! Respawn in 4h 30min.", pPlayer->GetName());
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
				case EVENT_NECROTIC_AURA:
					DoCast(me, SPELL_NECROTIC_AURA);
					break;
				case EVENT_BRAIN_LINK_DAMAGE:
					DoCastVictim(SPELL_BRAIN_LINK_DAMAGE);
					_events.ScheduleEvent(EVENT_BRAIN_LINK_DAMAGE, 8000);
					break;
				case EVENT_MANA_DESTRUCTION:
					Talk(SAY_RANDOM);
					DoCast(SPELL_MANA_DESTRUCTION);
					_events.ScheduleEvent(EVENT_MANA_DESTRUCTION, 1000);
					break;
				case EVENT_CRYSTAL_CHAINS:
					DoCastVictim(SPELL_CRYSTAL_CHAINS);
					_events.ScheduleEvent(EVENT_CRYSTAL_CHAINS, 30000);
					break;
				case EVENT_NECROTIC_POISON:
					Talk(SAY_BERSERK);
					DoCast(me, SPELL_NECROTIC_POISON);
					_events.ScheduleEvent(EVENT_NECROTIC_POISON, 120000);
					break;
				case EVENT_MANGLING_SLASH:
					Talk(SAY_ENRAGE);
					DoCast(me, SPELL_MANGLING_SLASH);
					_events.ScheduleEvent(EVENT_MANGLING_SLASH, 10000);
					break;
				case EVENT_PIERCING_SLASH:
					DoCastToAllHostilePlayers(SPELL_PIERCING_SLASH);
					_events.ScheduleEvent(EVENT_PIERCING_SLASH, 15000);
					break;
				case EVENT_BLOOD_MIRROR_DAMAGE:
					DoCast(SPELL_BLOOD_MIRROR_DAMAGE);
					_events.ScheduleEvent(EVENT_BLOOD_MIRROR_DAMAGE, 18000);
					break;
				case EVENT_ANNOYING_YIPPING:
					DoCastToAllHostilePlayers(SPELL_ANNOYING_YIPPING);
					_events.ScheduleEvent(EVENT_ANNOYING_YIPPING, 25000);
					break;
				case EVENT_SARGERAS:
					DoCastToAllHostilePlayers(SPELL_SARGERAS);
					_events.ScheduleEvent(EVENT_SARGERAS, 5000);
					break;
				case EVENT_BURN:
					DoCastToAllHostilePlayers(SPELL_BURN);
					_events.ScheduleEvent(EVENT_BURN, 35000);
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
		return new tyraniumAI(creature);
	}



};

void AddSC_tyranium()
{
	new tyranium();
}