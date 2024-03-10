  #include <SoftwareSerial.h>

  //Create software serial object to communicate with SIM800L
  SoftwareSerial mySerial(3, 2); //SIM800L Tx & Rx is connected to Arduino #3 & #2
  String numbers[] = {"9380831513","9380831513","9380831513","9380831513","9380831513"};
  int i1 = 0;
    int i2 = 0;
    int i3 = 0;
  void setup()
  {
    //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)

    pinMode(5,INPUT);
    pinMode(6,INPUT);
    pinMode(7,INPUT);
    //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
    Serial.begin(9600);
    
    //Begin serial communication with Arduino and SIM800L
    mySerial.begin(9600);

    Serial.println("Initializing..."); 
    delay(1000);

    mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
    updateSerial();

  
    
  }

  void loop()
  {
    i1 = digitalRead(5);
    i2 = digitalRead(6);
    i3 = digitalRead(7);

    Serial.println(i1);
    Serial.println(i2);
    Serial.println(i3);
    Serial.println();
    if(i1==1 && i2!=1 && i3!=1){
      for(String number : numbers){ //NORMAL
            sendSMS("9380831513","Level 1: Water is rising and currently in LEVEL 1, Be ATTENTIVE as of water is rising");
      }
    }else if(i1==1 && i2!=1 && i3!=1){
      for(String number : numbers){ //WARNING
            sendSMS("9380831513","Level 2: Water is rising RAPIDLY please EVACUATE IMMEDIATELY for the possible danger ");
      }

    }else if(i1==1 && i2!=1 && i3!=1){
      for(String number : numbers){ //DANGER
          sendSMS("9380831513","Level 3: EVACUATE, EVACUATE, EVACUATE. The water is in DANGER LEVEL and everyone is advised to take care");
      }
    }
    i1=0;
    i2=0;
    i3=0;
    // delay(1000);
  }
  void sendSMS(String num,String msg){
      mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
    updateSerial();
  mySerial.println("AT+CMGS=\"+63"+num+"\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
    updateSerial();
    mySerial.print(msg); //text content
    updateSerial();
    mySerial.write(26);
  }

  void updateSerial()
  {
    delay(500);
    while (Serial.available()) 
    {
      mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
    }
    while(mySerial.available()) 
    {
      Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
    }
  }