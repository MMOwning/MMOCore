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
		else
		{
		}
	}

};
void AddSC_Announce_NewPlayer()
{
	new Announce_NewPlayer;
}