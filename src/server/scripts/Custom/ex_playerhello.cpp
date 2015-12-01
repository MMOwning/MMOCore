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
			ss << "|cff54b5ffHerzlich willkommen auf MMOwning: |r " << ChatHandler(player->GetSession()).GetNameLink();
			sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
			sWorld->SendGMText(LANG_GM_BROADCAST,"Ein neuer Spieler ist auf MMO online gegangen.");
			return;
		}



		uint32 time = player->GetTotalPlayedTime();
		
		
		//10h
		if (time >= 1 && time <= 71999){
		
		QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`, `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `spieler`= '%s'", 10, player->GetName());
		if (!result){
				
				
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(100 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,benutzt) Values ('%u','%s','%u')", 10, player->GetName().c_str(), 1);

			}
		}

		//20h
		if (time >= 72000 && time <= 107999){
			QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`, `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `spieler`= '%s'", 20, player->GetName());
			if (!result){

				
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(200 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,benutzt) Values ('%u','%s','%u')", 20, player->GetName().c_str(), 1);

			}
			
		}

		//30h
		if (time >= 108000 && time <= 143999){
			QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`, `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `spieler`= '%s'", 30, player->GetName());
			if (!result){


				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(500 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,benutzt) Values ('%u','%s','%u')", 30, player->GetName().c_str(), 1);

			}
		}



		//40h
		if (time >= 144000 && time <= 179999){
			QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`, `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `spieler`= '%s'", 40, player->GetName());
			if (!result){


				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(1000 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,benutzt) Values ('%u','%s','%u')", 40, player->GetName().c_str(), 1);

			}
		}


		//50h
		if (time >= 180000 && time <= 215999){
			QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`, `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `spieler`= '%s'", 50, player->GetName());
			if (!result){

				Item* item = Item::CreateItem(23713,1);
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				item->SaveToDB(trans);
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddItem(item)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,benutzt) Values ('%u','%s','%u')", 50, player->GetName().c_str(), 1);

			}
		}

		//60h
		if (time >= 216000 && time <= 251999){
			QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`, `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `spieler`= '%s'", 60, player->GetName());
			if (!result){


				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(2000 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,benutzt) Values ('%u','%s','%u')", 60, player->GetName().c_str(), 1);

			}
		}

		/*else if (player->IsGameMaster() && player->GetSession()->GetSecurity() == 2){
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

			else if (accountid == 53103){ //Rumu
				ss << "|cff54b5ffEntwickler|r " << ChatHandler(player->GetSession()).GetNameLink() << " |cff54b5ff ist jetzt online!|r";
				sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
			}

			else{
				ss << "|cff54b5ffMMOwning Teammitglied|r " << ChatHandler(player->GetSession()).GetNameLink() << " |cff54b5ff ist jetzt online!|r";
				sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
			}
		}*/
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
			if (player->getLevel() < 80){
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
		
		if (active == true){
			return;
		}

		else{
			if (newzone == 876 && newarea == 876 && active == false && player->GetSession()->GetSecurity() == 0){
				player->TeleportTo(0, -9773, 2126.72, 15.40, 3.88);
			}
		}


	}
};


class Belohnung : public PlayerScript
{
public:
	Belohnung() : PlayerScript("Belohnung") {}

	void OnLogin(Player * player, bool online){
		uint32 time = player->GetTotalPlayedTime();	

		if (time >= 1 && time <= 1199){
			QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`, `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `spieler`= '%s'", 600, player->GetName());
			
			if (!result){
				

				char msg[250];
				snprintf(msg, 250, "MMOwning dankt dir fuer deine Spielzeit von ueber 600 Minuten.");
				ChatHandler(player->GetSession()).PSendSysMessage(msg,
					player->GetName());

				player->GetSession()->SendNotification("Dein Code wurde akzeptiert!");
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(100 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,benutzt) Values ('%u','%s','%u' ", 600, player->GetName().c_str(), 1);

			}

			else {
				player->GetSession()->SendNotification("Belohnung wurde schon durchgefuehrt!");
			}
			
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
		
		ss << "|cff54b5ffDer Server wird bald fuer Updates heruntergefahren. Weitere Informationen koennen auf der Homepage eingesehen werden.|r";
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
	new Shutdown();
	new DuelLog();
	new GMIsland();
}