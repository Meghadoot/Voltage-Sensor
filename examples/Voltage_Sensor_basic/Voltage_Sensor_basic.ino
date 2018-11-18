#include <Voltage_Sensor.h>

const int pin = 5;
Voltage_Sensor vs(pin);

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


