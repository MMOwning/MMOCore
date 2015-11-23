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

 


class codenpc : public CreatureScript
{
public: codenpc() : CreatureScript("codenpc"){ }
		std::ostringstream ss;


		bool OnGossipHello(Player* player, Creature* creature)
		{
			player->ADD_GOSSIP_ITEM_EXTENDED(0, "Code eingeben", GOSSIP_SENDER_MAIN, 1, "Itemcode eingeben", 0, true);
			player->ADD_GOSSIP_ITEM(7, "Bis bald", GOSSIP_SENDER_MAIN, 10);
			player->SEND_GOSSIP_MENU(1, creature->GetGUID());
			return true;
		}

		bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
		{
				
				player->PlayerTalkClass->ClearMenus();
				if (action == 10)
				{
					char msg[250];
					snprintf(msg, 250, "Dein Code wurde bereits verwendet");
					ChatHandler(player->GetSession()).PSendSysMessage(msg,
						player->GetName());
					return false;
					
					player->CLOSE_GOSSIP_MENU();
				}
			
			return true;
		}


		bool OnGossipSelectCode(Player* player, Creature* creature, uint32 /*sender*/, uint32 action, const char* code)
		{
			TC_LOG_INFO("entities.player.character", "1");
			player->PlayerTalkClass->ClearMenus();
			uint32 itemCode = atoi((char*)code);

			if (!itemCode)
			{
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendNotification("You must enter a value!");
				return false;
				TC_LOG_INFO("entities.player.character", "Spieler hat nichts eingetrage ausgewaehlt");
			}

			QueryResult result = WorldDatabase.PQuery("SELECT `code`, `belohnung`, `anzahl`, `benutzt`FROM `item_codes` WHERE `code` = %u", itemCode);
			TC_LOG_INFO("entities.player.character", "2");
			if (action == 1)
			{
				TC_LOG_INFO("entities.player.character", "3");
				if (result)
				{
					TC_LOG_INFO("entities.player.character", "4");
					Field* fields = result->Fetch();
					uint32 code = fields[0].GetUInt32();
					uint32 belohnung = fields[1].GetUInt32();
					uint32 anzahl = fields[2].GetUInt32();
					uint8 benutzt = fields[3].GetUInt8();

					if (benutzt == 0)
					{
						TC_LOG_INFO("entities.player.character", "5");
						Item* item = Item::CreateItem(belohnung, anzahl);

						SQLTransaction trans = CharacterDatabase.BeginTransaction();
						item->SaveToDB(trans);
						MailDraft("Geschenkcode", "Dein Code wurde erfolgreich eingelöst.").AddItem(item)
							.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
						CharacterDatabase.CommitTransaction(trans);

						WorldDatabase.PExecute("UPDATE item_codes SET name = '%s' WHERE code = %u", player->GetName().c_str(), itemCode);
						WorldDatabase.PExecute("UPDATE item_codes SET benutzt = 1 WHERE code = %u", itemCode);

						
						TC_LOG_INFO("entities.player.character", "Spieler %s hat Code(%u) eingelöst.", player->GetName().c_str(), itemCode);
					}
					else{
						TC_LOG_INFO("entities.player.character", "6");
						char msg[250];
						snprintf(msg, 250, "Dein Code wurde bereits verwendet");
						ChatHandler(player->GetSession()).PSendSysMessage(msg,
							player->GetName());
						return false;
					}
						
				}
				else{
					char msg[250];
					snprintf(msg, 250, "Dein Code wurde bereits verwendet");
					ChatHandler(player->GetSession()).PSendSysMessage(msg,
						player->GetName());
					return false;
				}
					
			}

			player->CLOSE_GOSSIP_MENU();

			return true;
		}
		
	
	
};





void AddSC_codenpc()
{
	new codenpc();
}