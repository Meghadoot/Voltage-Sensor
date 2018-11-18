#include <Voltage_Sensor.h>

const int pin = 5;
const float offset = 0.4;
Voltage_Sensor vs(pin,offset,PULL_UP);

void setup() 
{
 Serial.begin(9600);
}


void loop()
{
float voltage = vs.calculate_Volts();
Serial.print("Measured Voltage is:");
Serial.println(voltage);
}


