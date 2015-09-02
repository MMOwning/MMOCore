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

class npc_first_char : public CreatureScript
{
		public: npc_first_char() : CreatureScript("npc_first_char"){ }

				bool OnGossipHello(Player *pPlayer, Creature* _creature)
				{
					pPlayer->ADD_GOSSIP_ITEM(7, "Informationen und Hilfe", GOSSIP_SENDER_MAIN, 0);
					pPlayer->ADD_GOSSIP_ITEM(7, "Firstausstattung beantragen", GOSSIP_SENDER_MAIN, 1);
					pPlayer->ADD_GOSSIP_ITEM(7, "Gildenaufwertung 10er", GOSSIP_SENDER_MAIN, 2);
					pPlayer->ADD_GOSSIP_ITEM(7, "Gildenaufwertung 25er", GOSSIP_SENDER_MAIN, 3);
					
					if (pPlayer->IsGameMaster()){
						pPlayer->ADD_GOSSIP_ITEM(7, "Aufwertungen einsehen", GOSSIP_SENDER_MAIN, 4);
					}
					
					pPlayer->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());
					return true;


				}

				bool OnGossipSelect(Player * pPlayer, Creature * pCreature, uint32 /*uiSender*/, uint32 uiAction)
				{
					switch (uiAction)
					{
					case 1:
						{

							uint32 guid = pPlayer->GetGUID();
							
							QueryResult accountres = CharacterDatabase.PQuery("SELECT account FROM characters WHERE guid = %u", guid);
							uint32 accountresint = (*accountres)[0].GetUInt32();
							QueryResult charresult = CharacterDatabase.PQuery("Select count(guid) From characters where account = '%u'", accountresint);
							uint32 charresultint = (*charresult)[0].GetUInt32();

							QueryResult onechar = CharacterDatabase.PQuery("Select count(guid) From first_char where guid = '%u'", guid);
							uint32 onecharint = (*onechar)[0].GetUInt32();
						
							QueryResult ipadr = LoginDatabase.PQuery("SELECT last_ip FROM account where id = %u", accountresint);
							std::string ipadrint = (*ipadr)[0].GetString();
							QueryResult ipadrcount = LoginDatabase.PQuery("SELECT count(last_ip) FROM account WHERE last_ip = '%s'", ipadrint);
							uint32 ipadrcountint = (*ipadrcount)[0].GetUInt32();
							

							/*Username*/
							QueryResult guidname = CharacterDatabase.PQuery("SELECT name FROM characters where guid = %u", guid);
							std::string charname = (*guidname)[0].GetString();

							/*Accname*/
							QueryResult accountname = LoginDatabase.PQuery("SELECT username FROM account where id = %u", accountresint);
							std::string accname = (*accountname)[0].GetString();

							/*Acccountanzahl zählen*/
							QueryResult accountanz = CharacterDatabase.PQuery("SELECT account FROM characters WHERE guid = %u", guid);
							uint32 accountanzint = (*accountanz)[0].GetUInt32();
							QueryResult accountgesanz = CharacterDatabase.PQuery("SELECT count(account) FROM first_char WHERE account = '%u'", accountanzint);
							uint32 accountanzgesint = (*accountgesanz)[0].GetUInt32();

						

							if (charresultint == 1 && ipadrcountint == 1 && onecharint != 1 && accountanzgesint <= 1){
								
								 time_t sek;
								 time(&sek);
								 uint32 zeit = time(&sek);
								 pPlayer->GetGUID();
								 ChatHandler(pPlayer->GetSession()).PSendSysMessage("[Aufwertungs System] Deine Aufwertung wurde ausgefuehrt. Viel Spass wuenscht Exitare sowie das MMOwning-Team.",
									 pPlayer->GetName());
								pPlayer->PlayerTalkClass->SendCloseGossip();
								pPlayer->SetLevel(80);
								pPlayer->TeleportTo(0, -795.73, 1495.50, 104.54, 1.05, 0);
								pPlayer->AddItem(20400, 4);
								pPlayer->SetMoney(50000000);
							
								
								pPlayer->PlayerTalkClass->SendCloseGossip();	

								CharacterDatabase.PExecute("REPLACE INTO first_char "
									"(guid,Charname, account, Accname, time, guildid,ip) "
									"VALUES ('%u', '%s', %u, '%s', %u, %u, '%s')",
									guid, charname, accountresint, accname, zeit, 0 , ipadrint);
							
				     			return true;
							}
							 							
							 else {
								 pPlayer->GetGUID();
								 ChatHandler(pPlayer->GetSession()).PSendSysMessage("[Aufwertungs System]\nDu hast bereits einen anderen Charakter auf diesem Realm oder versuchst mit zu vielen Accounts eine Erstaustattung zu erlangen.\nDiese wird daher abgelehnt.\nMfG Exitare und das MMOwning-Team.",
								 pPlayer->GetName());
								 pPlayer->PlayerTalkClass->SendCloseGossip();
								 return true;
							}
							 
							

						}break;

					case 0:
						{
							uint32 guid = pPlayer->GetGUID();
											
							pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
							pPlayer->PlayerTalkClass->ClearMenus();
							pPlayer->ADD_GOSSIP_ITEM(7, "Einzelausstattung. Wer/Was/Wie?", GOSSIP_SENDER_MAIN, 5);
							pPlayer->ADD_GOSSIP_ITEM(7, "Gildentransfer Wer/Was/Wie?", GOSSIP_SENDER_MAIN, 6); 
							pPlayer->ADD_GOSSIP_ITEM(7, "Meine Aufwertung wurde abgelehnt! Was tun?", GOSSIP_SENDER_MAIN, 7);
							pPlayer->ADD_GOSSIP_ITEM(7, "Ich möchte einen anderen Charakter ausstatten lassen.", GOSSIP_SENDER_MAIN, 8);
							pPlayer->ADD_GOSSIP_ITEM(7, "Ein Spieler mit der selben IP möchte eine Charakteraufwertung! Wie geht das?", GOSSIP_SENDER_MAIN, 9);
							pPlayer->PlayerTalkClass->SendGossipMenu(907, pCreature->GetGUID());
							return true;
						}break;

					
					case 5:
					{
						pPlayer->GetGUID();
						ChatHandler(pPlayer->GetSession()).PSendSysMessage("[Aufwertungs System]\nWer? \nJeder der noch keinen Character auf seinem Account hat. Es muss zwingend der erste Charakter ausgestattet werden. Existiert ein Charakter auf dem Account muss dieser geloescht werden.\nWas?\nEs gibt 5k Gold, 4 Taschen, sowie eine Grundausstattung auf Itemlevel 219.\nWie? \nEinfach auf ""Charakteraufwertung beantragen"" klicken und alles wird in die Wege geleitet.",
							pPlayer->GetName());
						pPlayer->PlayerTalkClass->SendCloseGossip();
						return true;
					}

					case 6:
					{
						pPlayer->GetGUID();
						ChatHandler(pPlayer->GetSession()).PSendSysMessage("[Aufwertungs System]\nEine Gildenaufwertung funktioniert praktisch wie eine Einzelaufwertung.Zusätzlich bekommt ihr jedoch den Reitskill bis zu Schnellem Reiten hochgesetzt. Ihr muesst jedoch in einer Gilde sein und duerft keine Einzelaufwertung beantragt haben. Solltet ihr das getan haben, einfach den Charakter loeschen und neu machen. Ihr muesst die Gilde schon gegruendet haben und Euch auch schon in dieser befinden. Waehlt dann die entsprechende Groesse aus um die Aufwertung zu bekommen.",
							pPlayer->GetName());
						pPlayer->PlayerTalkClass->SendCloseGossip();
						return true;
					}

					case 7:
					{
						pPlayer->GetGUID();
						ChatHandler(pPlayer->GetSession()).PSendSysMessage("[Aufwertungs System]\nErst einmal keine Panik. Sollte deine Aufwertung abgelehnt werden, ist entweder ueber deinen Account oder deine IP schon eine Aufwertung erfolgt, der Charakter hat schon eine Aufwertung bekommen oder du hast mehr als 1 Charakter auf diesem Account.\nBeachte bitte: Nur der erste Charakter auf MMOwning darf ausgestattet werden. Solltest du dennoch Probleme haben, gehe bitte ins TS und frage nach Exitare.",
							pPlayer->GetName());
						pPlayer->PlayerTalkClass->SendCloseGossip();
						return true;
					}

					case 8:
					{
						pPlayer->GetGUID();
						ChatHandler(pPlayer->GetSession()).PSendSysMessage("[Aufwertungs System]\nDas ist kein Problem. Loesche einfach diesen Charakter und erstelle dir einen neuen. Bedenke aber das du nur 2 Ausstattungen beantragen kannst. Solltest du deinen Charakter also loeschen, hast du nur noch einmal die Moeglichkeit eine Erstaustattung zu beantragen.",
							pPlayer->GetName());
						pPlayer->PlayerTalkClass->SendCloseGossip();
						return true;
					}

					case 9:
					{
						pPlayer->GetGUID();
						ChatHandler(pPlayer->GetSession()).PSendSysMessage("[Aufwertungs System]\nUm eine Austattung ueber die gleiche IP vornehmen zu lassen muesst ihr euch BEIDE ins TS begeben. Fragt dort nach einem GM, dieser wird ueberpruefen ob alles für eine Ausstattung erfuellt ist und diese dann durchfuehren.",
							pPlayer->GetName());
						pPlayer->PlayerTalkClass->SendCloseGossip();
						return true;
					}

					case 2:
						{
							uint32 guid = pPlayer->GetGUID();
							
							bool gild = pPlayer->GetGuild();

							if (gild)
							{
								QueryResult accountres = CharacterDatabase.PQuery("SELECT account FROM characters WHERE guid = %u", guid);
								uint32 accountresint = (*accountres)[0].GetUInt32();
								QueryResult charresult = CharacterDatabase.PQuery("Select count(guid) From characters where account = '%u'", accountresint);
								uint32 charresultint = (*charresult)[0].GetUInt32();
						
								/*Gildenselect*/
								QueryResult guildid = CharacterDatabase.PQuery("SELECT guildid FROM guild_member WHERE guid= %u", guid);
								uint32 guildidint = (*accountres)[0].GetUInt32();

								/*Gildenmemberanzahl*/
								QueryResult guildmember = CharacterDatabase.PQuery("SELECT count(guid) FROM guild_member WHERE guildid = %u", guildidint);
								uint32 guildmemberint = (*guildmember)[0].GetUInt32();

								/*Gildenerstelldatum*/
								QueryResult guildcreate = CharacterDatabase.PQuery("SELECT createdate FROM guild WHERE guildid = %u", guildidint);
								uint32 guildcreateint = (*guildcreate)[0].GetUInt32();

								QueryResult onechar = CharacterDatabase.PQuery("Select count(guid) From first_char where guid = '%u'", guid);
								uint32 onecharint = (*onechar)[0].GetUInt32();

								/*Username*/
								QueryResult guidname = CharacterDatabase.PQuery("SELECT name FROM characters where guid = %u", guid);
								std::string charname = (*guidname)[0].GetString();

								/*Accname*/
								QueryResult accountname = LoginDatabase.PQuery("SELECT username FROM account where id = %u", accountresint);
								std::string accname = (*accountname)[0].GetString();

								QueryResult ipadr = LoginDatabase.PQuery("SELECT last_ip FROM account where id = %u", accountresint);
								std::string ipadrint = (*ipadr)[0].GetString();
								/*IPAdresse auslesen*/
								QueryResult ipadrcount = LoginDatabase.PQuery("SELECT count(last_ip) FROM account WHERE last_ip = '%s'", ipadrint);
								uint32 ipadrcountint = (*ipadrcount)[0].GetUInt32();

								time_t seconds;
								seconds = time(NULL);
								uint32 zeit = seconds;
								uint32 zeitraum = zeit - guildcreateint;
																
								
								/*Acccountanzahl zählen*/
								QueryResult accountanz = CharacterDatabase.PQuery("SELECT account FROM characters WHERE guid = %u", guid);
								uint32 accountanzint = (*accountanz)[0].GetUInt32();
								QueryResult accountgesanz = CharacterDatabase.PQuery("SELECT count(account) FROM first_char WHERE account = '%u'", accountanzint);
								uint32 accountanzgesint = (*accountgesanz)[0].GetUInt32();

								if (guildmemberint >= 10 && guildmemberint < 25 && zeitraum <1209600 && charresultint == 1 && ipadrcountint == 1 && onecharint != 1 && accountanzgesint <= 1){
									pPlayer->SetLevel(80);
									pPlayer->LearnDefaultSkill(762, 3);
									pPlayer->TeleportTo(0, -795.73, 1495.50, 104.54, 1.05, 0);
									pPlayer->AddItem(20400, 4);
									pPlayer->SetMoney(50000000);

									CharacterDatabase.PExecute("REPLACE INTO first_char "
										"(guid,Charname, account, Accname, time, guildid,ip) "
										"VALUES ('%u', '%s', %u, '%s', %u, %u, '%s')",
										guid, charname, accountresint, accname, zeit, guildidint, ipadrint);
									return true;

									
								}

								
								else{
									ChatHandler(pPlayer->GetSession()).PSendSysMessage("[Aufwertungs System] Deine Gilde ist nicht neu, oder hat nicht genug oder zu viele Mitglieder.",
										pPlayer->GetName());
									pPlayer->PlayerTalkClass->SendCloseGossip();
									return true;
								}

							
								return true;

							}

							else {
								ChatHandler(pPlayer->GetSession()).PSendSysMessage("[Aufwertungs System] Tut mir Leid du bist in keiner Gilde.",
									pPlayer->GetName());
								pPlayer->PlayerTalkClass->SendCloseGossip();
								return false;
							}
							
						}break;
					

					case 3:
					{
						uint32 guid = pPlayer->GetGUID();
						bool gild = false;
						gild = pPlayer->GetGuild();

						if (gild)
						{
							QueryResult accountres = CharacterDatabase.PQuery("SELECT account FROM characters WHERE guid = %u", guid);
							uint32 accountresint = (*accountres)[0].GetUInt32();
							QueryResult charresult = CharacterDatabase.PQuery("Select count(guid) From characters where account = '%u'", accountresint);
							uint32 charresultint = (*charresult)[0].GetUInt32();

							/*Gildenselect*/
							QueryResult guildid = CharacterDatabase.PQuery("SELECT guildid FROM guild_member WHERE guid= %u", guid);
							uint32 guildidint = (*accountres)[0].GetUInt32();

							/*Gildenmemberanzahl*/
							QueryResult guildmember = CharacterDatabase.PQuery("SELECT count(guid) FROM guild_member WHERE guildid = %u", guildidint);
							uint32 guildmemberint = (*guildmember)[0].GetUInt32();

							/*Gildenerstelldatum*/
							QueryResult guildcreate = CharacterDatabase.PQuery("SELECT createdate FROM guild WHERE guildid = %u", guildidint);
							uint32 guildcreateint = (*guildcreate)[0].GetUInt32();

							QueryResult onechar = CharacterDatabase.PQuery("Select count(guid) From first_char where guid = '%u'", guid);
							uint32 onecharint = (*onechar)[0].GetUInt32();

							/*Username*/
							QueryResult guidname = CharacterDatabase.PQuery("SELECT name FROM characters where guid = %u", guid);
							std::string charname = (*guidname)[0].GetString();

							/*Accname*/
							QueryResult accountname = LoginDatabase.PQuery("SELECT username FROM account where id = %u", accountresint);
							std::string accname = (*accountname)[0].GetString();


							QueryResult ipadr = LoginDatabase.PQuery("SELECT last_ip FROM account where id = %u", accountresint);
							std::string ipadrint = (*ipadr)[0].GetString();
							/*IPAdresse auslesen*/
							QueryResult ipadrcount = LoginDatabase.PQuery("SELECT count(last_ip) FROM account WHERE last_ip = '%s'", ipadrint);
							uint32 ipadrcountint = (*ipadrcount)[0].GetUInt32();

							/*Acccountanzahl zählen*/
							QueryResult accountanz = CharacterDatabase.PQuery("SELECT account FROM characters WHERE guid = %u", guid);
							uint32 accountanzint = (*accountanz)[0].GetUInt32();
							QueryResult accountgesanz = CharacterDatabase.PQuery("SELECT count(account) FROM first_char WHERE account = '%u'", accountanzint);
							uint32 accountanzgesint = (*accountgesanz)[0].GetUInt32();

							time_t seconds;
							seconds = time(NULL);
							uint32 zeit = seconds;
							uint32 zeitraum = zeit - guildcreateint;

							

							if (guildmemberint > 25 && zeitraum <1209600 && charresultint == 1 && ipadrcountint == 1 && onecharint != 1 && accountanzgesint <= 1){
								pPlayer->SetLevel(80);
								pPlayer->LearnDefaultSkill(762, 4);
								pPlayer->TeleportTo(0, -795.73, 1495.50, 104.54, 1.05, 0);
								pPlayer->AddItem(20400, 4);
								pPlayer->SetMoney(50000000);
														
								CharacterDatabase.PExecute("REPLACE INTO first_char "
									"(guid,Charname, account, Accname, time, guildid,ip) "
									"VALUES ('%u', '%s', %u, '%s', %u, %u, '%s')",
									guid, charname, accountresint, accname, zeit, guildidint, ipadrint);
								return true;
							}


							else{
								ChatHandler(pPlayer->GetSession()).PSendSysMessage("[Aufwertungs System] Deine Gilde ist nicht neu, oder hat nicht genug oder zu viele Mitglieder.",
									pPlayer->GetName());
								pPlayer->PlayerTalkClass->SendCloseGossip();
								return true;
							}


							return true;

						}

						else {
							ChatHandler(pPlayer->GetSession()).PSendSysMessage("[Aufwertungs System] Tut mir Leid du bist in keiner Gilde.",
								pPlayer->GetName());
							pPlayer->PlayerTalkClass->SendCloseGossip();
							return false;
						}
					}break;


					case 4:
					{
						ChatHandler(pPlayer->GetSession()).PSendSysMessage("[Aufwertungs System] Diese Funktion wird noch implementiert.",
							pPlayer->GetName());
						pPlayer->PlayerTalkClass->SendCloseGossip();
							
						return true;
	      				
						}break;

					
						return true;
					}

					


					return true;

			}
					
};
				






void AddSC_npcfirstchar()
{
	new npc_first_char();
}