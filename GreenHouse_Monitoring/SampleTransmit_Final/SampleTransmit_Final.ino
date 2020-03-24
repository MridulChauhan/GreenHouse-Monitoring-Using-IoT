#include "DHT.h"
#include "Arduino.h"
#include "Fan.h" 
#include <RF24.h>
#include <RF24Network.h>
#include <SPI.h>
#define DHTPIN A2     
#define DHTTYPE DHT11
#define PCFAN_PIN_COIL1  5 

DHT dht(DHTPIN, DHTTYPE);
Fan PCFan(PCFAN_PIN_COIL1);
RF24 radio(7,8); 
RF24Network network(radio);      // Include the radio in the network
char this_node='A';   // Address of this node in Octal format ( 04,031, etc)
const uint16_t node00 = 00;
const uint16_t node02 = 02;
const uint16_t node03 = 03;

int in1 = 4;
int in3 = 6;
const int ldrPin = A1;
int sensorPin = A0; 
int sensorValue;  
int limit = 200; 

void setup() 
{
  Serial.begin(9600);
  SPI.begin();
  radio.begin();
  network.begin(90, node00); //(channel, node address)
  radio.setDataRate(RF24_2MBPS);
  pinMode(in1, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(ldrPin, INPUT);
  pinMode(13, OUTPUT);
  dht.begin();
}
void loop() 
{
  // Reading data from LDR to operate Bulb
  int ldrStatus = analogRead(ldrPin);
  if (ldrStatus <= 300) 
  {
    Serial.print("Its DARK, Turn on the Bulb : ");
    digitalWrite(in1, LOW);
    Serial.println(ldrStatus);
  } 
  else
  {
    Serial.print("Its BRIGHT, Turn off the Bulb : ");
    digitalWrite(in1, HIGH);
    Serial.println(ldrStatus);
  }

 // Reading data from Soil moisture sensor to operate pump 
 sensorValue = analogRead(sensorPin); 
 Serial.print("Soil Moisture : ");
 Serial.println(sensorValue);
 if (sensorValue<limit) 
 {
  digitalWrite(in3, LOW); 
 }
 else 
 {
  digitalWrite(in3, HIGH);
 }

// Reading data from DHT11 to operate Fan for controlling Temp. and humidity
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if(h>80 && t>25)
    PCFan.on();
  else
    PCFan.off();
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) 
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // Compute heat index
  // Must send in temp in Fahrenheit!
  int hi = dht.computeHeatIndex(f, h);
  Serial.print("Humidity: "); 
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: "); 
  Serial.print(t);
  Serial.print(" *C \t");
  Serial.print("Heat index: ");
  Serial.print(hi);
  Serial.println(" *F");

  /*GGGG*/

  String ld = "1"+String(ldrStatus);
  String sv = "2"+String(sensorValue);
  String hl = "3"+String(hi);

 ldrStatus = ld.toInt();
 sensorValue = sv.toInt();
 hi = hl.toInt();
 
  



  /*KKKKKKKKKKKKKKKKKKKKKKKKKK*/


  
  network.update();
  
  RF24NetworkHeader header5(node03);
  bool ok = network.write(header5, &ldrStatus, sizeof(ldrStatus));
  Serial.println(ldrStatus); 
  delay(10000);
  
  RF24NetworkHeader header6(node03);
  bool ok1 = network.write(header6, &sensorValue, sizeof(sensorValue));
  Serial.println(sensorValue); 
  delay(10000);
  
  RF24NetworkHeader header7(node03);
  bool ok2 = network.write(header7, &hi, sizeof(hi));
  Serial.println(hi); 
  delay(10000);
  
}
