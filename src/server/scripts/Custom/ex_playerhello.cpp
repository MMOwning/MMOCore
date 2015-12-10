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
#include "Arena.h"
#include "ArenaTeam.h"
#include "ArenaScore.h"



#define MSG_COLOR_ALICEBLUE            "|cFFF0F8FF"
#define MSG_COLOR_ANTIQUEWHITE         "|cFFFAEBD7"
#define MSG_COLOR_AQUA                 "|cFF00FFFF"  
#define MSG_COLOR_AQUAMARINE           "|cFF7FFFD4"
#define MSG_COLOR_AZURE                "|cFFF0FFFF"
#define MSG_COLOR_BEIGE                "|cFFF5F5DC"  
#define MSG_COLOR_BISQUE               "|cFFFFE4C4"
#define MSG_COLOR_BLACK                "|cFF000000"
#define MSG_COLOR_BLANCHEDALMOND       "|cFFFFEBCD"
#define MSG_COLOR_BLUE                 "|cFF0000FF"
#define MSG_COLOR_BLUEVIOLET           "|cFF8A2BE2"
#define MSG_COLOR_BROWN                "|cFFA52A2A"
#define MSG_COLOR_BURLYWOOD            "|cFFDEB887"
#define MSG_COLOR_CADETBLUE            "|cFF5F9EA0"
#define MSG_COLOR_CHARTREUSE           "|cFF7FFF00"
#define MSG_COLOR_CHOCOLATE            "|cFFD2691E"
#define MSG_COLOR_CORAL                "|cFFFF7F50"
#define MSG_COLOR_CORNFLOWERBLUE       "|cFF6495ED"
#define MSG_COLOR_CORNSILK             "|cFFFFF8DC"
#define MSG_COLOR_CRIMSON              "|cFFDC143C"
#define MSG_COLOR_CYAN                 "|cFF00FFFF"
#define MSG_COLOR_DARKBLUE             "|cFF00008B"
#define MSG_COLOR_DARKCYAN             "|cFF008B8B"
#define MSG_COLOR_DARKGOLDENROD        "|cFFB8860B"
#define MSG_COLOR_DARKGRAY             "|cFFA9A9A9"
#define MSG_COLOR_DARKGREEN            "|cFF006400"
#define MSG_COLOR_DARKKHAKI            "|cFFBDB76B"
#define MSG_COLOR_DARKMAGENTA          "|cFF8B008B"
#define MSG_COLOR_DARKOLIVEGREEN       "|cFF556B2F"
#define MSG_COLOR_DARKORANGE           "|cFFFF8C00"
#define MSG_COLOR_DARKORCHID           "|cFF9932CC"
#define MSG_COLOR_DARKRED              "|cFF8B0000"
#define MSG_COLOR_DARKSALMON           "|cFFE9967A"
#define MSG_COLOR_DARKSEAGREEN         "|cFF8FBC8B"
#define MSG_COLOR_DARKSLATEBLUE        "|cFF483D8B"
#define MSG_COLOR_DARKSLATEGRAY        "|cFF2F4F4F"
#define MSG_COLOR_DARKTURQUOISE        "|cFF00CED1"
#define MSG_COLOR_DARKVIOLET           "|cFF9400D3"
#define MSG_COLOR_DEEPPINK             "|cFFFF1493"
#define MSG_COLOR_DEEPSKYBLUE          "|cFF00BFFF"
#define MSG_COLOR_DIMGRAY              "|cFF696969"
#define MSG_COLOR_DODGERBLUE           "|cFF1E90FF"
#define MSG_COLOR_FIREBRICK            "|cFFB22222"
#define MSG_COLOR_FLORALWHITE          "|cFFFFFAF0"
#define MSG_COLOR_FORESTGREEN          "|cFF228B22"
#define MSG_COLOR_FUCHSIA              "|cFFFF00FF"
#define MSG_COLOR_GAINSBORO            "|cFFDCDCDC"
#define MSG_COLOR_GHOSTWHITE           "|cFFF8F8FF"
#define MSG_COLOR_GOLD                 "|cFFFFD700"
#define MSG_COLOR_GOLDENROD            "|cFFDAA520"
#define MSG_COLOR_GRAY                 "|cFF808080"
#define MSG_COLOR_GREEN                "|cFF008000"
#define MSG_COLOR_GREENYELLOW          "|cFFADFF2F"
#define MSG_COLOR_HONEYDEW             "|cFFF0FFF0"
#define MSG_COLOR_HOTPINK              "|cFFFF69B4"
#define MSG_COLOR_INDIANRED            "|cFFCD5C5C"
#define MSG_COLOR_INDIGO               "|cFF4B0082"
#define MSG_COLOR_IVORY                "|cFFFFFFF0"
#define MSG_COLOR_KHAKI                "|cFFF0E68C"
#define MSG_COLOR_LAVENDER             "|cFFE6E6FA"
#define MSG_COLOR_LAVENDERBLUSH        "|cFFFFF0F5"
#define MSG_COLOR_LAWNGREEN            "|cFF7CFC00"
#define MSG_COLOR_LEMONCHIFFON         "|cFFFFFACD"
#define MSG_COLOR_LIGHTBLUE            "|cFFADD8E6"
#define MSG_COLOR_LIGHTCORAL           "|cFFF08080"
#define MSG_COLOR_LIGHTCYAN            "|cFFE0FFFF"
#define MSG_COLOR_LIGHTGRAY            "|cFFD3D3D3"
#define MSG_COLOR_LIGHTGREEN           "|cFF90EE90"
#define MSG_COLOR_LIGHTPINK            "|cFFFFB6C1"
#define MSG_COLOR_LIGHTRED             "|cFFFF6060"
#define MSG_COLOR_LIGHTSALMON          "|cFFFFA07A"
#define MSG_COLOR_LIGHTSEAGREEN        "|cFF20B2AA"
#define MSG_COLOR_LIGHTSKYBLUE         "|cFF87CEFA"
#define MSG_COLOR_LIGHTSLATEGRAY       "|cFF778899"
#define MSG_COLOR_LIGHTSTEELBLUE       "|cFFB0C4DE"
#define MSG_COLOR_LIGHTYELLOW          "|cFFFFFFE0"
#define MSG_COLOR_LIME                 "|cFF00FF00"
#define MSG_COLOR_LIMEGREEN            "|cFF32CD32"
#define MSG_COLOR_LINEN                "|cFFFAF0E6"
#define MSG_COLOR_MAGENTA              "|cFFFF00FF"
#define MSG_COLOR_MAROON               "|cFF800000"
#define MSG_COLOR_MEDIUMAQUAMARINE     "|cFF66CDAA"
#define MSG_COLOR_MEDIUMBLUE           "|cFF0000CD"
#define MSG_COLOR_MEDIUMORCHID         "|cFFBA55D3"
#define MSG_COLOR_MEDIUMPURPLE         "|cFF9370DB"
#define MSG_COLOR_MEDIUMSEAGREEN       "|cFF3CB371"
#define MSG_COLOR_MEDIUMSLATEBLUE      "|cFF7B68EE"
#define MSG_COLOR_MEDIUMSPRINGGREEN    "|cFF00FA9A"
#define MSG_COLOR_MEDIUMTURQUOISE      "|cFF48D1CC"
#define MSG_COLOR_MEDIUMVIOLETRED      "|cFFC71585"
#define MSG_COLOR_MIDNIGHTBLUE         "|cFF191970"
#define MSG_COLOR_MINTCREAM            "|cFFF5FFFA"
#define MSG_COLOR_MISTYROSE            "|cFFFFE4E1"
#define MSG_COLOR_MOCCASIN             "|cFFFFE4B5"
#define MSG_COLOR_NAVAJOWHITE          "|cFFFFDEAD"
#define MSG_COLOR_NAVY                 "|cFF000080"
#define MSG_COLOR_OLDLACE              "|cFFFDF5E6"
#define MSG_COLOR_OLIVE                "|cFF808000"
#define MSG_COLOR_OLIVEDRAB            "|cFF6B8E23"
#define MSG_COLOR_ORANGE               "|cFFFFA500"
#define MSG_COLOR_ORANGERED            "|cFFFF4500"
#define MSG_COLOR_ORCHID               "|cFFDA70D6"
#define MSG_COLOR_PALEGOLDENROD        "|cFFEEE8AA"
#define MSG_COLOR_PALEGREEN            "|cFF98FB98"
#define MSG_COLOR_PALETURQUOISE        "|cFFAFEEEE"
#define MSG_COLOR_PALEVIOLETRED        "|cFFDB7093"
#define MSG_COLOR_PAPAYAWHIP           "|cFFFFEFD5"
#define MSG_COLOR_PEACHPUFF            "|cFFFFDAB9"  
#define MSG_COLOR_PERU                 "|cFFCD853F"
#define MSG_COLOR_PINK                 "|cFFFFC0CB" 
#define MSG_COLOR_PLUM                 "|cFFDDA0DD"
#define MSG_COLOR_POWDERBLUE           "|cFFB0E0E6"
#define MSG_COLOR_PURPLE               "|cFF800080"
#define MSG_COLOR_RED                  "|cFFFF0000"
#define MSG_COLOR_ROSYBROWN            "|cFFBC8F8F"
#define MSG_COLOR_ROYALBLUE            "|cFF4169E1"   
#define MSG_COLOR_SADDLEBROWN          "|cFF8B4513"  
#define MSG_COLOR_SALMON               "|cFFFA8072" 
#define MSG_COLOR_SANDYBROWN           "|cFFF4A460"
#define MSG_COLOR_SEAGREEN             "|cFF2E8B57"
#define MSG_COLOR_SEASHELL             "|cFFFFF5EE"
#define MSG_COLOR_SIENNA               "|cFFA0522D"
#define MSG_COLOR_SILVER               "|cFFC0C0C0"
#define MSG_COLOR_SKYBLUE              "|cFF87CEEB"  
#define MSG_COLOR_SLATEBLUE            "|cFF6A5ACD"
#define MSG_COLOR_SLATEGRAY            "|cFF708090"
#define MSG_COLOR_SNOW                 "|cFFFFFAFA"    
#define MSG_COLOR_SPRINGGREEN          "|cFF00FF7F"    
#define MSG_COLOR_STEELBLUE            "|cFF4682B4"
#define MSG_COLOR_TAN                  "|cFFD2B48C"  
#define MSG_COLOR_TEAL                 "|cFF008080"
#define MSG_COLOR_THISTLE              "|cFFD8BFD8"
#define MSG_COLOR_TOMATO               "|cFFFF6347"    
#define MSG_COLOR_TRANSPARENT          "|c00FFFFFF"
#define MSG_COLOR_TURQUOISE            "|cFF40E0D0"
#define MSG_COLOR_VIOLET               "|cFFEE82EE"   
#define MSG_COLOR_WHEAT                "|cFFF5DEB3"
#define MSG_COLOR_WHITE                "|cFFFFFFFF"
#define MSG_COLOR_WHITESMOKE           "|cFFF5F5F5"
#define MSG_COLOR_YELLOW               "|cFFFFFF00"




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
			QueryResult result = CharacterDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 10, player->GetGUID());
		if (!result){
				
			uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(250 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				CharacterDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 10, player->GetName().c_str(), uid, 1);

			}
		}

		//20h
		if (time >= 72000 && time <= 107999){
			QueryResult result = CharacterDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 20, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(250 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				CharacterDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 20, player->GetName().c_str(), uid, 1);

			}
		}

		//30h
		if (time >= 108000 && time <= 143999){
			QueryResult result = CharacterDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 30, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(250 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				CharacterDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 30, player->GetName().c_str(), uid, 1);

			}
		}



		//40h
		if (time >= 144000 && time <= 179999){
			QueryResult result = CharacterDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 40, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(250 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				CharacterDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 40, player->GetName().c_str(), uid, 1);

			}
		}


		//50h
		if (time >= 180000 && time <= 215999){
			QueryResult result = CharacterDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 50, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(500 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				CharacterDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 50, player->GetName().c_str(), uid, 1);

			}
		}

		//60h
		if (time >= 216000 && time <= 251999){
			QueryResult result = CharacterDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 60, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(500 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				CharacterDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 60, player->GetName().c_str(), uid, 1);

			}
		}


		//70h
		if (time >= 252000 && time <= 279999){
			QueryResult result = CharacterDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 70, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(500 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				CharacterDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 70, player->GetName().c_str(), uid, 1);

			}
		}


		//80h
		if (time >= 288000 && time <= 323999){
			QueryResult result = CharacterDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 80, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(500 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				CharacterDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 80, player->GetName().c_str(), uid, 1);

			}
		}

		//90h
		if (time >= 324000 && time <= 359999){
			QueryResult result = CharacterDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 90, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(500 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				CharacterDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 90, player->GetName().c_str(), uid, 1);

			}
		}


		//100h
		if (time >= 360000 && time <= 395999){
			QueryResult result = CharacterDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 100, player->GetGUID());
			if (!result){
				uint32 uid = player->GetGUID();
				
				Item* item = Item::CreateItem(46802,1);
				player->GetSession()->SendNotification("Herzlichen Glueckwunsch zu 100h Spielzeit auf MMOwning.");
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				item->SaveToDB(trans);
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddItem(item)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				CharacterDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 100, player->GetName().c_str(), uid, 1);

			}
		}


		//110h
		if (time >= 396000 && time <= 431999){
			QueryResult result = CharacterDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 110, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(500 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				CharacterDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 110, player->GetName().c_str(), uid, 1);

			}
		}

		//120h
		if (time >= 432000 && time <= 467999){
			QueryResult result = CharacterDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 120, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(500 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				CharacterDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 120, player->GetName().c_str(), uid, 1);

			}
		}


		//130h
		if (time >= 468000 && time <= 503999){
			QueryResult result = CharacterDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 130, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(500 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				CharacterDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 130, player->GetName().c_str(), uid, 1);

			}
		}


		//140h
		if (time >= 504000 && time <= 539999){
			QueryResult result = CharacterDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 140, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(500 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				CharacterDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 140, player->GetName().c_str(), uid, 1);

			}
		}


		//150h
		if (time >= 540000 && time <= 575999){
			QueryResult result = CharacterDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 150, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(1000 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				CharacterDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 150, player->GetName().c_str(), uid, 1);

			}
		}


		//160h
		if (time >= 576000 && time <= 611999){
			QueryResult result = CharacterDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 160, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(1000 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				CharacterDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 160, player->GetName().c_str(), uid, 1);

			}
		}


		//170h
		if (time >= 612000 && time <= 647999){
			QueryResult result = CharacterDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 170, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(1000 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				CharacterDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 170, player->GetName().c_str(), uid, 1);

			}
		}

		//180h
		if (time >= 648000 && time <= 683999){
			QueryResult result = CharacterDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 180, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(1000 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				CharacterDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 180, player->GetName().c_str(), uid, 1);

			}
		}


		//190h
		if (time >= 684000 && time <= 719999){
			QueryResult result = CharacterDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 190, player->GetGUID());
			if (!result){

				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddMoney(1000 * GOLD)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				CharacterDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 190, player->GetName().c_str(), uid, 1);

			}
		}


		//200h
		if (time >= 720000){
			QueryResult result = CharacterDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 200, player->GetGUID());
			if (!result){

				Item* item = Item::CreateItem(37719, 1);
				uint32 uid = player->GetGUID();
				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				item->SaveToDB(trans);
				MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddItem(item)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				CharacterDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 200, player->GetName().c_str(), uid, 1);

			}
		}


		QueryResult result = CharacterDatabase.PQuery("SELECT `id`, `zeit`, `spieler`,`uid` `benutzt` FROM `lob` WHERE `zeit` = '%u' AND `uid`= '%u'", 100, player->GetGUID());
		 if (time >= 720000 && !result){
			uint32 uid = player->GetGUID();

			Item* item = Item::CreateItem(46802, 1);
			player->GetSession()->SendNotification("Deine nachtraegliche Belohnung ist im Postfach.");
			SQLTransaction trans = CharacterDatabase.BeginTransaction();
			item->SaveToDB(trans);
			MailDraft("Ein Geschenk", "Das MMOwning-Team bedankt sich fuer deine Unterstuetzung mit einer kleinen Geste. Viel Spass weiterhin auf MMOwning World.").AddItem(item)
				.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
			CharacterDatabase.CommitTransaction(trans);

			CharacterDatabase.PExecute("INSERT INTO lob (zeit,spieler,uid,benutzt) Values ('%u','%s','%u','%u')", 100, player->GetName().c_str(), uid, 1);
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


class fbevent : public PlayerScript
{
public:
	fbevent() : PlayerScript("fbevent") {}

	void OnCreate(Player* player) { 

		GameEventMgr::ActiveEvents const& ae = sGameEventMgr->GetActiveEventList();
		bool active = ae.find(78) != ae.end();
		
		QueryResult anzahl;
		anzahl = CharacterDatabase.PQuery("SELECT count(accountid) FROM fb_event WHERE accountid = '%u'", player->GetSession()->GetAccountId());
		Field *felder = anzahl->Fetch();
		uint32 accountanzahl = felder[0].GetUInt32();
		time_t sek;
		time(&sek);
		uint32 zeit = time(&sek);


		if (active == true && accountanzahl == 0){
			CharacterDatabase.PExecute("UPDATE `characters` set `level` = 80 where guid = '%u'", player->GetGUID());
			CharacterDatabase.PExecute("UPDATE `characters` set `position_x` = -792.84 where guid = '%u'", player->GetGUID());
			CharacterDatabase.PExecute("UPDATE `characters` set `position_y` = -1607.55 where guid = '%u'", player->GetGUID());
			CharacterDatabase.PExecute("UPDATE `characters` set `position_z` = 142.30 where guid = '%u'", player->GetGUID());
			CharacterDatabase.PExecute("UPDATE `characters` set `map` = 0 where guid = '%u'", player->GetGUID());
			
			player->SetFullHealth();
			QueryResult accountname = LoginDatabase.PQuery("SELECT username FROM account where id = %u", player->GetSession()->GetAccountId());
			std::string accname = (*accountname)[0].GetString();

			CharacterDatabase.PExecute("INSERT INTO fb_event (name,guid,accountname,accountid,date) Values ('%s','%u','%s','%u','%u')", player->GetSession()->GetPlayerName(),player->GetGUID() , accname, player->GetSession()->GetAccountId(),zeit);
		}
		
		else{
			return;
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

		Player* player;
		
		player->GetSession()->GetPlayer();

		tt << "|cff54b5ffDer Shutdown wurde eingeleitet von: |r " << ChatHandler(player->GetSession()).GetNameLink();
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
		sWorld->setBoolConfig(CONFIG_ALLOW_TWO_SIDE_TRADE, true);
		sWorld->setBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_AUCTION,true);
		
	}



};



class Chatlog : public PlayerScript
{

public:
	Chatlog() : PlayerScript("Chatlog") { }


	
	void chatlog(Player* player, std::string nachricht) {
		
		std::string lower = nachricht;
		std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

		const uint32 cheksSize = 31;
		std::string checks[cheksSize];
		checks[0] = "at";
		checks[1] = "frostmourne";
		checks[2] = "pws";
		checks[3] = "bigfamily";
		checks[4] = "castle-wow";
		checks[5] = "mwow";
		checks[6] = "maxwow";
		checks[7] = "hellscream wow";
		checks[8] = "soulwow";
		checks[9] = "adex";
		checks[10] = "eternyum";
		checks[11] = "eternal";
		checks[12] = "back2basics";
		checks[13] = "laenalith";
		checks[14] = "monster wow";
		checks[15] = "rising-gods";
		checks[16] = "privat-woW-server";
		checks[17] = "ice-wow";
		checks[18] = "land of elves";
		checks[19] = "solacewow";
		checks[20] = "world of paranoid";
		checks[21] = "buzzteria";
		checks[22] = "genesis";
		checks[23] = "fantasy";
		checks[24] = "heroes";
		checks[25] = "stormblade";
		checks[26] = "fm";
		checks[27] = "b2b";
		checks[28] = "molten";
		checks[29] = "warmane";
		checks[30] = "wow";
		

		for (uint32 i = 0; i < cheksSize; ++i)
			if (lower.find(checks[i]) != std::string::npos)
			{			
				
				if (checks[i] == "Nicht an der Tastatur"){
					return;
				}

				time_t sek;
				time(&sek);
				uint32 zeit = time(&sek);
				
				CharacterDatabase.PExecute("INSERT INTO fremdwerbung "
					"(nachricht,player, guid,accid, datum)"
					"VALUES ('%s', '%s','%u','%u','%u')",
					nachricht, player->GetSession()->GetPlayerName(), player->GetGUID(), player->GetSession()->GetAccountId(), zeit);

				std::ostringstream uu;
				std::ostringstream tt;
				


				tt << "|cff54b5ffFremdwerbung wurde erkannt von: |r " << ChatHandler(player->GetSession()).GetNameLink();
				uu <<  nachricht;
				
				sWorld->SendGMText(LANG_GM_BROADCAST, tt.str().c_str());
				sWorld->SendGMText(LANG_GM_BROADCAST, uu.str().c_str());		
				
			}

	}

	void OnChat(Player* player, uint32 /*type*/, uint32 /*lang*/, std::string& msg) {
		chatlog(player->GetSession()->GetPlayer(), msg);		
		

	}


	void OnChat(Player* player, uint32 /*type*/, uint32 /*lang*/, std::string& msg, Player* /*receiver*/) { 
		chatlog(player->GetSession()->GetPlayer(), msg);
	
	}


	void OnChat(Player* player, uint32 /*type*/, uint32 /*lang*/, std::string& msg, Group* /*group*/) { 	
		chatlog(player->GetSession()->GetPlayer(), msg);
	}


	void OnChat(Player* player, uint32 /*type*/, uint32 /*lang*/, std::string& msg, Guild* /*guild*/) { 	
		chatlog(player->GetSession()->GetPlayer(), msg);
	}


	void OnChat(Player* player, uint32 /*type*/, uint32 /*lang*/, std::string& msg, Channel* /*channel*/) { 
		chatlog(player->GetSession()->GetPlayer(), msg);
	}
};






void AddSC_Announce_NewPlayer()
{
	new fbevent();
	new Announce_NewPlayer();
	new DoupleXP();
	new Shutdown();
	new DuelLog();
	new GMIsland();
	new Chatlog();
}