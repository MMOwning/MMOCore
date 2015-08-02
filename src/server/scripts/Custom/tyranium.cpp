#include "ScriptPCH.h"
#include "ScriptedCreature.h"

enum Spells
{
	
	SPELL_NETHER_PORTAL_EFFECT = 66263,
	SPELL_SHOCK_BLAST = 63631,
	SPELL_SUMMON_BLIZZARD = 28560,
	SPELL_FROST_MISSILE = 30101,	
	SPELL_ENRAGE = 44807,
	SPELL_LEGION_LIGHTNING = 45664
};

class tyranium : public CreatureScript
{
public:
	tyranium() : CreatureScript("tyranium"){}

	CreatureAI* GetAI_tyranium(Creature* pCreature) const
	{
		return new tyraniumAI(pCreature);
	}

	struct tyraniumAI : public ScriptedAI
	{
		tyraniumAI(Creature *c) : ScriptedAI(c) {}

		uint32 NETHER_Timer;
		uint32 BLAST_Timer;
		uint32 SUMMON_BLIZZARD_Timer;
		uint32 FROST_Timer;
		uint32 LEGION_LIGHTNING_Timer;
		uint32 ENRAGE_Timer;

		uint32 Phase;

		void Reset()
		{
			NETHER_Timer = 20000;
			BLAST_Timer = 0;
			SUMMON_BLIZZARD_Timer = 3000;
			FROST_Timer = 30000;
			LEGION_LIGHTNING_Timer = 5000;
			ENRAGE_Timer = 60000;

			Phase = 1;
		}

		void UpdateAI(const uint32 uiDiff)
		{
			if (!UpdateVictim())
				return;

			if (me->GetHealthPct() <= 30.0f && Phase == 1)
			{
				Phase = 2;
			}

			if (Phase == 1)
			{
				if (NETHER_Timer <= uiDiff)
				{
					if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
						DoCast(pTarget, SPELL_LEGION_LIGHTNING);
					NETHER_Timer = 20000;
				}
				else
					NETHER_Timer -= uiDiff;

				if (BLAST_Timer <= uiDiff)
				{
					if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
						DoCast(pTarget, SPELL_NETHER_PORTAL_EFFECT);
					BLAST_Timer = 7500;
				}
				else
					BLAST_Timer -= uiDiff;

				if (SUMMON_BLIZZARD_Timer <= uiDiff)
				{
					DoCast(me, SPELL_SUMMON_BLIZZARD);
					SUMMON_BLIZZARD_Timer = 3000;
				}
				else
					SUMMON_BLIZZARD_Timer -= uiDiff;

				if (FROST_Timer <= uiDiff)
				{
					DoCast(me, SPELL_SHOCK_BLAST);
					FROST_Timer = 5000;
				}
				else
					FROST_Timer -= uiDiff;
			}

			if (Phase == 2)
			{
				if (LEGION_LIGHTNING_Timer <= uiDiff)
				{
					if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
						DoCast(pTarget, SPELL_NETHER_PORTAL_EFFECT);
					LEGION_LIGHTNING_Timer = 2000;
				}
				else
					LEGION_LIGHTNING_Timer -= uiDiff;

				if (BLAST_Timer <= uiDiff)
				{
					DoCast(me, SPELL_FROST_MISSILE);
					BLAST_Timer = 50000;
				}
				else
					BLAST_Timer -= uiDiff;

				if (ENRAGE_Timer <= uiDiff)
				{
					DoCast(me, SPELL_ENRAGE);
					ENRAGE_Timer = 18000000;
				}
				else
					ENRAGE_Timer -= uiDiff;
			}
			DoMeleeAttackIfReady();
		}
	};
};

void AddSC_tyranium()
{
	new tyranium();
}