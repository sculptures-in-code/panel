// Last modified: 08/17/2019
// Global definitions for color palettes
#pragma once

#include <FastLED.h>

 // up to 16 colors
  // this one is good with paletteStep=10
  // theres also a palette32 
  // fastLED pixeltypes.h for named colors

  // multicolor palettes
  CRGBPalette16 tequilaSunriseSet = CRGBPalette16(CRGB::FireBrick, CRGB::OrangeRed, CRGB::Orange, CRGB::Coral); 

  CRGBPalette16 blurples = CRGBPalette16(CRGB::Navy, CRGB::DarkSlateBlue, CRGB::Blue, CRGB::DarkViolet); 

  CRGBPalette16 neon2019 = CRGBPalette16(CRGB::DarkSlateBlue, CRGB::DarkRed, CRGB::Navy, CRGB::MidnightBlue); 

  //CRGBPalette16 easter; //easter
  //easter = CRGBPalette16(CRGB::PaleGoldenrod, CRGB::Goldenrod, CRGB::Yellow, CRGB::DarkGoldenrod); 
  // initialize color from palette
  //currentPalette = p2;
  
  CRGBPalette16 betterEaster = CRGBPalette16(CRGB::Indigo, CRGB::Plaid, CRGB::Gold, CRGB::LawnGreen); 

  CRGBPalette16 rainbowPony = CRGBPalette16(CRGB::DarkGreen, CRGB::OrangeRed, CRGB::Orchid, CRGB::ForestGreen); 

  CRGBPalette16 betterPartyColors = CRGBPalette16(CRGB::Cyan, CRGB::OrangeRed, CRGB::MidnightBlue, CRGB::DarkBlue); 
  
  CRGBPalette16 skylySun = CRGBPalette16(CRGB::Gold, CRGB::DarkGoldenrod, CRGB::DarkCyan, CRGB::Yellow); // up to 16 colors


  // palettes based on a single color
  CRGBPalette16 greens = CRGBPalette16(CRGB::GreenYellow, CRGB::LawnGreen, CRGB::Green, CRGB::DarkGreen);
  
  CRGBPalette16 yellows = CRGBPalette16(CRGB::Gold, CRGB::DarkGoldenrod, CRGB::Goldenrod, CRGB::Yellow); // up to 16 colors

  CRGBPalette16 reds = CRGBPalette16(CRGB::DarkRed, CRGB::Red, CRGB::FireBrick, CRGB::Maroon); // up to 16 colors

  CRGBPalette16 oranges = CRGBPalette16(CRGB::OrangeRed, CRGB::Orange, CRGB::OrangeRed, CRGB::Orange); // up to 16 colors

  CRGBPalette16 blues = CRGBPalette16(CRGB::RoyalBlue, CRGB::DarkBlue, CRGB::DarkCyan, CRGB::Blue); // up to 16 colors

  CRGBPalette16 purples = CRGBPalette16(CRGB::DarkViolet, CRGB::Indigo, CRGB::Plum, CRGB::Purple); // up to 16 colors


void changePalette() {
// Change currentPalette according to the value of the global variable whichPalette

  switch(whichPalette) {
    case 0:
      currentPalette = greens;
    break;
    case 1:
      currentPalette = betterEaster;
    break;
    case 2:
      currentPalette = yellows;
    break;
    case 3:
      currentPalette = skylySun;
    break;
    case 4:
      currentPalette = blues;
    break;
    case 5:
      currentPalette = neon2019;
    break;
    case 6: 
      currentPalette = reds;
    break;
    case 7:
      currentPalette = tequilaSunriseSet;
    break;
    case 8:
      currentPalette = purples;
    break;
    case 9:
      currentPalette = betterPartyColors;
    break;
    case 10:
      currentPalette = oranges;
    break;
    case 11:
      currentPalette = rainbowPony;
    break;
    default:
      // processing should never reach here
      currentPalette = greens;
    break;
  }

  // increment whichPalette
  if(whichPalette < 11){
    whichPalette++;
  }
  else{
    whichPalette = 0;
  }
  
} // end changePalette
