


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);


}

// the loop routine runs over and over again forever:
void loop() 
{
    float SensorValue = 0;// declararation and init of the variable
    SensorValue= SensorRead();// Reading the return value of the function

  Serial.println(SensorValue);// printing the sensor value in volts
}

float SensorRead()
{
    // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // return the value we need 
  return voltage;
}

