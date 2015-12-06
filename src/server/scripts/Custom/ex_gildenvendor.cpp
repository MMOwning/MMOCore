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




class gildenvendor : public CreatureScript
{
public: gildenvendor() : CreatureScript("gildenvendor"){ }


		void Gildenhauszuordnung(uint32 gildenidneu, uint32 hausid, uint32 groesse, uint32 kosten, Player* player){
			
			QueryResult result;
			result = CharacterDatabase.PQuery("SELECT guildid FROM `guildhouses` WHERE `id` = %u", hausid);
			Field *fields = result->Fetch();
			uint32 gildenidalt = fields[0].GetUInt32();


			QueryResult gildenanzahl;
			gildenanzahl = CharacterDatabase.PQuery("SELECT count(guid) FROM guild_member WHERE guildid = %u", gildenidneu);
			Field *felder = gildenanzahl->Fetch();
			uint32 memberanzahlsql = felder[0].GetUInt32();

			
			QueryResult ergebnis;
			ergebnis = CharacterDatabase.PQuery("Select count(guildid) from `guildhouses` where `guildid` = '%u'", gildenidneu);
			uint32 gildeplayer = player->GetGuildId();

			uint32 memberanzahllimit = groesse;

			Field *feld = ergebnis->Fetch();
			uint32 anzahl = feld[0].GetUInt32();

		
				if (gildenidalt == 0 && anzahl == 0 && gildeplayer != 0 && groesse >= memberanzahlsql){

					if (player->HasItemCount(200000, kosten)){
						player->DestroyItemCount(200000, kosten, true, false);;
						CharacterDatabase.PExecute("UPDATE guildhouses SET `guildid` = '%u' WHERE `id` = '%u'", gildenidneu, hausid);
						player->GetSession()->SendNotification("Du hast das Gildenhaus gekauft.");
						return;
					}
					else{
						player->GetSession()->SendNotification("Du hast nicht genug Gildenhaustoken um dir dieses Gildenhaus zu kaufen.");
						return;
					}
				}

				else {
					player->GetSession()->SendNotification("Das Gildenhaus ist belegt, deine Gilde zu klein oder deine Gilde besitzt schon ein Gildenhaus");
					return;
				}
			

		}


		bool OnGossipHello(Player *player, Creature* _creature)
		{
			uint32 test = player->GetGuildId();
			if (test != 0){
				QueryResult result;
				result = CharacterDatabase.PQuery("Select leaderguid from `guild` where `guildid` = '%u'", player->GetGuildId());

				Field *fields = result->Fetch();
				uint32 leaderid = fields[0].GetUInt32();

				uint32 guid = player->GetGUID();

				if (guid == leaderid){
					player->ADD_GOSSIP_ITEM(7, "Gildenhaeuser kaufen", GOSSIP_SENDER_MAIN, 0);
					player->ADD_GOSSIP_ITEM(7, "Gildenhaeuser verkaufen", GOSSIP_SENDER_MAIN, 1);
					player->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());

					return true;
				}

			}

			else{
				player->GetSession()->SendNotification("Du bist kein nicht der Leiter deiner Gilde.");
				return true;
			}
			
			return true;


		}

		std::ostringstream ss;

		bool OnGossipSelect(Player * player, Creature * creature, uint32 /*uiSender*/, uint32 uiAction)
		{
			switch (uiAction)
			{
			case 0:
			{

				player->PlayerTalkClass->ClearMenus();
				player->ADD_GOSSIP_ITEM(7, "Tauren Village at Veiled Sea", GOSSIP_SENDER_MAIN, 2);
				player->ADD_GOSSIP_ITEM(7, "Fishing outside an Nortshire Abbey", GOSSIP_SENDER_MAIN, 3);
				player->ADD_GOSSIP_ITEM(7, "Troll Village in mountains", GOSSIP_SENDER_MAIN, 4);
				player->ADD_GOSSIP_ITEM(7, "Dwarven village outside Ironforge", GOSSIP_SENDER_MAIN, 5);
				player->ADD_GOSSIP_ITEM(7, "Taruen Camp (Mulgore)", GOSSIP_SENDER_MAIN, 6);
				player->PlayerTalkClass->SendGossipMenu(907, creature->GetGUID());
				return true;

			}break;


			case 1:
			{
				uint32 platzhalter = 0;
				uint32 gilde = player->GetGuildId();

				QueryResult result;
				result = CharacterDatabase.PQuery("SELECT id FROM `guildhouses` WHERE `guildid` = '%u'", gilde);

				if (result){
					Field *fields = result->Fetch();
					uint32 gildenaktuell = fields[0].GetUInt32();

					if (gilde == 0){
						player->GetSession()->SendNotification("Du bist in keiner Gilde");
						return false;
					}



					QueryResult ergebnis;
					ergebnis = CharacterDatabase.PQuery("Select leaderguid from `guild` where `guildid` = '%u'", player->GetGuildId());

					Field *feld = ergebnis->Fetch();
					uint32 leaderid = feld[0].GetUInt32();

					uint32 guid = player->GetGUID();

					if (guid == leaderid){
						CharacterDatabase.PExecute("UPDATE guildhouses SET guildid = '%u' WHERE id = '%u'", platzhalter, gildenaktuell);
						player->GetSession()->SendNotification("Das Gildenhaus wurde verkauft.");
						return true;
					}
				}

				else {
					player->GetSession()->SendNotification("Deine Gilde besitzt kein Gildenhaus");
				}		

			}break;


			//Tauren Village at Veiled Sea
			case 2:
			{
				uint32 gildenid = player->GetGuildId();
				Gildenhauszuordnung(gildenid, 2, 10 , 30,player->GetSession()->GetPlayer());	
				player->PlayerTalkClass->SendCloseGossip();
			}break;


			//Fishing outside an Nortshire Abbey
			case 3:
			{
				uint32 gildenid = player->GetGuildId();
				// 1: gildenID , 2: GildenhausID ,	3: Groesse , 4:Kosten  5: Playerarray
				Gildenhauszuordnung(gildenid, 3, 10 ,30, player->GetSession()->GetPlayer());
				player->PlayerTalkClass->SendCloseGossip();
			}break;

			//Trollvillage in mountains
			case 4:
			{
				uint32 gildenid = player->GetGuildId();
				// 1: gildenID , 2: GildenhausID ,	3: Kosten ,   4: Playerarray
				Gildenhauszuordnung(gildenid, 4, 10 ,30, player->GetSession()->GetPlayer());
				player->PlayerTalkClass->SendCloseGossip();
			}break;

			//Dwarven Village
			case 5:
			{
				uint32 gildenid = player->GetGuildId();
				// 1: gildenID , 2: GildenhausID ,	3: Kosten ,   4: Playerarray
				Gildenhauszuordnung(gildenid,5, 10 , 30, player->GetSession()->GetPlayer());
				player->PlayerTalkClass->SendCloseGossip();
			}break;


			case 6:
			{

			}

			}

		}

};



void AddSC_gildenvendor()
{
	new gildenvendor();
}