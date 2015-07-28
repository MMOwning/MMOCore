DELETE FROM `creature_template` WHERE `entry` = 800035;
DELETE FROM `creature_loot_template` WHERE `Entry` = 800035;

REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800035, 52006, 0, 1, 0, 1, 0, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800035, 38186, 0, 1, 0, 1, 0, 2, 5);


REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800035, 37258, 0, 100, 0, 1, 1, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800035, 37256, 0, 50, 0, 1, 1, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800035, 37257, 0, 50, 0, 1, 1, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800035, 37255, 0, 80, 0, 1, 1, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800035, 37363, 0, 70, 0, 1, 1, 1, 1); 

REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800035, 37261, 0, 60, 0, 1, 2, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800035, 37262, 0, 50, 0, 1, 2, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800035, 37263, 0, 100, 0, 1, 2, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800035, 37260, 0, 40, 0, 1, 2, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800035, 37361, 0, 20, 0, 1, 2, 1, 1); 

REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800035, 37362, 0, 90, 0, 1, 3, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800035, 37364, 0, 85, 0, 1, 3, 1, 1);
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800035, 37360, 0, 100, 0, 1, 3, 1, 1);




DELETE FROM `creature_template` WHERE `entry` = 800035;
REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`,`faction` ,`npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) 
VALUES ( /*  ID */ 800035,
  /* Dificculty 1 */0,
  /* Dif2  */ 0,
  /* Dif3 */0,
  /* KillCredit1  */0,
  /* KillCredit2  */0,
  /* Modelid  */21601,
  /* Modelid2  */0,
  /* Modelid3   */0,
  /* Model4  */ 0,
  /* Name  */'Arcturus',
  /* Subname */'Herrscher der Kälte',
  /* Iconname */'',
  /* gossip_menu_id`  */800035,
  /* Min Level */80,
  /* Max Level  */80,
  /* Exp */0,
  21,
  /* npcflag Was ist er Questgeber oder weiteres? */0,
  /* Speedwalk */0,
  /* speedrun */ 1.14286,
  /* scale */1,
  /* rank  Normal, Elite?*/3,
  /* dmgschool Normal Holy Fire? */0,
  /* BaseAttackTime`  */5000,
  /* RangeAttackTime`  */2000,
  /* Welche Klasse? Krieger Pala, also Mana oder kein MAna? */0,
  /* unit flkag */0,
  /* unit flags2  */0,
  /* dynamicflag */0,
  /* Family  */0,
  /* Trainer type */0,
  /* trainer spell */0,
  /* trainer class */0,
  /* trainer race  */0,
  /* type  */0,
  /* type flag  */ 0,
  /* lootid */0,
  /* pickpocketloot` */0,
  /* Skinloot*/ 0,  
  /* Restistance1  */100,
  /*   */100,
  /*   */100,
  /*   */100,
  /*   */100,
  /*  Resi 6*/100,
  /* spell1  */0, 
  /*   */0,
  /*   */0,
  /*   */0, 
  /*   */0, 
  /*   */0, 
  /*   */0, 
  /*  Spell8 */0, 
  /*  Petspelldataid */0, 
  /*  VehicleId` */ 0, 
  /*  mingold`  */3000000, 
  /*  MaxGold  */ 9000000, 
  /*  AiName */'AggresorAI',
  /*  Movement Type */1, 
  /*  Inahbit Type   */1, 
  /*  Hoverheight */0, 
  /*  Racial Leader  */0,
  /*  movement id  */ 0, 
  /*  RegenHealth`` */1, 
  /*  mechanic_immune_mask` */617299839, 
  /*  flags_extra` */0, 
  /*  Scriptname  */'');


REPLACE INTO `creature`(`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES 
('800035','800035','571','1','1','21601','-1','2979.50','-5771.17','258.16','3.377','20000','0','0','1000000000','25000000','1');

UPDATE `creature_template` SET `HealthModifier`='1100', `ArmorModifier`='2', `DamageModifier`='50' WHERE `entry`='800035';

DELETE FROM `creature_text` WHERE `entry`=800035;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800035,1,0,'Ihr kleinen Wichte. Spürt meine Kälte',14,0,100,5,0,0,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800035,2,0,'Hier gibt es nichts als Schmerz für Euch',14,0,100,5,0,0,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800035,3,0,'Keine Spielchen jetzt! Sterbt!',14,0,100,5,0,0,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800035,7,0,'Eine Trophäe mehr an meiner Wand!',14,0,100,5,0,0,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800035,4,0,'Phase 1',41,0,100,5,0,0,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800035,5,0,'Phase 2',41,0,100,5,0,0,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800035,6,0,'Phase 3',41,0,100,5,0,0,'Comment');

-- Arcturus
SET @ENTRY := 800035;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,2,0,100,1,5,6,0,0,11,71049,4,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Blistering_Cold1"),
(@ENTRY,@SOURCETYPE,1,0,2,0,100,0,25,30,25000,35000,11,69649,2,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Frost_Breath"),
(@ENTRY,@SOURCETYPE,2,0,2,0,40,0,60,95,1000,5000,11,63757,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Thunder_Clap_Phase_1"),
(@ENTRY,@SOURCETYPE,3,0,2,0,100,1,1,10,0,0,11,68335,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Enrage_@_10%"),
(@ENTRY,@SOURCETYPE,4,0,2,0,100,1,3,4,0,0,11,71049,4,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Blistering_Cold2"),
(@ENTRY,@SOURCETYPE,5,0,2,0,100,1,1,2,0,0,11,71049,4,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Blistering_Cold3"),
(@ENTRY,@SOURCETYPE,6,0,2,0,60,0,31,60,5500,7500,11,70399,2,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Ice_Spike"),
(@ENTRY,@SOURCETYPE,7,0,2,0,100,1,99,100,0,0,1,1,1,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"yell_1"),
(@ENTRY,@SOURCETYPE,8,0,2,0,100,1,55,60,0,0,1,3,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"yell_2"),
(@ENTRY,@SOURCETYPE,9,0,2,0,100,1,5,10,0,0,1,2,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"yell_3"),
(@ENTRY,@SOURCETYPE,10,0,2,0,100,1,99,100,0,0,1,4,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"emote_1"),
(@ENTRY,@SOURCETYPE,11,0,2,0,100,1,59,60,0,0,1,5,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"emote_2"),
(@ENTRY,@SOURCETYPE,12,0,2,0,100,1,29,31,0,0,1,6,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"emote_3"),
(@ENTRY,@SOURCETYPE,13,0,2,0,50,0,35,60,15000,20000,11,63757,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Thunder_Clap_Phase_2"),
(@ENTRY,@SOURCETYPE,14,0,2,0,60,0,10,30,15000,20000,11,63757,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Thunder_Clap_Phase_3"),
(@ENTRY,@SOURCETYPE,15,0,5,0,100,1,10,1,0,0,1,7,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"on_kill");/*Boss Nerubischer Kommandant */

DELETE FROM `creature_loot_template` WHERE `Entry` = 800036;

REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800036, 45624, 0, 100, 0, 1, 0, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800036, 49426, 0, 100, 0, 1, 0, 1, 1);
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800036, 38186, 0, 1, 0, 1, 0, 1, 3);


REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800036, 37217, 0, 50, 0, 1, 1, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800036, 37216, 0, 50, 0, 1, 1, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800036, 37257, 0, 50, 0, 1, 1, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800036, 37255, 0, 50, 0, 1, 1, 1, 1); 

REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800036, 21524, 0, 50, 0, 1, 2, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800036, 21525, 0, 50, 0, 1, 2, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800036, 37361, 0, 50, 0, 1, 2, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800036, 37362, 0, 50, 0, 1, 2, 1, 1); 

REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800036, 37364, 0, 50, 0, 1, 3, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800036, 37290, 0, 50, 0, 1, 3, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800036, 40511, 0, 50, 0, 1, 3, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800036, 40489, 0, 50, 0, 1, 3, 1, 1); 




DELETE FROM `creature` WHERE `guid` = 800036;

REPLACE INTO `creature`(`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES 
('800036','800036','571','1','1','27394','-1','3486.27','-691.05','369.14','3.81','20000','0','0','1000000000','25000000','1');

DELETE FROM `creature_template` WHERE `entry` = 800036;
REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction`,`npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) 
VALUES ( /*  ID */ 800036,
  /*  Dificculty 1 */0,
 /* Dif2  */ 0,
  /*  Dif3 */0,
  /* KillCredit1  */0,
  /*  KillCredit2  */0,
  /* Modelid  */27394,
  /* Modelid2  */0,
  /* Modelid3   */0,
  /* Model4  */ 0,
 /* Name  */'Nerubischer Kommandant',
  /*  Subname */'Diener eines Herrschers',
  /*  Iconname */'',
  /* gossip_menu_id`  */0,
  /*  Min Level */80,
  /* Max Level  */80,
  /*  Exp */0,
  21,
  /*  npcflag Was ist er Questgeber oder weiteres? */0,
  /*  Speedwalk */2,
 /*  speedrun */ 2.14286,
  /*  scale */1,
  /*  rank  Normal, Elite?*/3,
  /*  dmgschool Normal Holy Fire? */0,
  /* BaseAttackTime`  */5000,
  /* RangeAttackTime`  */4000,
  /*  Welche Klasse? Krieger Pala, also Mana oder kein MAna? */0,
  /*  unit flag */0,
  /*  unit flags2  */0,
  /*  dynamicflag */0,
  /* Family  */0,
  /*  Trainer type */0,
  /*  trainer spell */0,
  /*  trainer class */0,
  /* trainer race  */7,
  /* type  */0,
  /* type flag  */ 0,
  /*  lootid */800036,
  /*  pickpocketloot` */0,
/*Skinloot*/ 0,  
  /* Restistance1  */100,
  /*   */100,
  /*   */100,
  /*   */100,
  /*   */100,
  /*  Resi 6*/100,
  /* spell1  */0, 
  /*   */0,
  /*   */0,
  /*   */0, 
  /*   */0, 
  /*   */0, 
  /*   */0, 
  /*  Spell8 */0, 
  /*  Petspelldataid */0, 
 /*   VehicleId` */ 0, 
  /* mingold`  */8000000, 
  /* MaxGold  */9000000, 
  /*  AiName */'AggresorAI',
  /*  Movement Type */1, 
  /*Inhabit Type   */1, 
  /*  Hoverheight */1, 
  /* Racial Leader  */0,
 /* movement id  */ 0, 
  /*  RegenHealth`` */1, 
  /*  mechanic_immune_mask` */617299839, 
  /*  flags_extra` */0, 
  /* Scriptname  */'');
