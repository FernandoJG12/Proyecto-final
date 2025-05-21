-- MySQL dump 10.13  Distrib 8.0.42, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: chatbot_anime
-- ------------------------------------------------------
-- Server version	5.5.5-10.4.32-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `conocimiento`
--

DROP TABLE IF EXISTS `conocimiento`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `conocimiento` (
  `pregunta` varchar(255) DEFAULT NULL,
  `respuesta` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `conocimiento`
--

LOCK TABLES `conocimiento` WRITE;
/*!40000 ALTER TABLE `conocimiento` DISABLE KEYS */;
INSERT INTO `conocimiento` VALUES ('Cual es el nombre completo de Goku en Dragon Ball','Son Goku'),('Como se llama el protagonista de Death Note','Light Yagami'),('Cual es el nombre del zorro de nueve colas en Naruto','Kurama'),('Como se llama la organizacion criminal en One Piece','Marines'),('Cual es el nombre del espadachin ciego en Rurouni Kenshin','Hiko Seijuro'),('Como se llama el robot gigante en Neon Genesis Evangelion','Eva'),('Cual es el nombre del hermano menor de Edward Elric en Fullmetal Alchemist','Alphonse Elric'),('Como se llama el deporte que practican en Kuroko no Basket','Baloncesto'),('Cual es el nombre del villano principal en Hunter x Hunter','Meruem'),('Como se llama el mundo de los muertos en Dragon Ball','Otro Mundo'),('Cual es el nombre del estudio que produce Attack on Titan','Wit Studio'),('Como se llama la espada de Ichigo en Bleach','Zangetsu'),('Cual es el nombre de la nave en Cowboy Bebop','Bebop'),('Como se llama el protagonista de One Punch Man','Saitama'),('Cual es el nombre del mejor amigo de Naruto','Sasuke Uchiha'),('Como se llama la tecnica especial de Luffy en One Piece','Gomu Gomu no Pistol'),('Cual es el nombre del dios de la destruccion en Dragon Ball Super','Beerus'),('Como se llama el arma principal en Soul Eater','Guadaña'),('Cual es el nombre del equipo de heroes en My Hero Academia','UA High School'),('Como se llama el gato negro en Fairy Tail','Happy'),('Cual es el nombre del protagonista de Demon Slayer','Tanjiro Kamado'),('Como se llama la hermana de Sailor Moon','Sailor Chibi Moon'),('Cual es el nombre del maestro de Rock Lee en Naruto','Might Guy'),('Como se llama el poder especial en JoJos Bizarre Adventure','Stand'),('Cual es el nombre del dragon en Fairy Tail','Igneel'),('Como se llama el protagonista de Tokyo Ghoul','Ken Kaneki'),('Cual es el nombre del mejor amigo de Deku en My Hero Academia','Katsuki Bakugo'),('Como se llama la organizacion de alquimistas en Fullmetal Alchemist','Ejercito'),('Cual es el nombre del protagonista de Sword Art Online','Kirito'),('Como se llama el mundo virtual en Log Horizon','Elder Tale'),('Cual es el nombre del grupo de piratas en One Piece','Piratas del Sombrero de Paja'),('Como se llama la tecnica de respiracion en Demon Slayer','Respiración del Agua'),('Cual es el nombre del protagonista de Code Geass','Lelouch Lamperouge'),('Como se llama el poder de los personajes en Naruto','Chakra'),('Cual es el nombre del robot gigante en Gurren Lagann','Gurren Lagann'),('Como se llama el protagonista de Steins Gate','Rintaro Okabe'),('Cual es el nombre del mundo en Made in Abyss','Abismo'),('Como se llama la protagonista de Kill la Kill','Ryuko Matoi'),('Cual es el nombre del club en Kaguya-sama Love is War','Consejo Estudiantil'),('Como se llama el poder especial en Fire Force','Piroquinesis'),('Cual es el nombre del protagonista de Mob Psycho 100','Shigeo Kageyama'),('Como se llama el mundo en No Game No Life','Disboard'),('Cual es el nombre del angel en The Melancholy of Haruhi Suzumiya','Itsuki Koizumi'),('Como se llama el poder en A Certain Scientific Railgun','Electromaster'),('Cual es el nombre del protagonista de ReZero','Subaru Natsuki'),('Como se llama la espada en Berserk','Espada del Berserker'),('Cual es el nombre del protagonista de Black Clover','Asta'),('Como se llama el poder en The Rising of the Shield Hero','Escudo Sagrado'),('Cual es el nombre del mundo en Overlord','Nazarick');
/*!40000 ALTER TABLE `conocimiento` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2025-05-19  8:35:13
