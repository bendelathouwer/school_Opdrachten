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

//function prototype's
void Adderes64Bit(void);
void Adderes16bit(void);
void PayloadSize(void);
void UserDataPayload(void);
void optionField(void);



void setup()
{

  Serial.begin(9600);// init of the serial port
  xbee.setSerial(Serial); // Tell XBee to use Hardware Serial.


}

void loop()
{
  Adderes64Bit();

}

void Adderes64Bit(void)
{

  uint8_t  Errorcode ; // init ik niet anders geen duidelijkheid in welke status we zich bevinden

   Errorcode = xbee.getErrorCode;
 
  if (Errorcode == 0)
  {
    Serial.println(raddr64.getMsb());
    delay(1000);
    Serial.println(raddr64.getLsb());
    delay(1000);
  }
}


