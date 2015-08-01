#include "ScriptPCH.h"

class teleportitem : public ItemScript
{
	public:
		teleportitem() : ItemScript("teleportitem"){}

		boolean OnPlayerUse(Player * pPlayer, Item *, SpellCastTargets const&)
		{
			pPlayer->TeleportTo(0, -9773.22, 2125.16, 15.49, 3.47, 0.0f);
			return true;
		}
};


void AddSC_teleportitem()
{
	new teleportitem();
}