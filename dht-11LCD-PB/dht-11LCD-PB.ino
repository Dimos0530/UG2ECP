/*
 * this program will display the current temperature and humitidy 
 * of your room on the lcd with the help of the DHT11. also while 
 * holding down a button the temperaute will convert from celcius
 * to farenheit
 */

#include <dht.h>//include the dht 11 library
#include <LiquidCrystal.h>//include the lcd library

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);//the pins that the lcd in connected to

dht DHT;

#define DHT11_PIN 7 // define the pin number of which the dht11 is connected to
int PBpin = 13; //set the pin that button is connected to
int buttonState = 1; //set the state of the button to 1 

void setup(){
  lcd.begin(16, 2); //set the numbers of columns and rows
}
void loop(){

 buttonState = digitalRead (PBpin); //the button will read the value of pin 13                         
                            
  if (buttonState ==LOW){ //what the program will do if the state if the button is low 
  int chk = DHT.read11(DHT11_PIN);//the dht11 is reading the values
  lcd.setCursor(0,0); //set the cursor to column 0, line 1
  lcd.print("Temp: "); //print "Temp: " on the LCD
  lcd.print(DHT.temperature); // print the temperature that the dht 11 is reading on the lcd
  lcd.print((char)223); //print degree symbol on the lcd
  lcd.print("C"); //print the celcius symbol on the lcd
  lcd.setCursor(0,1);//set the cursor to column 0, line 2
  lcd.print("Humidity: ");//print "Humidity: " on the lcd
  lcd.print(DHT.humidity);// print the humidity that the dht 11 is reading on the lcd
  lcd.print("%");//print % on the lcd
  delay(1000);//delay of 1000 ms between every reading
}

else {  //what the program will do if the state if the button is other than low

  int chk = DHT.read11(DHT11_PIN); //the dht11 is reading the values
  lcd.setCursor(0,0); //set the cursor to column 0, line 1
  lcd.print("Temp: ");//print "Temp: " on the LCD
  lcd.print(((DHT.temperature)*9/5)+32); // print the temperature that the dht 11 is reading on the lcd in celcius
  lcd.print((char)223);//print degree symbol on the lcd 
  lcd.print("F");//print the farenheit symbol on the lcd
  lcd.setCursor(0,1);//set the cursor to column 0, line 2
  lcd.print("Humidity: ");//print "Humidity: " on the lcd
  lcd.print(DHT.humidity);// print the humidity that the dht 11 is reading on the lcd
  lcd.print("%");//print % on the lcd
  delay(1000);//delay of 1000 ms between every reading
}
}
