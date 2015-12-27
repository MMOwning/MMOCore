#include "ScriptMgr.h"
#include "AccountMgr.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>
#include "GameEventMgr.h"
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


enum Belohnungen
{
	ASTRALER_KREDIT = 38186,
	FROSTMARKEN = 49426,
	TRIUMPHMARKEN = 47241,
	TITANSTAHLBARREN = 37663,
	SARONITBARREN = 36913,
	GOLDBARREN = 3577,
	EISENBARREN = 3575,
	URSARONIT = 49908,
	TRAUMSPLITTER = 34052,
	AKRTISCHERPELZ = 44128
};


class exitarenpc : public CreatureScript
{
public: exitarenpc() : CreatureScript("exitarenpc"){ }


		bool OnQuestReward(Player* player, Creature* creature, Quest const* quest, uint32 /*opt*/) {
			if (quest->GetQuestId() == 800552){
				creature->HandleEmoteCommand(EMOTE_ONESHOT_DANCE);
				creature->Yell("Du hast es geschafft", LANG_UNIVERSAL, NULL);
				return true;
			}
			return true;
		}
};


class indomatanpc : public CreatureScript
{
public: indomatanpc() : CreatureScript("indomatanpc"){ }


		void dailybelohnung(Player* player){

			srand(time(NULL));
			int r = rand();

			uint32 anzahl = 1 + (std::rand() % (2 - 1 + 1));


			if (r % 10 == 0){
				player->GetSession()->SendNotification("Heute habe ich leider nichts fuer dich");
			}

			if (r % 10 == 1){
				player->GetSession()->SendNotification("Heute habe ich leider nichts fuer dich");

			}

			if (r % 10 == 2){

				player->GetSession()->SendNotification("Heute habe ich leider nichts fuer dich");

			}

			if (r % 10 == 3){

				player->GetSession()->SendNotification("Heute habe ich leider nichts fuer dich");

			}

			if (r % 10 == 4){

				player->GetSession()->SendNotification("Heute habe ich leider nichts fuer dich");
			}

			if (r % 10 == 5){
				player->GetSession()->SendNotification("Heute habe ich leider nichts fuer dich");
			}

			if (r % 10 == 6){

				player->GetSession()->SendNotification("Heute habe ich leider nichts fuer dich");
			}

			if (r % 10 == 7){
				player->GetSession()->SendNotification("Heute habe ich leider nichts fuer dich");

			}

			if (r % 10 == 8){
				player->GetSession()->SendNotification("Heute habe ich leider nichts fuer dich");
			}

			if (r % 10 == 9){
				player->AddItem(URSARONIT, anzahl);
			}

		}
		
		bool OnGossipHello(Player *player, Creature* _creature)
		{
			
			player->ADD_GOSSIP_ITEM(7, "Wer bist du?", GOSSIP_SENDER_MAIN, 0);
			player->ADD_GOSSIP_ITEM(7, "Hast du heute etwas fuer mich?", GOSSIP_SENDER_MAIN, 1);
			player->ADD_GOSSIP_ITEM(7, "", GOSSIP_SENDER_MAIN, 2);

			player->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());
			return true;
		}



		bool OnGossipSelect(Player * player, Creature * pCreature, uint32 /*uiSender*/, uint32 uiAction)
		{
			switch (uiAction)
			{

			case 0:
			{
				return true;
			}

			case 1:
			{
				dailybelohnung(player->GetSession()->GetPlayer());
				return true;
			}

			case 2:
			{
				return true;
			}

			return true;

			}
			return true;
		}
};


void AddSC_inselnpc()
{
	new exitarenpc();
	new indomatanpc();
}