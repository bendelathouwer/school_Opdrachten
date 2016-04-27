// Opdracht 4A: Unicast
// Maak ontvangst programma.
// Adress Xbee: 0013A200 406F4B31

// bibliotheek toevoegen aan code
#include <XBee.h>

// aanmaken van een object Xbee
XBee xbee = XBee() ;


// maken van de klasse response
XBeeResponse response = XBeeResponse() ;
// maken van de klasse rx
ZBRxResponse rx = ZBRxResponse() ;

// stelt een 64 bit getal voor
XBeeAddress64 raddr64 ;
// 32 bit integer adres_lsb
uint32_t adres_lsb ;
// 32 bit integer adres_msb
uint32_t adres_msb ;

void setup() {
  Serial.begin(9600) ; // instellen van baut rare op 9600
  xbee.setSerial(Serial) ;
}

void loop() {

  // opvangen van  de data
  xbee.readPacket() ;
  // leest alle ontvangen data
  if (xbee.getResponse().isAvailable()) {
    // de if functie is vervuld als er een pakeket word ontvangen
    if (xbee.getResponse().getApiId() == ZB_RX_RESPONSE) {
      // de klasse rx word gevuld met de data
      xbee.getResponse().getZBRxResponse(rx) ;
      // kijken naar het adres van de ontvanger
      raddr64 = rx.getRemoteAddress64() ;
      // aders opsplitesen in de 2 variabelen
      adres_msb = raddr64.getMsb() ;
      adres_lsb = raddr64.getLsb() ;

      // als het adres van de ontvanger gelijk aan het adres het
      //ingestelde adres is het statmen voldaan
      //if ((adres_msb == 0x0013A200 ) && (adres_lsb == 0x406F4B3D))
      //{
        // bepaald de lengte van het paket en print het af op de seriële monitor
        for (int i = 0; i < rx.getDataLength(); i++) {
          Serial.print((char) rx.getData(i)) ;
      //  }
      }
      Serial.println() ;
    
  }

  }
}
  


