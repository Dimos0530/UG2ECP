/*
 * this program will read the temperature and the humidity with the 
 * help of the dht11. and then the micro sd reader will read the 
 * values of the dth11 reading and put them into a file of choice
 */

#include <SPI.h> //include the spi library
#include <SD.h> //incldue the sd library

#include <DHT.h> //inlcude dht 11 library

int CSpin = 4; //set the pin for the micro sd reader  
File myDHT11Data; //set the variable for the file 

#define DHTPIN 7 //define the pin that the dht 11 is connected to 
#define DHTTYPE DHT11   //define the type of dht

DHT dht(DHTPIN, DHTTYPE);

float Tempvalue = 0; //set a variable for the tempurature value
float Humvalue = 0; //set a variable for the humidity value

void setup() {
  // put your setup code here, to run once:
SD.begin(CSpin); //start reading from pin 4 
dht.begin();
}

void loop() {
// put your main code here, to run repeatedly:
Tempvalue = dht. readTemperature(); //set the value of the Tempvalue variable to be the temperature reading of the dht11
Humvalue = dht. readHumidity();//set the value of the Humvalue variable to be the humidity reading of the dht11

myDHT11Data = SD.open("dimoexcel200readings.txt", FILE_WRITE); //open the file

myDHT11Data.print(Tempvalue); //print "Tempvalue" on the file
myDHT11Data.print(","); //print "," on the file
myDHT11Data.print(Humvalue); //print "Humvalue" on the file
myDHT11Data.println();//print "downwards
delay(500); //delay of 500 ms between every reading
myDHT11Data.close(); // close the file

}
