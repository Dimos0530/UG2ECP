 /*
  * this program will turn on a dc motor on for 3 sec and then turn it off for 5 sec 
  * with the help of a relay and a 9V battery to power the dc motor
  */
  
  void setup() {
  // put your setup code here, to run once:
pinMode(7, OUTPUT); //connected to S terminal of the relay
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(7,HIGH); //turn relay ON 
  delay (3000); //keep it on for 3 sec 
digitalWrite (7, LOW);// turn relay OFF
delay(5000); //keep it off for 5 sec

}
