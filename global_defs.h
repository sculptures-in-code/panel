// Last modified: 07/30/2019
// Global definitions for djpanel and associated .h files
#pragma once
//#define LED_TYPE    WS2811
//#define COLOR_ORDER GRB

// LED array
const int NCOLS = 42;
const int NROWS = 24;
int brightsCanvas[NROWS][NCOLS];
CRGB colorCanvas[NROWS][NCOLS];
CRGB printCanvas[NROWS][NCOLS];

const float brightMAX = 255;

// OctoWS2811 objects
const int ROWS_PER_SNAKE = 3;
const int ledsPerPin = ROWS_PER_SNAKE * NCOLS;
DMAMEM int displayMemory[ledsPerPin*6];
int drawingMemory[ledsPerPin*6];
const int config = WS2811_GRB | WS2811_800kHz; // most LED strips are wired this way
OctoWS2811 leds(ledsPerPin, displayMemory, drawingMemory, config); // Octo represents all LEDS as 1 strand
   

//FastLED constants
CRGBPalette16 currentPalette;
TBlendType currentBlending = LINEARBLEND;
int paletteIndex = 0;
int paletteStep  = 10;
int whichPalette = 0;


// arrays for calculating 1D cellular automata
// does it make more sense to define these locally in setup()?
int oldBrightsRow[NCOLS]; // for CAs that propagate vertically
int newBrightsRow[NCOLS];
int oldBrightsCol[NROWS]; // for CAs that propagate horizontally
int newBrightsCol[NCOLS];

int *newBrights; // pointer to either the row or column version of *Brights
int *oldBrights;
int brightsLength;


// Durations & delays
int stepTime=100;    // delay between LED update
int patTime = 5000;  // duration of scrolling part of pattern


// others
//int sRules[] = {73, 90, 110, 124, 150, 181, 182};
// add rules: 18, 22, 26, 30, 37, 45, 50, 54, 58, 62, 69, 75, 79, 82, 86, 89, 93, 94, 99, 114, 118, 122, 123, 126, 131, 133, 135, 145, 147, 149, 154, 158, 161, 163, 165, 167, 177, 178, 179, 181, 190, 210, 214, 218, 222, 242, 246, 250 
//int aRules[] = {73, 84, 90, 106, 110, 124, 135, 150, 169, 181, 182, 188};
//int sRulesInvert[] = {135, 181};
