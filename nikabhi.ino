#include<ESP8266WiFi.h>

char* ssid="nikita";
char* password="9874493314";

int ledPin=LED_BUILTIN;
WiFiServer server(80);

void setup() {
  
Serial.begin(115200);
delay(10);

pinMode(ledPin,OUTPUT);
digitalWrite(ledPin,LOW);

WiFi.begin(ssid,password);
delay(10000);

Serial.println("inside setup");

while(WiFi.status()!=WL_CONNECTED)
{
  Serial.println("wait");
  
  }

server.begin();


Serial.println(WiFi.localIP());

}

void loop() 
{
WiFiClient Client=server.available();

if(!Client)
{
  return;
  }
  
Serial.println("new client");
while(!Client.available())
{
  delay(1);
}

String request=Client.readStringUntil('\r');
Serial.println(request);
Client.flush();

int value=LOW;
if(request.indexOf("/LED=ON")!=-1)
{
  digitalWrite(ledPin,HIGH);
  value=HIGH;
}
if(request.indexOf("/LED=OFF")!=-1)
{
  digitalWrite(ledPin,LOW);
  value=LOW;
}


Client.println("HTTP/1.1 200 OK");
Client.println("CONTENT_TYPE:text/html");
Client.println("");
Client.println("<!DOCTYPE HTML>");
Client.println("<html>");

Client.print("LED IS NOW: ");

if(value==HIGH)
{
  Client.println("ON");
}
else
{
  Client.println("OFF");
}

Client.println("<br><br>");
Client.println("<a href=\"/LED=ON\"\"><button>Turn ON</button></a>");
Client.println("<a href=\"/LED=OFF\"\"><button>Turn OFF</button></a><br/>");
Client.println("</html>");
delay(1000);

Client.println("Client Disconnected");
Client.println(" ");

}


