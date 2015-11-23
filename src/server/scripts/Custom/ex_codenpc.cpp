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

#define GOSSIP_ITEM_1       "A quiz: what's your name?"
#define GOSSIP_ITEM_2       "I'm not interested"


class codenpc : public CreatureScript
{
public: codenpc() : CreatureScript("codenpc"){ }
		std::ostringstream ss;


		bool OnGossipHello(Player* pPlayer, Creature* pCreature)
		{
			pPlayer->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_ITEM_1, GOSSIP_SENDER_MAIN, 1, "", 0, true);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_2, GOSSIP_SENDER_MAIN,  2);

			pPlayer->PlayerTalkClass->SendGossipMenu(907, pCreature->GetGUID());

			return true;
		}


		bool OnGossipSelectCode(Player* player, GameObject* /*go*/, uint32 /*sender*/, uint32 action, const char* code){
		
			
			switch (action)
			{
			case 1:
			
				
					uint32 spieler = player->GetGUID();
					std::string codes = code;

					if (!*code){
						char msg[250];
						snprintf(msg, 250, "Es wurde kein Code eingetragen.");
						ChatHandler(player->GetSession()).PSendSysMessage(msg,
							player->GetName());
						return false;
					}


					QueryResult coderesult = CharacterDatabase.PQuery("SELECT * FROM codes WHERE Code = %s", codes);
					std::string codedb = (*coderesult)[0].GetString();
					uint32 genutzt = (*coderesult)[3].GetUInt32();

					if (codedb == ""){
						char msg[250];
						snprintf(msg, 250, "Dein Code wurde nicht akzeptiert.");
						ChatHandler(player->GetSession()).PSendSysMessage(msg,
							player->GetName());
						return false;
					}


					if (genutzt == 0){
						genutzt = 1;
						CharacterDatabase.PExecute("UPDATE CODES set Spieler = %s, genutzt = %u WHERE Code = %s"
							"(Spieler,genutzt) "
							"VALUES ('%s', '%u')",
							spieler, genutzt, codes);


						char msg[250];
						snprintf(msg, 250, "Dein Code wurde akzeptiert. Deine Belohnung wurde dir gutgeschrieben.");
						ChatHandler(player->GetSession()).PSendSysMessage(msg,
							player->GetName());



						ss << "|cff54b5ffEin Code wurde eingeloest von |r " << ChatHandler(player->GetSession()).GetNameLink();
						sWorld->SendGMText(LANG_GM_BROADCAST, ss.str().c_str());
						return true;
		
				}
				
				player->CLOSE_GOSSIP_MENU();

				return true;
			
		}

		return false;

		

			}
		

};



void AddSC_codenpc()
{
	new codenpc();
}