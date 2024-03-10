#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 7
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
float temperature=0;
float humidity =0;
uint8_t waterLevels=0;
void setup() {
  Init();
 
}
uint8_t delays= 500;
void loop() {
  uint8_t NORMAL_MIN = 3*1000;
  uint8_t LOW_TEMP = 27;
  uint8_t HIGH_TEMP = 30;

  DHTSENSOR();
  WaterLevel();

   
  if(waterLevels>150){
    digitalWrite(3,HIGH);
  }else{
    digitalWrite(3,LOW);
  }

  if(temperature>=LOW_TEMP && temperature<=HIGH_TEMP){
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
  }else if(temperature<=LOW_TEMP){
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
  }else if(temperature>=HIGH_TEMP){
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
  }
 


  Serial.println(temperature);
  Serial.println(humidity);
  Serial.println(waterLevels);
  Serial.println();
 


  
  delay(500);

}
// THESE TONE IS FOR FOOD and WATER
void Tones(){
 
    tone(12,1000);
  delay(100);
    tone(12,500);
  delay(400);
  
  noTone(12);
  delay(500);
 
}
//Functionsl Tone
void ALl(){
  tone(12,1500);
  delay(1500);
  noTone(12);
  delay(200);
}
void DHTSENSOR(){
    temperature = dht.readTemperature();
     humidity = dht.readHumidity();
  
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
}
void relayCheck(){
   digitalWrite(3,HIGH);
  delay(delays);
  digitalWrite(3,LOW);
  delay(delays);
   digitalWrite(4,HIGH);
  delay(delays);
  digitalWrite(4,LOW);
  delay(delays);
   digitalWrite(5,HIGH);
  delay(delays);
  digitalWrite(5,LOW);
  delay(delays);
   digitalWrite(6,HIGH);
  delay(delays);
  digitalWrite(6,LOW);
  delay(delays);
   digitalWrite(3,HIGH);
   digitalWrite(4,HIGH);
   digitalWrite(5,HIGH);
   digitalWrite(6,HIGH);
  delay(delays);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  delay(delays);
}

void WaterLevel(){
  waterLevels = analogRead(A0);
}
void Init(){
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(A0,INPUT);
 digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(3,LOW);
    
  dht.begin();
}

