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


class wandervolk : public CreatureScript
{

public:
	wandervolk() : CreatureScript("wandervolk") { }

	bool OnGossipHello(Player *pPlayer, Creature* _creature)
	{
		bool status = pPlayer->GetQuestRewardStatus(900801);
		if (status){
			pPlayer->ADD_GOSSIP_ITEM(7, "Bring mich zum Wandervolk!", GOSSIP_SENDER_MAIN, 0);
		}
		
		pPlayer->ADD_GOSSIP_ITEM(7, "Wer bist du?", GOSSIP_SENDER_MAIN, 1);
		pPlayer->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player * pPlayer, Creature * pCreature, uint32 /*uiSender*/, uint32 uiAction)
	{
		switch (uiAction)
		{

		case 0: {

			pPlayer->GetGUID();
			pPlayer->TeleportTo(0, 3129.77, -6284.07, 140.95, 1.53);
			return true;
		}break;


		case 1: {
			pPlayer->GetGUID();
			ChatHandler(pPlayer->GetSession()).PSendSysMessage("Das Wandervolk ist ein sehr vorsichtiges Volk. Du kannst dich nur beweissen indem du ihre Aufgaben erfuellst.",
				pPlayer->GetName());
			pPlayer->PlayerTalkClass->SendCloseGossip();
			return true;
		}break;
		return true;
		}
	return true;
	};
};


void AddSC_wandervolk()
{
	new wandervolk();
}