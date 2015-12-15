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




class br_levelNPC : public CreatureScript
{
public: br_levelNPC() : CreatureScript("br_levelNPC"){ }

		bool OnGossipHello(Player* pPlayer, Creature* _creature) {

			pPlayer->ADD_GOSSIP_ITEM(7, "Ich wuerde gerne 1 Astralen Kredit gegen 1 Level eintauschen.", GOSSIP_SENDER_MAIN, 0);


			if (pPlayer->GetSession()->IsPremium()) 
			{
				pPlayer->ADD_GOSSIP_ITEM(7, "Ich moechte mein Level mit 1 Astralen Kredit um 15 level erhoehen.", GOSSIP_SENDER_MAIN, 1);	
			}


			pPlayer->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());
			return true;
		}

		bool OnGossipSelect(Player * pPlayer, Creature * /*pCreature*/, uint32 /*uiSender*/, uint32 uiAction)
		{
			switch (uiAction){


				//Ich würde gern 1 AstraleKredit gegen Level eintauschen
			case 0:
			{
				

				if (pPlayer->getLevel() < 80)
				{
					uint16 levelb = pPlayer->getLevel() + 1;

					if (pPlayer->HasItemCount(38186, 1, false))
					{
						pPlayer->DestroyItemCount(38186, 1, true);
						pPlayer->SetLevel(levelb);
						return true;
					}

					else {
								
						pPlayer->GetGUID();
						ChatHandler(pPlayer->GetSession()).PSendSysMessage("Du hast nicht genug Astrale Kredite.",
							pPlayer->GetName());
						pPlayer->PlayerTalkClass->SendCloseGossip();
						return true;
					}

				}
				
				else
				{
					pPlayer->GetGUID();
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Du bist doch schon Level 80.",
						pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}

				return true;
			}break;
			

			//Ich moechte mein Level mit 1 Astralen Kredit um 15 level erhoehen.

			case 1:
			{
				


				if (pPlayer->getLevel() < 80)
				{
					uint16 levelb = pPlayer->getLevel() + 15;

					if (pPlayer->HasItemCount(38186, 1, false))
					{
						pPlayer->DestroyItemCount(38186, 1, true);
						pPlayer->SetLevel(levelb);
						return true;
					}

					else {

						pPlayer->GetGUID();
						ChatHandler(pPlayer->GetSession()).PSendSysMessage("Du hast nicht genug Astrale Kredite.",
							pPlayer->GetName());
						pPlayer->PlayerTalkClass->SendCloseGossip();
						return true;
					}

				}

				else
				{
					pPlayer->GetGUID();
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Du bist doch schon Level 80.",
						pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}

				return true;
			}break;



			}

            return true;
		}

};


void AddSC_br_levelNPC()
{
	new br_levelNPC();
}