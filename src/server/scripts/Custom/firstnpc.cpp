#include "ScriptMgr.h"
#include "AccountMgr.h"


class npc_first_char : public CreatureScript
{
		public: npc_first_char() : CreatureScript("npc_first_char"){ }

				bool OnGossipHello(Player *pPlayer, Creature* _creature)
				{
					pPlayer->ADD_GOSSIP_ITEM(9, "Hochsetzen auf 80", GOSSIP_SENDER_MAIN, 0);
					pPlayer->ADD_GOSSIP_ITEM(9, "Was tut dieser NPC?", GOSSIP_SENDER_MAIN, 1);
					pPlayer->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());
					return true;


				}

				bool OnGossipSelect(Player * pPlayer, Creature * pCreature, uint32 /*uiSender*/, uint32 uiAction)
				{
					switch (uiAction)
					{
					case 0:
						{

							
							

							uint32 guid = pPlayer->GetGUID();
							pPlayer->getClass();
							QueryResult accountres = CharacterDatabase.PQuery("SELECT account FROM characters WHERE guid = %u", guid);
							QueryResult charresult = CharacterDatabase.PQuery("Select count(guid) From characters where account = '%u'", accountres);
							uint32 anzahl = 1;


							ChatHandler(pPlayer->GetSession()).PSendSysMessage("Accountres: %u", accountres,
							pPlayer->GetName());
							ChatHandler(pPlayer->GetSession()).PSendSysMessage("Guid: %u", guid,
								pPlayer->GetName());
							ChatHandler(pPlayer->GetSession()).PSendSysMessage("charresult: %u", charresult,
								pPlayer->GetName());
							pPlayer->SetLevel(80);
							pPlayer->SetMoney(50000000);
							pPlayer->AddItem(20400,4);
							pPlayer->TeleportTo(0, -4781.02, 1793.83, 132.98, 3.36, 0);
							pPlayer->PlayerTalkClass->SendCloseGossip();
							return true;
							/*if (charresult > 1){
								ChatHandler(pPlayer->GetSession()).PSendSysMessage("Du hast bereits mehr als einen Charakter auf deinem Account. Daher bist du nicht für eine Erstausstattung zugelassen.",
								pPlayer->GetName());
								pPlayer->PlayerTalkClass->SendCloseGossip();
								return true;
							}

							else if (charresult == anzahl){
								pPlayer->GetName();
								pPlayer->SetLevel(80);
								pPlayer->TeleportTo(0, -4781.02, 1793.83, 132.98, 3.36, 0);
								pPlayer->PlayerTalkClass->SendCloseGossip();
								
								return true;
							}

							else{
								ChatHandler(pPlayer->GetSession()).PSendSysMessage("Hier ist der else Baum.",
								pPlayer->GetName());
								pPlayer->PlayerTalkClass->SendCloseGossip();
								return true;
							}
							*/
							

						}break;

					case 1:
						{
							ChatHandler(pPlayer->GetSession()).PSendSysMessage("Dieser NPC vergibt deine Erstaustattung. Klicke einfach auf Hochsetzen auf 80 und es beginnt.", 
							pPlayer->GetName());
							pPlayer->PlayerTalkClass->SendCloseGossip();
						}break;

				}
					return true;
			}


};




void AddSC_npcfirstchar()
{
	new npc_first_char();
}