#include <Adafruit_NeoPixel.h>
#define PIN 11
#include <avr/power.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 3

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      200

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  for(int i=0;i<NUMPIXELS;i++){

 // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
//I used the random number generator with input random(min,max) 
//to select random RGB values between 0-255
    pixels.setPixelColor(i, pixels.Color(random(0,255),random(0,255),random(0,255))); 

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(random(10,100)); // Delay for some random period of time (in milliseconds), between 100 milliseconds and 1 second.


    
    pixels.setPixelColor(i, pixels.Color(0,255,0));
    //pixels.setPixelColor(i, pixels.Color(random(0,255),random(255,255),random(255,0))); 
    //pixels.show();
    //delay(1);
  } 
}
