#include <WiFiManager.h>

#include <ESP8266WiFi.h>
#include <SPI.h>

//char* ssid;//="nikita";
//char* password;// = "nikita123";
WiFiServer server(80);
int LED_PIN = D4;
void setup() {
  // put your setup code here, to run once:
pinMode(D4,OUTPUT);
//Serial.begin(115200);
//Serial.print("Connecting to...");
//Serial.println(ssid);
//WiFi.begin(ssid,password);
/*delay(1000);
while(WiFi.status()!=WL_CONNECTED){
delay(500);

Serial.println(".");

}*/
WiFiManager wifimanager;
wifimanager.autoConnect("NikkiAbhi");
server.begin();
Serial.println("Connected to");
//Serial.print(ssid);
Serial.println("Your Ip is");

Serial.println(WiFi.localIP());



}

void loop() {
  // put your main code here, to run repeatedly:
WiFiClient client = server.available();
if(client){
  if(client.connected()){
    digitalWrite(D4,LOW);
    Serial.println(".");
    String request = client.readStringUntil('\r');
    //Serial.print("from client");
    Serial.println(request);
    client.flush();
    Serial.println("yes");
    digitalWrite(D4,HIGH);
  }
  client.stop();
}
  }


  


