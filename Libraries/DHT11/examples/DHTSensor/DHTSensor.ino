/// 
/// @mainpage	DHT11 temperature and humidity sensor library
/// @details	DHT11 on LaunchPad
/// @author	Rei VILO
/// @author	http://embeddedcomputing.weebly.com
/// @date	Jul 02, 2012
/// @version	2.01
/// 
/// @copyright	© Rei VILO, 2012
/// @copyright	CC = BY NC SA
///
/// @see	
/// @n		Based on http://www.ladyada.net/learn/sensors/dht.html
/// @n		written by Adafruit Industries, MIT license
/// @n		 

// Core library - MCU-based
#if defined(__MSP430G2452__) || defined(__MSP430G2553__) || defined(__MSP430G2231__) // LaunchPad specific
#include "Energia.h"
#else // error
#error Platform not supported
#endif

// Include application, user and local libraries
#include "DHT11_430.h"


///
/// @brief	Pin for DHT11 signal
/// @n 		Connect 
/// *		pin 1 (on the left) of the sensor to +5V
/// *		pin 2 of the sensor to DHTPIN 
/// *		pin 4 (on the right) of the sensor to GROUND
///
#define DHTPIN P1_4

DHT11 mySensor(DHTPIN);
boolean flag;

void setup() {
  Serial.begin(9600);
  Serial.println("\n\n\n*** DHT11 test starts"); 
  Serial.println("PUSH2 to end"); 
  pinMode(PUSH2, INPUT_PULLUP);     
  
  mySensor.begin();
}

void loop() {
  delay(2000);
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  flag = mySensor.get();
  int32_t h = mySensor.humidity();
  int32_t t = mySensor.temperature();
  
  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (!flag) {
    Serial.println("Failed to read from DHT");
  } 
  else {
    Serial.print("RH% \t");
    Serial.print(h);
    Serial.println(" %\t");
    
    Serial.print("oC \t");
    Serial.print(t);
    Serial.println(" *C");    
  }
  
  if (digitalRead(PUSH2)==LOW) {
    Serial.println("\n\n*** End"); 
    Serial.end();
    while(true); // endless loop
  }
}

