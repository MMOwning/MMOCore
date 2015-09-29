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


class supportnpc : public CreatureScript
{
public:
		supportnpc() : CreatureScript("supportnpc") { }
		
		bool OnGossipHello(Player* player, Creature* creature)
	{
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Gibt es eine Erstaustattung?", GOSSIP_SENDER_MAIN, 0);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Wie kann ich einen GM erreichen?", GOSSIP_SENDER_MAIN, 1);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Der Questcompleter hat mir nicht alle Items zugesendet. Was tun?", GOSSIP_SENDER_MAIN, 2);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Ich habe einen Fehler gefunden. Was tun?", GOSSIP_SENDER_MAIN, 3);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Gibt es hier Crossfaction?", GOSSIP_SENDER_MAIN, 4);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Wie schreibe ich im Worldchat?", GOSSIP_SENDER_MAIN, 5);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Hilf mir bei meinen Quests", GOSSIP_SENDER_MAIN, 6);
		player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
		return true;
	}
	
		bool OnGossipSelect(Player * pPlayer, Creature * pCreature, uint32 /*uiSender*/, uint32 uiAction)
		{
			switch (uiAction)
			{
				case 0:
				{
					
					pPlayer->GetGUID();
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Ja, es gibt eine Erstaustattung. In jedem Startgebiet steht der entsprechende NPC. Es darf nur der erste Charakter ausgestattet werden.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					pPlayer->GetSession()->SendAreaTriggerMessage("Ja in den Startgebieten. Naehere Informationen auf der HP oder im Chatfenster.");
					return true;
				}

				case 1:
				{
					pPlayer->GetGUID();
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Einen GM erreicht ihr ueber das Ticketsystem. Jedoch koennt ihr auch den MMOwning Launcher benutzen, sowie eine PN an einen GM auf der Homepage schreiben.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					pPlayer->GetSession()->SendAreaTriggerMessage("Per Ticket, auf der Homepage, ueber den Launcher, oder ueber ein PN");
					return true;
				}

				case 2:
				{
					pPlayer->GetGUID();
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Das ist uns bekannt. Der Questcompleter verschickt nicht immer alle Questitems. Ist die Quest normal abschließbar wird es hier keine Erstattung geben. Ein Zuruecktreten vom Completen kann auch nicht erfolgen. Weitere Informationen gibt es auf der Homepage.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					pPlayer->GetSession()->SendAreaTriggerMessage("Das ist bekannt und wird nicht erstattet. Genauere Informationen auf der Homepage.");
					return true;
				}

				case 3:
				{
					pPlayer->GetGUID();
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Hast du einen Fehler gefunden, melde dich bitte ueber den Bugtracker. Da Entwickler nicht auf dem Liveserver spielen, lesen sie keine Tickets. Im Bugtracker bekommt ihr fuer eingereichte Daten 20 Punkte gutgeschrieben.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					pPlayer->GetSession()->SendAreaTriggerMessage("Melde dich am besten über den Bugtracker. Entwickler werden keine Tickets lesen, da sie nicht auf dem Liveserver spielen.");
					return true;
				}

				case 4:
				{
					pPlayer->GetGUID();
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Crossfaction spielen ist auf MMOwning nicht moeglich. Wir haben uns bewusst dagegen entschieden. Da wir einen pvp-orientierten Server stellen ist Crossfaction nicht moeglich.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					pPlayer->GetSession()->SendAreaTriggerMessage("Crossfaction spielen ist auf MMOwning nicht moeglich. Wir haben uns bewusst dagegen entschieden.");
					return true;
				}

				case 5:
				{
					pPlayer->GetGUID();
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Oeffne dein Chatfenster und schreibe .w gefolgt von deinem gewuenschten Text. Bsp: .w hallo.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					pPlayer->GetSession()->SendAreaTriggerMessage("Oeffne dein Chatfenster un tippe .w gefolgt von deinem Text.");
					return true;
				}

				case 6:
				{
					pPlayer->GetGUID();
					pPlayer->PlayerTalkClass->ClearMenus();
					
					QuestStatus pfad = pPlayer->GetQuestStatus(24498);
					QuestStatus plan = pPlayer->GetQuestStatus(14457);
					QuestStatus verkleidung = pPlayer->GetQuestStatus(20438);
					QuestStatus verkleidung2 = pPlayer->GetQuestStatus(24556);
					QuestStatus treffen = pPlayer->GetQuestStatus(20439);
					QuestStatus caladis = pPlayer->GetQuestStatus(24454);
					QuestStatus schwert = pPlayer->GetQuestStatus(24559);
					QuestStatus schwert2 = pPlayer->GetQuestStatus(24461);
					QuestStatus tempern1 = pPlayer->GetQuestStatus(24560);
					QuestStatus tempern2 = pPlayer->GetQuestStatus(24476);
					QuestStatus hallen = pPlayer->GetQuestStatus(24561);
					QuestStatus hallen2 = pPlayer->GetQuestStatus(24480);
					QuestStatus reise = pPlayer->GetQuestStatus(24562);
					QuestStatus reise2 = pPlayer->GetQuestStatus(24522);
					QuestStatus thalorien = pPlayer->GetQuestStatus(24563);
					QuestStatus reinigung = pPlayer->GetQuestStatus(24553);
					QuestStatus reinigung2 = pPlayer->GetQuestStatus(24594);
					QuestStatus reinigung3 = pPlayer->GetQuestStatus(24598);
					QuestStatus reinigung4 = pPlayer->GetQuestStatus(24564);
					QuestStatus reinigung5 = pPlayer->GetQuestStatus(24596);
					QuestStatus reinigung6 = pPlayer->GetQuestStatus(24553);
					

					if (pfad == QUEST_STATUS_INCOMPLETE){
						pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Der Pfad zur Zitadelle", GOSSIP_SENDER_MAIN, 7);
					}

					if (plan == QUEST_STATUS_INCOMPLETE){
						pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Der Plan der Sonnenhaescher", GOSSIP_SENDER_MAIN, 8);
					}
					
					if (verkleidung == QUEST_STATUS_INCOMPLETE){
						pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Eine passende Verkleidung", GOSSIP_SENDER_MAIN, 9);
					}

					if (treffen == QUEST_STATUS_INCOMPLETE){
						pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Ein Treffen mit dem Magister", GOSSIP_SENDER_MAIN, 10);
					}

					if (caladis == QUEST_STATUS_INCOMPLETE){
						pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Kehrt zu Caladis Prunkspeer zurueck", GOSSIP_SENDER_MAIN, 11);
					}

					if (schwert == QUEST_STATUS_INCOMPLETE){
						pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Das Schwert neu schmieden", GOSSIP_SENDER_MAIN, 12);
					}

					if (tempern1 == QUEST_STATUS_INCOMPLETE){
						pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Die Klinge tempern", GOSSIP_SENDER_MAIN, 13);
					}
					
					if (hallen == QUEST_STATUS_INCOMPLETE){
						pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Die Hallen der Reflexion", GOSSIP_SENDER_MAIN, 14);
					}

					if (reise == QUEST_STATUS_INCOMPLETE){
						pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Reise zum Sonnenbrunnen", GOSSIP_SENDER_MAIN, 15);
					}

					if (thalorien == QUEST_STATUS_INCOMPLETE){
						pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Thalorien Morgensucher", GOSSIP_SENDER_MAIN, 16);
					}

					if (reinigung == QUEST_STATUS_INCOMPLETE){
						pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Die Reinigung Quel´Delars", GOSSIP_SENDER_MAIN, 17);
					}

					if (tempern2 == QUEST_STATUS_INCOMPLETE){
						pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Die Klinge tempern", GOSSIP_SENDER_MAIN, 18);
					}

					if (hallen2 == QUEST_STATUS_INCOMPLETE){
						pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Die Hallen der Reflexion", GOSSIP_SENDER_MAIN, 19);
					}
					
					if (schwert2 == QUEST_STATUS_INCOMPLETE){
						pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Die Hallen der Reflexion", GOSSIP_SENDER_MAIN, 20);
					}

					if (reinigung2 == QUEST_STATUS_INCOMPLETE){
						pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Die Reinigung Quel´Delars", GOSSIP_SENDER_MAIN, 21);
					}

					if (reinigung3 == QUEST_STATUS_INCOMPLETE){
						pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Die Reinigung Quel´Delars", GOSSIP_SENDER_MAIN, 22);
					}

					if (reinigung4 == QUEST_STATUS_INCOMPLETE){
						pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Die Reinigung Quel´Delars", GOSSIP_SENDER_MAIN, 23);
					}

					if (reinigung5 == QUEST_STATUS_INCOMPLETE){
						pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Die Reinigung Quel´Delars", GOSSIP_SENDER_MAIN, 24);
					}

					if (reinigung6 == QUEST_STATUS_INCOMPLETE){
						pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Die Reinigung Quel´Delars", GOSSIP_SENDER_MAIN, 25);
					}

					if (verkleidung == QUEST_STATUS_INCOMPLETE){
						pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Eine passende Verkleidung", GOSSIP_SENDER_MAIN, 26);
					}

					if (reise2 == QUEST_STATUS_INCOMPLETE){
						pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Reise zum Sonnenbrunnen", GOSSIP_SENDER_MAIN, 27);
					}

					pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Ein Witz zum Test", GOSSIP_SENDER_MAIN, 100);
					pPlayer->PlayerTalkClass->SendGossipMenu(907, pCreature->GetGUID());
					

				
					

					return true;
				}
 
				//Der Pfad zur Zitadelle Allianz
				case 7:
				{
					pPlayer->GetGUID();
					pPlayer->CanCompleteQuest(24498);
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Die Quest 'Der Pfad zur Zitadelle' wurde abgeschlossen.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}

				//Plan 
				case 8:
				{
					pPlayer->GetGUID();
					
					pPlayer->AddItem(49536,1);
					pPlayer->CompleteQuest(14457);
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Die Quest 'Der Plan der Sonnenhaescher' wurde abgeschlossen.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}

				//VERKLEIDUNG
				case 9:
				{
					pPlayer->GetGUID();
					pPlayer->AddItem(49648, 1);
					pPlayer->CompleteQuest(20438);
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Die Quest 'Eine passende Verkleidung' wurde abgeschlossen.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}


				//TREFFEN
				case 10:
				{
					pPlayer->GetGUID();

					pPlayer->AddItem(49698, 1);
					pPlayer->CompleteQuest(20439);
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Die Quest 'Ein Trffen mit dem Magister' wurde abgeschlossen.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}


				//CALADIS
				case 11:
				{
					pPlayer->GetGUID();

					pPlayer->AddItem(49698, 1);
					pPlayer->CompleteQuest(24454);
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Die Quest 'Kehrt zu Caladis Prunkspeer zurueck' wurde abgeschlossen.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}

				//Schwert
				case 12:
				{
					pPlayer->GetGUID();

					pPlayer->AddItem(49718, 5);
					pPlayer->AddItem(49723, 1);
					pPlayer->AddItem(49740, 1);
					pPlayer->CompleteQuest(24559);
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Die Quest 'Das Schwert neu schmieden' wurde abgeschlossen.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}

				//Tempern
				case 13:
				{
					pPlayer->GetGUID();

					pPlayer->AddItem(49920, 1);
					pPlayer->CompleteQuest(24560);
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Die Quest 'Die Klinge tempern' wurde abgeschlossen.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}

				//Hallen
				case 14:
				{
					pPlayer->GetGUID();

					pPlayer->AddItem(49766, 1);
					pPlayer->CompleteQuest(24561);
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Die Quest 'Die Hallen der Reflexion' wurde abgeschlossen.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}

				//REISE
				case 15:
				{
					pPlayer->GetGUID();

					
					pPlayer->CompleteQuest(24562);
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Die Quest 'Reise zum Sonnenbrunnen' wurde abgeschlossen.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}


				//Thalorien
				case 16:
				{
					pPlayer->GetGUID();

					
					pPlayer->CompleteQuest(24563);
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Die Quest 'Thalorien Morgensucher' wurde abgeschlossen.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}

				//REINIGUNG
				case 17:
				{
					pPlayer->GetGUID();


					pPlayer->CompleteQuest(24563);
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Die Quest 'Die Reinigung Quel`Delars' wurde abgeschlossen.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}

				//Tempern2
				case 18:
				{
					pPlayer->GetGUID();

					pPlayer->AddItem(49920, 1);
					pPlayer->CompleteQuest(24476);
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Die Quest 'Die Klinge tempern' wurde abgeschlossen.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}

				//Hallen2
				case 19:
				{
					pPlayer->GetGUID();

					pPlayer->AddItem(49766, 1);
					pPlayer->CompleteQuest(24561);
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Die Quest 'Die Hallen der Reflexion' wurde abgeschlossen.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}

				//Schwert
				case 20:
				{
					pPlayer->GetGUID();

					pPlayer->AddItem(49718, 5);
					pPlayer->AddItem(49723, 1);
					pPlayer->AddItem(49740, 1);
					pPlayer->CompleteQuest(24461);
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Die Quest 'Das Schwert neu schmieden' wurde abgeschlossen.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}

				//REINIGUNG2
				case 21:
				{
					pPlayer->GetGUID();


					pPlayer->CompleteQuest(24594);
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Die Quest 'Die Reinigung Quel`Delars' wurde abgeschlossen.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}

				//REINIGUNG3
				case 22:
				{
					pPlayer->GetGUID();


					pPlayer->CompleteQuest(24598);
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Die Quest 'Die Reinigung Quel`Delars' wurde abgeschlossen.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}

				//REINIGUNG4
				case 23:
				{
					pPlayer->GetGUID();


					pPlayer->CompleteQuest(24564);
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Die Quest 'Die Reinigung Quel`Delars' wurde abgeschlossen.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}

				//REINIGUNG5
				case 24:
				{
					pPlayer->GetGUID();


					pPlayer->CompleteQuest(24596);
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Die Quest 'Die Reinigung Quel`Delars' wurde abgeschlossen.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}


				//REINIGUNG6
				case 25:
				{
					pPlayer->GetGUID();


					pPlayer->CompleteQuest(24553);
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Die Quest 'Die Reinigung Quel`Delars' wurde abgeschlossen.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}

				//VERKLEIDUNG2
				case 26:
				{
					pPlayer->GetGUID();
					pPlayer->AddItem(49648, 1);
					pPlayer->CompleteQuest(24556);
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Die Quest 'Eine passende Verkleidung' wurde abgeschlossen.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}

				//REISE2
				case 27:
				{
					pPlayer->GetGUID();
					pPlayer->CompleteQuest(24522);
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Die Quest 'Reise zum Sonnenbrunnen' wurde abgeschlossen.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}

				return true;
			};
			return true;
		}
};


void AddSC_supportnpc()
{
	new supportnpc();
}
