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


class sb_porter1 : public CreatureScript
{

public:
	sb_porter1() : CreatureScript("porter1") { }
	
	bool OnGossipHello(Player* pPlayer, Creature* pCreature)
	{
		pPlayer->ADD_GOSSIP_ITEM(7, "Teleportiert mich bitte zum nächsten Punkt", GOSSIP_SENDER_MAIN, 0);
		
		pPlayer->PlayerTalkClass->SendGossipMenu(907, pCreature->GetGUID());
		return true;

	}
	
	bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
	{

		switch (uiAction)
		{
		case 0:
		{
			pPlayer->TeleportTo(1, -1577.00, 357.25, 235.82, 5.37);

			return true;

		}break;

		}
		return true;
	}
};



void AddSC_sb_worldevent()
{
		new sb_porter1();
//		new sb_porter2();
}
