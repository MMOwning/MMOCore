#include "ScriptPCH.h"

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
					pPlayer->GetSession()->SendAreaTriggerMessage("Ja in den Startgebieten. Nähere Informationen auf der HP oder im Chatfenster.");
					return true;
				}

				case 1:
				{
					pPlayer->GetGUID();
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Einen GM erreicht ihr ueber das Ticketsystem. Jedoch koennt ihr auch den MMOwning Launcher benutzen, sowie eine PN an einen GM auf der Homepage schreiben.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					pPlayer->GetSession()->SendAreaTriggerMessage("Per Ticket, auf der Homepage, über den Launcher, oder über ein PN");
					return true;
				}

				case 2:
				{
					pPlayer->GetGUID();
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Das ist uns bekannt. Der Questcompleter verschickt nicht immer alle Questitems. Ist die Quest normal abschließbar wird es hier keine Erstattung geben. Ein Zurücktreten vom Completen kann auch nicht erfolgen. Weitere Informationen gibt es auf der Homepage.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					pPlayer->GetSession()->SendAreaTriggerMessage("Das ist bekannt, und wird nicht erstattet. Genauere Informationen auf der Homepage.");
					return true;
				}

				case 3:
				{
					pPlayer->GetGUID();
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Hast du einen Fehler gefunden, melde dich bitte ueber den Bugtracker Da Entwickler nicht auf dem Liveserver spielen, lesen sie keine Tickets. Im Bugtracker bekommt ihr fuer eingereichte Daten 20 Punkte gutgeschrieben.", pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					pPlayer->GetSession()->SendAreaTriggerMessage("Melde dich am besten über den Bugtracker. Entwickler werden keine Tickets lesen, da sie nicht auf dem Liveserver spielen.");
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
