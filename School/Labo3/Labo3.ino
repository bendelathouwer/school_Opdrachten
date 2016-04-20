#include <Printers.h>
#include <XBee.h>

XBee xbee = XBee();// creating a xbee class
uint8_t payload[] = "Ben De Lathouwer";// what do we whant to send 
XBeeAddress64 addr64 = XBeeAddress64(0x0, 0x0000ffff);
ZBTxRequest zbTx = ZBTxRequest(addr64, payload, sizeof(payload));// make Tx packet 
void setup() 
{
  Serial.begin(9600);// init of the serial port
  xbee.setSerial(Serial); // Tell XBee to use Hardware Serial.

}

void loop() 

{


  xbee.send(zbTx); // Send your request
  delay(2000);// delay for 2 seconds
  
}
