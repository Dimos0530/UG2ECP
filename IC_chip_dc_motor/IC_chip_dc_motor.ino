/*
 * this program makes the dc motor turn clockwise and counter clockwise with the help of the ic chip L293D
 * the way this program was made is that the dc motor will start turn in a clockwise direction for 5000 ms 
 * and then will turn in a counter clockwise direction for another 5000 ms and then go back to clockwise 
 * and then counterclockwise until we make it stop.
 */
int MotorPin1 = 9;  // put pin 9 as one of the motors pin
int MotorPin2 = 10; // put pin 10 as the other motors pin

void setup() {
  // put your setup code here, to run once:
pinMode(MotorPin1, OUTPUT); // identify the pin as a digital output
pinMode(MotorPin2, OUTPUT); //dentify the pin as a digital output
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(MotorPin1, HIGH); //MotorPin1 will be on for 5000 ms
digitalWrite(MotorPin2, LOW);  //MotorPin2 will be off for 5000 ms
delay(5000);

digitalWrite(MotorPin1, LOW); //MotorPin1 will be off for 5000 ms
digitalWrite(MotorPin2, HIGH);//MotorPin2 will be on for 5000 ms
delay(5000);
}
