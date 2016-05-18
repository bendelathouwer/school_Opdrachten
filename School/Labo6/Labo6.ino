#include <Printers.h>
#include <XBee.h>


// aanmaken van een object Xbee
XBee xbee = XBee() ;


// maken van de klasse response
XBeeResponse response = XBeeResponse() ;
// maken van de klasse rx
ZBRxResponse rx = ZBRxResponse() ;

// stelt een 64 bit getal voor
XBeeAddress64 raddr64 = XBeeAddress64();



// 32 bit integer adres_lsb
uint32_t adres_lsb ;
// 32 bit integer adres_msb
uint32_t adres_msb ;



void setup()
{

  Serial.begin(9600);// init of the serial port
  xbee.setSerial(Serial); // Tell XBee to use Hardware Serial.
}

void loop()
{
  Serial.println(rx.getDataLength ()); // datalengte van de transmitter ontvangen
  Serial.println(rx.getOption ()); // option veld van de transmitter ontvangen(hiermee kun je zien of de zender unicast of broadcast zend)
  Serial.println (int(rx.getRemoteAddress64())); // adres van de transmitter ontvangen
  Serial.println (rx.getRemoteAddress16 ()); // 16 bit adres van de transmitter ontvangen
  Serial.println (raddr64.getMsb ()); 
  Serial.println (raddr64.getLsb ());
}




