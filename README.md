# Voltage Sensor
This is a library for the Voltage sensor (driver) designed specifically to work with all Arduino Boards.

## Table of Contents

1. [Voltage Sensor](#VoltageSensor)
2. [Table of Contents](#table-of-contents)
3. [Summary](#summary)
4. [Installation](#installation)
5. [Usage](#usage)
6. [Contributing](#contributing)
7. [History](#history)
8. [License](#license)

<snippet>
<content>
  

## Summary

Voltage driver uses the voltage sensor (simple voltage divider) to measure the voltage of battery or cell(0V to 20V). Internal ADC is used to  calculate the exact value of analog voltage from raw measured reading.


## Installation

To use this library download the zip file or clone the repository, decompress it to a folder named Voltage Sensor. Move the folder to {Arduino Path}/libraries.

## Usage

* Include the library at the top of your Arduino script. `#include <Voltage_Sensor>`
* Create a global or local variable. 
  
 `Voltage_Sensor vs(Analog_pin, Offset_Voltage, Configuration)`
  ```
   *  Analog_pin: Any Analog Pin on Arduino Board
   
   *  Offset_Voltage: To get accurate voltage reading (by eliminating offset error due to ADC).  
   
   *  Configuration: sensor connection to analog pin of arduino [PULL_UP or PULL_DOWN]  
   ```
  
   Offset value can be caliberated initially by measuring the voltage using DMM and comparing it with the measurement done by arduino. By default, this value is set to **0.0 volts**. 
   
   Sensor (here, the resistor across which voltage is to be measured) can be connected in [PULL_UP or PULL_DOWN](https://electronics.stackexchange.com/questions/210643/pull-up-pull-down-resistor-confusion) manner. By default, configuration is set as [**PULL_DOWN**](https://electronics.stackexchange.com/questions/210643/pull-up-pull-down-resistor-confusion)
.
  
 or
 
 `Voltage_Sensor vs(Analog_pin, Offset_Voltage)`
 
 or
 
 Simply,
  
 `Voltage_Sensor vs(Analog_pin)`
 
* Read the exact voltage value
 `float voltage = vs.calculateVolts()`

## Contributing

1. Fork the project.
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request.

## History

- Nov  16, 2018   - Version 1.0.0 released (Readme Updated)

## License

GNU GPL, see License.txt
</content>
</snippet>
