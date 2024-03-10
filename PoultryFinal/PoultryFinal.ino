//START INCLUDES
#include <DHT.h>

#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include <Firebase.h>
#include <Firebase_ESP_Client.h>

//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

//END INCLUDES

//VARIABLES
#define DHTPIN 7
#define DHTTYPE DHT22

float temperature = 0;
float humidity = 0;
//END OF VARIABLES

//FUNCTION LIBRARIES

DHT dht(DHTPIN, DHTTYPE);

//END OF FUNCTION LIBRARIES

//FIREBASE
// Insert Firebase project API Key
#define API_KEY "AIzaSyA15QW_8OQrNUDo2J1_GZY6rJG-7cf9H_M"

// Insert RTDB URLefine the RTDB URL */
#define DATABASE_URL "https://poultry-management-syste-a2d22-default-rtdb.asia-southeast1.firebasedatabase.app"

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
int count = 0;
bool signupOK = false;
  WiFiManager wifiManager;
//END OF FIREBASE
void setup() {
   
  Serial.begin(9600);

  pinMode(D3, OUTPUT);  //WATER PUMP
  pinMode(D4, OUTPUT);  //FAN
  pinMode(D5, OUTPUT);  //LIGHTBULB 1
  pinMode(D6, OUTPUT);  //LIG           TBULB 2
  pinMode(D8, OUTPUT);  //BUZZER
  pinMode(A0, INPUT);   //AIR QUALITY SENSOR

 


  
  wifiManager.autoConnect("Jollycode Connection");
  Serial.println("Jollycode Connected");

  tone(D8, 1500);
  delay(1000);
  noTone(D8);
  delay(200);
  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")) {
    Serial.println("Firebase Connected");
    signupOK = true;
  } else {
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback;  //see addons/TokenHelper.h

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
  dht.begin();
  
}

void loop() {

  Serial.println("Hi");
  delay(500);
 

}


