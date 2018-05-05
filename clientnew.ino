
#include <ESP8266WiFi.h>
#include <SPI.h>
#include <WiFiManager.h>
int led=D4;
IPAddress server(192,168,43,21);
WiFiClient client;


void setup() {
Serial.begin(115200);
// put your setup code here, to run once:
pinMode(D4,OUTPUT);
WiFiManager  wifiManager;
wifiManager.autoConnect("NikkiAbhi");
}


void loop() {
  // put your main code here, to run repeatedly:
client.connect(server,80);
digitalWrite(D4,LOW);
Serial.println(".");
Serial.println("hello server\r");
String answer = client.readStringUntil('\r');
//Serial.println("from server");
Serial.println(answer);
client.flush();
digitalWrite(D4,HIGH);
delay(1000);

}
