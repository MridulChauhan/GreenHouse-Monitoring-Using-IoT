#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

const char *ssid = "jay";  //ENTER YOUR WIFI SETTINGS
const char *password = "12345678";

const char *host = "192.168.43.109";   //https://circuits4you.com website or IP address of server

#include <SoftwareSerial.h>
SoftwareSerial s(D6,D5);
long data;
void setup() {
s.begin(9600);
////////////////////////////////
Serial.begin(9600);


 WiFi.mode(WIFI_OFF);        //Prevents reconnection issue (taking too long to connect)
  delay(1000);
  WiFi.mode(WIFI_STA);        //This line hides the viewing of ESP as wifi hotspot
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");

  Serial.print("Connecting");
  // Wait for connection

 while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP


//////////////////////////////////////



}
 
void loop() {
  s.write("s");
  if (s.available()>0)
  {
    /*data=s.read();
    Serial.println(data);*/
    
    String incomingByte = s.readString();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte);

/////////////////////online////////////////////////////

 HTTPClient http;    //Declare object of class HTTPClient

  //String ADCData, station, getData, Link;
  String getData, Link;

/*Link = "https://manavhostel.000webhostapp.com/iot/updatehh.php?bit_address="*/

Link = "http://manavhostel.000webhostapp.com/iot/updatehh.php?bit_address="+String(incomingByte)+"&fire=yes&submit=";

 http.begin(Link);     //Specify request destination
  int httpCode = http.GET();            //Send the request
  String payload = http.getString();    //Get the response payload

  //Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload+"online");    //Print request response payload

  http.end();  //Close connection



/////////////////////////////////////////////////////

/////////////////////offline////////////////////////////

 HTTPClient http1;    //Declare object of class HTTPClient

  //String ADCData, station, getData, Link;
  String getData1, Link1;

/*Link = "https://manavhostel.000webhostapp.com/iot/updatehh.php?bit_address="*/
Link1 = "http://192.168.43.109/iot/updatehh.php?bit_address="+String(incomingByte)+"&fire=yes&submit=";

 http1.begin(Link1);     //Specify request destination
  int httpCode1 = http1.GET();            //Send the request
  String payload1 = http1.getString();    //Get the response payload

  //Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload1+"ofline");    //Print request response payload

  http1.end();  //Close connection



/////////////////////////////////////////////////////


    
  }
}
