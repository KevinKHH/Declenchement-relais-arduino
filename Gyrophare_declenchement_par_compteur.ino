/*****************************************************************************/
//	Fonction :  Déclencher le gyrophare à mi session
//	Auteur:	 ORCAS-Maker	
//	Date: 	 15-01-2019
//	by www.orcas-maker.com
//
//  Ce code vous permet de compter le temps afin de 
//  déclencher la fermeture ou l'ouverture d'un relais par exemple
//
//  Code libre de droit et pour tout usage.
//
/*******************************************************************************/

// tps_declenchement correspond au délai 
// qui précéde le déclenchement du relais : 
// - 1000 correspond à 1 seconde
// - 60 correspond à 1 minute ( 1mn = 60s )
// - 30 correspond à 30 minutes
// tps_declenchement s'exprime en millisecondes
// soit 1000*60*30 
long tps_declenchement = 1000*60*30 ;

// tps_init contient le temps écoulé en millisecondes depuis
// que l'Arduino est sous tension ou bien remise à zéro (via 
// son bouton reset).
// millis() est une fonction fournie par l'IDE pour
// donner le nombre de millisecondes écoulées depuis
// la mise sous tension ou bien l'appui sur le bouton reset
// de l'Arduino.
long tps_init = millis() ;




// void setup() est une fonction.
// Tous les codes Arduino commence par cette fonction.
// Elle initialise tous les paramètres de l'Arduino.
// C'est ici que le mode (OUTPUT ou INPUT) des pins sont définis
// Arduino applique le contenu de cette fonction qu'une seule fois
// après sa mise sous tension ou bien l'appui sur son bouton reset.
void setup()
{
  // 8 est le n° de la Pin de l'Arduino qui est reliée à la pin IN du relais
  // le terme "OUTPUT", indique à Arduino que sa pin n°8
  // envoie un message
	pinMode(8, OUTPUT);

  // Le terme "HIGH", insique à Arduino d'envoyer la consigne
  // HIGH sur la pin n°8. 
  // Pour le relais, "HIGH" signifie qu'il ne doit 
  // pas activer son interrupteur
  digitalWrite(8, HIGH);
}




// void loop() est une fonction.
// C'est cette fonction qui est appliquée à la suite de la fonction setup().
// loop() tourne en boucle tant que l'Arduino est sous tension.
void loop()
{

  // Condition "if" qui compare le nombre de millisecondes
  // acutelles avec le nombre de milliseconde enregistrée 
  // lors de la mise sous tension de l'Arduino (tps_init).
  //
  // Si la différence de "millis()-tps_init" est
  // supérieure au nombre de millisecondes qui doivent s'écouler et que nous avons
  // définies dans la variable "tps_declenchement", alors 
  // Arduino envoie la consigne "LOW" sur sa pin n°8 (pin_in),
  // ce qui a pour effet de déclencher l'interrupteur du relais.
  if ( (millis()-tps_init)>tps_declenchement ){
    digitalWrite(8, LOW);
  }
}
