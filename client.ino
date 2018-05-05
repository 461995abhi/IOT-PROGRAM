
#include <ESP8266WiFi.h>
#include <SPI.h>
char* ssid="nikita";
char* password = "nikita123";
WiFiClient client;

IPAddress server(192,168,43,25);
void setup() {
Serial.begin(115200);

  // put your setup code here, to run once:
pinMode(D4,OUTPUT);
Serial.print("Connecting to...");
Serial.println(ssid);
WiFi.begin(ssid,password);
delay(1000);
while(WiFi.status()!=WL_CONNECTED){
delay(500);
Serial.println(".");

}
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
