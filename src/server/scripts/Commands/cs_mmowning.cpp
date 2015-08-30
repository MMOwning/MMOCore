/*
 * Copyright (C) 2012 MMOwning
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
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

class mmowning_commandscript : public CommandScript
{
public:
    mmowning_commandscript() : CommandScript("mmowning_commandscript") { }

	ChatCommand* GetCommands() const override
    {

        static ChatCommand commandTable[] =
        {
			//{ "goname",         SEC_MODERATOR,      false, OldHandler<&ChatHandler::HandleAppearCommand>,              "", NULL },				
			//{ "namego",         SEC_MODERATOR,      false, OldHandler<&ChatHandler::HandleSummonCommand>,              "", NULL },				
			//Allows your players to gamble for fun and prizes
			{ "gamble",         SEC_PLAYER,         false, &HandleGambleCommand,              "", NULL },	
			{ "roulette",       SEC_PLAYER,         false, &HandleRouletteCommand,            "", NULL },
			//Mall Teleporter
			{ "mall",			SEC_PLAYER,			false, &HandleMallCommand,				"", NULL }, 		
			//Dalaran Teleporter
			{ "dala",			SEC_PLAYER,			false, &HandleDalaCommand,				"", NULL }, 				
			//Buffer
			{ "buffs",			SEC_PLAYER,			false, &HandleBuffsCommand,				"", NULL }, 
			//GuildHouse Tele
			{ "gh",             SEC_PLAYER,      	false, &HandleGHCommand,				"", NULL },	
			//insel
			{ "insel",			SEC_PLAYER,			false, &HandleInselCommand,				"", NULL },
			//{ "tcrecon",        SEC_MODERATOR,      false, &HandleIRCRelogCommand,            "", NULL },	
			{ NULL,             0,                  false,  NULL,                            "", NULL }
        };

        return commandTable;
    }


//Allows your players to gamble for fun and prizes
static bool HandleGambleCommand(ChatHandler* handler, const char* args)
{
    Player *chr = handler->GetSession()->GetPlayer();

    char* px = strtok((char*)args, " ");

    if (!px)
        return false;

    uint32 money = (uint32)atoi(px);

    if (chr->GetMoney() < money)
    {
        handler->PSendSysMessage("Du kannst kein Gold setzen welches du nicht hast!");
        return true;
    }

    else
    {
        if (money>0)
        {
             //if (rand()%100 < 50)
			 if (rand()%100 < 40)
             {
				  chr->ModifyMoney(money);	
                  //chr->ModifyMoney(money*2);
                  handler->PSendSysMessage("Du hast gewonnen und einen Einsatz verdoppelt");
             }
             else
             {
                  chr->ModifyMoney(-int(money));
                  handler->PSendSysMessage("Du hast verloren");
             }  
        }
    }

    return true;
}

static bool HandleRouletteCommand(ChatHandler* handler, const char* args)
{
    Player *chr = handler->GetSession()->GetPlayer();

    char* px = strtok((char*)args, " ");

    if (!px)
        return false;

    uint32 money = (uint32)atoi(px);

    if (chr->GetMoney() < money)
    {
        handler->PSendSysMessage("Du kannst kein Gold setzen welches du nicht hast!");
        return true;
    }

    else
    {
        if (money>0)
        {
             //if (rand()%36 < 1)
			 if (rand()%42 < 1)
             {
                  chr->ModifyMoney(money*36);
                  handler->PSendSysMessage("Du hast das 36x deines Einsatzes gewonnen, GZ!");
             }
             else
             {
                  chr->ModifyMoney(-int(money));
                  handler->PSendSysMessage("Du hast verloren");
             }  
        }
    }

     return true;
 }

//Mall Teleporter
static bool HandleMallCommand(ChatHandler* handler, const char* /*args*/)
{
        //MALL command
        
        Player *chr = handler->GetSession()->GetPlayer();

        if (chr->IsInCombat())
        {
        handler->PSendSysMessage(LANG_YOU_IN_COMBAT);
        //SetSentErrorMessage(true);
        return false;
        }
        if (chr->IsInFlight())
        {
        handler->PSendSysMessage(LANG_YOU_IN_FLIGHT);
        //SetSentErrorMessage(true);
        return false;
        }

        chr->ResurrectPlayer(0.5, false);

        switch(chr->GetTeam())
   {
        case ALLIANCE:
                chr->TeleportTo(0, -8842.09f, 626.358f, 94.0867f, 0.0f);    // Insert Ally mall Cords here
                break;

        case HORDE:
				chr->TeleportTo(1, 1601.08f, -4378.69f, 9.9846f, 0.15315f);    // Insert Horde mall Cords here
                break;
   }
        return true;
}

