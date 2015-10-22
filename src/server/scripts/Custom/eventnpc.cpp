#include "ScriptMgr.h"
#include "AccountMgr.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>
#include "GameEventMgr.h"
#include "AccountMgr.h"
#include "time.h"
#include <stdio.h>
#include "Bag.h"
#include "Common.h"
#include "Config.h"
#include "DatabaseEnv.h"
#include "DBCStructure.h"
#include "Define.h"
#include "Field.h"
#include "GameEventMgr.h"
#include "Item.h"
#include "ItemPrototype.h"
#include "Language.h"
#include "Log.h"
#include "ObjectGuid.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "QueryResult.h"
#include "ScriptMgr.h"
#include "SharedDefines.h"
#include "Transaction.h"
#include "WorldSession.h"
#include <sstream>
#include <string>
#include <stdlib.h>


class eventnpc : public CreatureScript
{
public: eventnpc() : CreatureScript("eventnpc"){ }



		bool OnGossipHello(Player *pPlayer, Creature* _creature)
		{
			
			pPlayer->GetGUID();
			pPlayer->ADD_GOSSIP_ITEM(7, "Was tut dieser NPC?", GOSSIP_SENDER_MAIN, 0);
			pPlayer->ADD_GOSSIP_ITEM(7, "MMOwning Weihnachtsevent.", GOSSIP_SENDER_MAIN, 1);
			pPlayer->ADD_GOSSIP_ITEM(7, "MMOwning Halloweenevent. 21.10. - 11.11.", GOSSIP_SENDER_MAIN, 2);
			pPlayer->ADD_GOSSIP_ITEM(7, "Das Wandervolk", GOSSIP_SENDER_MAIN, 3);
			pPlayer->ADD_GOSSIP_ITEM(7, "Jumpevent", GOSSIP_SENDER_MAIN, 4);
			pPlayer->ADD_GOSSIP_ITEM(7, "Das Portal", GOSSIP_SENDER_MAIN, 5);
			pPlayer->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());
			return true;
		}
			


		bool OnGossipSelect(Player * pPlayer, Creature * pCreature, uint32 /*uiSender*/, uint32 uiAction)
		{
			switch (uiAction)
			{
				
				case 1: {
					
					GameEventMgr::ActiveEvents const& ae = sGameEventMgr->GetActiveEventList();
					bool active = ae.find(70) != ae.end();
					if (active == true){
						pPlayer->GetGUID();
						ChatHandler(pPlayer->GetSession()).PSendSysMessage("Viel Spaß beim Weihnachtsevent wuenscht dir Exitare und das gesammte MMOwning Team.",
							pPlayer->GetName());
						pPlayer->PlayerTalkClass->SendCloseGossip();
						pPlayer->TeleportTo(1, 16226.21, 16256.77, 13.19, 1.65);
						return true;
					}
					else{
						ChatHandler(pPlayer->GetSession()).PSendSysMessage("Es ist noch nicht Weihnachten! Bitte gedulde dich daher bis zum 18. Dezember.",
							pPlayer->GetName());
						pPlayer->PlayerTalkClass->SendCloseGossip();
					}
					return true;
				}break;
				
						
				case 0: {
					pPlayer->GetGUID();
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Dieser NPC zeigt die MMOwning Events an. Mit einem Klick auf das entsprechende Event bekommst du entweder eine Erklaerung, oder wirst bei aktivem Event direkt dorthin geportet. ",
						pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}break;

				//Halloween
				case 2:
				{
					GameEventMgr::ActiveEvents const& ae = sGameEventMgr->GetActiveEventList();
					bool active = ae.find(71) != ae.end();
					if (active == true){
						pPlayer->GetGUID();
						pPlayer->TeleportTo(0, -9741.38, 1258.66, 11.31, 5.93);
						ChatHandler(pPlayer->GetSession()).PSendSysMessage("Viel Spass beim Halloweenevent wuenscht dir Exitare und das gesammte MMOwning Team.",
							pPlayer->GetName());
						pPlayer->PlayerTalkClass->SendCloseGossip();
						return true;
					}
					else{
						pPlayer->GetGUID();
						ChatHandler(pPlayer->GetSession()).PSendSysMessage("Das Halloweenevent ist noch nicht aktiv. Bitte gedulde dich bis zum 21.10 des Jahres.",
							pPlayer->GetName());
						pPlayer->PlayerTalkClass->SendCloseGossip();
						return true;
					}
					return true;
				}break;


				//Wandervolk
				case 3:
				{
					GameEventMgr::ActiveEvents const& ae = sGameEventMgr->GetActiveEventList();
					bool active = ae.find(72) != ae.end();
					if (active == true){
						pPlayer->GetGUID();
						ChatHandler(pPlayer->GetSession()).PSendSysMessage("Das Event ist aktuell aktiv. Der Start ist bei Exitare auf der Insel. Wir wuenschen viel Spass.",
							pPlayer->GetName());
						pPlayer->PlayerTalkClass->SendCloseGossip();
						return true;
					}

					else{
						pPlayer->GetGUID();
						ChatHandler(pPlayer->GetSession()).PSendSysMessage("Das Wandervolk ist alle 3 Tage verfuegbar. Ihr koennt die Vorbereitungen fuer das Event bei Exitare starten.",
							pPlayer->GetName());
						pPlayer->PlayerTalkClass->SendCloseGossip();
						return true;
					}
					return true;
				}break;

				//Jumpevent
				case 4:
				{
					GameEventMgr::ActiveEvents const& ae = sGameEventMgr->GetActiveEventList();
					bool active = ae.find(73) != ae.end();
					if (active == true){
						pPlayer->GetGUID();
						pPlayer->TeleportTo(1, 7345.04, -1541.83, 161.32, 0.39);
						ChatHandler(pPlayer->GetSession()).PSendSysMessage("Das Event ist aktuell aktiv. Viel Spaß beim Erreichen des Ziels.",
							pPlayer->GetName());
						pPlayer->PlayerTalkClass->SendCloseGossip();
						return true;
					}

					else{
						pPlayer->GetGUID();
						ChatHandler(pPlayer->GetSession()).PSendSysMessage("Das Jumpevent ist alle 2 Wochen fuer 7 Tage aktiv. Aktuell ist es nicht aktiv.",
							pPlayer->GetName());
						pPlayer->PlayerTalkClass->SendCloseGossip();
						return true;
					}
					return true;
				}break;

				//Portalevent
				case 5:
				{
					GameEventMgr::ActiveEvents const& ae = sGameEventMgr->GetActiveEventList();
					bool active = ae.find(74) != ae.end();
					if (active == true){
						pPlayer->GetGUID();
						pPlayer->TeleportTo(1, 7345.04, -1541.83, 161.32, 0.39);
						ChatHandler(pPlayer->GetSession()).PSendSysMessage("Das Event ist aktuell aktiv. Viel Spaß beim Erreichen des Ziels.",
							pPlayer->GetName());
						pPlayer->PlayerTalkClass->SendCloseGossip();
						return true;
					}

					else{
						pPlayer->GetGUID();
						ChatHandler(pPlayer->GetSession()).PSendSysMessage("Das Event 'Das Portal' ist alle 14 Tage fuer 7 Tage aktiv.  Aktuell ist es nicht aktiv.",
							pPlayer->GetName());
						pPlayer->PlayerTalkClass->SendCloseGossip();
						return true;
					}
					return true;
				}break;

					return true;
			}
			return true;
		}
};


void AddSC_eventnpc()
{
	new eventnpc();
}