/***************************************************************************
	Voltage_Sensor.cpp
	Author: Meghadoot
  	2018-11-16
	
	This is a library for the Voltage sensor.
	Voltage sensor use voltage divider to sense voltage, ADC is required to interface.
	Designed specifically to work with the Arduino Boards.
	
    Copyright (C) 2018  Meghadoot Gardi.  All right reserved.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

 ***************************************************************************/

#include "Arduino.h"
#include "Voltage_Sensor.h"

/***************************************************************************
 CONSTRUCTORS
 ***************************************************************************/

/****************************************************************************
** Function name:           Voltage_Sensor
** Descriptions:            set pin and pin mode
****************************************************************************/

Voltage_Sensor::Voltage_Sensor(int pin)
{
  pinMode(pin, INPUT);
  _pin = pin;
  _offset = 0.0;
  _config = PULL_DOWN;
}

/****************************************************************************
** Function name:           Voltage_Sensor
** Descriptions:            set pin, pin mode and offset voltage 
****************************************************************************/

Voltage_Sensor::Voltage_Sensor(int pin, float offset)
{
  pinMode(pin, INPUT);
  _pin = pin;
  _offset = offset;
  _config = PULL_DOWN;
}

/******************************************************************************
** Function name:           Voltage_Sensor
** Descriptions:            set pin, pin mode, offset voltage, sensor connection 
*******************************************************************************/

Voltage_Sensor::Voltage_Sensor(int pin, float offset, sensor_connection_types_t configuration)
{
  pinMode(pin, INPUT);
  _pin = pin;
  _offset=offset;
  _config = configuration;
}

/***************************************************************************
 PUBLIC FUNCTIONS
 ***************************************************************************/

/******************************************************************************
** Function name:           calculate_Volts
** Descriptions:            read sensor value and measure voltage 
*******************************************************************************/

float Voltage_Sensor::calculate_Volts()
{
  int sensorValue = analogRead(_pin); //read the Analog pin passed value
  
  #if(__Voltage_Sensor_debug == ENABLED)
	Serial.print("Raw reading: ");
	Serial.println(sensorValue);
  #endif
  
  float voltage = fabs(fmap(sensorValue, MIN_RANGE, MAX_RANGE, MIN_OUTPUT, MAX_OUTPUT))*4 + _offset; //multiplication factor of 4 to measure between range 0 to 20V

  #if(__Voltage_Sensor_debug == ENABLED)
	Serial.print("Voltage = ");
	Serial.println(voltage);	
  #endif
  
  return voltage;  
}

/******************************************************************************
** Function name:           fmap
** Descriptions:            calculate actual voltage by mapping between 0 to 5V 
*******************************************************************************/

float Voltage_Sensor::fmap(float x, float in_min, float in_max, float out_min, float out_max) 
{
	
  if(_config == PULL_DOWN)
  {
	  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  }
  else if(_config == PULL_UP)
  {
	  return MAX_OUTPUT - ( (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
	
  }
  else
  {
	/* Do noothing , return nothing */
  }
}


