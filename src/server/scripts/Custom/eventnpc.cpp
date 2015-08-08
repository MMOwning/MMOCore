#include "ScriptMgr.h"
#include "AccountMgr.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>

class eventnpc : public CreatureScript
{
public: eventnpc() : CreatureScript("eventnpc"){ }



		bool OnGossipHello(Player *pPlayer, Creature* _creature)
		{
			pPlayer->GetGUID();
			pPlayer->ADD_GOSSIP_ITEM(7, "Was tut dieser NPC?", GOSSIP_SENDER_MAIN, 2);


			/*if (pPlayer->IsGameMaster()){
				pPlayer->ADD_GOSSIP_ITEM(7, "Winterevent Port", GOSSIP_SENDER_MAIN, 0);
				pPlayer->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());
				return true;
			}*/
			pPlayer->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());
			return true;
		}


		bool OnGossipSelect(Player * pPlayer, Creature * pCreature, uint32 /*uiSender*/, uint32 uiAction)
		{
			switch (uiAction)
			{
					
				case 0: {
					pPlayer->GetGUID();
					pPlayer->TeleportTo(1, 16226.21, 16256.77, 13.19, 1.65);
					return true;
				}break;
				
						
				case 2: {
					pPlayer->GetGUID();
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Dieser NPC zeigt an, welche Events von MMOwning gerade aktiv sind. Wenn keine Events aktiv sind, werden auch keine angezeigt.",
						pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}break;

					return true;
			}
		}
};


void AddSC_eventnpc()
{
	new eventnpc();
}