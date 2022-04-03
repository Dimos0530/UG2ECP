/*
 * this program will control a stepper motor with the help 
 * of a joystick. if you move the joystick to the left the 
 * motor will rotate clockwise and if you move the joystick
 * to the right the motor will rotate counter clockwise
 */

#include <Stepper.h> //include the stepper motor library

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
const int rolePerMinute = 15; //set a value for the role per minute
const int X_pin = 1; // analog pin connected to X output

Stepper myStepper(stepsPerRevolution, 2, 4, 3, 5); //identify the pins that the stepper motor is connected to
void setup() {
  myStepper.setSpeed(rolePerMinute);
  
 Serial.begin(9600);// baud rate of 9600

}

void loop() {
Serial.print("X-axis: "); // print "X-axis: " on the serial monitor
Serial.println(analogRead(X_pin));// print the analog value of pin 1
  int a = analogRead(X_pin);  //set a variable for pin 1
  if (a > 400 && a < 520) // what the program will do if the analog value of pin 1 is bigger than 400 and smaller than 520
  {// the motor wont move
    for (int i = 2; i < 6; i++) 
    {
      digitalWrite(i, LOW); 
    }
  }
  else if (a < 400) //what the program will do if the analog value of pin 1 is smaller than 400
  {//the motor will go counter clockwise
    myStepper.setSpeed(rolePerMinute);
    myStepper.step(-30);
  }
  else if (a > 530)//what the program will do if the analog value of pin 1 is bigger than 530
  {//the motor will go clockwise
    myStepper.setSpeed(rolePerMinute);
    myStepper.step(30);
  }



}


}