//Dalaran Teleporter
static bool HandleDalaCommand(ChatHandler* handler, const char* /*args*/)
{
        //MALL command
        
        Player *chr = handler->GetSession()->GetPlayer();

        if (chr->IsInCombat())
        {
        handler->PSendSysMessage(LANG_YOU_IN_COMBAT);
        //SetSentErrorMessage(true);
        return false;
        }
        if (chr->IsInFlight())
        {
        handler->PSendSysMessage(LANG_YOU_IN_FLIGHT);
        //SetSentErrorMessage(true);
        return false;
        }

        chr->ResurrectPlayer(0.5, false);

        chr->TeleportTo(571, 5809.55f, 503.975f, 657.526f, 1.70185f);    // Insert Dala Coords

        return true;
}

//Buffer
static bool HandleBuffsCommand(ChatHandler* handler, const char* /*args*/)              
{
                                Player *chr = handler->GetSession()->GetPlayer();
                                
        if (chr->IsInCombat())
        {
        handler->PSendSysMessage("Du kannst dich nicht waehrend eines Kampfes buffen");
        //SetSentErrorMessage(true);
        return false;
        }
        if (chr->IsInFlight())
        {
        handler->PSendSysMessage("Du kannste dich nicht waehrend des Fliegens buffen");
        //SetSentErrorMessage(true);
        return false;
        }
                
        if (chr->GetMoney() >= 2000000)
                {
								chr->Dismount();
                                chr->RemoveAurasByType(SPELL_AURA_MOUNTED);
                                chr-> AddAura(48161, chr);              // Power Word: Fortitude        
                                chr-> AddAura(48073, chr);              // Divine Spirit
                                chr-> AddAura(20217, chr);              // Blessing of Kings
                                chr-> AddAura(48469, chr);              // Mark of the wild
                                chr-> AddAura(16609, chr);              // Spirit of Zandalar
                                chr-> AddAura(15366, chr);              // Songflower Serenade
                                chr-> AddAura(22888, chr);              // Rallying Cry of the Dragonslayer
                                chr-> AddAura(57399, chr);              // Well Fed
                                chr-> AddAura(17013, chr);              // Agamaggan's Agility
                                chr-> AddAura(16612, chr);              // Agamaggan's Strength
                                chr->ModifyMoney(-2000000);
                                handler->PSendSysMessage("Du bist jetzt gebufft!");
                                return false;
                }
        else
                {
                handler->PSendSysMessage("Du hast nicht genug Gold!");
        }
                return false;
}	

//GuildHouse Tele
static bool HandleGHCommand(ChatHandler* handler, const char* args)
{
        Player *chr = handler->GetSession()->GetPlayer();

        if(chr->IsInFlight())
        {
                //pokud hrac leti
                handler->PSendSysMessage(LANG_YOU_IN_FLIGHT);
                //SetSentErrorMessage(true);
                return false;
        }

        if(chr->IsInCombat())
        {
                //pokud je hrac v combatu
                handler->PSendSysMessage(LANG_YOU_IN_COMBAT);
                //SetSentErrorMessage(true);
                return false;
        }

        if (chr->GetGuildId() == 0)
        {
                //pokud hrac nema guildu
                return false;
        }

        QueryResult result;
        result = CharacterDatabase.PQuery("SELECT `x`, `y`, `z`, `map` FROM `guildhouses` WHERE `guildId` = %u", chr->GetGuildId());
        if(!result)
        {
                //pokud guilda nema guildhouse zapsany v tabulce guildhouses
                handler->PSendSysMessage("GH Port");
                return false;
        }


        float x, y, z;
        uint32 map;

        Field *fields = result->Fetch();
        x = fields[0].GetFloat();
        y = fields[1].GetFloat();
        z = fields[2].GetFloat();
        map = fields[3].GetUInt32();
        

        chr->SaveRecallPosition();
        chr->TeleportTo(map, x, y, z, 0);
        chr->SaveToDB();
        return true;
}

//GuildHouse Tele
static bool HandleInselCommand(ChatHandler* handler, const char* args)
{
	Player *chr = handler->GetSession()->GetPlayer();

	chr->TeleportTo(1, 16226.20, 16257.00, 13.20, 1.65);
	return true;

}




};

void AddSC_mmowning_commandscript()
{
    new mmowning_commandscript();
}