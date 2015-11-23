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
enum eEnums
{
	SPELL_POLYMORPH = 12826,
	SPELL_MARK_OF_THE_WILD = 26990,

	SAY_NOT_INTERESTED = -1999922,
	SAY_WRONG = -1999923,
	SAY_CORRECT = -1999924
};

#define GOSSIP_ITEM_1       "A quiz: what's your name?"
#define GOSSIP_ITEM_2       "I'm not interested"

class codenpc : public CreatureScript
{
public:

	codenpc()
		: CreatureScript("codenpc")
	{
	}

	bool OnGossipHello(Player* pPlayer, Creature* pCreature)
	{
		pPlayer->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1, "", 0, true);
		pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

		pPlayer->PlayerTalkClass->SendGossipMenu(907, pCreature->GetGUID());

		return true;
	}

	bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
	{
		pPlayer->PlayerTalkClass->ClearMenus();
		if (uiAction == GOSSIP_ACTION_INFO_DEF + 2)
		{
			DoScriptText(SAY_NOT_INTERESTED, pCreature);
			pPlayer->CLOSE_GOSSIP_MENU();
		}

		return true;
	}

	bool OnGossipSelectCode(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction, const char* code)
	{
		pPlayer->PlayerTalkClass->ClearMenus();
		if (uiSender == GOSSIP_SENDER_MAIN)
		{
			switch (uiAction)
			{
			case GOSSIP_ACTION_INFO_DEF + 1:
				if (std::strcmp(code, pPlayer->GetName()) != 0)
				{
					pPlayer->ModifyArenaPoints(2222);
				}
				else
				{
					pPlayer->ModifyArenaPoints(1111);
				}
				pPlayer->CLOSE_GOSSIP_MENU();

				return true;
			}
		}

		return false;
	}
};


void AddSC_codenpc()
{
	new codenpc();
}