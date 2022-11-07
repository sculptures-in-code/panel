/*
   DJ PANEL
   Last Modified: 07/30/2019
   Maintainer: Christine

   Cellular automaton visualizer. CA applies to brightness, not to color
*/

#include <OctoWS2811.h>
#include <FastLED.h>
#include "global_defs.h"
#include "helpers.h"
#include "rule_chooser.h"
#include "1d2bright_rules.h"
#include "patterns.h"
#include "palettes.h"


void setup() {
  delay(3000); // power-up safety delay

  // set up text output
  Serial.begin(57600);
  Serial.println("serial began...");
  
  // add LED array
  leds.begin();

//  // initialize color
//  for(int r=0; r<NROWS; r++){
//    for(int c=0; c<NCOLS; c++){
//      colorCanvas[r][c] = CRGB::Yellow;
//    }
//  }

 
  currentPalette = greens;
  currentBlending = LINEARBLEND; 
  for(int r=0; r<NROWS;r++){
    for(int c=0; c<NCOLS; c++){
      colorCanvas[r][c] = ColorFromPalette( currentPalette, paletteIndex, 255, currentBlending);
    }
    paletteIndex += paletteStep;
  }

  
  // initialize brightness
  for(int r=0; r<NROWS; r++){
    for(int c=0; c<NCOLS; c++){
      brightsCanvas[r][c] = 255;
    }
  }
  //mapNShow();
  //delay(5000);

  // turn on the display
  //leds.begin();
  //leds.show();

  // initial condition: single pixel
}

void loop() {

  //Serial.println("turning off all leds...");
  //turnOffAll();
  //delay(2000);

  // color brightness can scale down but not up.
  // workaround: make a an array to print
  // write in the color, then nscale it

  //Serial.println("turning on all leds...");
  //turnOnAll();
  //delay(2000);

  //Serial.println("lace90");
  lace90();

  longTime169();
  
  // Choose pattern duration, other variables
  // choose pattern?
  //     random/unpredictable number & switch statement. or put it in its own function
  // where does color change happen?

  // run pattern

}
