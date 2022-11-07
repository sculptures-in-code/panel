// Last modified: 08/07/2019
// helper functions for running cellular automata
#pragma once

#include "1d2bright_rules.h"
#include "rule_chooser.h"

// Functions defined in this file:
void setUpPattern1D(int rule, char initialCondition, char fillDirection);
void window1DBright(int rule, long brightBound);
void turnOffAll();
void turnOnAll();
void fillDOWN(int rule);  // brightness only (not color)
void fillUP(int rule);    // brightness only
void fillLEFT(int rule);  // brightness only
void fillRIGHT(int rule); // brightness only
void bumpUPBrights(int nth);
void bumpDOWNBrights(int nth);
void bumpLEFTBrights(int nth=1);
void bumpRIGHTBrights(int nth);
void fillToEdge(int rule, char fillDirection); // brightness only
void scrollPattern(int rule, char fillDirection, int duration); // brightness only
void mapNShow();
// add a color changer
// later: sort them into categories: ca dimension, brightness vs. color; display


// Initialize canvas for a new pattern. Choose whether 1D CA is applied to a row or a column
void setUpPattern1D(int rule, char initialCondition, char fillDirection){
  // Inputs
  // rule              : the name of the CA rule
  // initialCondition  : 's' to start over, 'a' to use row/column as-is
  // boundaryCondition :  NOT IMPLEMENTED-- hard coded as continuous boundary (long)
  // fillDirection     : 'd' to fill downward, 'u' to fill upward
  //                   : 'l' to fill leftward, 'r' to fill rightward
  // duration          : total duration of pattern
  // invert            : when true, dark pattern on light background // i might get rid of this if it's hard to implement

  // NOT IMPLEMENTED YET:
  // boundaryCondition


  if(initialCondition=='s'){ // start pattern from scratch
    // Set canvas to dark: all brightness = 0
    turnOffAll();
   
    // set oldBrights to dark and illuminate one LED at/near the center
    if(fillDirection == 'd' || fillDirection == 'u'){
       // fill is up or down-- use rows
       for(int c=0; c<NCOLS; c++){oldBrightsRow[c]=0;} 
       oldBrightsRow[round(NCOLS/2)] = brightMAX;
       //oldBrightsRow[11] = brightMAX // set arbitrary pixel for testing
       oldBrights     = oldBrightsRow;
       brightsLength  = NCOLS;

       for(int c=0; c<NCOLS; c++){Serial.print(oldBrights[c]);}
       Serial.println("");

       newBrights = newBrightsRow;

       // write into brightsCanvas
       if(fillDirection=='u'){ for(int c=0; c<NCOLS; c++){brightsCanvas[NROWS-1][c]=oldBrights[c];} }
       else{for(int c=0; c<NCOLS; c++){brightsCanvas[0][c]=oldBrights[c];} }
    }
    else { // fill is to left or right-- use columns
       for(int r=0; r<NROWS; r++){oldBrightsRow[r]=0;}
       oldBrightsCol[NROWS/2] = brightMAX;
       oldBrights     = oldBrightsCol;
       brightsLength  = NROWS;

       newBrights = newBrightsCol;

       // write into brightsCanvas
       if(fillDirection=='l'){ for(int r=0; r<NROWS; r++){brightsCanvas[r][NCOLS-1]=oldBrights[r];} }
       else{for(int r=0; r<NROWS; r++){brightsCanvas[r][0]=oldBrights[r];} }
    }
  } // end initialCondition=='s'
  else {
    // set oldBrights to the top/bottom/left/right edge depending on fill direction
    // set up pattern (should that be its own function?
    // Get the row/column from which the pattern originates
    switch(fillDirection){
      case 'd':
        for(int c = 0; c < NCOLS; c++){ oldBrightsRow[c] = brightsCanvas[0][c]; }
        oldBrights = oldBrightsRow;
        brightsLength=NCOLS;
      break;
      case 'u':
        for(int c = 0; c < NCOLS; c++){ oldBrightsRow[c] = brightsCanvas[NROWS-1][c]; }
        oldBrights = oldBrightsRow;
        brightsLength=NCOLS;
      break;
      case 'l':
        for(int r = 0; r < NROWS; r++){ oldBrightsCol[r] = brightsCanvas[NROWS-1][r]; }
        oldBrights = oldBrightsCol;
        brightsLength=NROWS;
      break;
      case 'r':
        for(int r = 0; r < NROWS; r++){ oldBrightsCol[r] = brightsCanvas[0][r]; }
        oldBrights = oldBrightsCol;
        brightsLength=NROWS;
      break;
      default:
        // shouldn't ever reach this. but set default to scroll down
        for(int c = 0; c < NCOLS; c++){ oldBrightsRow[c] = brightsCanvas[0][c];}
        oldBrights = oldBrightsRow;
        brightsLength=NCOLS;
      break;
    } // end switch
  
  } // end initialCondition=='a'


} // end setUpPattern1D
  

