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

class Race_Change_NPC : public CreatureScript
{
public:
	Race_Change_NPC() : CreatureScript("racechange") {  }

	bool OnGossipHello(Player* player, Creature* creature)
	{
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Wie funktioniert das?", GOSSIP_SENDER_MAIN, 0);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Rassenwechsel Kosten: 500 Gold & 2 Frostmarken", GOSSIP_SENDER_MAIN,1);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Fraktionswechsel Kosten: 500 Gold & 2 Frostmarken", GOSSIP_SENDER_MAIN, 2);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Fraktions & Rassenwechsel Kosten: 500 Gold & 2 Frostmarken.", GOSSIP_SENDER_MAIN,3);
		player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
		return true;
	}
	bool OnGossipSelect(Player* pPlayer, Creature* creature, uint32 sender, uint32 action){
		pPlayer->PlayerTalkClass->ClearMenus();
		if (sender != GOSSIP_SENDER_MAIN)
			return false;
		switch (action){

		case  0:
			
				pPlayer->GetGUID();
				ChatHandler(pPlayer->GetSession()).PSendSysMessage("Einfach auswaehlen was du moechtest und dann reloggen.",
					pPlayer->GetName());
				pPlayer->PlayerTalkClass->SendCloseGossip();
				return true;
			break;
		case  1:
			if (pPlayer->HasItemCount(49426, 2)){
				pPlayer->DestroyItemCount(49426, 2, true, false);
				pPlayer->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
				pPlayer->GetGUID();
				sWorld->SendGMText(LANG_GM_BROADCAST, "Ein Rassenwechsel wurde vorgenommen.");
				ChatHandler(pPlayer->GetSession()).PSendSysMessage("Bitte ausloggen um Aenderungen durchzufuehren.",
					pPlayer->GetName());
				pPlayer->ModifyMoney(-5000000);
				pPlayer->PlayerTalkClass->SendCloseGossip();
				return true;
			}

			else{
				pPlayer->GetSession()->SendAreaTriggerMessage("Du hast nicht genug Marken zum wechseln. Komm wieder wenn du genug hast.");
				return true;
			}

			break;
		case  2:

			if (pPlayer->HasItemCount(49426, 2)){
				pPlayer->DestroyItemCount(49426, 2, true);
				pPlayer->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
				pPlayer->GetGUID();
				sWorld->SendGMText(LANG_GM_BROADCAST, "Ein Franktionswechsel wurde vorgenommen.");
				ChatHandler(pPlayer->GetSession()).PSendSysMessage("Bitte ausloggen um Aenderungen durchzufuehren.",
					pPlayer->GetName());
				pPlayer->ModifyMoney(-5000000);
				pPlayer->PlayerTalkClass->SendCloseGossip();
				return true;
			}


		else{
			pPlayer->GetSession()->SendAreaTriggerMessage("Du hast nicht genug Marken zum wechseln. Komm wieder wenn du genug hast.");
			return true;
		}

			break;
		case 3:
			if (pPlayer->HasItemCount(49426, 2)){
				pPlayer->DestroyItemCount(49426, 2, true, false);
				pPlayer->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
				pPlayer->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
				
				pPlayer->GetGUID();
				sWorld->SendGMText(LANG_GM_BROADCAST, "Ein Fraktions und Rassenwechsel wurde vorgenommen.");
				ChatHandler(pPlayer->GetSession()).PSendSysMessage("Bitte ausloggen um Aenderungen durchzuführen.",
					pPlayer->GetName());
				pPlayer->ModifyMoney(-5000000);
				pPlayer->PlayerTalkClass->SendCloseGossip();
				return true;
			}


			else{
				pPlayer->GetSession()->SendAreaTriggerMessage("Du hast nicht genug Frostmarken zum wechseln. Komm wieder wenn du genug hast.");
				return true;
			}


			break;
		}
		return true;
	}
};

void AddSC_Race_Change_NPC()
{
	new Race_Change_NPC();
}