/*M!999999\- enable the sandbox mode */ 

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*M!100616 SET @OLD_NOTE_VERBOSITY=@@NOTE_VERBOSITY, NOTE_VERBOSITY=0 */;

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `autocore_char` /*!40100 DEFAULT CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci */;

USE `autocore_char`;
DROP TABLE IF EXISTS `account`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `account` (
  `Id` int(11) unsigned NOT NULL DEFAULT 0,
  `Name` varchar(14) NOT NULL,
  `Level` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `FirstFlags1` int(11) unsigned NOT NULL DEFAULT 0,
  `FirstFlags2` int(11) unsigned NOT NULL DEFAULT 0,
  `FirstFlags3` int(11) unsigned NOT NULL DEFAULT 0,
  `FirstFlags4` int(11) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
DROP TABLE IF EXISTS `character`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `character` (
  `Coid` bigint(20) NOT NULL,
  `AccountId` int(11) unsigned NOT NULL,
  `ActiveVehicleCoid` bigint(20) NOT NULL,
  `Name` varchar(51) NOT NULL,
  `HeadId` int(11) NOT NULL,
  `BodyId` int(11) NOT NULL,
  `HeadDetail1` int(11) NOT NULL,
  `HeadDetail2` int(11) NOT NULL,
  `HelmetId` int(11) NOT NULL,
  `EyesId` int(11) NOT NULL,
  `MouthId` int(11) NOT NULL,
  `HairId` int(11) NOT NULL,
  `PrimaryColor` int(11) unsigned NOT NULL,
  `SecondaryColor` int(11) unsigned NOT NULL,
  `EyesColor` int(11) unsigned NOT NULL,
  `HairColor` int(11) unsigned NOT NULL,
  `SkinColor` int(11) unsigned NOT NULL,
  `SpecialityColor` int(11) unsigned NOT NULL,
  `LastTownId` int(11) NOT NULL DEFAULT -1,
  `LastStationId` int(11) NOT NULL DEFAULT -1,
  `LastStationMapId` int(11) NOT NULL DEFAULT -1,
  `PositionX` float NOT NULL,
  `PositionY` float NOT NULL,
  `PositionZ` float NOT NULL,
  `RotationX` float NOT NULL,
  `RotationY` float NOT NULL,
  `RotationZ` float NOT NULL,
  `RotationW` float NOT NULL,
  `ScaleOffset` float NOT NULL,
  `Level` tinyint(3) unsigned NOT NULL DEFAULT 1,
  `Deleted` bit(1) NOT NULL DEFAULT b'0',
  `CargoWidth` int(11) NOT NULL DEFAULT 24,
  `CargoPageCount` int(11) NOT NULL DEFAULT 13,
  `Credits` bigint(20) NOT NULL DEFAULT 0,
  `CreditDebt` bigint(20) NOT NULL DEFAULT 0,
  `Experience` int(11) NOT NULL DEFAULT 0,
  `SkillPoints` smallint(6) NOT NULL DEFAULT 0,
  `AttributePoints` smallint(6) NOT NULL DEFAULT 0,
  `ResearchPoints` smallint(6) NOT NULL DEFAULT 0,
  `AttributeTech` smallint(6) NOT NULL DEFAULT 0,
  `AttributeCombat` smallint(6) NOT NULL DEFAULT 0,
  `AttributeTheory` smallint(6) NOT NULL DEFAULT 0,
  `AttributePerception` smallint(6) NOT NULL DEFAULT 0,
  PRIMARY KEY (`Coid`),
  UNIQUE KEY `Name Unique` (`Name`),
  KEY `AccountId index` (`AccountId`),
  KEY `FK_character_active_vehicle` (`ActiveVehicleCoid`) USING BTREE,
  CONSTRAINT `FK_character_account` FOREIGN KEY (`AccountId`) REFERENCES `account` (`Id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `FK_character_simple_object` FOREIGN KEY (`Coid`) REFERENCES `simple_object` (`Coid`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
DROP TABLE IF EXISTS `character_completed_mission`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `character_completed_mission` (
  `CharacterCoid` bigint(20) NOT NULL,
  `MissionId` int(11) NOT NULL,
  PRIMARY KEY (`CharacterCoid`,`MissionId`),
  KEY `IX_character_completed_mission_CharacterCoid` (`CharacterCoid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
DROP TABLE IF EXISTS `character_exploration`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `character_exploration` (
  `CharacterCoid` bigint(20) NOT NULL,
  `ContinentId` int(11) NOT NULL,
  `ExploredBits` int(11) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`ContinentId`,`CharacterCoid`) USING BTREE,
  KEY `FK_character_exploration_character` (`CharacterCoid`),
  CONSTRAINT `FK_character_exploration_character` FOREIGN KEY (`CharacterCoid`) REFERENCES `character` (`Coid`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
DROP TABLE IF EXISTS `character_inventory`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `character_inventory` (
  `Id` bigint(20) NOT NULL AUTO_INCREMENT,
  `CharacterCoid` bigint(20) NOT NULL,
  `ItemCoid` bigint(20) NOT NULL,
  `Cbid` int(11) NOT NULL,
  `Type` tinyint(3) unsigned NOT NULL,
  `SlotX` tinyint(3) unsigned NOT NULL,
  `SlotY` tinyint(3) unsigned NOT NULL,
  `Quantity` int(11) NOT NULL DEFAULT 1,
  `IsMissionItem` tinyint(1) NOT NULL DEFAULT 0,
  `InventoryType` tinyint(3) unsigned NOT NULL DEFAULT 1,
  PRIMARY KEY (`Id`),
  UNIQUE KEY `IX_character_inventory_ItemCoid` (`ItemCoid`),
  KEY `IX_character_inventory_CharacterCoid` (`CharacterCoid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
DROP TABLE IF EXISTS `character_learned_skill`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `character_learned_skill` (
  `CharacterCoid` bigint(20) NOT NULL,
  `SkillId` int(11) NOT NULL,
  `Rank` tinyint(3) unsigned NOT NULL,
  PRIMARY KEY (`CharacterCoid`,`SkillId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
DROP TABLE IF EXISTS `character_mission`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `character_mission` (
  `CharacterCoid` bigint(20) NOT NULL,
  `MissionId` int(11) NOT NULL,
  `ActiveObjectiveSequence` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `State` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `ObjectiveProgress` longblob DEFAULT NULL,
  PRIMARY KEY (`CharacterCoid`,`MissionId`),
  KEY `IX_character_mission_CharacterCoid` (`CharacterCoid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
DROP TABLE IF EXISTS `character_mission_completed`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `character_mission_completed` (
  `CharacterCoid` bigint(20) NOT NULL,
  `MissionId` int(11) NOT NULL,
  PRIMARY KEY (`CharacterCoid`,`MissionId`),
  KEY `IX_character_mission_completed_CharacterCoid` (`CharacterCoid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
DROP TABLE IF EXISTS `character_quest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `character_quest` (
  `CharacterCoid` bigint(20) NOT NULL,
  `MissionId` int(11) NOT NULL,
  `ActiveObjectiveSequence` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `State` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `ObjectiveProgress` varbinary(64) DEFAULT NULL,
  PRIMARY KEY (`CharacterCoid`,`MissionId`),
  KEY `IX_character_quest_CharacterCoid` (`CharacterCoid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
DROP TABLE IF EXISTS `character_quickbar`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `character_quickbar` (
  `CharacterCoid` bigint(20) NOT NULL,
  `Slot` tinyint(3) unsigned NOT NULL,
  `ItemCoid` bigint(20) NOT NULL DEFAULT -1,
  `SkillId` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`CharacterCoid`,`Slot`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
DROP TABLE IF EXISTS `character_social`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `character_social` (
  `CharacterCoid` bigint(20) NOT NULL,
  `TargetCoid` bigint(20) NOT NULL,
  `Type` tinyint(3) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`CharacterCoid`,`TargetCoid`),
  KEY `FK_character_social_character_2` (`TargetCoid`),
  CONSTRAINT `FK_character_social_character` FOREIGN KEY (`CharacterCoid`) REFERENCES `character` (`Coid`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `FK_character_social_character_2` FOREIGN KEY (`TargetCoid`) REFERENCES `character` (`Coid`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
DROP TABLE IF EXISTS `character_stats`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `character_stats` (
  `CharacterCoid` bigint(20) NOT NULL,
  `Currency` bigint(20) NOT NULL DEFAULT 0,
  `Experience` int(11) NOT NULL DEFAULT 0,
  `CurrentMana` smallint(6) NOT NULL DEFAULT 100,
  `MaxMana` smallint(6) NOT NULL DEFAULT 100,
  `AttributeTech` smallint(6) NOT NULL DEFAULT 0,
  `AttributeCombat` smallint(6) NOT NULL DEFAULT 0,
  `AttributeTheory` smallint(6) NOT NULL DEFAULT 0,
  `AttributePerception` smallint(6) NOT NULL DEFAULT 0,
  `AttributePoints` smallint(6) NOT NULL DEFAULT 0,
  `SkillPoints` smallint(6) NOT NULL DEFAULT 0,
  `ResearchPoints` smallint(6) NOT NULL DEFAULT 0,
  PRIMARY KEY (`CharacterCoid`),
  CONSTRAINT `FK_character_stats_character` FOREIGN KEY (`CharacterCoid`) REFERENCES `character` (`Coid`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
DROP TABLE IF EXISTS `clan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `clan` (
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `Name` varchar(51) NOT NULL,
  `MOTD` varchar(251) NOT NULL,
  `Rank1` varchar(51) NOT NULL,
  `Rank2` varchar(51) NOT NULL,
  `Rank3` varchar(51) NOT NULL,
  `MonthlyDues` int(11) NOT NULL,
  `MonthlyUpkeep` int(11) NOT NULL,
  PRIMARY KEY (`Id`),
  UNIQUE KEY `Name Unique` (`Name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
DROP TABLE IF EXISTS `clan_member`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `clan_member` (
  `ClanId` int(11) NOT NULL,
  `CharacterCoid` bigint(20) NOT NULL,
  `Rank` int(11) NOT NULL,
  PRIMARY KEY (`ClanId`,`CharacterCoid`),
  KEY `FK_clan_member_character` (`CharacterCoid`),
  CONSTRAINT `FK_clan_member_character` FOREIGN KEY (`CharacterCoid`) REFERENCES `character` (`Coid`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `FK_clan_member_clan` FOREIGN KEY (`ClanId`) REFERENCES `clan` (`Id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
DROP TABLE IF EXISTS `simple_object`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `simple_object` (
  `Coid` bigint(20) NOT NULL AUTO_INCREMENT,
  `Type` tinyint(3) unsigned NOT NULL,
  `CBID` int(11) NOT NULL,
  `Faction` int(11) NOT NULL,
  `TeamFaction` int(11) NOT NULL,
  PRIMARY KEY (`Coid`)
) ENGINE=InnoDB AUTO_INCREMENT=29 DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
DROP TABLE IF EXISTS `vehicle`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `vehicle` (
  `Coid` bigint(20) NOT NULL,
  `CharacterCoid` bigint(20) NOT NULL,
  `Name` varchar(33) NOT NULL,
  `PositionX` float NOT NULL,
  `PositionY` float NOT NULL,
  `PositionZ` float NOT NULL,
  `RotationX` float NOT NULL,
  `RotationY` float NOT NULL,
  `RotationZ` float NOT NULL,
  `RotationW` float NOT NULL,
  `Ornament` bigint(20) NOT NULL,
  `RaceItem` bigint(20) NOT NULL,
  `PowerPlant` bigint(20) NOT NULL,
  `Wheelset` bigint(20) NOT NULL,
  `Armor` bigint(20) NOT NULL,
  `MeleeWeapon` bigint(20) NOT NULL,
  `Front` bigint(20) NOT NULL,
  `Turret` bigint(20) NOT NULL,
  `Rear` bigint(20) NOT NULL,
  `PrimaryColor` int(11) unsigned NOT NULL,
  `SecondaryColor` int(11) unsigned NOT NULL,
  `Trim` tinyint(3) unsigned NOT NULL,
  `CurrentHP` int(11) NOT NULL DEFAULT -1,
  `CurrentShield` int(11) NOT NULL DEFAULT -1,
  `CurrentPower` int(11) NOT NULL DEFAULT -1,
  `CurrentHeat` int(11) NOT NULL DEFAULT -1,
  PRIMARY KEY (`Coid`) USING BTREE,
  UNIQUE KEY `Name Unique` (`Name`) USING BTREE,
  KEY `FK_vehicle_character` (`CharacterCoid`) USING BTREE,
  CONSTRAINT `FK_vehicle_character` FOREIGN KEY (`CharacterCoid`) REFERENCES `character` (`Coid`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `FK_vehicle_simple_object` FOREIGN KEY (`Coid`) REFERENCES `simple_object` (`Coid`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*M!100616 SET NOTE_VERBOSITY=@OLD_NOTE_VERBOSITY */;

