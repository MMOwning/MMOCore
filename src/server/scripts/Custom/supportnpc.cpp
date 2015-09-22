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

				return true;
			};
			return true;
		}
};


void AddSC_supportnpc()
{
	new supportnpc();
}
