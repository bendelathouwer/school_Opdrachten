#include <Printers.h>
#include <XBee.h>

// Opdracht5 Unicast zend en ontvangen
// Maak zend programma. Zodat zender om de 2 sec uw naam stuuurt
// naar de onvanger.
// Adress Xbee: 0013A200 406F4B31(ontvanger)Radek
//0x0013A200, 0x406F4B3D nico ontvanger

#define TIMEOUT 4000
// aanmaken van een object Xbee
XBee xbee = XBee();

// maken van een string met de doortesturen informatie
uint8_t payload[] = "testBen";

// instellen van het zendt adress SH + SL
XBeeAddress64 addr64 = XBeeAddress64(0x0013A200, 408BEE26);// opgegeven adderes maakt dit unicast
// maken van een TX verzoek
ZBTxRequest zbTx = ZBTxRequest(addr64, payload, sizeof(payload));
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

void zend(void);

void ontvang(void);


void setup()
{

  Serial.begin(9600);  // instellen seriele communicatie
  xbee.begin(Serial);  //
}

void loop()
{
  ontvang();

  zend();



}


void zend (void)
{
  // zenden van het verzoek
  xbee.send(zbTx);
  // delay van 2 seconden
  delay(2000);


}


void ontvang(void)
{
  

  if (xbee.readPacket(TIMEOUT)) {

    // leest alle ontvangen data
    if (xbee.getResponse().isAvailable())
    {
      // de if functie is vervuld als er een pakeket word ontvangen
      if (xbee.getResponse().getApiId() == ZB_RX_RESPONSE)
      {
        // de klasse rx word gevuld met de data
        xbee.getResponse().getZBRxResponse(rx) ;
        // kijken naar het adres van de ontvanger
        raddr64 = rx.getRemoteAddress64() ;
        // aders opsplitesen in de 2 variabelen
        adres_msb = raddr64.getMsb() ;
        adres_lsb = raddr64.getLsb() ;

        // bepaald de lengte van het paket en print het af op de seriële monitor
        for (int i = 0; i < rx.getDataLength(); i++)
        {
          Serial.print((char) rx.getData(i)) ;

        }
        Serial.println() ;

      }
    }
  }
}

