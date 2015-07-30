#include "ScriptMgr.h"
#include "AccountMgr.h"



class npc_first_char : public CreatureScript
{
		public: npc_first_char() : CreatureScript("npc_first_char"){ }

				bool OnGossipHello(Player *pPlayer, Creature* _creature)
				{
					pPlayer->ADD_GOSSIP_ITEM(7, "Was tut dieser NPC?", GOSSIP_SENDER_MAIN, 0);
					pPlayer->ADD_GOSSIP_ITEM(7, "Firstausstattung", GOSSIP_SENDER_MAIN, 1);
					if (pPlayer->IsGameMaster()){
						pPlayer->ADD_GOSSIP_ITEM(7, "GM Punkt", GOSSIP_SENDER_MAIN, 3);
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

						
							QueryResult ipadr = LoginDatabase.PQuery("SELECT last_ip FROM account where id = %u", accountresint);
							std::string ipadrint = (*ipadr)[0].GetString();
							QueryResult ipadrcount = LoginDatabase.PQuery("SELECT count(last_ip) FROM account WHERE last_ip = '%s'", ipadrint);
							uint32 ipadrcountint = (*ipadrcount)[0].GetUInt32();
							
							ChatHandler(pPlayer->GetSession()).PSendSysMessage("ipadrcountint: %u", ipadrcountint,
								pPlayer->GetName());
							ChatHandler(pPlayer->GetSession()).PSendSysMessage("ipadrint: %s", ipadrint,
								pPlayer->GetName());
							ChatHandler(pPlayer->GetSession()).PSendSysMessage("charresultint %u", charresultint,
								pPlayer->GetName());
							ChatHandler(pPlayer->GetSession()).PSendSysMessage("accountresint: %u", accountresint,
								pPlayer->GetName());
						
							
							

							 if (charresultint == 1 && ipadrcountint == 1){
								
								pPlayer->PlayerTalkClass->SendCloseGossip();
								pPlayer->SetLevel(80);
								pPlayer->TeleportTo(0, -4781.02, 1793.83, 132.98, 3.36, 0);
								pPlayer->AddItem(20400, 4);
								pPlayer->SetMoney(50000000);
								ChatHandler(pPlayer->GetSession()).PSendSysMessage("Deine Aufwertung wurde ausgeführt. Sucht Euch nun Euer gewünschtes Equipment aus. Viel Spaß wünscht Exitare sowie das MMOwning-Team.",
								pPlayer->GetName());
								pPlayer->PlayerTalkClass->SendCloseGossip();
								
										
								
								
				     			return true;
							}
							 							
							 else {
								 ChatHandler(pPlayer->GetSession()).PSendSysMessage("Du hast bereits einen anderen Charakter auf diesem Realm oder versuchst mit\nzu vielen Accounts eine Erstaustattung zu erlangen.\nDiese wird daher abgelehnt.\nMfG Exitare und das MMOwning-Team.",
								 pPlayer->GetName());
								 pPlayer->PlayerTalkClass->SendCloseGossip();
								return false;
							}
							 
							

						}break;

					case 0:
						{
							ChatHandler(pPlayer->GetSession()).PSendSysMessage("Dieser NPC vergibt deine Erstaustattung. Klicke einfach auf 'Firstausstattung'und es beginnt.", 
							pPlayer->GetName());
							pPlayer->PlayerTalkClass->SendCloseGossip();
							return true;
						}break;

					

					


					

				}
					
			}
				

};




void AddSC_npcfirstchar()
{
	new npc_first_char();
}