// Run a 3-LED moving window down the brightess array, to (a) determine each cell's neighborhood and (b)
// apply the current brightness CA rule
void window1DBright(int rule, long brightBound= -1){
  // Input
  // rule        : the CA rule (binary) or code (3-color) to apply 
  // brightBound : boundary condition
  //               -1: contiuous boundary
  //               <0: set boundary to constant color from palette
  
  //Serial.println("New call to window1D BRIGHTNESS");
  //Serial.print("Boundary condition is ");
  //Serial.println(brightBound);

  // variables to store values in the neighborhood
  int leftNeighbor  = -1;
  int self          = -1;
  int rightNeighbor = -1;

  for(int i = 0; i < brightsLength; i++) {
      // Get neighborhood for LED i
      self = oldBrights[i];

      if (i==0) { // first LED in row/column
        if(brightBound < 0) {leftNeighbor  = oldBrights[brightsLength-1];}
        else {leftNeighbor = brightBound;}
        rightNeighbor = oldBrights[i+1];
      }
      else if (i==brightsLength-1) { // last LED in row/column
        if(brightBound < 0) {rightNeighbor = oldBrights[0];}
        else {rightNeighbor=brightBound;}
        leftNeighbor  = oldBrights[i-1];
      }
      else{// LED in middle of strip
        leftNeighbor  = oldBrights[i-1];
        rightNeighbor = oldBrights[i+1];
      }

      //Serial.print(leftNeighbor);
      //Serial.print(" ");
      //Serial.print(self);
      //Serial.print(" ");
      //Serial.println(rightNeighbor);
      //Serial.println(applyBrightness(rule, leftNeighbor, self, rightNeighbor));
      //Serial.println(newBrights[i]);

      // apply brightness CA rule
      newBrights[i] = applyBrightness(rule, leftNeighbor, self, rightNeighbor);
      
    } // end for
  
} // end window1DBright


// Turn off all LEDs
void turnOffAll(){
  for(int c=0; c<NCOLS; c++){
    for(int r=0; r<NROWS; r++){
      brightsCanvas[r][c]=0;
    }
  }
  mapNShow();
  delay(stepTime);
} // end turnOffAll


// Turn on all LEDs
void turnOnAll(){
  for(int c=0; c<NCOLS; c++){
    for(int r=0; r<NROWS; r++){
     brightsCanvas[r][c]=brightMAX;
    }
  }
  mapNShow();
  delay(stepTime);
} // end turnOnAll


// Fill canvas with a pattern from top to bottom, according to CA rule
void fillDOWN(int rule){
  for(int c=0; c<NCOLS; c++){oldBrights[c]=brightsCanvas[0][c];}
  for(int r=1; r<NROWS; r++){
        window1DBright(rule); // calculate newBrights

        for(int c=0; c<NCOLS; c++){ // write newBrights to brightsCanvas
          brightsCanvas[r][c] = newBrights[c];
        }
        mapNShow();
        delay(stepTime);

        // new brights are now old
        for(int i=0; i<NCOLS; i++){oldBrights[i]=newBrights[i];}
  }
} // end fillDOWN

// Fill canvas with a pattern from bottom to top
void fillUP(int rule) {
  for(int r=NROWS-1; r>=0; r--){
      window1DBright(rule); // calculate newBrights

      for(int c=0; c<NCOLS; c++){ // write newBrights to canvas
        brightsCanvas[r][c] = newBrights[c];
      }
      mapNShow();
      delay(stepTime);
      
      // newBrights are now old
      for(int i=0; i<NCOLS; i++){oldBrights[i]=newBrights[i];}
    }
} // end fillUP


// fill canvas with a pattern from right to left
void fillLEFT(int rule){
 for(int c=NCOLS-1; c>=0; c--){
        window1DBright(rule); // calculate newBrights
        
        for(int r=0; r<NROWS; r++){ // write newBrights to canvas
          brightsCanvas[r][c]=newBrights[r];
        }
        mapNShow();
        delay(stepTime);
        
        // newBrights are now old
        for(int i=0; i<NROWS; i++){oldBrights[i]=newBrights[i];}
      }     
} // end fillLEFT


