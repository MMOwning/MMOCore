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


		bool OnGossipSelectCode(Player* player, Creature* creature, uint32 /*sender*/, uint32 action, const char* code)
		{
			player->PlayerTalkClass->ClearMenus();
			uint32 itemCode = atoi((char*)code);

			if (!itemCode)
			{
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendNotification("You must enter a value!");
				return false;
			}

			QueryResult result = CharacterDatabase.PQuery("SELECT `code`, `genutzt` FROM `codes` WHERE `code` = %u", itemCode);

			if (action == 1)
			{
				if (result)
				{
					Field* fields = result->Fetch();
					uint32 code = fields[0].GetUInt32();
					char msg[250];
					snprintf(msg, 250, "Code fetch");
					ChatHandler(player->GetSession()).PSendSysMessage(msg,
						player->GetName());
					uint8 genutzt = fields[2].GetUInt8();
					uint32 belohnung = 49426;
					uint32 anzahl = 2;


					if (code == itemCode) {
						if (genutzt == 0)
						{
							Item* item = Item::CreateItem(belohnung, anzahl);

							SQLTransaction trans = CharacterDatabase.BeginTransaction();
							item->SaveToDB(trans);
							MailDraft("Geschenkcode", "Dein Code wurde erfolgreich eingelöst.").AddItem(item)
								.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
							CharacterDatabase.CommitTransaction(trans);

							CharacterDatabase.PExecute("UPDATE codes SET spieler = '%s' WHERE code = %u", player->GetName().c_str(), itemCode);
							CharacterDatabase.PExecute("UPDATE codes SET genutzt = 1 WHERE code = %u", itemCode);

							char msg[250];
							snprintf(msg, 250, "Dein Code wurde akzeptiert. Deine Belohnung wurde dir gutgeschrieben.");
							ChatHandler(player->GetSession()).PSendSysMessage(msg,
								player->GetName());

						}
						else{
							char msg[250];
							snprintf(msg, 250, "Dein Code wurde bereits verwendet");
							ChatHandler(player->GetSession()).PSendSysMessage(msg,
								player->GetName());
							return false;
						}

					}
					else
					{
						char msg[250];
						snprintf(msg, 250, "Dein Code wurde nicht akzeptiert.");
						ChatHandler(player->GetSession()).PSendSysMessage(msg,
							player->GetName());
						return false;
					}
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