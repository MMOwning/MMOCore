-- Wandervolk Questender
UPDATE `quest_template` SET `RequiredNpcOrGo2`='0', `RequiredNpcOrGoCount2`='0' WHERE `ID`='800005';
REPLACE INTO `creature_questender` (`id`, `quest`) VALUES ('800027', '900800');
REPLACE INTO `creature_questender` (`id`, `quest`) VALUES ('800027', '900801');

/* LIGHT HARDMODE LOOTANPASSUNG */
REPLACE INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES ('800063', '46964', '0', '25', '0', '4', '5', '1', '1');
REPLACE INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES ('800063', '46991', '0', '25', '0', '4', '5', '1', '1');
REPLACE INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES ('800063', '46993', '0', '25', '0', '4', '5', '1', '1');
REPLACE INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES ('800063', '46986', '0', '25', '0', '4', '5', '1', '1');
UPDATE `creature_loot_template` SET `LootMode`='5' WHERE `Entry`='800063' and`Item`='50300';



-- Bitty Frostschleuder FLAGGER
UPDATE `creature_template` SET `npcflag`='3' WHERE `entry`= '32690';

/*Kupferpulver Quest Itemcountanpassung*/
UPDATE `quest_template` SET `RequiredItemCount1`='30' WHERE `ID`='800513';


/*--Beschreibung Halloweenquest 900503*/
UPDATE `quest_template` SET `LogDescription`='Hey $N, wir wollen ein bisschen Action zu Halloween oder nicht ? Bringt mir 20 Grobes Gorillahaar und 15 Gorillafangzaehne. Geht danach zu Orrig vor Orgrimmar.' WHERE `ID`='900503';


/*--Orrig Halloweenquest Starter*/

DELETE FROM `creature_queststarter` WHERE `id` = 800002 and `quest` = 900504;
DELETE FROM `creature_questender` WHERE `id` = 800002 and `quest` = 900504;
REPLACE INTO `game_event_creature_quest` (`eventEntry`, `id`, `quest`) VALUES ('71', '800002', '900504');
REPLACE INTO `creature_questender` (`id`, `quest`) VALUES ('800002', '900504');

/* Halloweenabzeichen stackable */
UPDATE `item_template` SET `stackable`='100' WHERE `entry`='700520';


/* Quest 900509 auf Daily gesetzt */
UPDATE `quest_template` SET `Flags`='4096' WHERE `ID`='900509';


