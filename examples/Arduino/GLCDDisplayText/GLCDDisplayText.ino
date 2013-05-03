/*
  Arduino Graphic LCD text example
  
  This example demonstrates how to draw text on the 
  screen when connected to an Arduino. The Arduino reads
  the value of an analog sensor attached to pin A0, and
  writes the value to the LCD screen, updating every
  quarter second.
  
  This example code is in the public domain

  Created 15 April 2013 by Scott Fitzgerald
 
  http://arduino.cc/en/Tutorial/GLCDDisplayText
 
 */

// pin definition for the Uno
#define cs   10
#define dc   9
#define rst  8  

// pin definition for the Leonardo
// #define cs   7
// #define dc   0
// #define rst  1 

#include <Adafruit_GFX.h>    // Core graphics library
#include <GTFT.h> // Hardware-specific library
#include <SPI.h>

// create an instance of the library
GTFT TFTscreen = GTFT(cs, dc, rst);

// char array to print to the screen
char sensorPrintout[4];

void setup(void) {
  Serial.begin(9600);

  Serial.print("Initializing display!");

  // Put this line at the beginning of every sketch that uses the GLCD:
  TFTscreen.begin();

  // clear the screen with a black background
  TFTscreen.background(0, 0, 0);
  
  // write the static text to the screen
  // set the font color to white
  TFTscreen.stroke(255,255,255);
  // set the font size
  TFTscreen.setTextSize(2);
  // write the text to the top left corner of the screen
  TFTscreen.text("Sensor Value :\n ",0,0);
  // ste the font size very large for the loop
  TFTscreen.setTextSize(5);
}

void loop() {

  // Read the value of the sensor on A0
  String sensorVal = String(analogRead(A0));
 
  // convert the reading to a char array
  sensorVal.toCharArray(sensorPrintout, 4);

  // set the font color
  TFTscreen.stroke(255,255,255);
  // print the sensor value
  TFTscreen.text(sensorPrintout, 0, 20);
  // wait for a moment
  delay(250);
  // erase the text you just wrote
  TFTscreen.stroke(0,0,0);
  TFTscreen.text(sensorPrintout, 0, 20);
}

