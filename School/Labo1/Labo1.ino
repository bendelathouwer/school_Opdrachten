// included libary
#include <Printers.h>
#include <XBee.h>

// defining the pin where we conect the led
const int ledPin =  13;    

//setuproutine
void setup() 
{
  pinMode(ledPin, OUTPUT);// making the ledpin an outout

}

// repeat forever
void loop() 
{
 digitalWrite(ledPin,HIGH);// led on
 delay(500);// waiht 500ms
 digitalWrite(ledPin,LOW);// led of 
 delay(500);
}
