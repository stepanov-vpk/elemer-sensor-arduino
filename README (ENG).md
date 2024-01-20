# Resistance thermometer Elemer TS-1088 + Arduino Nano

![Image alt](https://github.com/stepanov-vpk/elemer-sensor-arduino/blob/main/img/sensor.png?raw=true)

The purpose of this development is to use the development board of the AVR family, namely the Arduino Nano, to record the resistance value of the thermometer and obtain an approximate temperature value in degrees Celsius.

Connecting a resistance thermometer to the Arduino Nano is based on the use of a voltage divider. The measured resistance value is converted into a temperature value and displayed on the LCD1602.

![Image alt](https://github.com/stepanov-vpk/elemer-sensor-arduino/blob/main/img/scheme.png?raw=true)

To determine the temperature, a table of temperature values will be used for various resistance values of resistance thermometers with NSKH 50M.

|Temperature (°C)|50M (Ohm)|
|:-------------:|:------------------:|
|-50|	39.30|
|-40|	41.44|
|-30|	43.58|
|-20|	45.72|
|-10|	47.86|
|0|	50.00|
|10|	52.14|
|20|	54.28|
|30|	56.42|
|40|	58.56|
|50|	60.70|
|60|	62.84|
|70|	64.98|
|80|	67.12|
|90|	69.26|
|100|	71.40|
|110|	73.54|
|120|	75.68|
|130|	77.82|
|140|	79.96|
|150|	82.10|
|160|	84.24|
|170|	86.38|
|180|	88.52|

When replacing a known resistor with a resistor with a different value on the 19th line of the code, you need to change the resistance value of the variable R1 (default 380 Ohms):

```C++
float R1 = 380; 
```

For a more detailed acquaintance with the characteristics of the resistance thermometer, I leave a link to the official documentation for the resistance thermometer of the NNP Elemer Instrument-Making Plant:
- [TS-1088](https://www.elemer.ru/files/catalog/glavi/ts.pdf) - TS-1088, TS-1187, TS-1288, TS-1388, TS-0295. Platinum and copper resistance thermal converters (PDF) - Instrument-making plant NNP Elemer.
