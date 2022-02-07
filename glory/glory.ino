#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <SoftwareSerial.h>

#include "index.h" //Our HTML webpage contents with javascripts

 
const int relais1 = 16 ,relais2 = 5,relais3 = 4,buzzer = 0,prise1= 2;
const int capteur_feux = 14;
const int capteur_fumer = 12;

#define Cap_light  A0

//creation d'une adresse ip statique pour le ESP8266
IPAddress local_IP(192,168,43,22);
IPAddress gateway(192,168,43,9);
IPAddress subnet(255,255,255,0);


ESP8266WebServer server(80); //Server on port 80

#define RX 13
#define TX 15
#define BAUD 9600
SoftwareSerial sim800l(RX, TX);
char* number = "+243972688605";

void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}
//fonction a exposes
void lampe1() {
  Serial.println("Changing to text mode.");
 digitalWrite(relais1,LOW);

}
void lampe1off() {
 digitalWrite(relais1,HIGH);
 Serial.println("Changing to text mode.");
}

void lampe2() {
 digitalWrite(relais2,LOW);
}
void lampe2off() {
 digitalWrite(relais2,HIGH);
}
void lampe3() {
 digitalWrite(relais3,LOW);
}
void lampe3off() {
 digitalWrite(relais3,HIGH);
}

//commande de la premiere prise
void lampe4() {
 digitalWrite(buzzer,LOW);
}
void lampe4off() {
 digitalWrite(buzzer,HIGH);
}
//commande de la premiere prise
void prise() {
 digitalWrite(prise1,HIGH);
}
void priseoff() {
 digitalWrite(prise1,LOW);
}
void setup() { 
  
  Serial.begin(9600); 
  Serial.println("Glory project");
  Serial.println("");
  sim800l.begin(BAUD);
  
 //LAMPE
  pinMode(relais1,OUTPUT);  
  digitalWrite(relais1,HIGH);
  pinMode(relais2,OUTPUT);  
  digitalWrite(relais2,HIGH);
  pinMode(relais3,OUTPUT);  
  digitalWrite(relais3,HIGH);
 /////////////BUZZER////////////////////////////////////
  pinMode(buzzer,OUTPUT);  
  digitalWrite(buzzer,HIGH);
  ///////////////PRISE//////////////
  pinMode(prise1,OUTPUT);
  digitalWrite(prise1,LOW);
  //////////CAPTEUR//////////////
  pinMode(capteur_feux, INPUT);
  pinMode(capteur_fumer, INPUT);
  pinMode(Cap_light, INPUT);
  ////////////////WIFI/////////////////////
  WiFi.softAPConfig(local_IP, gateway, subnet);
  boolean result = WiFi.softAP("glory project", "1234567890");
  Serial.print("Soft-AP IP address = ");
  Serial.println(WiFi.softAPIP());

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  
  server.on("/", handleRoot);//affichage de la page principale
  
  server.on("/lampe1", lampe1); //envoi des donnnees du capteur
  server.on("/lampe1off", lampe1off); //envoi des donnnees du capteur
  
  server.on("/lampe2", lampe2); //envoi des donnnees du capteur
  server.on("/lampe2off", lampe2off); //envoi des donnnees du 

  server.on("/lampe3", lampe3); //envoi des donnnees du capteur
  server.on("/lampe3off", lampe3off); //envoi des donnnees du capteur
  
  server.on("/prise1", prise); //envoi des donnnees du capteur
  server.on("/prise1off", priseoff); //envoi des donnnees du capteur

  server.on("/lampe4", lampe4); //envoi des donnnees du capteur
  server.on("/lampe4off", lampe4off); //envoi des donnnees du capteur
  server.begin();                  //Start server
  Serial.println("HTTP server started");

  delay(500);
}
void loop() {
   digitalWrite(buzzer,HIGH);
  
   
   bool condition = digitalRead(capteur_feux) == 1 || !digitalRead(capteur_fumer)==1;
   Serial.print(digitalRead(capteur_feux));
   Serial.print(" | ");
   Serial.print(!digitalRead(capteur_fumer));
   Serial.print(" = ");
   Serial.println(condition);
   
   while(condition == true)
   {
    Serial.println("Alert");
    digitalWrite(buzzer,LOW);
    if( digitalRead(capteur_feux) == 1)
    {
        Serial.println("Feux dans la maison");
        SendSMS("Salut Glory, il y a le feux dans la maison.");
//        calls();
    }
    if(!digitalRead(capteur_fumer)==1)
    {
      Serial.println("Fumée dans la maison");
      SendSMS("Salut Glory, detection de fumee dans la maison.");
//      calls();
    }
    condition = digitalRead(capteur_feux) == 1 || !digitalRead(capteur_fumer)==1;
    server.handleClient();  //Handle client requests
   
   }
  
   server.handleClient();  //Handle client requests
}

void SendSMS(String message)
{
  Serial.println("Envoi alert....");               //Show this message on serial monitor
  sim800l.print("AT+CMGF=1\r");                   //Set the module to SMS mode
  delay(100);
  sim800l.print("AT+CMGS=\"+243970806372\"\r");  //Your phone number don't forget to include your country code, example +212123456789"
  delay(500);
  sim800l.print(message);       //This is the text to send to the phone number, don't make it too long or you have to modify the SoftwareSerial buffer
  delay(500);
  sim800l.print((char)26);// (required according to the datasheet)
  delay(500);
  sim800l.println();
  Serial.println("Alete envoye Sent.");
  delay(500);
}

void calls()
{
  sim800l.println("AT"); //Once the handshake test is successful, i t will back to OK
  delay(500);
  sim800l.println("ATD+ +243972688605;"); //  change ZZ with country code and xxxxxxxxxxx with phone number to dial
  delay(2000); // wait for 2 seconds...
  sim800l.println("ATH"); //hang up
}

void crepusculaire()
{
  if(analogRead(Cap_light) > 200)
  {
    digitalWrite(relais1,HIGH);
    digitalWrite(relais2,HIGH);
    digitalWrite(relais3,HIGH);
  }
}
