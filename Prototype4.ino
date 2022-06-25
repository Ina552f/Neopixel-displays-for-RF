#include <Adafruit_NeoPixel.h>
#define PIN 11
#include <avr/power.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 7

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      5

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
  }

  // delaying for 2 seconds
  delay(1000);

  for (int i = 0; i < NUMPIXELS; i++) {
      // blue color
      pixels.setPixelColor(i, (pixels.Color(0,0,255)));
      pixels.show();
      delay(1000);
  }

  colorSwap();

  // delaying for 2 seconds
  delay(1000);

   for (int i = 0; i < NUMPIXELS; i++) {
    // magenta color
    pixels.setPixelColor(i, (pixels.Color(255,0,255)));
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(1000);
   }

    colorSwap();

      // delaying for 2 seconds
    delay(1000);

     for (int i = 0; i < NUMPIXELS; i++) {
    // orange color
    pixels.setPixelColor(i, (pixels.Color(255,69,0)));
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(1000);
   }


    colorSwap();
   delay(1000); 
   RGBLoop();
   colorSwap();

  // delaying for 2 seconds
  delay(300);

     for (int i = 0; i < NUMPIXELS; i++) {
    // red color
    pixels.setPixelColor(i, (pixels.Color(255,0,0)));
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(1000);
   }

    colorSwap();


     // delaying for 2 seconds
    delay(1000);

     for (int i = 0; i < NUMPIXELS; i++) {
    // green color
    pixels.setPixelColor(i, (pixels.Color(0,255,0)));
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(1000);
   }

  colorSwap();

   // delaying for 2 seconds
    delay(1000);

     for (int i = 0; i < NUMPIXELS; i++) {
    // cyan color
    pixels.setPixelColor(i, (pixels.Color(0,255,255)));
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(1000);
   }

    colorSwap();


     // delaying for 2 seconds
    delay(1000);

     for (int i = 0; i < NUMPIXELS; i++) {
    // no color
    pixels.setPixelColor(i, (pixels.Color(0,0,0)));
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(500);
   }


   RGBLoop();
   delay(500);

    colorSwap();
    delay(500);

   RGBLoop();
   delay(500);

 

     for (int i = 0; i < NUMPIXELS; i++) {
    // green color
    pixels.setPixelColor(i, (pixels.Color(0,255,0)));
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(1000);
   }  
}


void colorSwap() {
  
  for(int i=0;i<NUMPIXELS;i++){

  // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
  //I used the random number generator with input random(min,max) 
  //to select random RGB values between 0-255
   pixels.setPixelColor(i, pixels.Color(random(0,255),random(0,255),random(0,255))); 
    
   pixels.show(); // This sends the updated pixel color to the hardware.

   delay(random(10,100)); // Delay for some random period of time (in milliseconds), between 100 milliseconds and 1 second.
  }
}


void showStrip() {
 #ifdef ADAFRUIT_NEOPIXEL_H
   // NeoPixel
   pixels.show();
 #endif
 
}

void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUMPIXELS; i++ ) {
    setPixel(i, red, green, blue);
  }
  showStrip();
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
 #ifdef ADAFRUIT_NEOPIXEL_H
   // NeoPixel
   pixels.setPixelColor(Pixel, pixels.Color(red, green, blue));
 #endif
}


void RGBLoop() {
  for (int j = 0; j < 3; j++) {
    // Fade In
    for (int k = 0; k < 256; k++) {
      switch(j) {
        case 0: setAll(k,0,0); break;
        case 1: setAll(0,k,0); break;
        case 2: setAll(0,0,k); break;
      }
      showStrip();
      delay(10); 
    }

   // Fade Out
   for (int k = 255; k >= 0; k--) {
    switch(j) {
      case 0: setAll(k,0,0); break;
      case 1: setAll(0,k,0); break;
      case 2: setAll(0,0,k); break;
    }
    showStrip();
    delay(10);
   } 
  }
}
