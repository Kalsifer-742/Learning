# --------------------------------------------------------
# Host:                         127.0.0.1
# Server version:               5.1.36-community-log
# Server OS:                    Win32
# HeidiSQL version:             6.0.0.3622
# Date/time:                    2011-01-07 23:25:28
# --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

# Dumping database structure for mobili_componibili
CREATE DATABASE IF NOT EXISTS `mobili_componibili` /*!40100 DEFAULT CHARACTER SET latin1 */;
USE `mobili_componibili`;

# Dumping structure for table mobili_componibili.categorie
CREATE TABLE IF NOT EXISTS `categorie` (
  `id_categoria` varchar(3) NOT NULL DEFAULT '',
  `descrizione` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`id_categoria`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

# Dumping data for table mobili_componibili.categorie: ~4 rows (approximately)
/*!40000 ALTER TABLE `categorie` DISABLE KEYS */;
INSERT INTO `categorie` (`id_categoria`, `descrizione`) VALUES
	('L10', 'Libreria'),
	('M10', 'Mobile'),
	('M20', 'Armadio'),
	('T10', 'Tavolo');
/*!40000 ALTER TABLE `categorie` ENABLE KEYS */;

# Dumping structure for table mobili_componibili.laboratori
CREATE TABLE IF NOT EXISTS `laboratori` (
  `id_laboratorio` varchar(4) NOT NULL DEFAULT '',
  `indirizzo` varchar(50) DEFAULT NULL,
  `citta` varchar(50) DEFAULT NULL,
  `telefono` varchar(16) DEFAULT NULL,
  PRIMARY KEY (`id_laboratorio`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

# Dumping data for table mobili_componibili.laboratori: ~6 rows (approximately)
/*!40000 ALTER TABLE `laboratori` DISABLE KEYS */;
INSERT INTO `laboratori` (`id_laboratorio`, `indirizzo`, `citta`, `telefono`) VALUES
	('0010', 'Via S. Lucia, 21', 'Firenze', '05513467998'),
	('0020', 'Viale Redi, 3', 'Roma', '062451899'),
	('0030', 'Via Marino, 1', 'Lucca', '058343451'),
	('0040', 'Viale dei Tigli', 'Firenze', '0553379801'),
	('0050', 'Via Bianchi, 3', 'Roma', '066576804'),
	('0060', 'Via dei Poggi, 456', 'Pisa', '05032391');
/*!40000 ALTER TABLE `laboratori` ENABLE KEYS */;


# Dumping structure for table mobili_componibili.componenti
CREATE TABLE IF NOT EXISTS `componenti` (
  `id_componente` varchar(4) NOT NULL DEFAULT '',
  `descrizione` varchar(50) DEFAULT NULL,
  `costo` float DEFAULT NULL,
  `cod_laboratorio` varchar(4) DEFAULT NULL,
  PRIMARY KEY (`id_componente`),
  CONSTRAINT `componenti_ibfk_1` FOREIGN KEY (`cod_laboratorio`) REFERENCES `laboratori` (`id_laboratorio`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

# Dumping data for table mobili_componibili.componenti: ~15 rows (approximately)
/*!40000 ALTER TABLE `componenti` DISABLE KEYS */;
INSERT INTO `componenti` (`id_componente`, `descrizione`, `costo`, `cod_laboratorio`) VALUES
	('0010', 'Montante laterale 100 cm', 50, '0010'),
	('0020', 'Montante laterale 200 cm', 100, '0010'),
	('0030', 'Ripiano 60 cm', 50, '0050'),
	('0040', 'Piano tavolo tondo', 120, '0050'),
	('0050', 'Piano tavolo quadrato', 120, '0050'),
	('0060', 'Gamba tavolo 60 cm', 20, '0020'),
	('0070', 'Gamba tavolo 40 cm', 15, '0020'),
	('0080', 'Anta 100 cm', 80, '0040'),
	('0090', 'Anta 200 cm', 120, '0040'),
	('0100', 'Cassettiera da incasso', 200, '0030'),
	('0110', 'Busta 100 tasselli', 5, NULL),
	('0120', 'Busta 10 viti', 10, NULL),
	('0130', 'Pomello anta/cassetti', 5, '0060'),
	('0140', 'Bastone appendiabiti', 15, '0060'),
	('0150', 'Pannello posteriore 100 cm x 60 cm', 30, '0050');
/*!40000 ALTER TABLE `componenti` ENABLE KEYS */;


# Dumping structure for table mobili_componibili.articoli
CREATE TABLE IF NOT EXISTS `articoli` (
  `id_articolo` varchar(4) NOT NULL DEFAULT '',
  `cod_categoria` varchar(3) DEFAULT NULL,
  `descrizione` varchar(50) DEFAULT NULL,
  `prezzo` float DEFAULT NULL,
  `IVA` tinyint(4) DEFAULT NULL,
  `spese_trasporto` float DEFAULT NULL,
  PRIMARY KEY (`id_articolo`),
  CONSTRAINT `articoli_ibfk_1` FOREIGN KEY (`cod_categoria`) REFERENCES `categorie` (`id_categoria`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

# Dumping data for table mobili_componibili.articoli: ~11 rows (approximately)
/*!40000 ALTER TABLE `articoli` DISABLE KEYS */;
INSERT INTO `articoli` (`id_articolo`, `cod_categoria`, `descrizione`, `prezzo`, `IVA`, `spese_trasporto`) VALUES
	('L100', 'L10', 'Libreria 100 cm x 120 cm', 475, 20, 48),
	('L200', 'L10', 'Libreria 200 cm x 120 cm', 950, 20, 95),
	('M100', 'M10', 'Mobile 1 anta 100 cm x 60 cm', 390, 20, 39),
	('M200', 'M10', 'Mobile 2 ante 100 cm x 120 cm', 720, 20, 72),
	('M300', 'M10', 'Mobile 1 anta + cassetti 100 cm x 120 cm', 785, 20, 0),
	('M_40', 'M20', 'Armadio 2 ante 200 cmx120 cm', 810, 20, 85),
	('M_50', 'M20', 'Armadio 4 ante 200 cm x 240 cm', 1495, 20, 150),
	('T100', 'T10', 'Tavolo tondo', 255, 20, NULL),
	('T200', 'T10', 'Tavolo quadrato', 255, 20, 21),
	('T300', 'T10', 'Tavolo rettangolare', 390, 20, 35),
	('T400', 'T10', 'Tavolino basso da salotto', 196, 20, 19);
/*!40000 ALTER TABLE `articoli` ENABLE KEYS */;



# Dumping structure for table mobili_componibili.componenti_articoli
CREATE TABLE IF NOT EXISTS `componenti_articoli` (
  `cod_articolo` varchar(4) NOT NULL DEFAULT '',
  `cod_componente` varchar(4) NOT NULL DEFAULT '',
  `qta` tinyint(4) DEFAULT NULL,
  PRIMARY KEY (`cod_articolo`,`cod_componente`),
  CONSTRAINT `componenti_articoli_ibfk_1` FOREIGN KEY (`cod_articolo`) REFERENCES `articoli` (`id_articolo`),
  CONSTRAINT `componenti_articoli_ibfk_2` FOREIGN KEY (`cod_componente`) REFERENCES `componenti` (`id_componente`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

# Dumping data for table mobili_componibili.componenti_articoli: ~59 rows (approximately)
/*!40000 ALTER TABLE `componenti_articoli` DISABLE KEYS */;
INSERT INTO `componenti_articoli` (`cod_articolo`, `cod_componente`, `qta`) VALUES
	('L100', '0010', 3),
	('L100', '0030', 6),
	('L100', '0110', 1),
	('L200', '0020', 3),
	('L200', '0030', 12),
	('L200', '0110', 2),
	('L200', '0120', 2),
	('M100', '0010', 2),
	('M100', '0030', 3),
	('M100', '0080', 1),
	('M100', '0110', 1),
	('M100', '0120', 1),
	('M100', '0130', 1),
	('M100', '0150', 1),
	('M200', '0010', 3),
	('M200', '0030', 6),
	('M200', '0080', 2),
	('M200', '0110', 2),
	('M200', '0120', 2),
	('M200', '0150', 2),
	('M300', '0010', 3),
	('M300', '0030', 5),
	('M300', '0080', 1),
	('M300', '0100', 1),
	('M300', '0110', 2),
	('M300', '0120', 1),
	('M300', '0130', 5),
	('M300', '0150', 1),
	('M_40', '0020', 4),
	('M_40', '0030', 4),
	('M_40', '0090', 2),
	('M_40', '0110', 2),
	('M_40', '0120', 2),
	('M_40', '0130', 2),
	('M_40', '0150', 4),
	('M_50', '0020', 3),
	('M_50', '0030', 8),
	('M_50', '0090', 4),
	('M_50', '0110', 3),
	('M_50', '0120', 3),
	('M_50', '0130', 4),
	('M_50', '0140', 2),
	('M_50', '0150', 4),
	('T100', '0040', 1),
	('T100', '0060', 4),
	('T100', '0110', 1),
	('T100', '0120', 1),
	('T200', '0050', 1),
	('T200', '0060', 4),
	('T200', '0110', 1),
	('T200', '0120', 1),
	('T300', '0050', 2),
	('T300', '0060', 4),
	('T300', '0110', 2),
	('T300', '0120', 2),
	('T400', '0050', 1),
	('T400', '0070', 4),
	('T400', '0110', 1),
	('T400', '0120', 1);
/*!40000 ALTER TABLE `componenti_articoli` ENABLE KEYS */;



# Dumping structure for table mobili_componibili.negozi
CREATE TABLE IF NOT EXISTS `negozi` (
  `id_negozio` varchar(4) NOT NULL DEFAULT '',
  `nome` varchar(30) DEFAULT NULL,
  `indirizzo` varchar(50) DEFAULT NULL,
  `citta` varchar(50) DEFAULT NULL,
  `telefono` varchar(16) DEFAULT NULL,
  PRIMARY KEY (`id_negozio`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

# Dumping data for table mobili_componibili.negozi: ~6 rows (approximately)
/*!40000 ALTER TABLE `negozi` DISABLE KEYS */;
INSERT INTO `negozi` (`id_negozio`, `nome`, `indirizzo`, `citta`, `telefono`) VALUES
	('0010', 'CompoLegno', 'Via S. Felice, 2', 'Firenze', '0553232100'),
	('0020', 'EcoMobili', 'Viale Olanda, 33', 'Roma', '065989331'),
	('0030', 'F. Bianchi & C.', 'Via Circeo, 15/B', 'Lucca', '0583446690'),
	('0040', 'MobilMarket', 'L.go S. Severo, 11R', 'Firenze', '0553245781'),
	('0050', 'Micheli', 'Via Landi, 189', 'Roma', NULL),
	('0060', 'Co.M.It.', 'Via dei Pini, 119', 'Trento', '0336390469');
/*!40000 ALTER TABLE `negozi` ENABLE KEYS */;


# Dumping structure for table mobili_componibili.ordini
CREATE TABLE IF NOT EXISTS `ordini` (
  `id_ordine` varchar(6) NOT NULL DEFAULT '',
  `cod_negozio` varchar(4) DEFAULT NULL,
  `data` datetime DEFAULT NULL,
  PRIMARY KEY (`id_ordine`),
  CONSTRAINT `ordini_ibfk_1` FOREIGN KEY (`cod_negozio`) REFERENCES `negozi` (`id_negozio`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

# Dumping data for table mobili_componibili.ordini: ~4 rows (approximately)
/*!40000 ALTER TABLE `ordini` DISABLE KEYS */;
INSERT INTO `ordini` (`id_ordine`, `cod_negozio`, `data`) VALUES
	('001009', '0040', '2009-01-10 00:00:00'),
	('001509', '0010', '2009-01-25 00:00:00'),
	('003209', '0060', '2009-01-25 00:00:00'),
	('004009', '0020', '2009-02-02 00:00:00');
/*!40000 ALTER TABLE `ordini` ENABLE KEYS */;


# Dumping structure for table mobili_componibili.ordini_articoli
CREATE TABLE IF NOT EXISTS `ordini_articoli` (
  `cod_ordine` varchar(6) NOT NULL DEFAULT '',
  `cod_articolo` varchar(4) NOT NULL DEFAULT '',
  `qta` tinyint(4) DEFAULT NULL,
  PRIMARY KEY (`cod_ordine`,`cod_articolo`),
  CONSTRAINT `ordini_articoli_ibfk_1` FOREIGN KEY (`cod_ordine`) REFERENCES `ordini` (`id_ordine`),
  CONSTRAINT `ordini_articoli_ibfk_2` FOREIGN KEY (`cod_articolo`) REFERENCES `articoli` (`id_articolo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

# Dumping data for table mobili_componibili.ordini_articoli: ~8 rows (approximately)
/*!40000 ALTER TABLE `ordini_articoli` DISABLE KEYS */;
INSERT INTO `ordini_articoli` (`cod_ordine`, `cod_articolo`, `qta`) VALUES
	('001009', 'L100', 4),
	('001009', 'M200', 2),
	('001509', 'L200', 1),
	('001509', 'T400', 1),
	('003209', 'L100', 2),
	('003209', 'T200', 20),
	('004009', 'L100', 1),
	('004009', 'T400', 40);
/*!40000 ALTER TABLE `ordini_articoli` ENABLE KEYS */;
/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
