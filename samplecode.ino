#include <WiFi.h>
#include<ESP8266WiFi.h>
#include"Adafruit_MQTT.h"
#include"Adafruit_MQTT_Client`h"

#define WLAN_SSID   "mophone"
#define WLAN_PASS   "12345678"
#define AIO_SERVER "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define IO_USERNAME  "axiomaticashirbad"
#define IO_KEY       "e66f228bfe83475595c271acdb0be79d"



WiFiClient client;
Adafruit_MQTT_Client mqtt(&client,AIO_SERVER,AIO_SERVERPORT,AIO_USERNAME,AIO_KEY);
Adafruit_MQTT_Subscribe ph value = Adafruit_MQTT_Subscribe(&mqtt,AIO_USERNAME "/feeds/sih/ph value");
Adafruit_MQTT_Subscribe turbidity = Adafruit_MQTT_Subscribe(&mqtt,AIO_USERNAME "/feeds/sih/turbidity");
Adafruit_MQTT_Subscribe water = Adafruit_MQTT_Subscribe(&mqtt,AIO_USERNAME "/feeds/sih/water");

void setup()
{
  Serial.begin(115200);
  delay(10);
  PinMode(27,OUTPUT);
  PinMode(26,OUTPUT); 
  Serial.println();
  Serial.print("connrcting to mqtt");
  Serial.println(WLAN_SSTD);
  WiFi.begin(WLAN_SSTD,WLAN_PASS);
  while(WiFi.status() !=WL_CONNECTED){
    delay(500);
    Serial.print("not connected");
    }
  Serial.println(".....");
  Serial.println("WiFi connected");
  Serial.print("IP address :");
  Serial.print(WiFi.localIP());
  mqtt.subscribe(&ph value);
   mqtt.subscribe(&turbidity);
   mqtt.subscribe(&water);
 

  Serial.begin(115200);
 
 }




 void loop(){
  MQTT_Connect();
  Adafruit_MQTT_Subscribe *subscription;
  while((subscription = mqtt.readSubscription(5000)))
  {
   if(subscription==&water)
   {
    Serial.print(F("getting data for water"));
    Serial.println((char *)forward.lastread);
    if(!strcmp((char*)forward.lastread,"forward"))
    {
     
     }
    } 
    if(subscription==&backward)
   {
    Serial.print(F("moving backward"));
    Serial.println((char *)backward.lastread);
    if(!strcmp((char*)backward.lastread,"backword"))
    {
      Serial.println("Moving backward");   //code check karibi
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, LOW); 
      delay(2000);
     }
    } 
    if(subscription==&stopit)
   {
    Serial.print(F("stop"));
    Serial.println((char *)stopit.lastread);
    if(!strcmp((char*)stopit.lastread,"stopit"))
    {
      Serial.println("stopit");
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, LOW); 
      delay(2000);
     }
    } 

  }
 
  
}

void MQTT_connect(){
  
  int8_t ret;
  if(mqtt.connected()){
    return;
    }
  Serial.println("connecting to MQTT...");
  uint8_t retries = 3;
  while((ret = mqtt.connect()) !=0)
  {
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("retrying MQTT connection in 5 seconds");
    mqtt.disconnect();
    delay(5000);
    retries--;
    if(retries==0){
      while(1);
      }
    }
  Serial.println("MQTT connected!!!!");
 }