// fill canvas with a pattern from left to right
void fillRIGHT(int rule){
  for(int c=0; c<NCOLS; c++){
        window1DBright(rule); // calculate newBrights

        for(int r=0; r<NROWS; r++){ // write newBrights to canvas
          brightsCanvas[r][c]=newBrights[r];
        }
        mapNShow();
        delay(stepTime);
        
        // newBrights are now old
        for(int i=0; i<NROWS; i++){oldBrights[i]=newBrights[i];}
      }
} // end fillRIGHT


// Bump the brightness pattern on the LED display UP by one row
void bumpUPBrights(int nth=1){
  // put the top row aside (nth ==1)
  // intersperse values in the top, bottom rows (nth > 1)
  int topRow[NCOLS]; 
  for(int c = 0; c < NCOLS; c++){ 
    if(c % nth == 0){topRow[c] = brightsCanvas[0][c];}
    else{topRow[c] = brightsCanvas[NROWS-1][c];}
  }

  // starting at the top, copy the contents of each row into the row above,
  // in every nth column
  for(int r = 0; r < NROWS-1; r++){
    for(int c = 0; c < NCOLS; c++){
      if(c % nth == 0){brightsCanvas[r][c] = brightsCanvas[r+1][c];}
    }
  }// end for

  // write the old top row into the bottom row
  for(int c = 0; c < NCOLS; c++){ brightsCanvas[NROWS-1][c] = topRow[c];}
} // end bumpUPBrights


// Bump the brightness pattern on the LED display DOWN by one row,
// in every nth column
void bumpDOWNBrights(int nth=1){
  // put the bottom row aside (nth == 1)
  // intersperse values in the top, bottom rows (nth > 1)
  int botRow[NCOLS];
  for(int c = 0; c < NCOLS; c++){ 
    if(c % nth == 0){botRow[c] = brightsCanvas[NROWS-1][c];}
    else{botRow[c] = brightsCanvas[0][c];}
  }

  // starting at the bottom, copy the contents of each row into the row below
  for(int r = NROWS-1; r > 0; r--){
    for(int c = 0; c < NCOLS; c++){
      if(c % nth == 0) {brightsCanvas[r][c] = brightsCanvas[r-1][c];}
    }
  }// end for

  // write the old bottom row into the top row
  for(int c = 0; c < NCOLS; c++){ brightsCanvas[0][c] = botRow[c];}
  
} // end bumpDOWNBrights



// Bump the brightness pattern on the LED display LEFT by one row
void bumpLEFT(int nth=1){
  // put the leftmost column aside (nth == 1)
  // intersperse values in the left, right rows (nth > 1)
  int leftCol[NROWS];
  for(int r = 0; r < NROWS; r++){ 
    if(r % nth == 0){leftCol[r] = brightsCanvas[r][0];}
    else{leftCol[r] = brightsCanvas[r][NCOLS-1];}
  }

  // starting at the left, copy the contents of each column into the column to the left
  for(int c = 0; c > NCOLS-1; c++){
    for(int r = 0; r < NROWS; r++){
      if(r % nth == 0){brightsCanvas[r][c] = brightsCanvas[r][c+1];}
    }
  }// end for

  // write the old rightmost column into the leftmost column
  for(int r = 0; r < NROWS; r++){ brightsCanvas[r][NCOLS-1] = leftCol[r];}
  
} // end bumpLEFTBrights


// Bump the brightness pattern on the LED display RIGHT by one row
//bumpRIGHT
void bumpRIGHTBrights(int nth=1){
  // put the rightmost column aside (nth == 1)
  // intersperse values in the left, right rows (nth > 1)
  int rightCol[NROWS];
  for(int r = 0; r < NROWS; r++){ 
    if(r % nth == 0){rightCol[r] = brightsCanvas[r][NCOLS-1];}
    else{rightCol[r] = brightsCanvas[r][0];}
  }

  // starting at the right, copy the contents of each column into the column to the right
  for(int c = NCOLS-1; c > 0; c--){
    for(int r = 0; r < NROWS; r++){
      if(r % nth == 0){brightsCanvas[r][c] = brightsCanvas[r][c-1];}
    }
  }// end for

  // write the old rightmost column into the leftmost column
  for(int r = 0; r < NROWS; r++){ brightsCanvas[r][0] = rightCol[r];}
  
} // end bumpRIGHT


