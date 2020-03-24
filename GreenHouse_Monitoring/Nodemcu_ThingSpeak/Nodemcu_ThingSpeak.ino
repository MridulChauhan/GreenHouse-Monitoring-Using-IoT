#include <ESP8266WiFi.h>  
#include <WiFiClient.h>  
#include <ThingSpeak.h> 
  const char* ssid = "mridul";  
 const char* password = "12345678";  
 WiFiClient client;  
 unsigned long myChannelNumber = 901811;  
 const char * myWriteAPIKey = "ERHM3HEY60PNEKIM";    
 void setup()  
 {  
  Serial.begin(115200);  
  pinMode(A0,INPUT);  
  delay(10);  
  // Connect to WiFi network  
  Serial.println();  
  Serial.println();  
  Serial.print("Connecting to ");  
  Serial.println(ssid);  
  WiFi.begin(ssid, password);  
  while (WiFi.status() != WL_CONNECTED)  
  {  
   delay(500);  
   Serial.print(".");  
  }  
  Serial.println("");  
  Serial.println("WiFi connected");  
  // Print the IP address  
  Serial.println(WiFi.localIP());  
  ThingSpeak.begin(client);  
 }  
 void loop()   
 {  
  float h = analogRead(A0);    
  Serial.print("Gas Level: ");
  Serial.println(h);
  Serial.println("Data Send to Thingspeak");
//   Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different  
//   pieces of information in a channel. Here, we write to field 1.  
  ThingSpeak.writeField(myChannelNumber, 1, h, myWriteAPIKey);
  delay(10000); // ThingSpeak will only accept updates every 15 seconds.  
 }  
