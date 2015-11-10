DELETE FROM `game_event` WHERE `eventEntry` = 75;
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `description`, `world_event`)
VALUES (75, '2015-10-21 21:00:00', '2030-11-10 20:00:00', '5760', '20160', '0','DoppeltXP', '0');

DELETE FROM `game_event` WHERE `eventEntry` = 76;
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `description`, `world_event`)
VALUES (76, '2015-11-15 21:00:00', '2030-11-10 20:00:00', '5760', '20160', '0','DoppeltPVP', '0');