#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin();
  //BUTTON DECLARATION
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  //LED DECALRATION
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  lcd.clear();
  lcd.setCursor(0,0);
 lcd.print("Basic Calculator");

}
int num1 =0; 
int num2 =0; 
void loop() {
 byte i =digitalRead(2);
 byte i1 =digitalRead(3);
 byte i2 =digitalRead(4);
 byte i3 =digitalRead(5);
ledFunction(i, i1,i2, i3);
lcd.setCursor(0,1);
lcd.blink();
num1Trig(i2, i3);
int output1 = num1;
lcd.print(output1);

delay(500);
  // put your main code here, to run repeatedly:

}
void ledFunction(byte i, byte i1, byte i2, byte i3){
   //i=8, i1=9, i2=10, i3=11

  if(i==LOW){
    digitalWrite(8,HIGH);
  }else{
    digitalWrite(8,LOW);
  }
  if(i1==LOW){
    digitalWrite(9,HIGH);
  }else{
    digitalWrite(9,LOW);
  }
  if(i2==LOW){
    digitalWrite(10,HIGH);
  }else{
    digitalWrite(10,LOW);
  }
  if(i3==LOW){
    digitalWrite(11,HIGH);
  }else{
    digitalWrite(11,LOW);
  }
}
void num1Trig(byte inc, byte dec){
  
  if(inc==LOW){
    num1 = num1+1;
  }
  if(dec==LOW){
    num1 = num1-1;
  }

}
