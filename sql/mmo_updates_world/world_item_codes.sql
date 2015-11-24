CREATE TABLE `item_codes` (
  `code` INT NOT NULL COMMENT '',
  `belohnung` INT NULL COMMENT '',
  `itemanzahl` INT NULL COMMENT '',
  `benutzt` INT NULL COMMENT '',
  `name` VARCHAR(45) NULL COMMENT '',
  `nutzbar` INT NULL COMMENT '',
  PRIMARY KEY (`code`)  COMMENT '');
