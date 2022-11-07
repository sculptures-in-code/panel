// Last modified: 07/30/2019
// Patterns combining one or more CA rules and initial conditions
// Are 1D patterns fundamentally different from 2D patterns?

#pragma once
#include "palettes.h"

// Functions defined in this file:
void lace90();
void u182(); 
void longTime169();

// rules used so far:
// 90, 182, 169
// to use:
// 150, 105, 109


void lace90() {
  // run CA rule 90 from the top 3 times
  // comb up
  // run rule 90

  // change the color palette
  changePalette();
  
  setUpPattern1D(90, 's', 'd');
  // screen is dark except for one pixel in the middle of the top row
  mapNShow();

  // Write Rule 90 downwards 3 times
  fillDOWN(90); // run rule 90 from top to bottom
  delay(stepTime*3);

  // set old brightnesses to top row
  for(int c=0; c<NCOLS; c++){oldBrights[c]=brightsCanvas[0][c];}

  brightsCanvas[0][32] = brightMAX; // turn on a pixel in the top row
  mapNShow();
  fillDOWN(90);
  delay(stepTime*3);

  // set old brightnesses to top row
  for(int c=0; c<NCOLS; c++){oldBrights[c]=brightsCanvas[0][c];}
  
  brightsCanvas[0][11] = brightMAX;
  mapNShow();
  fillDOWN(90);
  delay(stepTime*3);
  // set old brightnesses to top row
  for(int c=0; c<NCOLS; c++){oldBrights[c]=brightsCanvas[0][c];}

  // comb up 
  for(int i=0; i<37; i++){
    bumpUPBrights(3);
    mapNShow();
    delay(stepTime*2);
  }

  // random rule 90 for awhile
  for(int c=0; c<NCOLS; c++){oldBrights[c]= brightsCanvas[NROWS-1][c];} // update oldBrights
  for(int b=0; b<100; b++) { // bump the pattern b times
    window1DBright(90);
    bumpUPBrights();
    for(int c=0; c<NCOLS; c++){brightsCanvas[NROWS-1][c] = newBrights[c];}
    for(int c=0; c<NCOLS; c++){oldBrights[c]=newBrights[c];}
    mapNShow();
    delay(stepTime);
  }
  
} // end lace90


void u182() {
  // Pattern makes a u shape:
  // 1. fill 182 downward
  // 2. continue scrolling it down
  // 3. comb to the right
  // 4. scroll up rule 182

  // change the color palette
  changePalette();
  
  setUpPattern1D(182, 's', 'd');
  // screen is dark except for one pixel in the middle of the top row
  mapNShow();

  // 1. Write Rule 182 downwards
  fillDOWN(182); // run rule 90 from top to bottom
  delay(stepTime*3);

  // 2. continue scrolling it down
  for(int b=0; b<NROWS*50; b++) { // bump the pattern b times
    window1DBright(182);
    bumpUPBrights();
    for(int c=0; c<NCOLS; c++){brightsCanvas[NROWS-1][c] = newBrights[c];}
    for(int c=0; c<NCOLS; c++){oldBrights[c]=newBrights[c];}
    mapNShow();
    delay(stepTime);
  }

  // 3. comb to the right
  for(int i=0; i<13; i++){
    bumpRIGHTBrights(2);
    mapNShow();
    delay(stepTime*2);
  }
  
  // 4. scroll up rule 182
  for(int c=0; c<NCOLS; c++){oldBrights[c]= brightsCanvas[NROWS-1][c];} // update oldBrights
  for(int b=0; b<100; b++) { // bump the pattern b times
    window1DBright(182);
    bumpUPBrights();
    for(int c=0; c<NCOLS; c++){brightsCanvas[NROWS-1][c] = newBrights[c];}
    for(int c=0; c<NCOLS; c++){oldBrights[c]=newBrights[c];}
    mapNShow();
    delay(stepTime);
  }
  
} // end u82


void longTime169(){
  
  // change the color palette
  changePalette();
  
  setUpPattern1D(169, 's', 'u');
  // screen is dark except for one pixel in the middle of the bottom row
  mapNShow();

  for(int b=0; b<NROWS*100; b++) { // bump the pattern b times
    window1DBright(169);
    bumpUPBrights();
    for(int c=0; c<NCOLS; c++){brightsCanvas[NROWS-1][c] = newBrights[c];}
    for(int c=0; c<NCOLS; c++){oldBrights[c]=newBrights[c];}
    mapNShow();
    delay(stepTime);
  }
} // end longTime169
