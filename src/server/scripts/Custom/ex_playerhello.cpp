#include "AccountMgr.h"
#include "time.h"
#include <stdio.h>
#include "Bag.h"
#include "Mail.h"
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

class DoupleXP : public PlayerScript
{
public:
	DoupleXP() : PlayerScript("DoupleXP"){}

	void OnGiveXP(Player* player, uint32& amount, Unit* /*victim*/)
	{

			bool premium = player->GetSession()->IsPremium();
			boost::gregorian::date date(boost::gregorian::day_clock::local_day());
			if (date.day_of_week() == boost::date_time::Friday ||
				date.day_of_week() == boost::date_time::Saturday ||
				date.day_of_week() == boost::date_time::Sunday){
				if (!premium){
					
					char msg[250];
					snprintf(msg, 250, "Dir wurden %u EP gutgeschrieben.", amount);
					ChatHandler(player->GetSession()).PSendSysMessage(msg,
						player->GetName());
					amount = amount * 2;
				}

				else {
					char msg[250];
					snprintf(msg, 250, "Dir wurden %u EP gutgeschrieben.", amount);
					ChatHandler(player->GetSession()).PSendSysMessage(msg,
						player->GetName());
					amount = amount * 1.25;
				}
			}
	
			else if (date.day_of_week() == boost::date_time::Monday ||
				date.day_of_week() == boost::date_time::Tuesday ||
				date.day_of_week() == boost::date_time::Wednesday ||
				date.day_of_week() == boost::date_time::Thursday){
				amount = amount * 0.75;
			}
		

	}


};

class GMIsland : public PlayerScript
{
public:
	GMIsland() : PlayerScript("GMIsland"){}

	void OnUpdateZone(Player* player, uint32 newzone, uint32 newarea){
		
		GameEventMgr::ActiveEvents const& ae = sGameEventMgr->GetActiveEventList();
		bool active = ae.find(70) != ae.end();

		if (newzone == 876 && newarea == 876 && active == false && player->GetSession()->GetSecurity() == 0){
			player->TeleportTo(0, -9773, 2126.72, 15.40, 3.88);
		}


	}
};


class Lob : public PlayerScript
{
public:
	Lob() : PlayerScript("Lob") {}

	void OnLogin(Player * player, bool online){
		uint32 time = player->GetTotalPlayedTime();
		
		

		if (time >= 1){
			char msg[250];
			snprintf(msg, 250, "MMOwning dankt dir fuer deine Spielzeit von: %u", time);
			ChatHandler(player->GetSession()).PSendSysMessage(msg,
				player->GetName());
			
		}
	}
};

class DoublePVP : public PlayerScript
{
public:
	DoublePVP() : PlayerScript("DoublePVP"){}

	void OnPVPKill(Player* player, Player* pPlayer /*killed*/)
	{
		boost::gregorian::date date(boost::gregorian::day_clock::local_day());
		if (date.day_of_week() == boost::date_time::Friday ||
			date.day_of_week() == boost::date_time::Saturday ||
			date.day_of_week() == boost::date_time::Sunday || 
			date.day_of_week() == boost::date_time::Monday ||
			date.day_of_week() == boost::date_time::Wednesday) {
			int amount = player->GetHonorPoints();
			uint32 bonus = 25;
			amount = amount + bonus;
			char msg[250];
			snprintf(msg, 250, "Dir wurden %u Ehre gutgeschrieben.", bonus);

			ChatHandler(player->GetSession()).PSendSysMessage(msg,
				player->GetName());


			player->ModifyHonorPoints(amount, nullptr);
		}

	}


};


class DuelLog : public PlayerScript
{
public:
	DuelLog() : PlayerScript("DuelLog"){}

	std::ostringstream ss;

	void OnDuelStart(Player* player, Player* pPlayer){
		ss << "|cff54b5ffDuel wurde gestartet mit den Teilnehmern: |r " << ChatHandler(player->GetSession()).GetNameLink() << " |cff54b5ff und |r" << ChatHandler(pPlayer->GetSession()).GetNameLink();
		sWorld->SendGMText(LANG_GM_BROADCAST, ss.str().c_str());

	}
};


class Shutdown : public WorldScript
{
public:
	Shutdown() : WorldScript("Shutdown"){}

	std::ostringstream ss;
	std::ostringstream tt;
	std::ostringstream uu;


	void OnShutdownInitiate(ShutdownExitCode /*code*/, ShutdownMask /*mask*/){
		
		ss << "|cff54b5ffDer Server wird fuer Updates heruntergefahren. Wir sind bald wieder erreichbar. Weitere Informationen koennen auf der Homepage eingesehen werden.|r";
		sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());

		tt << "|cff54b5ffDer Shutdown wurde eingeleitet.|r";
		sWorld->SendGMText(LANG_GM_BROADCAST, tt.str().c_str());
		
	}

	void OnStartup(){
		uu << "Willkommen auf MMOwning World.";
		sWorld->SetMotd(uu.str().c_str());
		
	}



};





void AddSC_Announce_NewPlayer()
{
	new Announce_NewPlayer();
	new DoupleXP();
	new DoublePVP();
	new Shutdown();
	new DuelLog();
	new GMIsland();
	
}