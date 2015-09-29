-- Wandervolk Questender
UPDATE `quest_template` SET `RequiredNpcOrGo2`='0', `RequiredNpcOrGoCount2`='0' WHERE `ID`='800005';
REPLACE INTO `creature_questender` (`id`, `quest`) VALUES ('800027', '900800');
REPLACE INTO `creature_questender` (`id`, `quest`) VALUES ('800027', '900801');

/* LIGHT HARDMODE LOOTANPASSUNG */
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES ('800063', '46964', '0', '25', '0', '4', '5', '1', '1');
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES ('800063', '46991', '0', '25', '0', '4', '5', '1', '1');
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES ('800063', '46993', '0', '25', '0', '4', '5', '1', '1');
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES ('800063', '46986', '0', '25', '0', '4', '5', '1', '1');
UPDATE `creature_loot_template` SET `LootMode`='5' WHERE `Entry`='800063' and`Item`='50300';

--Ende

-- Bitty Frostschleuder FLAGGER
UPDATE `creature_template` SET `npcflag`='3' WHERE `entry`='32690';

--Kupferpulver Quest Itemcountanpassung
UPDATE `quest_template` SET `RequiredItemCount1`='30' WHERE `ID`='800513';
