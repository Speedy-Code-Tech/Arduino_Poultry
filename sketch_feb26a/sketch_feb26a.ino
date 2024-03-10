#include <MQ135.h>

#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN D7
#define DHTTYPE DHT22
MQ135 air(A0);
DHT dht(DHTPIN, DHTTYPE);
void setup(){
  pinMode(A0,INPUT);
  pinMode(D0,INPUT);
  Serial.begin(9600);
  dht.begin();
}
int i=0;
void loop(){
  float airquality = analogRead(A0);

  Serial.println(airquality);
  delay(500);
}