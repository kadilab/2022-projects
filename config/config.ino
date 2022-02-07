
////library 
#include <Servo.h>//library pour le servo moteur
#include <Wire.h> //communication I2C 
#include <LiquidCrystal_I2C.h>//utilisation de la l

Servo porte;//instance de la classe Servo utiliser comme porte

LiquidCrystal_I2C lcd(0x27,16,2); //creation de l'objet pour l'afficheur LCD I2C
#define porte_pin 2 //pin ou sera brancher le servo moteur de la pporte
#define temps 2000 //temp entre l'ouverture et la fermeture de la porte

#define buzzer 0 //pin du buzzer
#define green_led 16 //pin de la led verte
#define red_led 15 //pin de la led rouge

const int pins[3] = {buzzer,green_led,red_led}; //table des pins [buzzer,led verte,led rouge]
//fonction d'initialisation  
void setup() {
  
  Serial.begin(115200); //initialisation de la communication serie avec une vitesse de communication de 115200
  lcd.init();//initialisation de l'afficheur LCD
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("QRCODE  READER");
  Serial.println("QRCODE  READER\n-------------------");
  porte.attach(porte_pin);
  porte.write(0);
  for(int i= 0; i<3;i++)
  {
      pinMode(pins[i],OUTPUT); //definition des pins du tableau en sortie
  }
}
//fonction principale

void loop() {
  String msg; //message recu via la communication serie
  if(Serial.available()>0)//verifie si des donnees sont disponible sur le moniteur serie
  {
    msg = Serial.readString(); //recuperation est stockage de valeurs rec
    msg.trim();//suppression de espace blancs dans la chaine

   //si non recoi 0  on lance les instruction d'alerte
    if(msg == "0")
    {
        error();
    }
    //si on recois un nom on ouvre la porte puis on affiche le message avec le nom de la personne
    else
    { 
      ///////AFFICHAGE DU NOM////////
        Serial.print("WELCOME! : ");
        Serial.println(msg);
        lcd.clear();
        lcd.setCursor(5,0);
        lcd.print("WELCOME!");
        lcd.setCursor(5,1);
        lcd.print(msg);
        //////////OUVERTURE DE LA PORTE////////////////
        Serial.println("ouverture de la porte");
        porte.write(180);
        digitalWrite(green_led,HIGH);
        delay(temps);
        ////////////FERMETURE DE LA PORTE///////////////////
        Serial.println("Fermeture de la porte");
        porte.write(0);
        digitalWrite(green_led,HIGH);
        digitalWrite(red_led,LOW);
        delay(1000);
        //////////////MESSAGE PRINCIPAL///////////////////////
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print("QRCODE  READER");
        Serial.println("QRCODE  READER\n-------------------"); 
        digitalWrite(green_led,LOW);
    }
  }
}
//fonction d'erreur
void error()
{
  //////////////MESSAGE ACCES REFUSE///////////////////////
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print("ACCES REFUSE");
        Serial.println("ACCÈS REFUSE");
        digitalWrite(buzzer, HIGH);
        digitalWrite(red_led, HIGH);
       
        delay(3000);
        //////////////MESSAGE PRINCIPAL///////////////////////
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print("QRCODE  READER");
        Serial.println("QRCODE  READER\n-------------------"); 
        digitalWrite(buzzer, LOW);
        digitalWrite(red_led, LOW);
}