// Fill pattern from one edge to the opposite edge
void fillToEdge(int rule, char fillDirection) {
  // Inputs:
  // fillDirection : 'd' to fill downward, 'u' to fill upward
  //               : 'l' to fill leftward, 'r' to fill 
  // rule          : the name of the CA rule

  // apply oldBrights to the edge across from fillDirection and show
  switch(fillDirection){
    case 'd':
      // start pattern at top
      for(int c=0; c<NCOLS-1; c++){
        brightsCanvas[0][c] = oldBrights[c];
      }
      fillDOWN(rule);
    break;
    case 'u':
      // start pattern at bottom
      for(int c=0; c<NCOLS-1; c++){
        brightsCanvas[NROWS-1][c] = oldBrights[c];
      }
      fillUP(rule);
    break;
    case 'l':
      // start pattern at right
      for(int r=0; r<NROWS-1; r++){
        brightsCanvas[r][NROWS-1] = oldBrights[r];
      }
      fillLEFT(rule);
    break;
    case 'r':
     // start pattern at left
     for(int r=0; r<NROWS-1; r++){
        brightsCanvas[r][0] = oldBrights[r];
      }
      fillRIGHT(rule);
    default:
      // shouldn't ever reach this. but set default to scroll down
      // start pattern at top
      for(int c=0; c<NCOLS-1; c++){
        brightsCanvas[0][c] = oldBrights[c];
      }
      fillDOWN(rule);
    break;
  } // end switch on oldBrights assignment
 
} // end fillToEdge


//scrollPattern
// UNTESTED
// CHANGE tTO BRIGHTNESS ONLY YOU ARE HERE
void scrollBrightness(int rule, char fillDirection, int duration) {
  // Inputs:
  // rule          : the name of the CA rule
  // fillDirection : 'd' to fill downward, 'u' to fill upward
  //               : 'l' to fill leftward, 'r' to fill rightward
  // duration      : total duration of pattern

  //initialized elapsed and starting time for duration comparisons
  long elapsed   = 0;
  long startTime = millis();
  
  switch(fillDirection){
    case 'd':
      // pattern updates from the top
      while(elapsed <= duration){
        elapsed = millis() - startTime;                           // update elapsed
        for(int c; c<NCOLS; c++) {oldBrights[c] = brightsCanvas[0][c];}  // oldBrights is the top row of canvas
        window1DBright(rule);                                         // calculate newBrights
        bumpDOWNBrights();                                               // bump all rows on canvas down by 1
        for(int c; c<NCOLS; c++) {brightsCanvas[0][c]  = newBrights[c];} // top row of canvas is newBrights
        mapNShow();
        delay(stepTime);
      }
    break;
    case 'u':
      // pattern updates from the bottom
      while(elapsed <= duration){
        elapsed = millis() - startTime;                                // update elapsed
        for(int c; c<NCOLS; c++) {oldBrights[c] = brightsCanvas[NROWS-1][c];} // oldBrights is the top row of canvas
        window1DBright(rule);                                              // calculate newBrights
        bumpUPBrights();                                                      // bump all rows on canvas down by 1
        for(int c; c<NCOLS; c++) {brightsCanvas[NROWS-1][c] = newBrights[c];} // bottom row of canvas is newBrights
        mapNShow();
        delay(stepTime);
      }
    break;
    case 'l':
      // pattern updates from the right
      while(elapsed <= duration){
        elapsed = millis() - startTime;                                // update elapsed
        for(int r; r<NROWS; r++) {oldBrights[r] = brightsCanvas[r][NCOLS-1];} // oldBrights is the top row of canvas
        window1DBright(rule);                                              // calculate newBrights
        bumpLEFTBrights();                                                    // bump all rows on canvas down by 1
        for(int r; r<NROWS; r++) {brightsCanvas[r][NCOLS-1] = newBrights[r];} // top row of canvas is newBrights
        mapNShow();
        delay(stepTime); 
      }
    break;
    case 'r':
      // pattern updates from the left
      while(elapsed <= duration){
        elapsed = millis() - startTime;                          // update elapsed
        for(int r; r<NROWS; r++) {oldBrights[r] = brightsCanvas[r][0];} // oldBrights is the top row of canvas
        window1DBright(rule);                                        // calculate newBrights
        bumpRIGHTBrights();                                             // bump all rows on canvas down by 1
        for(int r; r<NROWS; r++) {brightsCanvas[r][0] = newBrights[r];} // top row of canvas is newBrights
        mapNShow();
        delay(stepTime);
      }
    break;
    default:
      // shouldn't ever reach this. but scroll down by default
      // pattern updates from the top
      while(elapsed <= duration){
        elapsed = millis() - startTime;                           // update elapsed
        for(int c; c<NCOLS; c++) {oldBrights[c] = brightsCanvas[0][c];}  // oldBrights is the top row of canvas
        window1DBright(rule);                                         // calculate newBrights
        bumpDOWNBrights();                                               // bump all rows on canvas down by 1
        for(int c; c<NCOLS; c++) {brightsCanvas[0][c]  = newBrights[c];} // top row of canvas is newBrights
        mapNShow();
        delay(stepTime); 
      }
    break;   
  }

} // end scrollBrightness
  


