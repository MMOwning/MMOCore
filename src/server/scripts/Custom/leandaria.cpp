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


class leandaria : public CreatureScript
{

public:
	leandaria() : CreatureScript("leandaria") { }

	

	bool OnGossipHello(Player *pPlayer, Creature* _creature)
	{
		
		pPlayer->ADD_GOSSIP_ITEM(7, "Hallo", GOSSIP_SENDER_MAIN, 0);
		bool status = pPlayer->GetQuestRewardStatus(900811);
		if (status){
			pPlayer->ADD_GOSSIP_ITEM(7, "Beam mich hoch!", GOSSIP_SENDER_MAIN, 1);
		}

		
		pPlayer->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player * pPlayer, Creature * pCreature, uint32 /*uiSender*/, uint32 uiAction)
	{
		switch (uiAction)
		{

		case 0: {
			pPlayer->GetGUID();
			ChatHandler(pPlayer->GetSession()).PSendSysMessage("Hallo, ich bin Leandaria. Ihr muesst erst in meiner Gunst stehen um bei mir etwas zu bekommen. Schliesst zuerst die Quest 'Der Wyrm' ab.",
				pPlayer->GetName());
			pPlayer->PlayerTalkClass->SendCloseGossip();
			return true;
		}break;


		case 1: {
			pPlayer->GetGUID();
			pPlayer->TeleportTo(0, 3174.49, -6000.48, 203.88, 0.27);
			return true;
		}break;

		return true;
		}
	return true;
	};

	
};


void AddSC_leandaria()
{
	new leandaria();
}