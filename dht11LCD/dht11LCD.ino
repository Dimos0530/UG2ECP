/*
 * this program will display the current temperature and humitidy 
 * of your room on the lcd with the help of the DHT11
 */

#include <dht.h> //include the dht 11 library
#include <LiquidCrystal.h> //include the lcd library

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //the pins that the lcd in connected to

dht DHT; 

#define DHT11_PIN 7 // define the pin number of which the dht11 is connected to

void setup(){
  lcd.begin(16, 2); //set the numbers of columns and rows
}

void loop(){
  int chk = DHT.read11(DHT11_PIN); //the dht11 is reading the values
  lcd.setCursor(0,0); //set the cursor to column 0, line 1
  lcd.print("Temp: "); //print "Temp: " on the LCD
  lcd.print(DHT.temperature); // print the temperature that the dht 11 is reading on the lcd in celcius
  lcd.print((char)223); //print degree symbol on the lcd 
  lcd.print("C"); //print the celcius symbol on the lcd
  lcd.setCursor(0,1); //set the cursor to column 0, line 2
  lcd.print("Humidity: "); //print "Humidity: " on the lcd
  lcd.print(DHT.humidity); // print the humidity that the dht 11 is reading on the lcd
  lcd.print("%"); //print % on the lcd
  delay(1000); //delay of 1000 ms between every reading
}