// Map the values on canvas onto the LED strands, and show the result
void mapNShow() {
  // Since Octo sees all LED strands as a single strand, and because strands are snaked,
  // write canvas into a linear array (leds) with the direction of every other canvas row
  // reversed.

  // Write colors into printCanvas
  for(int r=0; r<NROWS; r++){
    for(int c=0; c<NCOLS; c++){
      printCanvas[r][c]=colorCanvas[r][c];
    }
  }

  CRGB currentLED;
  int i = 0;       // linear index along leds
  
  for(int r=0; r<NROWS; r++){
    // CUSTOM PIECE: SPECIFIC TO OLIVER & RICK'S LED BOARD
    //     Rows 3-8 are backwards
    // IF USING OTHER BOARD, USE COMMENTED SECTION ONLY

    if((r>=3 && r<=5) || (r>=9 && r<=11) || (r>=15 && r<=17) || (r>=21 && r<=23)){ // THESE LEDS ARE BACKWARDS ON THE BOARD
      // these rows are backwards; flip them around
      if(r % 2 != 0) { // odd row
        // write forwards into leds
        for(int c=0; c<NCOLS; c++){
          // combine brightness, color information
          //Serial.print("brightness: ");
          //Serial.println(brightsCanvas[r][c]);
          currentLED = printCanvas[r][c].nscale8(brightsCanvas[r][c]);
          // convert to RGB for octo
          leds.setPixel(i,currentLED.r, currentLED.g, currentLED.b);
          i++; // move to next LED
        }
      }
      else { // even row
        // write backwards into leds
        for(int c=NCOLS-1; c>=0; c--){
          // combine brightness, color information
          currentLED = printCanvas[r][c].nscale8(brightsCanvas[r][c]);
          // convert to RGB for octo
          leds.setPixel(i,currentLED.r, currentLED.g, currentLED.b);
          i++; // move to next LED
        }
      }
    } // end backwards case
    else{ // begin forwards case
      if(r % 2 == 0) { // even row
        // write forwards into leds
        for(int c=0; c<NCOLS; c++){
          // combine brightness, color information
          //Serial.print("brightness: ");
          //Serial.println(brightsCanvas[r][c]);
          currentLED = printCanvas[r][c].nscale8(brightsCanvas[r][c]);
          // convert to RGB for octo
          leds.setPixel(i,currentLED.r, currentLED.g, currentLED.b);
          i++; // move to next LED
        }
      }
      else { // odd row
        // write backwards into leds
        for(int c=NCOLS-1; c>=0; c--){
          // combine brightness, color information
          currentLED = printCanvas[r][c].nscale8(brightsCanvas[r][c]);
          // convert to RGB for octo
          leds.setPixel(i,currentLED.r, currentLED.g, currentLED.b);
          i++; // move to next LED
        }
      }
    } // end forwards case


    
//    if(r % 2 == 0) { // even row
//      // write forwards into leds
//      for(int c=0; c<NCOLS; c++){
//        // combine brightness, color information
//        //Serial.print("brightness: ");
//        //Serial.println(brightsCanvas[r][c]);
//        currentLED = printCanvas[r][c].nscale8(brightsCanvas[r][c]);
//        // convert to RGB for octo
//        leds.setPixel(i,currentLED.r, currentLED.g, currentLED.b);
//        i++; // move to next LED
//      }
//    }
//    else { // odd row
//      // write backwards into leds
//      for(int c=NCOLS-1; c>=0; c--){
//        // combine brightness, color information
//        currentLED = printCanvas[r][c].nscale8(brightsCanvas[r][c]);
//        // convert to RGB for octo
//        leds.setPixel(i,currentLED.r, currentLED.g, currentLED.b);
//        i++; // move to next LED
//      }
//    }
  
  } // all values have been written to LEDs

  //Serial.print("here's a brightness value: ");
  //Serial.println(brightsCanvas[NROWS-1][NCOLS-1]);
  //Serial.print("here's the red value: ");
  //Serial.println(currentLED.r);
  //Serial.print("here's what's in colorCanvas: ");
  //CRGB a_color = colorCanvas[NROWS-1][NCOLS-1];
  //Serial.println(a_color.r);
  //Serial.println();
     
  // show on board
  leds.show();
  
} // end mapNShow
