// Last modified: 07/30/2019
// 1D binary cellular automaton rules for brightness display
// SOURCE: wolframalpha.com
#pragma once

#include "global_defs.h" // for brightMAX definition

/* 1 DIMENSIONAL BINARY CA TEMPLATE

// Scale LED brightness to 0 or brightMAX according to Binary CA Rule ???
// Good for: 
int rule???(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return();   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return();   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return();   }
  
}// end rule ???

*/

// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 13
// Good for: LED board, initialized with 1 pixel
int rule13(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(0);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }

}// end rule13

// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 57
// Good for: LED board, initialized with 1 pixel, short runs with random start
int rule57(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(0);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
  
}// end rule 57

// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 73
// Good for: full strip. CAUTION: FLASHING IF INITIALIZED WITH 1 CELL
int rule73(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(0);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(0);   }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0);   }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(brightMAX); }
  
}// end rule 73


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 77
// Good for: LED board with inital pixel
int rule77(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(0);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
  
}// end rule 77


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 84
// Good for: full strip
int rule84(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(0);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
  
}// end rule 84


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 90
// Good for: sweep from middle with 'on' seed, full strip
int rule90(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(0);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 90


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 91
// Good for: LED panel 1 pixel. CAUTION: will blink on a strip
int rule91(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(0);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
  
}// end rule 91


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 101
// Good for: LED panel single pixel and random. CAUTION: Will blink on a strip
int rule101(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(0);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
  
}// end rule 101


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 105
// Good for: LED panel single pixel or random. CAUTION ON STRIP: flasing
int rule105(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(0);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
  
}// end rule 105


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 109
// Good for: LED panel single pixel or random
int rule109(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(0);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
  
}// end rule 109


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 106
// Good for: full strip
int rule106(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(0);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 106


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 110
// Good for: sweep from far end with 'on' seed, full strip
int rule110(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(0);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 110


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 113
// Good for: LED board single pixel, random
int rule113(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(0);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
  
}// end rule 113


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 124
// Good for: sweep from near end with 'on' seed, full strip
int rule124(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(0);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 124


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 129
// Good for: LED board, initial pixel or random
int rule129(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(brightMAX);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
  
}// end rule 129


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 135
// Good for: sweep from middle with 'off' seed, full strip
int rule135(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(brightMAX);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
}// end rule 135


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 150
// Good for: sweep from middle with 'on' seed, full strip
int rule150(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(brightMAX);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 150


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 157
// Good for: constant fill from far end
int rule157(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(brightMAX);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
}// end rule 157


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 160
// Good for: Fade out
int rule160(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(brightMAX);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 160


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 168
// Good for: Fade out 
int rule168(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(brightMAX);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 168

// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 169
// Good for: single traveling stripe, full strip
int rule169(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(brightMAX);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
}// end rule 169


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 181
// Good for: Sweep from 'on' seed, 'off' seed; full strip
int rule181(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(brightMAX);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
}// end rule 181


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 182
// Good for: LED board with initial pixel or random
int rule182(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(brightMAX);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
  
}// end rule 182


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 188
// Good for: Sweep from near end with 'on' seed, travelling stripe
int rule188(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(brightMAX);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 188


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 194
// Good for: Static with blinking
int rule194(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(brightMAX);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 194


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 216
// Good for: static, mostly on
int rule216(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(brightMAX);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 216


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 224
// Good for: Fade out 
int rule224(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(brightMAX);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 224


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 225
// Good for: LED board with one pixel or random 
int rule225(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(brightMAX);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
  
}// end rule 225



// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 232
// Good for: Static
int rule232(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(brightMAX);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 232


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 235
// Good for: 
int rule235(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(brightMAX);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
}// end rule 235


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 248
// Good for: Fade in
int rule248(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(brightMAX);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 248


// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 249
// Good for: Fade in
int rule249(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(brightMAX);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
}// end rule 249



// Scale LED brightness to 0 or brightMAX according to Binary CA Rule 254
// Good for: LED panel from single pixel
int rule254(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(brightMAX);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(brightMAX);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(brightMAX); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(brightMAX); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
  
}// end rule 254
