// Receiver NODE03 (B)

#include <stdio.h>
#include <SoftwareSerial.h>
#include <RF24.h>
#include <RF24Network.h>
#include <SPI.h>
SoftwareSerial s(5,6);


RF24 radio(7,8);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
char this_node='B';
const uint16_t node03 = 03; // Address of our node in Octal format ( 04,031, etc)

long ldrStatus;

void setup() 
{
  Serial.begin(9600);
  SPI.begin();
  radio.begin();
  s.begin(9600);
  network.begin(90, node03); //(channel, node address)
  radio.setDataRate(RF24_2MBPS);
}
void loop() 
{
  network.update();
  if ( network.available() )  // Is there any incoming data?
  {    
    RF24NetworkHeader header5;
    network.read(header5, &ldrStatus, sizeof(ldrStatus)); // Read the incoming data
    //Serial.println(ldrStatus);
    //ldrStatus = int(ldrStatus);
    String k = String(ldrStatus);
    //char s[10];
    //k.toCharArray(s,10);
    //Serial.println(s);
    //s.write(s);
    char* cString = (char*) malloc(sizeof(char)*(k.length() + 1));
    k.toCharArray(cString, k.length() + 1);
    Serial.println(cString);
    s.write(cString);


    
    
   // ArduinoUno.println(a1);
    //delay(10000);
  }
   /*network.update();
   if ( network.available() )  // Is there any incoming data?
    {  
    RF24NetworkHeader header6;
    network.read(header6, &sensorValue, sizeof(sensorValue)); // Read the incoming data
    Serial.println(sensorValue);
    int a2=sensorValue;
     if(s.available()>0)
      {
       s.write(a2);
      }

    //ArduinoUno.println(a2);
    //delay(10000);
    }
     network.update();
  if ( network.available() )  // Is there any incoming data?
  {  
    RF24NetworkHeader header7;
    network.read(header7, &hi, sizeof(hi)); // Read the incoming data
    Serial.println(hi);
    int a3=hi;
    if(s.available()>0)
    {
     s.write(a3);
    }

   // ArduinoUno.println(a3);
    //delay(10000);
  }*/
}
