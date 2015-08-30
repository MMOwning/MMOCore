#include "ScriptMgr.h"
#include "AccountMgr.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>

class seruc : public CreatureScript
{
public: seruc() : CreatureScript("seruc"){ }



		bool OnGossipHello(Player *pPlayer, Creature* _creature)
		{
			pPlayer->ADD_GOSSIP_ITEM(7, "Raid [Gesperrt]", GOSSIP_SENDER_MAIN, 0);
			pPlayer->ADD_GOSSIP_ITEM(7, "Instanz [Gesperrt]", GOSSIP_SENDER_MAIN, 13);
			pPlayer->ADD_GOSSIP_ITEM(7, "Teleport zum PVP Areal [500 Wertung]", GOSSIP_SENDER_MAIN, 1);
			pPlayer->ADD_GOSSIP_ITEM(7, "Teleport zur Insel ", GOSSIP_SENDER_MAIN, 2);
			pPlayer->ADD_GOSSIP_ITEM(7, "Teleport zu Yasio ", GOSSIP_SENDER_MAIN, 3);
			pPlayer->ADD_GOSSIP_ITEM(7, "MMOwning Worldbosse", GOSSIP_SENDER_MAIN, 15);
			pPlayer->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());
			return true;
		}


		bool OnGossipSelect(Player * pPlayer, Creature * pCreature, uint32 /*uiSender*/, uint32 uiAction)
		{
			switch (uiAction)
			{
				/*RAID*/
			case 0: {
				pPlayer->GetGUID();
				pPlayer->TeleportTo(169, -393.26, 2972.93, 92.85, 5.94);
				pPlayer->ModifyMoney(-200000);
				return true;
			}break;

			case 15:
			{
				uint32 guid = pPlayer->GetGUID();

				pPlayer->PlayerTalkClass->ClearMenus();
				pPlayer->ADD_GOSSIP_ITEM(7, "Boss: Orrig [5-10] ", GOSSIP_SENDER_MAIN, 4);
				pPlayer->ADD_GOSSIP_ITEM(7, "Boss: Exitares Schatten [7-15]", GOSSIP_SENDER_MAIN, 5);
				pPlayer->ADD_GOSSIP_ITEM(7, "Boss: Die gequälte Seele [5-15]", GOSSIP_SENDER_MAIN, 6);
				pPlayer->ADD_GOSSIP_ITEM(7, "Boss: Kayoula [25-40]", GOSSIP_SENDER_MAIN, 7);
				pPlayer->ADD_GOSSIP_ITEM(7, "Boss: Tempus [15-25]", GOSSIP_SENDER_MAIN, 8);
				pPlayer->ADD_GOSSIP_ITEM(7, "Boss: Arcturus [5-10] ", GOSSIP_SENDER_MAIN, 9);
				pPlayer->ADD_GOSSIP_ITEM(7, "Boss: Moon [25-40]", GOSSIP_SENDER_MAIN, 10);
				pPlayer->ADD_GOSSIP_ITEM(7, "Boss: Maltyriun [5-10]", GOSSIP_SENDER_MAIN, 11);
				pPlayer->ADD_GOSSIP_ITEM(7, "Boss: LORDofDOOM [10-25]", GOSSIP_SENDER_MAIN, 12);
				pPlayer->ADD_GOSSIP_ITEM(7, "Boss: Tyranium [5-10]", GOSSIP_SENDER_MAIN, 14);
				pPlayer->ADD_GOSSIP_ITEM(7, "Boss: Tolreos [5-10]", GOSSIP_SENDER_MAIN, 16);
				pPlayer->PlayerTalkClass->SendGossipMenu(907, pCreature->GetGUID());
				return true;
			}
				/*PVP*/
			case 1: {
				pPlayer->GetGUID();
				uint32 rating = pPlayer->GetArenaPersonalRating(1);
					if (rating >= 500){
						pPlayer->ModifyHonorPoints(-500, NULL);
						pPlayer->TeleportTo(0, -793.67,1565.25,19.88,3.25);
						pPlayer->ModifyMoney(-200000);
						return true;
					}
					
					else{
						pPlayer->GetGUID();
						ChatHandler(pPlayer->GetSession()).PSendSysMessage("Deine persönliche Wertung ist zu gering. Sie muss mindestens 500 betragen.",
							pPlayer->GetName());
						pPlayer->PlayerTalkClass->SendCloseGossip();
						return true;
					}
					return true;
			}break;
				
				
				/*INSEL*/
				case 2: {
					pPlayer->GetGUID();
					pPlayer->TeleportTo(0,-9773,2126.72,15.40,3.88);
					pPlayer->ModifyMoney(-200000);
					return true;
				}break;

			    
						/*YASIO*/
				case 3: {
					pPlayer->GetGUID();
					pPlayer->TeleportTo(571,5728.79,608.62,618.59,5.60);
					pPlayer->ModifyMoney(-200000);
					return true;
				}break;




						/*ORRIG*/
				case 4: {
					pPlayer->GetGUID();
					pPlayer->TeleportTo(0, -12556.57,-1366.97,41.56,1.024);
					pPlayer->ModifyMoney(-200000);
					return true;

				}break;




						/*EXI*/
				case 5: {
					pPlayer->GetGUID();
					pPlayer->TeleportTo(0, -7440.66,-2029.63,313.72,6.28);
					pPlayer->ModifyMoney(-200000);
					return true;
				}break;





						/*GEQUÄLTE*/
				case 6: {
					pPlayer->GetGUID();
					pPlayer->TeleportTo(0,-12978.69, -1774.43, 137.11,3.5);
					pPlayer->ModifyMoney(-200000);
					return true;
				}break;


						/*KAYOULA*/
				case 7: {
					pPlayer->GetGUID();
					pPlayer->TeleportTo(530, -2793.37,493.29,-25.33,0.42);
					pPlayer->ModifyMoney(-200000);
					return true;
				}break;



						/*TEMPUIS*/
				case 8: {
					pPlayer->GetGUID();
					pPlayer->TeleportTo(1, -8041.57, 1603.90, 14.58,3.19);
					pPlayer->ModifyMoney(-200000);
					return true;
				}break;



						/*ARC*/
				case 9: {
					pPlayer->GetGUID();
					pPlayer->TeleportTo(571,2973.87,-5825.54,262.95,1.6);
					pPlayer->ModifyMoney(-200000);
					return true;
				}break;



						/*MOON*/
				case 10: {
					pPlayer->GetGUID();
					pPlayer->TeleportTo(0,-12474.73,-2688.13,89.61,3.05);
					pPlayer->ModifyMoney(-200000);
					return true;
				}break;


						 /*MALTYRiun*/
				case 11: {
					pPlayer->GetGUID();
					pPlayer->TeleportTo(0,-11764.75,-3560.32,86.50,5.31);
					return true;
				}break;




						 /*LORDOFDOOM*/
				case 12: {
					pPlayer->GetGUID();
					pPlayer->TeleportTo(0,-6362.47,-2324.61,390.93,0.55);
					pPlayer->ModifyMoney(-200000);
					return true;
				}break;

					/*RAID*/
				case 13: {
					pPlayer->GetGUID();
					pPlayer->TeleportTo(169, -393.26, 2972.93, 92.85, 5.94);
					pPlayer->ModifyMoney(-200000);
					return true;
				}break;

					/*Tyranium*/
				case 14: {
					pPlayer->GetGUID();
					pPlayer->TeleportTo(0, -4698.80, -2045.90, 521.12, 1.4);
					pPlayer->ModifyMoney(-200000);
					return true;
				}break;

					/*Tolreos*/
				case 16: {
					pPlayer->GetGUID();
					pPlayer->TeleportTo(530, -1281.67, 1375.05, 6.75, 1.04);
					pPlayer->ModifyMoney(-200000);
					return true;
				}break;


			}
			return true;
		}

};



void AddSC_seruc()
{
	new seruc();
}