DELETE FROM `game_event` WHERE `eventEntry` = 72;
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `description`, `world_event`)
VALUES (72, '2015-09-19 12:40:00', '2030-11-10 20:00:00', '4320', '600', '0','Das Wandervolk', '0');

DELETE FROM `game_event_npcflag` WHERE `eventEntry` = '72';
INSERT INTO `game_event_npcflag` (`eventEntry`, `guid`, `npcflag`) VALUES ('72', '800027', '4227');

DELETE FROM `game_event_creature_quest` WHERE `eventEntry` = 72;
INSERT INTO `game_event_creature_quest` (`eventEntry`, `id`, `quest`) VALUES 
('72', '800015', '900800'),
('72', '800027', '900801');

DELETE FROM `game_event_creature` WHERE `eventEntry` = 72;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES 
('72', '800070'),
('72', '800071'),
('72', '800072'),
('72', '800073'),
('72', '800074'),
('72', '800075'),
('72', '800076'),
('72', '800077'),
('72', '800078'),
('72', '800079'),
('72', '800080'),
('72', '800081'),
('72', '800082'),
('72', '800083'),
('72', '800084'),
('72', '800085'),
('72', '800086'),
('72', '800087'),
('72', '800088');



