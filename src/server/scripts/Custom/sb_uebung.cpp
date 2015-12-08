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


class sb_uebung : public CreatureScript
{

public:
	sb_uebung() : CreatureScript("sb_uebung") { }

	bool OnGossipHello(Player* pPlayer, Creature* pCreature)
	{
		pPlayer->ADD_GOSSIP_ITEM(7, "Levelprüfen", GOSSIP_SENDER_MAIN, 0);
		pPlayer->ADD_GOSSIP_ITEM(7, "Funktion 2", GOSSIP_SENDER_MAIN, 1);
		pPlayer->ADD_GOSSIP_ITEM(7, "Questreward", GOSSIP_SENDER_MAIN, 2);

		if (pPlayer->GetSession()->GetSecurity() > 1){
			pPlayer->ADD_GOSSIP_ITEM(7, "Funktion 4", GOSSIP_SENDER_MAIN, 3);
		}

		pPlayer->PlayerTalkClass->SendGossipMenu(907, pCreature->GetGUID());
		return true;

	}
	bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
	{
		switch (uiAction)
		{
		case 0:
		{
			if (pPlayer->getLevel() >= 50)
			{
				ChatHandler(pPlayer->GetSession()).PSendSysMessage("Glückwunsch du bist Level 50 oder höher!");
				return true;
			}
			else
			{
				ChatHandler(pPlayer->GetSession()).PSendSysMessage("Du bist leider noch nicht Level 50.");
				return true;
			}
			return true;
		}
		

		case 1:
		{
			pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
			pPlayer->PlayerTalkClass->ClearMenus();
			pPlayer->ADD_GOSSIP_ITEM(7, "Funktion 5", GOSSIP_SENDER_MAIN, 4);
			pPlayer->ADD_GOSSIP_ITEM(7, "Funktion 6", GOSSIP_SENDER_MAIN, 5);
			pPlayer->ADD_GOSSIP_ITEM(7, "Funktion 7", GOSSIP_SENDER_MAIN, 6);
			pPlayer->PlayerTalkClass->SendGossipMenu(907, pCreature->GetGUID());
			return true;

		}break;
		
		

		case 3:
		{

		}break;
		
		case 4:
		{

		}break;
		
		case 5:
		{

		}break;
		
		case 6:
		{

		}break;

	
		return true;
		}
		return true;
	}
};

void AddSC_sb_uebung()
{
	new sb_uebung();
}






