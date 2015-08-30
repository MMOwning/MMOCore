#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Spells{
	SPELL_HEX = 66054,							// FLUCH
	SPELL_SHEEP = 65801,						// MAGIE
	SPELL_FLUCH_DER_PEIN = 65814,				// FLUCH
	SPELL_SPALTEN = 40504,						// bis zu 3 Ziele
	SPELL_SCHATTENWORT_SCHMERZ = 65541,			// MAGIE
	SPELL_FROSTFIEBER = 67767,					// KRANKHEIT
	SPELL_RUESTUNG_ZERREISSEN = 74367,			// stackbar bis 5x
	SPELL_VERDERBNIS = 65810,					// MAGIE
	SPELL_FLEISCH_EINAESCHERN = 66237,			// 30k muessen weggeheilt werden sonst explodiert der Spell und fuegt AOE Feuerschaden zu
	SPELL_ZAUBERSCHILD = 33054,					// 75% weniger Zauberschaden BUFF
	SPELL_WIRBELWIND = 40219,					// 6 Sekunden Wirbelwind
	SPELL_INSTABILES_GEBRECHEN = 65812,			// MAGIE
	SPELL_VERDERBENDE_SEUCHE = 60588,			// STERBT EINFACH
	SPELL_WUNDGIFT = 65962,						// GIFT
	SPELL_HAMMER_DER_GERECHTIGKEIT = 66613,		// STUN
	SPELL_GOETTLICHER_STURM = 66006				// Melee AOE auf 4 Targets, Waffenschaden+Heiligschaden
};

enum Events{
	EVENT_HEX = 1,							
	EVENT_SHEEP = 2,						
	EVENT_FLUCH_DER_PEIN = 3,				
	EVENT_SPALTEN = 4,						
	EVENT_SCHATTENWORT_SCHMERZ = 5,			
	EVENT_FROSTFIEBER = 6,					
	EVENT_RUESTUNG_ZERREISSEN = 7,			
	EVENT_VERDERBNIS = 8,					
	EVENT_FLEISCH_EINAESCHERN = 9,			
	EVENT_ZAUBERSCHILD = 10,					
	EVENT_WIRBELWIND = 11,					
	EVENT_INSTABILES_GEBRECHEN = 12,		
	EVENT_VERDERBENDE_SEUCHE = 13,			
	EVENT_WUNDGIFT = 14,						
	EVENT_HAMMER_DER_GERECHTIGKEIT = 15,		
	EVENT_GOETTLICHER_STURM = 16
};

enum Phases{
	PHASE_ONE = 1,
	PHASE_TWO = 2,
	PHASE_THREE = 3,
};

class anna : public CreatureScript{
	public:
		anna() : CreatureScript("anna") { }

		struct annaAI : public ScriptedAI {

			annaAI(Creature* creature) : ScriptedAI(creature) {}

			void Reset() override
			{
				_events.Reset();
			}

			void EnterCombat(Unit* /*who*/) override
			{
				_events.SetPhase(PHASE_ONE);
				_events.ScheduleEvent(EVENT_HEX, 1000);
				_events.ScheduleEvent(EVENT_SHEEP, 1000);
				_events.ScheduleEvent(EVENT_FLUCH_DER_PEIN, 8000);
				_events.ScheduleEvent(EVENT_SPALTEN, 10000);
				_events.ScheduleEvent(EVENT_SCHATTENWORT_SCHMERZ, 20000);
				_events.ScheduleEvent(EVENT_FROSTFIEBER, 800);

			}

			void DamageTaken(Unit* /*attacker*/, uint32& damage) override
			{
				if (me->HealthBelowPctDamaged(75, damage) && _events.IsInPhase(PHASE_ONE))
				{
					_events.SetPhase(PHASE_TWO);
					_events.ScheduleEvent(EVENT_HEX, 1000);
					_events.ScheduleEvent(EVENT_SHEEP, 1000);
					_events.ScheduleEvent(EVENT_FLUCH_DER_PEIN, 8000);
					_events.ScheduleEvent(EVENT_SPALTEN, 10000);
					_events.ScheduleEvent(EVENT_SCHATTENWORT_SCHMERZ, 20000);
					_events.ScheduleEvent(EVENT_FLEISCH_EINAESCHERN, 2000);

				}

				if (me->HealthBelowPctDamaged(50, damage) && _events.IsInPhase(PHASE_TWO))
				{
					_events.SetPhase(PHASE_THREE);
					_events.ScheduleEvent(EVENT_HEX, 1000);
					_events.ScheduleEvent(EVENT_SHEEP, 1000);
					_events.ScheduleEvent(EVENT_FLUCH_DER_PEIN, 8000);
					_events.ScheduleEvent(EVENT_SPALTEN, 10000);
					_events.ScheduleEvent(EVENT_RUESTUNG_ZERREISSEN, 1000);
					_events.ScheduleEvent(EVENT_VERDERBNIS, 1000);
					_events.ScheduleEvent(EVENT_FLEISCH_EINAESCHERN, 2000);
					_events.ScheduleEvent(EVENT_ZAUBERSCHILD, 4000);
					_events.ScheduleEvent(EVENT_WIRBELWIND, 2000);
					_events.ScheduleEvent(EVENT_INSTABILES_GEBRECHEN, 3000);
					_events.ScheduleEvent(EVENT_VERDERBENDE_SEUCHE, 800);
					_events.ScheduleEvent(EVENT_WUNDGIFT, 600);

				}

				if (me->HealthBelowPctDamaged(20, damage) && _events.IsInPhase(PHASE_THREE))
				{
					_events.SetPhase(PHASE_THREE);
					_events.ScheduleEvent(EVENT_HEX, 1000);
					_events.ScheduleEvent(EVENT_SHEEP, 1000);
					_events.ScheduleEvent(EVENT_FLUCH_DER_PEIN, 8000);
					_events.ScheduleEvent(EVENT_RUESTUNG_ZERREISSEN, 1000);
					_events.ScheduleEvent(EVENT_VERDERBNIS, 1000);
					_events.ScheduleEvent(EVENT_FLEISCH_EINAESCHERN, 2000);
					_events.ScheduleEvent(EVENT_VERDERBENDE_SEUCHE, 800);
					_events.ScheduleEvent(EVENT_WUNDGIFT, 600);
					_events.ScheduleEvent(EVENT_HAMMER_DER_GERECHTIGKEIT, 1500);
					_events.ScheduleEvent(EVENT_GOETTLICHER_STURM, 1320);

				}
			}

