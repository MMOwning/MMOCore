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
							uint32 accountresint = (*accountres)[0].GetUInt32();
							QueryResult charresult = CharacterDatabase.PQuery("Select count(guid) From characters where account = '%u'", accountresint);
							uint32 charresultint = (*charresult)[0].GetUInt32();


							ChatHandler(pPlayer->GetSession()).PSendSysMessage("Accountres: %u", accountresint,
							pPlayer->GetName());
							ChatHandler(pPlayer->GetSession()).PSendSysMessage("Guid: %u", guid,
								pPlayer->GetName());
							ChatHandler(pPlayer->GetSession()).PSendSysMessage("charresult: %u", charresultint,
								pPlayer->GetName());
							
							 if (charresultint == 1){
								pPlayer->GetName();
								pPlayer->SetLevel(80);
								pPlayer->TeleportTo(0, -4781.02, 1793.83, 132.98, 3.36, 0);
								pPlayer->AddItem(20400, 4);
								pPlayer->PlayerTalkClass->SendCloseGossip();
								ChatHandler(pPlayer->GetSession()).PSendSysMessage("charresult: %u", charresultint,
									pPlayer->GetName());
								return true;
							}

							
							 else {
								 ChatHandler(pPlayer->GetSession()).PSendSysMessage("Du hast bereits einen anderen Charakter auf diesem Realm. Pro Realm ist nur eine Charakteraufwertung gestattet.",
								 pPlayer->GetName());
								 pPlayer->PlayerTalkClass->SendCloseGossip();
								return false;
							}
							

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