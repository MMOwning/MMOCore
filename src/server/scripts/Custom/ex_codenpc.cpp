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

		bool OnGossipSelectCode(Player* player, GameObject* /*go*/, uint32 /*sender*/, uint32 action , const char* code){
			
			player->GetGUID();	
			

			if (!*code){
				char msg[250];
				snprintf(msg, 250, "Es wurde kein Code eingetragen.");
				ChatHandler(player->GetSession()).PSendSysMessage(msg,
					player->GetName());
				return false;
			}
	

			QueryResult coderesult = CharacterDatabase.PQuery("SELECT * FROM CODES WHERE Code = %s", code);
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
				genutzt = genutzt + 1;
				CharacterDatabase.PExecute("REPLACE INTO CODES "
					"(Spieler,genutzt) "
					"VALUES ('%s', %u)",
					player, genutzt);

				
				char msg[250];
				snprintf(msg, 250, "Dein Code wurde akzeptiert. Deine Belohnung wurde dir gutgeschrieben.");
				ChatHandler(player->GetSession()).PSendSysMessage(msg,
					player->GetName());



				ss << "|cff54b5ffEin Code wurde eingeloest von |r " << ChatHandler(player->GetSession()).GetNameLink();
				sWorld->SendGMText(LANG_GM_BROADCAST, ss.str().c_str());
				return true;

			}

		}

};


void AddSC_codenpc()
{
	new codenpc();
}