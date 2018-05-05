#include <ESP8266WiFi.h>

#include<WiFiUdp.h>
WiFiUDP    udp;
char*  ssid= "AndroidAP";
char*  password ="qwertyui";

char  msg[20];
int led=5;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
WiFi.begin(ssid, password);
if( WiFi.status()!=WL_CONNECTED)
{
  Serial.println("wait, wifi is not connected ");
  delay(1000);
  }

pinMode(5,OUTPUT);

udp.begin(50000);
udp.read(msg,20);


}

void loop() {
  Serial.println(WiFi.localIP());
Serial.println("Wifi  is connected , wait..");
delay(1000);
String  Logic =String(msg);
Serial.println(msg);
if(Logic.equals("ON"))
{
  digitalWrite(led,HIGH);
  delay(1000);
}
else 
{
  digitalWrite(led,LOW);
  delay(1000);
}
}
