class Race_Change_NPC : public CreatureScript
{
public:
	Race_Change_NPC() : CreatureScript("racechange") {  }

	bool OnGossipHello(Player* player, Creature* creature)
	{
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Ich möchte einen Racechange haben.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Ich möchte einen Factionchange haben.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Ich möchte beides haben.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
		player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
		return true;
	}
	bool OnGossipSelect(Player* pPlayer, Creature* creature, uint32 sender, uint32 action){
		pPlayer->PlayerTalkClass->ClearMenus();
		if (sender != GOSSIP_SENDER_MAIN)
			return false;
		switch (action){
		case GOSSIP_ACTION_INFO_DEF + 1:
			pPlayer->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
			pPlayer->PlayerTalkClass->SendCloseGossip();
			ChatHandler(pPlayer->GetSession()).PSendSysMessage("Bitte ausloggen um Änderungen durchzuführen.",
				pPlayer->GetName());
			pPlayer->PlayerTalkClass->SendCloseGossip();
			break;
		case GOSSIP_ACTION_INFO_DEF + 2:
			pPlayer->PlayerTalkClass->SendCloseGossip();
			pPlayer->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
			ChatHandler(pPlayer->GetSession()).PSendSysMessage("Bitte ausloggen um Änderungen durchzuführen.",
				pPlayer->GetName());
			pPlayer->PlayerTalkClass->SendCloseGossip();
			break;
		case GOSSIP_ACTION_INFO_DEF + 3:
			pPlayer->PlayerTalkClass->SendCloseGossip();
			pPlayer->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
			ChatHandler(pPlayer->GetSession()).PSendSysMessage("Bitte ausloggen um Änderungen durchzuführen.",
				pPlayer->GetName());
			pPlayer->PlayerTalkClass->SendCloseGossip();
			break;
		}
		return true;
	}
};

void AddSC_Race_Change_NPC()
{
	new Race_Change_NPC();
}