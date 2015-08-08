#include "ScriptPCH.h"

class port_item : public ItemScript
{
	public:
		port_item() : ItemScript("teleportitem"){}

		boolean Onuse(Player * player, Item *, SpellCastTargets const&)
		{
			player->TeleportTo(0, -9773.22, 2125.16, 15.49, 3.47, 0.0f);
			return true;
		}
};


void AddSC_port_item()
{
	new port_item;
}