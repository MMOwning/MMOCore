#include "AccountMgr.h"
#include "time.h"
#include <stdio.h>
#include "Bag.h"
#include "Mail.h"
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
#include "Guild.h"
#include "Arena.h"
#include "ArenaTeam.h"
#include "ArenaScore.h"



class goldaufbank : public PlayerScript
{

public:
	goldaufbank() : PlayerScript("goldaufbank") { }


	void OnMoneyChanged(Player* pPlayer, int32& gGold)
	{
		bool elite = pPlayer->GetSession()->IsPremium();
		uint32 gildenid = pPlayer->GetGuildId();

		if (gildenid == 0)
		{
			return;
		}

		else
		{
			if (!elite)
			{

				QueryResult ergebnis;
				ergebnis = CharacterDatabase.PQuery("Select bankmoney from `guild` where `guildid` = '%u'", gildenid);
				Field *feld = ergebnis->Fetch();
				uint32 bankmoney = feld[0].GetUInt32();

				uint32 zusatzbetrag = gGold * 0.10;

				uint32 neubetrag = bankmoney + zusatzbetrag;

				CharacterDatabase.PExecute("UPDATE guild SET `bankmoney` = '%u' WHERE `guildid` = '%u'", neubetrag, gildenid);

			}

			else
			{

				QueryResult ergebnis;
				ergebnis = CharacterDatabase.PQuery("Select bankmoney from `guild` where `guildid` = '%u'", gildenid);
				Field *feld = ergebnis->Fetch();
				uint32 bankmoney = feld[0].GetUInt32();

				uint32 zusatzbetrag = gGold * 0.20;

				uint32 neubetrag = bankmoney + zusatzbetrag;

				CharacterDatabase.PExecute("UPDATE guild SET `bankmoney` = '%u' WHERE `guildid` = '%u'", neubetrag, gildenid);

			}

			return;
		}

	}
}; 


// Speed wieder normal setzen?
class totlaufen : public UnitScript
{

public:
	totlaufen() : UnitScript("totlaufen") { }
	
	void OnDamage(Unit* /*attacker*/, Unit*  /*victem*/, uint32& /*damage*/)
	{
		Player* pPlayer = pPlayer->GetSession()->GetPlayer();
		
		uint32 gildenid = pPlayer->GetGuildId();
		if (gildenid == 0)
		{
			return;
		}
		else
		{
			if (pPlayer->isDead() == true)
			{
				if (pPlayer->GetSession()->IsPremium())
				{
					pPlayer->SetSpeed(MOVE_RUN, 4, true);
				}

				else
				{
					pPlayer->SetSpeed(MOVE_RUN, 4, true);
				}

			}

			return;
		}

	}
};





class X : public PlayerScript
{

public:
	X() : PlayerScript("X") { }

};



void AddSC_sb_uebung()
{
	new goldaufbank();
	new totlaufen();
}

