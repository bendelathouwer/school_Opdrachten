#include <Printers.h>
#include <XBee.h>

// Opdracht 4A: Unicast 
// Maak zend programma. Zodat zender om de 2 sec uw naam stuuurt 
// naar de onvanger. 
// Adress Xbee: 0013A200 406F4B31(ontvanger)Radek
//0x0013A200, 0x406F4B3D nico ontvanger

// bibliotheek toevoegen aan code
#include <XBee.h>

// aanmaken van een object Xbee
XBee xbee = XBee();

// maken van een string met de doortesturen informatie
uint8_t payload[] = "testBen";

// instellen van het zendt adress SH + SL
XBeeAddress64 addr64 = XBeeAddress64(0x0013A200, 0x;p408BEE26);// opgegeven adderes maakt dit unicast
// maken van een TX verzoek
ZBTxRequest zbTx = ZBTxRequest(addr64, payload, sizeof(payload));

void setup() {
  Serial.begin(9600);  // instellen seriele communicatie
  xbee.begin(Serial);  //
}

void loop() {

  // zenden van het verzoek
  xbee.send(zbTx);
  // delay van 2 seconden
  delay(2000);
}