UPDATE `creature_template` SET `HealthModifier`='450', `ArmorModifier`='2', `DamageModifier`='40' WHERE `entry`='800036';

  
  
DELETE FROM `creature_text` WHERE `entry`=800036;
REPLACE INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800036,1,0,'Wer möchte gegen mich bestehen?',14,0,100,1,0,17457,'Comment');
REPLACE INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800036,2,0,'Ihr Wenigen wollt gegen mich standhalten?',14,0,100,1,0,17458,'Comment');
REPLACE INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800036,3,0,'Ahh sehr schön. Unterstützung.',14,0,100,1,0,17459,'Comment');
REPLACE INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800036,4,0,'Merkt Euch meine Worte!',14,0,100,1,0,17460,'Comment');
REPLACE INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800036,7,0,'Ich .... kann ...nicht tot sein. Arrgh Ich komme wieder!',14,0,100,1,0,17460,'Comment');
REPLACE INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800036,5,0,'Erzittert vor meiner Angst',41,0,100,1,0,0,'Comment');
REPLACE INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800036,6,0,'Und es wird schlimmer',41,0,100,1,0,0,'Comment');

SET @ENTRY := 800036;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
REPLACE INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,
/*  id */  1,
/* link  */0,
/* event_type*/2,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags   */0,
/* event_param1  */10,
/* event_param2  */40,
/* event_param3  */12000,
/* event_param4  */13000,
/* action_type   */11,
/* action_param1 */74398,
/* action_param2 */0,
/* action_param3 */0,
/* action_param4 */0,
/* action_param5 */0,
/* action_param6 */0,
/* target_type   */5,
/* target_param1 */0,
/* target_param2 */0,
/* target_param3 */0,
/* target_x  */0.0,
/* target_y  */0.0,
/* target_z  */0.0,
/* target_o  */0.0,
/* comment  */"Summon"),

/* SAY */
(@ENTRY,@SOURCETYPE,/*  id */14,/* link  */0,/* event_type*/2,/* event_phase_mask */0,/* event_chance  */100,/* event_flags  */1,/* event_param1 */60,/* event_param2  */95,/* event_param3   */0,/* event_param4 */0,/* action_type  */1,/*ActionType 1*/1,/* action_param2 */0,/* action_param3 */0,/* action_param4 */0,/* action_param5 */0,/* action_param6 */0,/* target_type  */2,/* target_param1 */0,/* target_param2*/0,/* target_param3  */0,/* target_x  */0.0,/* target_y   */0.0,/* target_z  */0.0,/* target_o */0.0,/* comment  */"Yell 1"),

