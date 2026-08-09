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

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `autocore_auth` /*!40100 DEFAULT CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci */;

USE `autocore_auth`;
DROP TABLE IF EXISTS `account`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `account` (
  `Id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `Email` varchar(255) NOT NULL,
  `Username` varchar(14) NOT NULL,
  `Password` varchar(64) NOT NULL,
  `Salt` varchar(40) NOT NULL,
  `Level` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `LastIP` tinytext DEFAULT NULL,
  `LastServerId` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `LastLogin` datetime(6) DEFAULT NULL,
  `JoinDate` timestamp NOT NULL DEFAULT current_timestamp(),
  `Locked` bit(1) NOT NULL DEFAULT b'0',
  `Validated` bit(1) NOT NULL DEFAULT b'0',
  `ValidationToken` varchar(40) DEFAULT NULL,
  PRIMARY KEY (`Id`),
  UNIQUE KEY `Unique_Email` (`Email`),
  UNIQUE KEY `Unique_Username` (`Username`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
DROP TABLE IF EXISTS `discord_account_link`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `discord_account_link` (
  `Id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `DiscordUserId` bigint(20) unsigned NOT NULL,
  `AccountId` int(10) unsigned NOT NULL,
  `CreatedAt` datetime(6) NOT NULL,
  `CreatedByUsername` longtext DEFAULT NULL,
  PRIMARY KEY (`Id`),
  UNIQUE KEY `IX_discord_account_link_AccountId` (`AccountId`),
  KEY `IX_discord_account_link_DiscordUserId` (`DiscordUserId`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
DROP TABLE IF EXISTS `global_server`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `global_server` (
  `Id` tinyint(3) unsigned NOT NULL,
  `Password` varchar(50) NOT NULL DEFAULT '',
  `Enabled` bit(1) NOT NULL,
  PRIMARY KEY (`Id`)
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

