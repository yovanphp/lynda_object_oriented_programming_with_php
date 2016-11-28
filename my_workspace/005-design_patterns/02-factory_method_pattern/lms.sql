CREATE TABLE `lms`.`addresses` (
  `id` INT(11) NOT NULL AUTO_INCREMENT,
  `street_address_1` VARCHAR(45) NOT NULL,
  `street_address_2` VARCHAR(45) NULL,
  `city_name` VARCHAR(45) NOT NULL,
  `subdivision_name` VARCHAR(45) NULL,
  `postal_code` VARCHAR(5) NOT NULL,
  `country_name` VARCHAR(45) NOT NULL,
  `address_type_id` INT(1) NOT NULL,
  `time_created` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `time_updated` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`));