(@ENTRY,@SOURCETYPE,2,0,2,0,100,0,75,80,10000,13000,11,/*58907*/0,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"FEAR"),
(@ENTRY,@SOURCETYPE,3,0,2,0,100,1,60,70,0,0,11,/*70821*/0,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"FRENZY"),
(@ENTRY,@SOURCETYPE,4,0,2,0,100,0,50,60,7000,8000,11,/*72999*/0,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"CHAIN_LIGHTNING"),
(@ENTRY,@SOURCETYPE,5,0,2,0,100,1,40,50,0,0,11,/*71405*/0,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"BLISTERING_COLD"),
(@ENTRY,@SOURCETYPE,8,0,2,0,100,0,10,20,6000,7000,11,/*69108*/0,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"SINBEAM"),
(@ENTRY,@SOURCETYPE,10,0,2,0,100,1,1,10,0,0,11,/*68335*/0,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Enrage at 10%"),
(@ENTRY,@SOURCETYPE,11,0,2,0,100,0,80,90,10000,69140,11,5649,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Stunning Blast "),
(@ENTRY,@SOURCETYPE,12,0,2,0,100,1,30,40,0,0,11,66046,2,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Shield Block"),
(@ENTRY,@SOURCETYPE,13,0,2,0,100,0,1,10,9000,10000,11,/*71255*/0,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"BLIZZARD"),
(@ENTRY,@SOURCETYPE,14,0,2,0,100,1,60,95,0,0,1,1,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Yell 1"),
(@ENTRY,@SOURCETYPE,15,0,2,0,100,1,75,80,0,0,1,2,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Yell 2"),
(@ENTRY,@SOURCETYPE,16,0,2,0,100,1,20,30,0,0,1,3,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Yell 3"),
(@ENTRY,@SOURCETYPE,17,0,2,0,100,1,1,5,0,0,1,4,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Yell 4"),
(@ENTRY,@SOURCETYPE,18,0,2,0,100,1,90,100,0,0,11,/*54237*/0,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Dark Barrage"),
(@ENTRY,@SOURCETYPE,19,0,2,0,100,0,80,87,12000,13000,11,68989,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Knochenstachel"),
(@ENTRY,@SOURCETYPE,20,0,2,0,100,1,70,80,0,0,11,59971,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Rain of Fire"),
(@ENTRY,@SOURCETYPE,21,0,2,0,100,1,60,70,15000,18000,11,70492,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Draw Soul"),
(@ENTRY,@SOURCETYPE,22,0,2,0,100,0,50,60,8000,9000,11,41131,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Flame Burst"),
(@ENTRY,@SOURCETYPE,23,0,2,0,100,0,40,50,13000,15000,11,41545,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Soul Scream"),
(@ENTRY,@SOURCETYPE,24,0,2,0,100,1,55,100,0,0,1,5,1,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Emote 5"),
(@ENTRY,@SOURCETYPE,25,0,2,0,100,1,1,50,0,0,1,6,1,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Emote 6"),
(@ENTRY,@SOURCETYPE,27,0,2,0,100,0,25,35,8000,9000,11,/*68989*/0,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Knochenstachel"),
(@ENTRY,@SOURCETYPE,28,0,2,0,100,0,20,30,8000,9000,11,56431,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Arcane Bomb"),
(@ENTRY,@SOURCETYPE,30,0,2,0,100,1,1,0,0,0,1,7,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Yell 5"),
(@ENTRY,@SOURCETYPE,32,0,25,0,100,0,0,0,0,0,41,/*58907*/1000,0,0,0,0,0,9,39814,0,5000,0.0,0.0,0.0,0.0,"FEAR"),
(@ENTRY,@SOURCETYPE,31,0,2,0,100,0,5,10,8000,9000,11,72934,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Sartahrion");









DELETE FROM `creature_template` WHERE `entry` = 800037;
DELETE FROM `creature_loot_template` WHERE `Entry` = 800037;

REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800037, 52006, 0, 1, 0, 1, 0, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800037, 38186, 0, 1, 0, 1, 0, 15, 50);


REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800037, 47850, 0, 25, 0, 1, 1, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800037, 47853, 0, 25, 0, 1, 1, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800037, 47851, 0, 25, 0, 1, 1, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800037, 47856, 0, 25, 0, 1, 1, 1, 1); 

REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800037, 47910, 0, 25, 0, 1, 2, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800037, 47896, 0, 25, 0, 1, 2, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800037, 47894, 0, 25, 0, 1, 2, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800037, 47646, 0, 25, 0, 1, 2, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800037, 47629, 0, 25, 0, 1, 2, 1, 1); 

REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`,`faction` ,`npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) 
VALUES ( /*  ID */ 800037,
  /* Dificculty 1 */0,
  /* Dif2  */ 0,
  /* Dif3 */0,
  /* KillCredit1  */0,
  /* KillCredit2  */0,
  /* Modelid  */17894,
  /* Modelid2  */0,
  /* Modelid3   */0,
  /* Model4  */ 0,
  /* Name  */'Kayoula',
  /* Subname */'Exitares verschollene Frau',
  /* Iconname */'',
  /* gossip_menu_id`  */800037,
  /* Min Level */83,
  /* Max Level  */83,
  /* Exp */0,
  21,
  /* npcflag Was ist er Questgeber oder weiteres? */0,
  /* Speedwalk */0,
  /* speedrun */ 1.14286,
  /* scale */1,
  /* rank  Normal, Elite?*/3,
  /* dmgschool Normal Holy Fire? */0,
  /* BaseAttackTime`  */5000,
  /* RangeAttackTime`  */2000,
  /* Welche Klasse? Krieger Pala, also Mana oder kein MAna? */0,
  /* unit flkag */0,
  /* unit flags2  */0,
  /* dynamicflag */0,
  /* Family  */0,
  /* Trainer type */0,
  /* trainer spell */0,
  /* trainer class */0,
  /* trainer race  */0,
  /* type  */0,
  /* type flag  */ 0,
  /* lootid */800037,
  /* pickpocketloot` */0,
  /* Skinloot*/ 0,  
  /* Restistance1  */100,
  /*   */100,
  /*   */100,
  /*   */100,
  /*   */100,
  /*  Resi 6*/100,
  /* spell1  */0, 
  /*   */0,
  /*   */0,
  /*   */0, 
  /*   */0, 
  /*   */0, 
  /*   */0, 
  /*  Spell8 */0, 
  /*  Petspelldataid */0, 
  /*  VehicleId` */ 0, 
  /*  mingold`  */3000000, 
  /*  MaxGold  */ 9000000, 
  /*  AiName */'AggresorAI',
  /*  Movement Type */1, 
  /*  Inahbit Type   */1, 
  /*  Hoverheight */0, 
  /*  Racial Leader  */0,
  /*  movement id  */ 0, 
  /*  RegenHealth`` */1, 
  /*  mechanic_immune_mask` */617299839, 
  /*  flags_extra` */0, 
  /*  Scriptname  */'');




UPDATE `creature_template` SET `HealthModifier`='5500', `ArmorModifier`='20', `DamageModifier`='160' WHERE `entry`='800037';

 REPLACE INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES 
('800037','800037','530','1','1','17894','0','-2743.78','503.41','-26.74','2.46','250000','0','0','1000000','250000','0');



DELETE FROM `creature_text` WHERE `entry`=800037;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800037,1,0,'Oh schön. Neue Kundschaft.',14,0,100,5,0,0,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800037,2,0,'Hahaha. Ihr kitzelt mich.',14,0,100,5,0,0,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800037,3,0,'Ihr müsst viel lernen.',14,0,100,5,0,0,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800037,4,0,'Habt ihr niemand anderen, dem ihr auf die Nerven gehen könnt?',14,0,100,5,0,0,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800037,5,0,'Phase 1',41,0,100,5,0,0,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800037,6,0,'Phase 2',41,0,100,5,0,0,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800037,7,0,'Phase 3',41,0,100,5,0,0,'Comment');


SET @ENTRY := 800037;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,
/*  id */  1,
/* link  */0,
/* event_type*/0,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags  */0,
/* event_param1 */95,
/* event_param2  */100,
/* event_param3   */12000,
/* event_param4 */13000,
/* action_type  */11,
/* action_param1 */69021,
/* action_param2 */2,
/* action_param3  */0,
/* action_param4  */0,
/* action_param5  */0,
/* action_param6 */0,
/* target_type  */2,
/* target_param1 */0,
/* target_param2*/0,
/* target_param3  */0,
/* target_x  */0.0,
/* target_y   */0.0,
/* target_z  */0.0,
/* target_o */0.0,
/* comment  */"SPELL_MIGHTY_KICK"),

(@ENTRY,@SOURCETYPE,
/*  id */  2,
/* link  */0,
/* event_type*/0,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags  */0,
/* event_param1 */20,
/* event_param2  */80,
/* event_param3   */5000,
/* event_param4 */13000,
/* action_type  */11,
/* action_param1 */70381,
/* action_param2 */2,
/* action_param3  */0,
/* action_param4  */0,
/* action_param5  */0,
/* action_param6 */0,
/* target_type  */3,
/* target_param1 */0,
/* target_param2*/0,
/* target_param3  */0,
/* target_x  */0.0,
/* target_y   */0.0,
/* target_z  */0.0,
/* target_o */0.0,
/* comment  */"SPELL_DEEP_FREEZE "),

(@ENTRY,@SOURCETYPE,
/*  id */  3,
/* link  */0,
/* event_type*/0,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags  */0,
/* event_param1 */10,
/* event_param2  */95,
/* event_param3   */5000,
/* event_param4 */13000,
/* action_type  */11,
/* action_param1 */66824,
/* action_param2 */2,
/* action_param3  */0,
/* action_param4  */0,
/* action_param5  */0,
/* action_param6 */0,
/* target_type  */2,
/* target_param1 */0,
/* target_param2*/0,
/* target_param3  */0,
/* target_x  */0.0,
/* target_y   */0.0,
/* target_z  */0.0,
/* target_o */0.0,
/* comment  */"SPELL_PARALYTIC_BITE "),


(@ENTRY,@SOURCETYPE,
/*  id */  4,
/* link  */0,
/* event_type*/5,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags  */0,
/* event_param1 */1,
/* event_param2  */10,
/* event_param3   */1,
/* event_param4 */0,
/* action_type  */11,
/* action_param1 */74398,
/* action_param2 */2,
/* action_param3  */0,
/* action_param4  */0,
/* action_param5  */0,
/* action_param6 */0,
/* target_type  */5,
/* target_param1 */0,
/* target_param2*/0,
/* target_param3  */0,
/* target_x  */0.0,
/* target_y   */0.0,
/* target_z  */0.0,
/* target_o */0.0,
/* comment  */"Summon"),


(@ENTRY,@SOURCETYPE,
/*  id */  5,
/* link  */0,
/* event_type*/2,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags  */0,
/* event_param1 */80,
/* event_param2  */81,
/* event_param3   */8000,
/* event_param4 */15000,
/* action_type  */11,
/* action_param1 */69845,
/* action_param2 */1,
/* action_param3  */0,
/* action_param4  */0,
/* action_param5  */0,
/* action_param6 */0,
/* target_type  */6,
/* target_param1 */0,
/* target_param2*/0,
/* target_param3  */0,
/* target_x  */0.0,
/* target_y   */0.0,
/* target_z  */0.0,
/* target_o */0.0,
/* comment  */"SPELL_FROST_BOMB"),

(@ENTRY,@SOURCETYPE,
/*  id */  6,
/* link  */0,
/* event_type*/0,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags  */0,
/* event_param1 */70,
/* event_param2  */80,
/* event_param3   */8000,
/* event_param4 */13000,
/* action_type  */11,
/* action_param1 */62522,
/* action_param2 */2,
/* action_param3  */0,
/* action_param4  */0,
/* action_param5  */0,
/* action_param6 */0,
/* target_type  */6,
/* target_param1 */0,
/* target_param2*/0,
/* target_param3  */0,
/* target_x  */0.0,
/* target_y   */0.0,
/* target_z  */0.0,
/* target_o */0.0,
/* comment  */"SPELL_ELECTROSHOCK"),

(@ENTRY,@SOURCETYPE,7,0,2,0,100,1,99,100,0,0,1,1,1,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"yell_1"),
(@ENTRY,@SOURCETYPE,8,0,2,0,100,1,55,60,0,0,1,3,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"yell_2"),
(@ENTRY,@SOURCETYPE,9,0,2,0,100,1,5,10,0,0,1,2,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"yell_3"),
(@ENTRY,@SOURCETYPE,10,0,2,0,100,1,35,40,0,0,1,4,1,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"yell_4"),

(@ENTRY,@SOURCETYPE,
/*  id */  11,
/* link  */0,
/* event_type*/0,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags  */0,
/* event_param1 */20,
/* event_param2  */80,
/* event_param3   */8000,
/* event_param4 */13000,
/* action_type  */11,
/* action_param1 */69024,
/* action_param2 */1,
/* action_param3  */0,
/* action_param4  */0,
/* action_param5  */0,
/* action_param6 */0,
/* target_type  */6,
/* target_param1 */0,
/* target_param2*/0,
/* target_param3  */0,
/* target_x  */0.0,
/* target_y   */0.0,
/* target_z  */0.0,
/* target_o */0.0,
/* comment  */"SPELL_TOXIC_WASTE"),

(@ENTRY,@SOURCETYPE,
/*  id */  12,
/* link  */0,
/* event_type*/2,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags  */0,
/* event_param1 */60,
/* event_param2  */61,
/* event_param3   */8000,
/* event_param4 */15000,
/* action_type  */11,
/* action_param1 */69845,
/* action_param2 */1,
/* action_param3  */0,
/* action_param4  */0,
/* action_param5  */0,
/* action_param6 */0,
/* target_type  */6,
/* target_param1 */0,
/* target_param2*/0,
/* target_param3  */0,
/* target_x  */0.0,
/* target_y   */0.0,
/* target_z  */0.0,
/* target_o */0.0,
/* comment  */"SPELL_FROST_BOMB"),


(@ENTRY,@SOURCETYPE,
/*  id */  13,
/* link  */0,
/* event_type*/2,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags  */0,
/* event_param1 */40,
/* event_param2  */41,
/* event_param3   */8000,
/* event_param4 */15000,
/* action_type  */11,
/* action_param1 */69845,
/* action_param2 */1,
/* action_param3  */0,
/* action_param4  */0,
/* action_param5  */0,
/* action_param6 */0,
/* target_type  */6,
/* target_param1 */0,
/* target_param2*/0,
/* target_param3  */0,
/* target_x  */0.0,
/* target_y   */0.0,
/* target_z  */0.0,
/* target_o */0.0,
/* comment  */"SPELL_FROST_BOMB"),


(@ENTRY,@SOURCETYPE,
/*  id */  14,
/* link  */0,
/* event_type*/2,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags  */0,
/* event_param1 */20,
/* event_param2  */21,
/* event_param3   */8000,
/* event_param4 */15000,
/* action_type  */11,
/* action_param1 */69845,
/* action_param2 */1,
/* action_param3  */0,
/* action_param4  */0,
/* action_param5  */0,
/* action_param6 */0,
/* target_type  */6,
/* target_param1 */0,
/* target_param2*/0,
/* target_param3  */0,
/* target_x  */0.0,
/* target_y   */0.0,
/* target_z  */0.0,
/* target_o */0.0,
/* comment  */"SPELL_FROST_BOMB"),

(@ENTRY,@SOURCETYPE,
/*  id */  15,
/* link  */0,
/* event_type*/2,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags  */0,
/* event_param1 */ 10,
/* event_param2  */ 11,
/* event_param3   */8000,
/* event_param4 */15000,
/* action_type  */11,
/* action_param1 */69845,
/* action_param2 */1,
/* action_param3  */0,
/* action_param4  */0,
/* action_param5  */0,
/* action_param6 */0,
/* target_type  */6,
/* target_param1 */0,
/* target_param2*/0,
/* target_param3  */0,
/* target_x  */0.0,
/* target_y   */0.0,
/* target_z  */0.0,
/* target_o */0.0,
/* comment  */"SPELL_FROST_BOMB"),

(@ENTRY,@SOURCETYPE,
/*  id */  16,
/* link  */0,
/* event_type*/5,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags  */0,
/* event_param1 */1,
/* event_param2  */10,
/* event_param3   */1,
/* event_param4 */0,
/* action_type  */11,
/* action_param1 */74398,
/* action_param2 */2,
/* action_param3  */0,
/* action_param4  */0,
/* action_param5  */0,
/* action_param6 */0,
/* target_type  */5,
/* target_param1 */0,
/* target_param2*/0,
/* target_param3  */0,
/* target_x  */0.0,
/* target_y   */0.0,
/* target_z  */0.0,
/* target_o */0.0,
/* comment  */"Summon"),


(@ENTRY,@SOURCETYPE,
/*  id */  17,
/* link  */0,
/* event_type*/0,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags  */0,
/* event_param1 */40,
/* event_param2  */80,
/* event_param3   */25000,
/* event_param4 */30000,
/* action_type  */11,
/* action_param1 */74398,
/* action_param2 */2,
/* action_param3  */0,
/* action_param4  */0,
/* action_param5  */0,
/* action_param6 */0,
/* target_type  */2,
/* target_param1 */0,
/* target_param2*/0,
/* target_param3  */0,
/* target_x  */0.0,
/* target_y   */0.0,
/* target_z  */0.0,
/* target_o */0.0,
/* comment  */"Summon");




DELETE FROM `creature_template` WHERE `entry` = 800038;
DELETE FROM `creature_loot_template` WHERE `Entry` = 800038;

REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800038, 49284, 0, 0.1, 0, 1, 0, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800038, 21176, 0, 0.1, 0, 1, 0, 1, 1);


REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800038, 47617, 0, 70, 0, 1, 1, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800038, 47649, 0, 100,0, 1, 1, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800038, 47630, 0, 70, 0, 1, 1, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800038, 49908, 0, 55, 0, 1, 1, 1, 4); 

REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800038, 56806, 0, 0.5, 0, 1, 2, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800038, 49426, 0, 70, 0, 1, 2, 1, 2); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800038, 47241, 0,100, 0, 1, 2, 1, 3); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800038, 36928, 0, 70, 0, 1, 2, 3, 5); 

REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800038, 51336, 0, 70, 0, 1, 3, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800038, 51358, 0, 70, 0, 1, 3, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800038, 51377, 0, 70, 0, 1, 3, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800038, 51378, 0, 70, 0, 1, 3, 1, 1); 

REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`,`faction` ,`npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) 
VALUES ( /*  ID */ 800038,
  /* Dificculty 1 */0,
  /* Dif2  */ 0,
  /* Dif3 */0,
  /* KillCredit1  */0,
  /* KillCredit2  */0,
  /* Modelid  */20512,
  /* Modelid2  */0,
  /* Modelid3   */0,
  /* Model4  */ 0,
  /* Name  */'Tempus Schatten',
  /* Subname */'',
  /* Iconname */'',
  /* gossip_menu_id`  */800038,
  /* Min Level */80,
  /* Max Level  */80,
  /* Exp */0,
  21,
  /* npcflag Was ist er Questgeber oder weiteres? */0,
  /* Speedwalk */0,
  /* speedrun */ 1.14286,
  /* scale */1,
  /* rank  Normal, Elite?*/3,
  /* dmgschool Normal Holy Fire? */0,
  /* BaseAttackTime`  */5000,
  /* RangeAttackTime`  */2000,
  /* Welche Klasse? Krieger Pala, also Mana oder kein MAna? */2,
  /* unit flkag */0,
  /* unit flags2  */0,
  /* dynamicflag */0,
  /* Family  */0,
  /* Trainer type */0,
  /* trainer spell */0,
  /* trainer class */0,
  /* trainer race  */0,
  /* type  */0,
  /* type flag  */ 0,
  /* lootid */800038,
  /* pickpocketloot` */0,
  /* Skinloot*/ 0,  
  /* Restistance1  */100,
  /*   */100,
  /*   */100,
  /*   */100,
  /*   */100,
  /*  Resi 6*/100,
  /* spell1  */0, 
  /*   */0,
  /*   */0,
  /*   */0, 
  /*   */0, 
  /*   */0, 
  /*   */0, 
  /*  Spell8 */0, 
  /*  Petspelldataid */0, 
  /*  VehicleId` */ 0, 
  /*  mingold`  */3000000, 
  /*  MaxGold  */ 9000000, 
  /*  AiName */'AggresorAI',
  /*  Movement Type */1, 
  /*  Inahbit Type   */1, 
  /*  Hoverheight */0, 
  /*  Racial Leader  */0,
  /*  movement id  */ 0, 
  /*  RegenHealth`` */1, 
  /*  mechanic_immune_mask` */617299839, 
  /*  flags_extra` */0, 
  /*  Scriptname  */'');




UPDATE `creature_template` SET `HealthModifier`='4000', `ArmorModifier`='20', `DamageModifier`='120' WHERE `entry`='800038';

 REPLACE INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES 
('800038','800038','1','1','1','20512','0','-8117.64','1605.21','13.99','6.25','250000','0','0','1000000','250000','0');



DELETE FROM `creature_text` WHERE `entry`=800038;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800038,1,0,'Willkommen! Ich habe Euch erwartet.',14,0,100,5,0,0,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800038,2,0,'Eine nette kleine Runde hier. Fast wie damals.',14,0,100,5,0,0,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800038,3,0,'Wer ist euer Anführer?',14,0,100,5,0,0,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800038,4,0,'Ihr seid so erbärmlich',14,0,100,5,0,0,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800038,5,0,'Phase 1',41,0,100,5,0,0,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800038,6,0,'Phase 2',41,0,100,5,0,0,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800038,7,0,'Phase 3',41,0,100,5,0,0,'Comment');


SET @ENTRY := 800038;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
REPLACE INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,
/*  id */  1,
/* link  */0,
/* event_type*/2,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags   */0,
/* event_param1  */99,
/* event_param2  */100,
/* event_param3  */12000,
/* event_param4  */13000,
/* action_type   */11,
/* action_param1 */53210,
/* action_param2 */0,
/* action_param3 */0,
/* action_param4 */0,
/* action_param5 */0,
/* action_param6 */0,
/* target_type   */5,
/* target_param1 */0,
/* target_param2 */0,
/* target_param3 */0,
/* target_x  */0.0,
/* target_y  */0.0,
/* target_z  */0.0,
/* target_o  */0.0,
/* comment  */"Apocalyspe"),

/* SAY */
(@ENTRY,@SOURCETYPE,/*  id */14,/* link  */0,/* event_type*/2,/* event_phase_mask */0,/* event_chance  */100,/* event_flags  */1,/* event_param1 */60,/* event_param2  */95,/* event_param3   */0,/* event_param4 */0,/* action_type  */1,/*ActionType 1*/1,/* action_param2 */0,/* action_param3 */0,/* action_param4 */0,/* action_param5 */0,/* action_param6 */0,/* target_type  */2,/* target_param1 */0,/* target_param2*/0,/* target_param3  */0,/* target_x  */0.0,/* target_y   */0.0,/* target_z  */0.0,/* target_o */0.0,/* comment  */"Yell 1"),


(@ENTRY,@SOURCETYPE,4,0,2,0,100,0,50,60,7000,8000,11,40504,2,0,0,0,0,6,0,0,0,0.0,0.0,0.0,0.0,"Ruby"),
(@ENTRY,@SOURCETYPE,5,0,2,0,100,0,40,50,0,0,11,70123,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"BLISTERING_COLD"),
(@ENTRY,@SOURCETYPE,8,0,0,0,100,0,1,100,10000,15000,11,74367,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Rüstung_spalten"),
(@ENTRY,@SOURCETYPE,10,0,2,0,100,1,1,8,0,0,11,68335,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Enrage_@_8%"),
(@ENTRY,@SOURCETYPE,11,0,2,0,100,0,70,75,10000,69140,11,72363,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"SPELL_CORRUPTED_FLESH"),
(@ENTRY,@SOURCETYPE,12,0,2,0,100,1,30,40,0,0,11,40504,2,0,0,0,0,6,0,0,0,0.0,0.0,0.0,0.0,"Ruby"),
(@ENTRY,@SOURCETYPE,13,0,2,0,100,0,1,10,9000,10000,11,70123,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"BLISTERING_COLD"),
(@ENTRY,@SOURCETYPE,14,0,2,0,100,1,60,95,0,0,1,1,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Yell 1"),
(@ENTRY,@SOURCETYPE,15,0,2,0,100,1,75,80,0,0,1,2,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Yell 2"),
(@ENTRY,@SOURCETYPE,16,0,2,0,100,1,20,30,0,0,1,3,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Yell 3"),
(@ENTRY,@SOURCETYPE,17,0,2,0,100,1,1,5,0,0,1,4,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Yell 4"),
(@ENTRY,@SOURCETYPE,18,0,2,0,100,1,90,100,8000,13000,11,68982,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Phantomschlag"),
(@ENTRY,@SOURCETYPE,19,0,2,0,100,0,80,87,12000,13000,11,70425,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Kettenblitz"),
(@ENTRY,@SOURCETYPE,20,0,0,0,100,1,60,70,0,0,11,74398,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Summon"),
(@ENTRY,@SOURCETYPE,21,0,2,0,100,1,60,70,15000,18000,11,40504,2,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Ruby"),
(@ENTRY,@SOURCETYPE,22,0,2,0,100,0,50,60,8000,9000,11,40504,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Ruby"),
(@ENTRY,@SOURCETYPE,23,0,2,0,100,0,40,50,13000,15000,11,49034,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"SPELL_BLIZZARD"),
(@ENTRY,@SOURCETYPE,32,0,2,0,100,0,1,10,13000,15000,11,36911,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Eisblock"),
(@ENTRY,@SOURCETYPE,24,0,2,0,100,1,55,100,0,0,1,5,1,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Emote 5"),
(@ENTRY,@SOURCETYPE,25,0,2,0,100,1,1,50,0,0,1,6,1,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Emote 6"),
(@ENTRY,@SOURCETYPE,27,0,2,0,100,0,1,5,8000,9000,11,26662,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"SPELL_BERSERK"),
(@ENTRY,@SOURCETYPE,28,0,2,0,100,0,20,30,8000,9000,11,59658,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Argentumsheldentum"),
(@ENTRY,@SOURCETYPE,31,0,2,0,100,0,5,10,8000,9000,11,41367,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Gotteschild");
DELETE FROM `creature_template` WHERE `entry` = 800039;
DELETE FROM `creature_loot_template` WHERE `Entry` = 800039;

REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800039, 52006, 0, 1, 0, 1, 0, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800039, 38186, 0, 1, 0, 1, 0, 5, 25);


REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800039, 47248, 0, 25, 0, 1, 1, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800039, 47172, 0, 25, 0, 1, 1, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800039, 47493, 0, 25, 0, 1, 1, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800039, 47249, 0, 25, 0, 1, 1, 1, 1); 

REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800039, 47522, 0, 25, 0, 1, 2, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800039, 47512, 0, 25, 0, 1, 2, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800039, 47202, 0, 25, 0, 1, 2, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800039, 47508, 0, 12.5, 0, 1, 2, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800039, 47230, 0, 12.5, 0, 1, 2, 1, 1); 

REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`,`faction` ,`npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) 
VALUES ( /*  ID */ 800039,
  /* Dificculty 1 */0,
  /* Dif2  */ 0,
  /* Dif3 */0,
  /* KillCredit1  */0,
  /* KillCredit2  */0,
  /* Modelid  */16694,
  /* Modelid2  */0,
  /* Modelid3   */0,
  /* Model4  */ 0,
  /* Name  */'Moon',
  /* Subname */'Die abtrünnige Sammlerin',
  /* Iconname */'',
  /* gossip_menu_id`  */800039,
  /* Min Level */83,
  /* Max Level  */83,
  /* Exp */0,
  21,
  /* npcflag Was ist er Questgeber oder weiteres? */0,
  /* Speedwalk */0,
  /* speedrun */ 1.14286,
  /* scale */1,
  /* rank  Normal, Elite?*/3,
  /* dmgschool Normal Holy Fire? */0,
  /* BaseAttackTime`  */5000,
  /* RangeAttackTime`  */2000,
  /* Welche Klasse? Krieger Pala, also Mana oder kein MAna? */0,
  /* unit flkag */0,
  /* unit flags2  */0,
  /* dynamicflag */0,
  /* Family  */0,
  /* Trainer type */0,
  /* trainer spell */0,
  /* trainer class */0,
  /* trainer race  */0,
  /* type  */0,
  /* type flag  */ 0,
  /* lootid */800039,
  /* pickpocketloot` */0,
  /* Skinloot*/ 0,  
  /* Restistance1  */100,
  /*   */100,
  /*   */100,
  /*   */100,
  /*   */100,
  /*  Resi 6*/100,
  /* spell1  */0, 
  /*   */0,
  
  /*   */0,
  /*   */0, 
  /*   */0, 
  /*   */0, 
  /*   */0, 
  /*  Spell8 */0, 
  /*  Petspelldataid */0, 
  /*  VehicleId` */ 0, 
  /*  mingold`  */3000000, 
  /*  MaxGold  */ 9000000, 
  /*  AiName */'AggresorAI',
  /*  Movement Type */1, 
  /*  Inahbit Type   */1, 
  /*  Hoverheight */0, 
  /*  Racial Leader  */0,
  /*  movement id  */ 0, 
  /*  RegenHealth`` */1, 
  /*  mechanic_immune_mask` */617299839, 
  /*  flags_extra` */0, 
  /*  Scriptname  */'');




UPDATE `creature_template` SET `HealthModifier`='3200', `ArmorModifier`='50', `DamageModifier`='110' WHERE `entry`='800039';

REPLACE INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES 
('800039','800039','0','1','1','16694','0','-12535.60','-2674.06','89.30','6.18','250000','0','0','1000000','250000','0');



DELETE FROM `creature_text` WHERE `entry`=800039;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800039,1,0,'Die Sammler müssen vernichtet werden.',14,0,100,5,0,0,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800039,2,0,'Niemand hat verdient am Leben zu bleiben',14,0,100,5,0,0,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800039,3,0,'Ich werde die Insel säubern.',14,0,100,5,0,0,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800039,4,0,'Habt ihr niemand anderen, dem ihr auf die Nerven gehen könnt?',14,0,100,5,0,0,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800039,5,0,'Phase 1',41,0,100,5,0,0,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800039,6,0,'Phase 2',41,0,100,5,0,0,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800039,7,0,'Phase 3',41,0,100,5,0,0,'Comment');


SET @ENTRY := 800039;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,
/*  id */  1,
/* link  */0,
/* event_type*/0,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags  */0,
/* event_param1 */95,
/* event_param2  */100,
/* event_param3   */20000,
/* event_param4 */25000,
/* action_type  */11,
/* action_param1 */30101,
/* action_param2 */2,
/* action_param3  */0,
/* action_param4  */0,
/* action_param5  */0,
/* action_param6 */0,
/* target_type  */6,
/* target_param1 */0,
/* target_param2*/0,
/* target_param3  */0,
/* target_x  */0.0,
/* target_y   */0.0,
/* target_z  */0.0,
/* target_o */0.0,
/* comment  */"SPELL_FROST_MISSILE"),

(@ENTRY,@SOURCETYPE,
/*  id */  2,
/* link  */0,
/* event_type*/0,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags  */0,
/* event_param1 */1,
/* event_param2  */100,
/* event_param3   */30000,
/* event_param4 */45000,
/* action_type  */11,
/* action_param1 */68839,
/* action_param2 */2,
/* action_param3  */0,
/* action_param4  */0,
/* action_param5  */0,
/* action_param6 */0,
/* target_type  */6,
/* target_param1 */0,
/* target_param2*/0,
/* target_param3  */0,
/* target_x  */0.0,
/* target_y   */0.0,
/* target_z  */0.0,
/* target_o */0.0,
/* comment  */"SPELL_CORRUPT_SOUL"),

(@ENTRY,@SOURCETYPE,
/*  id */  3,
/* link  */0,
/* event_type*/2,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags  */0,
/* event_param1 */1,
/* event_param2  */95,
/* event_param3   */15000,
/* event_param4 */20000,
/* action_type  */11,
/* action_param1 */18392,
/* action_param2 */2,
/* action_param3  */0,
/* action_param4  */0,
/* action_param5  */0,
/* action_param6 */0,
/* target_type  */6,
/* target_param1 */0,
/* target_param2*/0,
/* target_param3  */0,
/* target_x  */0.0,
/* target_y   */0.0,
/* target_z  */0.0,
/* target_o */0.0,
/* comment  */"SPELL_FIREBALL"),

(@ENTRY,@SOURCETYPE,
/*  id */  4,
/* link  */0,
/* event_type*/2,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags  */0,
/* event_param1 */60,
/* event_param2  */80,
/* event_param3   */30000,
/* event_param4 */65000,
/* action_type  */11,
/* action_param1 */37335,
/* action_param2 */2,
/* action_param3  */0,
/* action_param4  */0,
/* action_param5  */0,
/* action_param6 */0,
/* target_type  */2,
/* target_param1 */0,
/* target_param2*/0,
/* target_param3  */0,
/* target_x  */0.0,
/* target_y   */0.0,
/* target_z  */0.0,
/* target_o */0.0,
/* comment  */"SPELL_SHEAR"),


(@ENTRY,@SOURCETYPE,
/*  id */  5,
/* link  */0,
/* event_type*/2,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags  */0,
/* event_param1 */1,
/* event_param2  */75,
/* event_param3   */30000,
/* event_param4 */60000,
/* action_type  */11,
/* action_param1 */40276,
/* action_param2 */2,
/* action_param3  */0,
/* action_param4  */0,
/* action_param5  */0,
/* action_param6 */0,
/* target_type  */5,
/* target_param1 */0,
/* target_param2*/0,
/* target_param3  */0,
/* target_x  */0.0,
/* target_y   */0.0,
/* target_z  */0.0,
/* target_o */0.0,
/* comment  */"SPELL_VOLCANIC_SUMMON"),

(@ENTRY,@SOURCETYPE,
/*  id */  6,
/* link  */0,
/* event_type*/2,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags  */0,
/* event_param1 */50,
/* event_param2  */65,
/* event_param3   */30000,
/* event_param4 */45000,
/* action_type  */11,
/* action_param1 */55813,
/* action_param2 */2,
/* action_param3  */0,
/* action_param4  */0,
/* action_param5  */0,
/* action_param6 */0,
/* target_type  */2,
/* target_param1 */0,
/* target_param2*/0,
/* target_param3  */0,
/* target_x  */0.0,
/* target_y   */0.0,
/* target_z  */0.0,
/* target_o */0.0,
/* comment  */"SPELL_ECK_BITE"),


(@ENTRY,@SOURCETYPE,
/*  id */  7,
/* link  */0,
/* event_type*/2,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags  */0,
/* event_param1 */20,
/* event_param2  */25,
/* event_param3   */30000,
/* event_param4 */45000,
/* action_type  */11,
/* action_param1 */65874,
/* action_param2 */2,
/* action_param3  */0,
/* action_param4  */0,
/* action_param5  */0,
/* action_param6 */0,
/* target_type  */5,
/* target_param1 */0,
/* target_param2*/0,
/* target_param3  */0,
/* target_x  */0.0,
/* target_y   */0.0,
/* target_z  */0.0,
/* target_o */0.0,
/* comment  */"SPELL_DARK_SHIELD"),

(@ENTRY,@SOURCETYPE,
/*  id */  8,
/* link  */0,
/* event_type*/2,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags  */0,
/* event_param1 */10,
/* event_param2  */45,
/* event_param3   */30000,
/* event_param4 */45000,
/* action_type  */11,
/* action_param1 */69508,
/* action_param2 */2,
/* action_param3  */0,
/* action_param4  */0,
/* action_param5  */0,
/* action_param6 */0,
/* target_type  */5,
/* target_param1 */0,
/* target_param2*/0,
/* target_param3  */0,
/* target_x  */0.0,
/* target_y   */0.0,
/* target_z  */0.0,
/* target_o */0.0,
/* comment  */"SPELL_SLIME_SPRAY"),

(@ENTRY,@SOURCETYPE,
/*  id */  9,
/* link  */0,
/* event_type*/2,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags  */0,
/* event_param1 */10,
/* event_param2  */70,
/* event_param3   */30000,
/* event_param4 */45000,
/* action_type  */11,
/* action_param1 */72172,
/* action_param2 */2,
/* action_param3  */0,
/* action_param4  */0,
/* action_param5  */0,
/* action_param6 */0,
/* target_type  */6,
/* target_param1 */0,
/* target_param2*/0,
/* target_param3  */0,
/* target_x  */0.0,
/* target_y   */0.0,
/* target_z  */0.0,
/* target_o */0.0,
/* comment  */"SPELL_SUMMON_BLOOD_BEAST"),

(@ENTRY,@SOURCETYPE,
/*  id */  10,
/* link  */0,
/* event_type*/2,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags  */0,
/* event_param1 */1,
/* event_param2  */10,
/* event_param3   */30000,
/* event_param4 */45000,
/* action_type  */11,
/* action_param1 */70702,
/* action_param2 */2,
/* action_param3  */0,
/* action_param4  */0,
/* action_param5  */0,
/* action_param6 */0,
/* target_type  */6,
/* target_param1 */0,
/* target_param2*/0,
/* target_param3  */0,
/* target_x  */0.0,
/* target_y   */0.0,
/* target_z  */0.0,
/* target_o */0.0,
/* comment  */"SPELL_COLUMN_OF_FROST_DAMAGE"),

(@ENTRY,@SOURCETYPE,11,0,2,0,100,1,1,5,0,0,11,68335,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Enrage_@_5%"),
(@ENTRY,@SOURCETYPE,12,0,2,0,100,1,99,100,0,0,1,1,1,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"yell_1"),
(@ENTRY,@SOURCETYPE,13,0,2,0,100,1,55,60,0,0,1,3,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"yell_2"),
(@ENTRY,@SOURCETYPE,14,0,2,0,100,1,5,10,0,0,1,2,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"yell_3"),
(@ENTRY,@SOURCETYPE,15,0,2,0,100,1,35,40,0,0,1,4,1,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"yell_4"),

(@ENTRY,@SOURCETYPE,
/*  id */  16,
/* link  */0,
/* event_type*/2,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags  */0,
/* event_param1 */30,
/* event_param2  */70,
/* event_param3   */30000,
/* event_param4 */45000,
/* action_type  */11,
/* action_param1 */72172,
/* action_param2 */2,
/* action_param3  */0,
/* action_param4  */0,
/* action_param5  */0,
/* action_param6 */0,
/* target_type  */6,
/* target_param1 */0,
/* target_param2*/0,
/* target_param3  */0,
/* target_x  */0.0,
/* target_y   */0.0,
/* target_z  */0.0,
/* target_o */0.0,
/* comment  */"SPELL_SUMMON_BLOOD_BEAST"),

(@ENTRY,@SOURCETYPE,
/*  id */  17,
/* link  */0,
/* event_type*/2,
/* event_phase_mask */0,
/* event_chance  */100,
/* event_flags  */0,
/* event_param1 */30,
/* event_param2  */70,
/* event_param3   */30000,
/* event_param4 */45000,
/* action_type  */11,
/* action_param1 */72172,
/* action_param2 */2,
/* action_param3  */0,
/* action_param4  */0,
/* action_param5  */0,
/* action_param6 */0,
/* target_type  */6,
/* target_param1 */0,
/* target_param2*/0,
/* target_param3  */0,
/* target_x  */0.0,
/* target_y   */0.0,
/* target_z  */0.0,
/* target_o */0.0,
/* comment  */"SPELL_SUMMON_BLOOD_BEAST");

DELETE FROM `creature_template` WHERE `entry` = 800040;
DELETE FROM `creature_loot_template` WHERE `Entry` = 800040;


REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800040, 52006, 0, 1, 0, 1, 0, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800040, 38186, 0, 1, 0, 1, 0, 5, 25);


REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800040, 49323, 0, 25, 0, 1, 1, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800040, 49327, 0, 25, 0, 1, 1, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800040, 49318, 0, 25, 0, 1, 1, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800040, 49316, 0, 25, 0, 1, 1, 1, 1); 

REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800040, 49320, 0, 25, 0, 1, 2, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800040, 49296, 0, 25, 0, 1, 2, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800040, 49305, 0, 25, 0, 1, 2, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800040, 49303, 0, 12.5, 0, 1, 2, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800040, 49437, 0, 12.5, 0, 1, 2, 1, 1); 



REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`,`faction` ,`npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) 
VALUES ( /*  ID */ 800040,
  /* Dificculty 1 */0,
  /* Dif2  */ 0,
  /* Dif3 */0,
  /* KillCredit1  */0,
  /* KillCredit2  */0,
  /* Modelid  */24942,
  /* Modelid2  */0,
  /* Modelid3   */0,
  /* Model4  */ 0,
  /* Name  */'Marltyriun',
  /* Subname */'Der Zerstörer',
  /* Iconname */'',
  /* gossip_menu_id`  */0,
  /* Min Level */83,
  /* Max Level  */83,
  /* Exp */0,
  21,
  /* npcflag Was ist er Questgeber oder weiteres? */0,
  /* Speedwalk */0,
  /* speedrun */ 1.14286,
  /* scale */2,
  /* rank  Normal, Elite?*/3,
  /* dmgschool Normal Holy Fire? */0,
  /* BaseAttackTime`  */5000,
  /* RangeAttackTime`  */2000,
  /* Welche Klasse? Krieger Pala, also Mana oder kein MAna? */0,
  /* unit flkag */0,
  /* unit flags2  */0,
  /* dynamicflag */0,
  /* Family  */0,
  /* Trainer type */0,
  /* trainer spell */0,
  /* trainer class */0,
  /* trainer race  */0,
  /* type  */0,
  /* type flag  */ 0,
  /* lootid */800040,
  /* pickpocketloot` */0,
  /* Skinloot*/ 0,  
  /* Restistance1  */100,
  /*   */100,
  /*   */100,
  /*   */100,
  /*   */100,
  /*  Resi 6*/100,
  /* spell1  */0, 
  /*   */0,
  
  /*   */0,
  /*   */0, 
  /*   */0, 
  /*   */0, 
  /*   */0, 
  /*  Spell8 */0, 
  /*  Petspelldataid */0, 
  /*  VehicleId` */ 0, 
  /*  mingold`  */5000000, 
  /*  MaxGold  */ 9000000, 
  /*  AiName */'AggresorAI',
  /*  Movement Type */1, 
  /*  Inahbit Type   */1, 
  /*  Hoverheight */0, 
  /*  Racial Leader  */0,
  /*  movement id  */ 0, 
  /*  RegenHealth`` */1, 
  /*  mechanic_immune_mask` */617299839, 
  /*  flags_extra` */0, 
  /*  Scriptname  */'');



UPDATE `creature_template` SET `HealthModifier`='600', `ArmorModifier`='50', `DamageModifier`='110' WHERE `entry`='800040';
DELETE FROM `creature` WHERE `guid` = 800040;
REPLACE INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES 
('800040','800040','0','1','1','24942','0','-11715.54','-3627.68','91.95','2.64','20000','0','0','1000000','250000','0');
  
 
DELETE FROM `creature_text` WHERE `entry`=800040;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800040,1,0,'Ihr Verräter. Loyalistenschweine.',14,0,100,1,0,17457,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800040,2,0,'You mortals......you cant...........KILL ME!!',14,0,100,1,0,17458,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800040,3,0,'You are not prepared!',14,0,100,1,0,17459,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800040,4,0,'NO! NO! NO! NO! NO!......Impossible!!',14,0,100,1,0,17460,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800040,5,0,'Phase 1',41,0,100,1,0,0,'Comment');
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES (800040,6,0,'Phase 2',41,0,100,1,0,0,'Comment');
 

SET @ENTRY := 800040;
SET @SOURCETYPE := 0;
 
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,2,0,100,0,90,100,12000,13000,11,46589,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"SHADOW_SPIKE"),
(@ENTRY,@SOURCETYPE,2,0,2,0,100,0,75,80,10000,13000,11,68950,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"FEAR"),
(@ENTRY,@SOURCETYPE,3,0,2,0,100,1,60,70,0,0,11,8269,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"FRENZY"),
(@ENTRY,@SOURCETYPE,4,0,2,0,100,0,50,60,7000,8000,11,33665,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"CHAIN_LIGHTNING"),
(@ENTRY,@SOURCETYPE,5,0,2,0,100,1,40,50,0,0,11,71049,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"BLISTERING_COLD"),
(@ENTRY,@SOURCETYPE,8,0,2,0,100,0,10,20,6000,7000,11,40827,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"SINBEAM"),
(@ENTRY,@SOURCETYPE,10,0,2,0,100,1,1,10,0,0,11,68335,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Enrage at 10%"),
(@ENTRY,@SOURCETYPE,11,0,2,0,100,0,80,90,10000,13000,11,5649,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Stunning Blast "),
(@ENTRY,@SOURCETYPE,12,0,2,0,100,1,30,40,0,0,11,2565,2,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Shield Block"),
(@ENTRY,@SOURCETYPE,13,0,2,0,100,0,1,10,9000,10000,11,26607,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"BLIZZARD"),
(@ENTRY,@SOURCETYPE,14,0,2,0,100,1,60,95,0,0,1,1,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Yell 1"),
(@ENTRY,@SOURCETYPE,15,0,2,0,100,1,40,55,0,0,1,2,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Yell 2"),
(@ENTRY,@SOURCETYPE,16,0,2,0,100,1,20,30,0,0,1,3,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Yell 3"),
(@ENTRY,@SOURCETYPE,17,0,2,0,100,1,1,5,0,0,1,4,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Yell 4"),
(@ENTRY,@SOURCETYPE,18,0,2,0,100,1,90,100,0,0,11,40585,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Dark Barrage"),
(@ENTRY,@SOURCETYPE,19,0,2,0,100,0,80,87,12000,13000,11,21066,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Void Bolt"),
(@ENTRY,@SOURCETYPE,20,0,2,0,100,1,70,80,0,0,11,59971,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Rain of Fire"),
(@ENTRY,@SOURCETYPE,21,0,2,0,100,1,60,70,15000,18000,11,40904,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Draw Soul"),
(@ENTRY,@SOURCETYPE,22,0,2,0,100,0,50,60,8000,9000,11,41131,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Flame Burst"),
(@ENTRY,@SOURCETYPE,23,0,2,0,100,0,40,50,13000,15000,11,41545,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Soul Scream"),
(@ENTRY,@SOURCETYPE,24,0,2,0,100,1,55,100,0,0,1,5,1,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Emote 5"),
(@ENTRY,@SOURCETYPE,25,0,2,0,100,1,1,50,0,0,1,6,1,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Emote 6"),
(@ENTRY,@SOURCETYPE,27,0,2,0,100,0,25,35,8000,9000,11,42052,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Volcanic Geyser"),
(@ENTRY,@SOURCETYPE,28,0,2,0,100,0,20,30,8000,9000,11,56431,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Arcane Bomb");DELETE FROM `creature_template` WHERE `entry` =800041;
DELETE FROM `creature_loot_template` WHERE `Entry` = 800041;

REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800041, 52006, 0, 1, 0, 1, 0, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800041, 38186, 0, 1, 0, 1, 0, 5, 25);


REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800041, 37180, 0, 25, 0, 1, 1, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800041, 35570, 0, 25, 0, 1, 1, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800041, 41793, 0, 25, 0, 1, 1, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800041, 37193, 0, 25, 0, 1, 1, 1, 1); 

REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800041, 41793, 0, 25, 0, 1, 2, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800041, 37186, 0, 25, 0, 1, 2, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800041, 37191, 0, 25, 0, 1, 2, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800041, 37194, 0, 12.5, 0, 1, 2, 1, 1); 
REPLACE INTO `creature_loot_template` (`Entry`,`Item`,`Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`)
VALUES (800041, 49307, 0, 12.5, 0, 1, 2, 1, 1); 


UPDATE `creature_template` SET `HealthModifier`=500, `ArmorModifier`=50, `DamageModifier`=110 WHERE `entry`=800041;

DELETE FROM `creature` WHERE `guid` = 800041;
REPLACE INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES 
('800041','800041','0','1','1','21322','0','-6279.27','-2304.74','398.35','3.34','20000','0','0','1000000','250000','0');

REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`,`faction` ,`npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) 
VALUES ( /*  ID */ 800041,
  /* Dificculty 1 */0,
  /* Dif2  */ 0,
  /* Dif3 */0,
  /* KillCredit1  */0,
  /* KillCredit2  */0,
  /* Modelid  */21322,
  /* Modelid2  */0,
  /* Modelid3   */0,
  /* Model4  */ 0,
  /* Name  */'Lord of Doom',
  /* Subname */'Ein Unbekannter',
  /* Iconname */'',
  /* gossip_menu_id`  */800041,
  /* Min Level */83,
  /* Max Level  */83,
  /* Exp */0,
  21,
  /* npcflag Was ist er Questgeber oder weiteres? */0,
  /* Speedwalk */0,
  /* speedrun */ 1.14286,
  /* scale */0.5,
  /* rank  Normal, Elite?*/3,
  /* dmgschool Normal Holy Fire? */0,
  /* BaseAttackTime`  */5000,
  /* RangeAttackTime`  */2000,
  /* Welche Klasse? Krieger Pala, also Mana oder kein MAna? */0,
  /* unit flkag */0,
  /* unit flags2  */0,
  /* dynamicflag */0,
  /* Family  */0,
  /* Trainer type */0,
  /* trainer spell */0,
  /* trainer class */0,
  /* trainer race  */0,
  /* type  */0,
  /* type flag  */ 0,
  /* lootid */800041,
  /* pickpocketloot` */0,
  /* Skinloot*/ 0,  
  /* Restistance1  */100,
  /*   */100,
  /*   */100,
  /*   */100,
  /*   */100,
  /*  Resi 6*/100,
  /* spell1  */0, 
  /*   */0,
  /*   */0,
  /*   */0,
  /*   */0, 
  /*   */0, 
  /*   */0, 
  /*  Spell8 */0, 
  /*  Petspelldataid */0, 
  /*  VehicleId` */ 0, 
  /*  mingold`  */3000000, 
  /*  MaxGold  */ 9000000, 
  /*  AiName */'SmartAI',
  /*  Movement Type */1, 
  /*  Inahbit Type   */1, 
  /*  Hoverheight */0, 
  /*  Racial Leader  */0,
  /*  movement id  */ 0, 
  /*  RegenHealth`` */1, 
  /*  mechanic_immune_mask` */617299839, 
  /*  flags_extra` */0, 
  /*  Scriptname  */'');

UPDATE `creature_template` SET `HealthModifier`=500, `ArmorModifier`=50, `DamageModifier`=110 WHERE `entry`=800041;


DELETE FROM `creature_text` WHERE `entry` = 800041;
REPLACE INTO  `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES ('800041', '1', '0', 'Ihr seid langweilig. Moment ich hole einen Kaffee.', '14', '0', '100', '5', '0', '0', 'VPP');
REPLACE INTO  `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES ('800041', '2', '0', 'Tötet ihr mich, wird das Konsequenzen nach sich ziehen.', '14', '0', '100', '5', '0', '0', 'VPP');
REPLACE INTO  `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES ('800041', '3', '0', 'Niemals! Bevor ich sterbe, wird der Server ausgemacht.', '14', '0', '100', '5', '0', '0', 'VPP');
REPLACE INTO  `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES ('800041', '4', '0', 'Ich habe Euch gewarnt.', '14', '0', '100', '5', '0', '0', 'VPP');
REPLACE INTO  `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES ('800041', '5', '0', 'Verdammt! Ihr wart zu schnell für mich!', '14', '0', '100', '5', '0', '0', 'VPP');



SET @ENTRY := 800040;
SET @SOURCETYPE := 0;
 
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 800041;
REPLACE INTO  `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) 
VALUES ('800041', '0', '9', '0', '2', '0', '100', '0', '90', '95', '20000', '30000', '11', '3651', '2', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'Boucler NICE !');
REPLACE INTO  `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`)  VALUES ('800041', '0', '7', '0', '2', '0', '100', '0', '32', '40', '20000', '30000', '11', '19645', '2', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'Boucler');
 REPLACE INTO  `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES ('800041', '0', '5', '0', '2', '0', '100', '0', '30', '87', '9000', '12000', '11', '39176', '2', '0', '0', '0', '0', '5', '0', '0', '0', '0', '0', '0', '0', 'FEAR');
REPLACE INTO  `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`)  VALUES ('800041', '0', '6', '0', '2', '0', '100', '0', '1', '99', '5000', '6000', '11', '43114', '2', '0', '0', '0', '0', '6', '0', '0', '0', '0', '0', '0', '0', 'FireWall');
REPLACE INTO  `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`)  VALUES ('800041', '0', '18', '0', '2', '0', '100', '0', '99', '100', '50000', '51000', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'Talk');
 REPLACE INTO  `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES ('800041', '0', '22', '0', '2', '0', '100', '0', '0', '1', '70000', '70000', '1', '5', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'Talk4');
REPLACE INTO  `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`)  VALUES ('800041', '0', '17', '0', '2', '0', '100', '0', '1', '99', '2000', '3500', '11', '11264', '2', '0', '0', '0', '0', '5', '0', '0', '0', '0', '0', '0', '0', 'Ice Blaste');
 REPLACE INTO  `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES ('800041', '0', '8', '0', '2', '0', '100', '0', '1', '99', '5000', '6000', '11', '23169', '2', '0', '0', '0', '0', '5', '0', '0', '0', '0', '0', '0', '0', 'FireWall');
 REPLACE INTO  `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES ('800041', '0', '0', '0', '2', '0', '100', '0', '2', '60', '8000', '8100', '11', '22291', '2', '0', '0', '0', '0', '5', '0', '0', '0', '0', '0', '0', '0', 'CYCLY 70%');
 REPLACE INTO  `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES ('800041', '0', '16', '0', '2', '0', '100', '0', '30', '80', '3000', '5000', '11', '69167', '2', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'Big and big dmg ');
 REPLACE INTO  `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES ('800041', '0', '15', '0', '2', '0', '100', '0', '1', '100', '2000', '3500', '11', '69024', '2', '0', '0', '0', '0', '6', '0', '0', '0', '0', '0', '0', '0', 'Toxic Waste 12 - 1%');
 REPLACE INTO  `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES ('800041', '0', '14', '0', '2', '0', '100', '0', '20', '86', '7000', '9500', '11', '69024', '2', '0', '0', '0', '0', '5', '0', '0', '0', '0', '0', '0', '0', 'Toxic Waste 86 - 20 %');
REPLACE INTO  `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`)  VALUES ('800041', '0', '13', '0', '2', '0', '100', '0', '1', '16', '50000', '60000', '11', '55816', '2', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'BERSRk');
REPLACE INTO  `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`)  VALUES ('800041', '0', '19', '0', '2', '0', '100', '0', '85', '86', '70000', '70000', '1', '2', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'Talk1');
REPLACE INTO  `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`)  VALUES ('800041', '0', '20', '0', '2', '0', '100', '0', '15', '16', '70000', '70000', '1', '3', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'Talk2');
REPLACE INTO  `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`)  VALUES ('800041', '0', '21', '0', '2', '0', '100', '0', '15', '16', '70000', '70000', '1', '4', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'Talk3');
