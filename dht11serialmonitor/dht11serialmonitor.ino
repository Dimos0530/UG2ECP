/*
 * this program will display the current temperature and humitidy 
 * of your room on the serial monitor with the help of the DHT11
 */

#include <dht.h> // include the dht11 library

dht DHT;

#define DHT11_PIN 7 // define the pin number of which the dht11 is connected to

void setup(){
  Serial.begin(9600); //baud rate of 9600
}

void loop(){
  int chk = DHT.read11(DHT11_PIN); //the dht11 is reading the values
  Serial.print("Temperature = "); //print "Temperature = " on the serial monitor
  Serial.println(DHT.temperature);//print the temperature that the dht11 is reading on the serial monitor
  Serial.print("Humidity = "); //print "Humidity = " on the serial monitor 
  Serial.println(DHT.humidity); //print the humidity that the dht11 is reading on the serial monitor
  delay(1000); //delay of 1000 ms between every reading
}
