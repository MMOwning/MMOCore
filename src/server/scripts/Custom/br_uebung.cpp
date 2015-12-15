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






class br_uebung : public CreatureScript
{
public: br_uebung() : CreatureScript("br_uebung"){ }

		bool OnGossipHello(Player* pPlayer, Creature* _creature) { 
		

			pPlayer->ADD_GOSSIP_ITEM(7, "porte mich", GOSSIP_SENDER_MAIN, 0);
			pPlayer->ADD_GOSSIP_ITEM(7, "Wsetz mich bitte auf level 60", GOSSIP_SENDER_MAIN, 1);
			pPlayer->ADD_GOSSIP_ITEM(7, "gib mir alc! ", GOSSIP_SENDER_MAIN, 2);
			pPlayer->ADD_GOSSIP_ITEM(7, "awffwf", GOSSIP_SENDER_MAIN, 3);

			pPlayer->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());
			return true;
		}

		bool OnGossipSelect(Player * pPlayer, Creature * /*pCreature*/, uint32 /*uiSender*/, uint32 uiAction)
		{
			switch (uiAction)
			{


				// porte mich
			case 0:
			{
				if (pPlayer->getLevel() >= 10) {
					pPlayer->TeleportTo(1, 1, 1, 1, 1, 0);
				}
				else {
					pPlayer->GetGUID();
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Du musst wohl noch mehr Leveln, damit du dich porten kannst. Sorry",
						pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}

			}break;


			// setz mich bitte auf level 60
			case 1:
			{
				if (pPlayer->getLevel() <= 50) {
					pPlayer->SetLevel(60);

				}
				else {
					pPlayer->GetGUID();
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("trollololol",
						pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}

			}break;


			// gib mir alc!
			case 2:
			{
				if (pPlayer->HasItemCount(123455, 23, false) && pPlayer->getLevel() >= 18){
					pPlayer->SetDrunkValue(123, 321354);
					pPlayer->DestroyItemCount(123455, 5, true);

				}

				else {
					pPlayer->GetGUID();
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Du erfüllst leider die anförderungen nicht.",
						pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}
			}break;

			//aefweafw
			case 3:
			{
				if (pPlayer->IsGameMaster()) {
					pPlayer->TeleportTo(1, 1, 1, 1, 1, 0);
					return true;
				}

				else{
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;

				}
				return true;
			}
			return true;
		}
            return true;
	}


};


void AddSC_br_uebung()
{
	new br_uebung();
}
