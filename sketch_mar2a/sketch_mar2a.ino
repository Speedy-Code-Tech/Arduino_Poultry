void setup() {
  // put your setup code here, to run once:
  pinMode(1,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(1,HIGH);
  delay(200);
  digitalWrite(1,LOW);
  delay(200);
}
