#include "AccountMgr.h"
#include "ScriptMgr.h"
#include "Chat.h"
#include "Common.h"
#include "Player.h"
#include "WorldSession.h"
#include "Language.h"
#include "Log.h"
#include "SpellAuras.h"
#include "World.h"

#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "Chat.h"
#include "SocialMgr.h"

class ex_commands : public CommandScript
{
public:
	ex_commands() : CommandScript("ex_commands") { }

	ChatCommand* GetCommands() const override
	{

		static ChatCommand commandTable[] =
		{

			//Set your Characterstats to test single Bosses
			{ "testing", SEC_ADMINISTRATOR, false, &HandleTestingCommand, "", NULL },
			//bonuscode
			{ "code", SEC_PLAYER, false, &HandleGutscheinCommand, "", NULL }
		};

		return commandTable;
	}

	
	//Allows members of your team, with sec > 2 to set their chars to Testing mode.
	static bool HandleTestingCommand(ChatHandler* handler, const char* args)
	{
		Player *player = handler->GetSession()->GetPlayer();
		if (player->GetSession()->GetSecurity() < 2){
			return false;
		}
		player->ResurrectPlayer(100, false);
		player->SetHealth(400000000);
		player->SetGameMaster(true);
		player->DurabilityRepairAll(false,0,false);
		

	}

	
	/*Codes */
	static bool HandleGutscheinCommand(ChatHandler* handler, const char* args)
	{
		Player *player = handler->GetSession()->GetPlayer();
		char msg[250];
		snprintf(msg, 250, "Dein Code wurde bereits verwendet");
		ChatHandler(player->GetSession()).PSendSysMessage(msg,
			player->GetName());
		return false;
		
		/*
		uint32 itemCode = atoi((char*)args);

		if (!itemCode)
		{
			player->GetSession()->SendNotification("Ohne Code geht das leider nicht!");
			return false;
		}
		
		
		


		
		if (itemCode)
		{
			QueryResult result = WorldDatabase.PQuery("SELECT `code`, `belohnung`, `anzahl`, `benutzt` FROM `item_codes` WHERE `code` = %u", itemCode);
			Field* fields = result->Fetch();
			uint32 code = fields[0].GetUInt32();
			uint32 belohnung = fields[1].GetUInt32();
			uint32 anzahl = fields[2].GetUInt32();
			uint8 benutzt = fields[3].GetUInt8();

			if (benutzt == 0)
			{
				Item* item = Item::CreateItem(belohnung, anzahl);

				SQLTransaction trans = CharacterDatabase.BeginTransaction();
				item->SaveToDB(trans);
				MailDraft("Dein Gutscheincode", "Dein Code wurde erfolgreich eingelöst. Wir wünschen dir weiterhin viel Spaß auf MMOwning. Dein MMOwning-Team").AddItem(item)
					.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
				CharacterDatabase.CommitTransaction(trans);

				WorldDatabase.PExecute("UPDATE item_codes SET name = '%s' WHERE code = %u", player->GetName().c_str(), itemCode);
				WorldDatabase.PExecute("UPDATE item_codes SET benutzt = 1 WHERE code = %u", itemCode);


				
			}
			else{
				char msg[250];
				snprintf(msg, 250, "Dein Code wurde bereits verwendet");
				ChatHandler(player->GetSession()).PSendSysMessage(msg,
					player->GetName());
				return false;
			}

		}
			else{
				char msg[250];
				snprintf(msg, 250, "Der eingegebene Code exisitert nicht.");
				ChatHandler(player->GetSession()).PSendSysMessage(msg,
					player->GetName());
				return false;
				}
			return true;*/
		}
		
};

void AddSC_ex_commands()
{
	new ex_commands();
}