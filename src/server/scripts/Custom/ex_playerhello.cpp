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


class Announce_NewPlayer : public PlayerScript
{
public:
	Announce_NewPlayer() : PlayerScript("Announce_NewPlayer") {}

	void OnLogin(Player * player, bool online)
	{
		std::ostringstream ss;
		
		
		uint32 guid = player->GetGUID();
		uint32 accountid = player->GetSession()->GetAccountId();
<<<<<<< HEAD
		
=======
>>>>>>> 015c5fc899bf9e6b150bdd84b408d420efe1dd36

		QueryResult accountres = CharacterDatabase.PQuery("SELECT account FROM characters WHERE guid = %u", guid);
		uint32 accountresint = (*accountres)[0].GetUInt32();
		QueryResult charresult = CharacterDatabase.PQuery("Select count(guid) From characters where account = '%u'", accountresint);
		uint32 charresultint = (*charresult)[0].GetUInt32();
		
		if (player->GetTotalPlayedTime() < 1 && charresultint == 1)
		{
			ss << "|cff54b5ffWir heissen unseren neuesten Mitspieler|r " << ChatHandler(player->GetSession()).GetNameLink() << " |cff54b5ff auf MMOwning willkommen!|r";
			sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
			sWorld->SendGMText(LANG_GM_BROADCAST,"Ein neuer Spieler ist auf MMO online gegangen.");
			return;
		}

		else if (player->IsGameMaster() && player->GetSession()->GetSecurity() == 2){
			ss << "|cff54b5ffGM|r " << ChatHandler(player->GetSession()).GetNameLink() << " |cff54b5ff ist jetzt online!|r";
			sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
		}

		else if (player->IsGameMaster() && player->GetSession()->GetSecurity() == 3){
			if (accountid == 52252){ //Exitare
				ss << "|cff54b5ffMMOwning Administrator|r " << ChatHandler(player->GetSession()).GetNameLink() << " |cff54b5ff ist jetzt online!|r";
				sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
			}

			else if (accountid == 52806){ //Sturm
				ss << "|cff54b5ffHead GM|r " << ChatHandler(player->GetSession()).GetNameLink() << " |cff54b5ff ist jetzt online!|r";
				sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
			}

			else if (accountid == 6){ //Thiemo
				ss << "|cff54b5ffGruender|r " << ChatHandler(player->GetSession()).GetNameLink() << " |cff54b5ff ist jetzt online!|r";
				sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
			}

			else if (accountid == 52239){ //Pihaar
				ss << "|cff54b5ffEntwickler|r " << ChatHandler(player->GetSession()).GetNameLink() << " |cff54b5ff ist jetzt online!|r";
				sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
			}

			else if (accountid == 16296){ //Rumu
				ss << "|cff54b5ffEntwickler|r " << ChatHandler(player->GetSession()).GetNameLink() << " |cff54b5ff ist jetzt online!|r";
				sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
			}

			else{
				ss << "|cff54b5ffMMOwning Teammitglied|r " << ChatHandler(player->GetSession()).GetNameLink() << " |cff54b5ff ist jetzt online!|r";
				sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
			}
		}
	}

};
void AddSC_Announce_NewPlayer()
{
	new Announce_NewPlayer;
}