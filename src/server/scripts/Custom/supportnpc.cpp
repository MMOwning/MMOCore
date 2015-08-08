#include "ScriptPCH.h"

class supportnpc : public CreatureScript
{
public:
		supportnpc() : CreatureScript("supportnpc") { }
		
		bool OnGossipHello(Player* player, Creature* creature)
	{
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Gibt es eine Erstaustattung?", GOSSIP_SENDER_MAIN, 0);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Wie kann ich einen GM erreichen?", GOSSIP_SENDER_MAIN, 1);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Fraktionswechsel Kosten: Umsonst.", GOSSIP_SENDER_MAIN, 2);
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


				return true;
			};
			return true;
		}
};


void AddSC_supportnpc()
{
	new supportnpc();
}
