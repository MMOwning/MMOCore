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
#include "Guild.h"




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
		
#pragma region

		//10h
		if (time >= 36000 && time <= 71999){
		QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 10, player->GetGUID());
		if (!result){
				
			uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(250 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 10, player->GetName().c_str(),uid, 1);

			}
		}

		//20h
		if (time >= 72000 && time <= 107999){
			QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 20, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(250 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 20, player->GetName().c_str(), uid, 1);

			}
		}

		//30h
		if (time >= 108000 && time <= 143999){
			QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 30, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(250 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 30, player->GetName().c_str(), uid, 1);

			}
		}



		//40h
		if (time >= 144000 && time <= 179999){
			QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 40, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(250 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 40, player->GetName().c_str(), uid, 1);

			}
		}


		//50h
		if (time >= 180000 && time <= 215999){
			QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 50, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(500 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 50, player->GetName().c_str(), uid, 1);

			}
		}

		//60h
		if (time >= 216000 && time <= 251999){
			QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 60, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(500 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 60, player->GetName().c_str(), uid, 1);

			}
		}


		//70h
		if (time >= 252000 && time <= 279999){
			QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 70, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(500 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 70, player->GetName().c_str(), uid, 1);

			}
		}


		//80h
		if (time >= 288000 && time <= 323999){
			QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 80, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(500 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 80, player->GetName().c_str(), uid, 1);

			}
		}

		//90h
		if (time >= 324000 && time <= 359999){
			QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 90, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(500 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 90, player->GetName().c_str(), uid, 1);

			}
		}


		//100h
		if (time >= 360000 && time <= 395999){
			QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 100, player->GetGUID());
			if (!result){
				uint32 uid = player->GetGUID();
				
				Item* item = Item::CreateItem(46802,1);
				player->GetSession()->SendNotification("Herzlichen Glueckwunsch zu 100h Spielzeit auf MMOwning.");
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				item->SaveToDB(trans);
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddItem(item)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 100, player->GetName().c_str(), uid, 1);

			}
		}


		//110h
		if (time >= 396000 && time <= 431999){
			QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 110, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(500 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 110, player->GetName().c_str(), uid, 1);

			}
		}

		//120h
		if (time >= 432000 && time <= 467999){
			QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 120, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(500 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 120, player->GetName().c_str(), uid, 1);

			}
		}


		//130h
		if (time >= 468000 && time <= 503999){
			QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 130, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(500 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 130, player->GetName().c_str(), uid, 1);

			}
		}


		//140h
		if (time >= 504000 && time <= 539999){
			QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 140, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(500 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 140, player->GetName().c_str(), uid, 1);

			}
		}


		//150h
		if (time >= 540000 && time <= 575999){
			QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 150, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(1000 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 150, player->GetName().c_str(), uid, 1);

			}
		}


		//160h
		if (time >= 576000 && time <= 611999){
			QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 160, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(1000 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 160, player->GetName().c_str(), uid, 1);

			}
		}


		//170h
		if (time >= 612000 && time <= 647999){
			QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 170, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(1000 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 170, player->GetName().c_str(), uid, 1);

			}
		}

		//180h
		if (time >= 648000 && time <= 683999){
			QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 180, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(1000 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 180, player->GetName().c_str(), uid, 1);

			}
		}


		//190h
		if (time >= 684000 && time <= 719999){
			QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 190, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(1000 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 190, player->GetName().c_str(), uid, 1);

			}
		}


		//200h
		if (time >= 720000){
			QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 200, player->GetGUID());
			if (!result){

				Item* item = Item::CreateItem(37719, 1);
				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				item->SaveToDB(trans);
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddItem(item)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 200, player->GetName().c_str(), uid, 1);

			}
		}


		QueryResult result = WorldDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 100, player->GetGUID());
		 if (time >= 720000 && !result){
			uint32 uid = player->GetGUID();

			Item* item = Item::CreateItem(46802, 1);
			player->GetSession()->SendNotification("Deine nachtraegliche Belohnung ist im Postfach.");
			SQLTransaction trans = CharacterDatabase.BeginTransaction();
			item->SaveToDB(trans);
			MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddItem(item)
				.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
			CharacterDatabase.CommitTransaction(trans);

			WorldDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 100, player->GetName().c_str(), uid, 1);
		}




#pragma endregion

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


class Gold : public PlayerScript
{
public:
	Gold() : PlayerScript("Gold") {}

	void OnMoneyChanged(Player* player, int32& amount) { 
		Guild* guild;
		
		
			
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
		Rates* rate;
		sWorld->setRate(RATE_DROP_ITEM_LEGENDARY,1);
		sWorld->setRate(RATE_REPAIRCOST, 3);
		sWorld->setRate(RATE_DROP_ITEM_EPIC, 1);
		sWorld->setRate(RATE_DROP_ITEM_UNCOMMON, 3);
	 
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