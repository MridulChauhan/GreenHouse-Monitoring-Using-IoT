# GreenHouse-Monitoring-Using-IoT

=>> Objective :-

To automate the monitoring processes of a plant inside a greenhouse with respect to its surrounding conditions.

=> Components Used :-

Sensors :-

a) DHT11 – Temperature and Humidity Sensor

-> Reason - This DHT11 Temperature & Humidity Sensor features a calibrated digital signal output with the temperature and humidity  sensors. Its technology ensures the high reliability and excellent long-term stability. This sensor includes a resistive element and a sense of wet NTC temperature measuring devices. It has excellent quality, fast response, anti-interference ability and high cost performance advantages. Each DHT11 sensors features extremely accurate calibration of humidity calibration chamber. The single-wire serial interface system is integrated to become quick and easy. Small size, low power, signal transmission distance up to 20 meters.

-> Purpose – To ensure that the plant grows in an optimum temperature and if it is too hot or too cold we can take necessary action.

b) MQ2

-> Reason - 
1. Wide detecting scope 
2. High sensitivity and fast response 
3. Long life and stable 
4. Simple drive circuit
Due to its fast response time and high sensitivity, measurements can be taken as soon as possible. The sensor sensitivity can be adjusted by using the potentiometer.

-> Purpose – To measure greenhouse gases such as CO2 and water vapour sensing. This will help us to open the shed if too much CO2 is trapped inside and start the air vent or fan.

c) Soil Moisture Sensor

-> Reason - Simple method of measurement. It delivers the results immediately. Watermark sensors and tensiometers are very low in cost.
Offers accurate results. Watermark sensors offer larger moisture reading range from 0 to 200 cb or kpa.

-> Purpose – It is the job of the soil moisture sensor to continuously check that there is enough water content in the soil. If the value falls below a particular limit sprinklers will be activated.

d) LDR

-> Reason - It is easy to integrate with lighting system such as automatic lighting system. It is used for energy consumption or energy management by automatic control of brightness level in mobile phones and auto ON/OFF of street lights based on ambient light intensity. LDR (i.e. photoresistor) based light sensors are available in different shapes and sizes. Light sensors need small voltage and power for its operation.

-> Purpose – It is used to measure intensity of light inside the greenhouse and fire up the bulb if the surroundings become dark.


Actuators :-

a) Sprinkler
Purpose – It is used to pour water into the soil in case of low moisture content. The threshold value has been selected accordingly after observing multiple use cases.

b) Air vent controller
Purpose – It is a fan which is turned on when the humidity is high inside the greenhouse or when the gas content is such that ventilation is required.

c) Lighting Systems
Purpose – A bulb will be switched on when the light sensor senses that surroundings are dark. It will come into play at night time.


External Components :-

a) Arduino UNO
Arduino Uno is a microcontroller board based on the ATmega328P. It has 14 digital input/output pins (of which 6 can be used as PWM outputs), 6 analog inputs, a 16 MHz quartz crystal, a USB connection, a power jack, an ICSP header and a reset button. It contains
everything needed to support the microcontroller; simply connect it to a computer with a USB cable or power it with a AC-to-DC adapter or battery to get started.

b) Relay Module
We can control high voltage electronic devices using relays. A Relay is actually a switch which is electrically operated by an electromagnet. The electromagnet is activated with a low voltage, for example 5 volts from a microcontroller and it pulls a contact to make or break a high voltage circuit.

c) Node MCU
NodeMCU is an open source IoT platform. It includes firmware which runs on the ESP8266 Wi-Fi SoC from Espressif Systems, and hardware which is based on the ESP-12 module. The term "NodeMCU" by default refers to the firmware rather than the development kits. The firmware uses the Lua scripting language. It is based on the eLua project, and built on the Espressif Non-OS SDK for ESP8266. It uses many open source projects, such as luacjson and SPIFFS.

d) NRF module
NRF24L01 transceiver module. It uses the 2.4 GHz band and it can operate with baud rates from 250 kbps up to 2 Mbps. If used in open space and with lower baud rate its range can reach up to 100 meters. The module can use 125 different channels which gives a possibility to have a network of 125 independently working modems in one place. Each channel can have up to 6 addresses, or each unit can communicate with up to 6 other units at the same time.