			void JustDied(Unit* /*killer*/) override
			{
				char msg[250];
				snprintf(msg, 250, "|cffff0000[Boss System]|r Boss|cffff6060 Anna|r wurde getötet! Der Respawn erfolgt in 7 Tagen.");
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
					case EVENT_HEX:
						DoCastVictim(SPELL_HEX);
						_events.ScheduleEvent(EVENT_HEX, 1000);
						break;
					case EVENT_SHEEP:
						DoCastVictim(SPELL_SHEEP);
						_events.ScheduleEvent(EVENT_SHEEP, 1000);
						break;
					case EVENT_FLUCH_DER_PEIN:
						DoCastVictim(SPELL_FLUCH_DER_PEIN);
						_events.ScheduleEvent(EVENT_FLUCH_DER_PEIN, 8000);
						break;
					case EVENT_SPALTEN:
						DoCastVictim(SPELL_SPALTEN);
						_events.ScheduleEvent(EVENT_SPALTEN, 10000);
						break;
					case EVENT_SCHATTENWORT_SCHMERZ:
						DoCastToAllHostilePlayers(SPELL_SCHATTENWORT_SCHMERZ);
						_events.ScheduleEvent(EVENT_SCHATTENWORT_SCHMERZ, 20000);
						break;
					case EVENT_RUESTUNG_ZERREISSEN:
						DoCastVictim(SPELL_RUESTUNG_ZERREISSEN);
						_events.ScheduleEvent(EVENT_RUESTUNG_ZERREISSEN, 1000);
						break;
					case EVENT_VERDERBNIS:
						DoCastVictim(SPELL_VERDERBNIS);
						_events.ScheduleEvent(EVENT_VERDERBNIS, 1000);
						break;
					case EVENT_FLEISCH_EINAESCHERN:
						DoCastVictim(SPELL_FLEISCH_EINAESCHERN);
						_events.ScheduleEvent(EVENT_FLEISCH_EINAESCHERN, 2000);
						break;
					case EVENT_INSTABILES_GEBRECHEN:
						DoCastVictim(SPELL_INSTABILES_GEBRECHEN);
						_events.ScheduleEvent(EVENT_INSTABILES_GEBRECHEN, 3000);
						break;
					case EVENT_WIRBELWIND:
						DoCastVictim(SPELL_WIRBELWIND);
						_events.ScheduleEvent(EVENT_WIRBELWIND, 2000);
						break;
					case EVENT_VERDERBENDE_SEUCHE:
						DoCastVictim(SPELL_VERDERBENDE_SEUCHE);
						_events.ScheduleEvent(EVENT_VERDERBENDE_SEUCHE, 800);
						break;
					case EVENT_WUNDGIFT:
						DoCastVictim(SPELL_WUNDGIFT);
						_events.ScheduleEvent(EVENT_WUNDGIFT, 1000);
						break;
					case EVENT_HAMMER_DER_GERECHTIGKEIT:
						DoCastVictim(SPELL_HAMMER_DER_GERECHTIGKEIT);
						_events.ScheduleEvent(EVENT_HAMMER_DER_GERECHTIGKEIT, 1000);
						break;
					case EVENT_GOETTLICHER_STURM:
						DoCastVictim(SPELL_GOETTLICHER_STURM);
						_events.ScheduleEvent(EVENT_GOETTLICHER_STURM, 1000);
						break;
					case EVENT_ZAUBERSCHILD:
						DoCast(me, SPELL_ZAUBERSCHILD);
						_events.ScheduleEvent(EVENT_ZAUBERSCHILD, 4000);
						break;
					default:
						break;
					}
				}

				DoMeleeAttackIfReady();
			}

		private:
			EventMap _events;
		};

		CreatureAI* GetAI(Creature* creature) const override
		{
			return new annaAI(creature);
		}

};

void AddSC_anna()
{
	new anna();
}