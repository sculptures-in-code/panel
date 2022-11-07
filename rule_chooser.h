// Last modified: 08/11/2019
// this is in its own file due to extremely long switch statement
#pragma once
// Apply the current brightness rule to the given neighborhood
int applyBrightness(int rule, CRGB leftNeighbor, CRGB self, CRGB rightNeighbor) {

  int new_brightness = -1;
  switch(rule) {
    case 13:
      new_brightness = rule13(leftNeighbor, self, rightNeighbor);
      break;
    case 57:
      new_brightness = rule57(leftNeighbor, self, rightNeighbor);
      break;
    case 73:
      new_brightness = rule73(leftNeighbor, self, rightNeighbor);
      break;
    case 77:
      new_brightness = rule77(leftNeighbor, self, rightNeighbor);
      break;
    case 84:
      new_brightness = rule84(leftNeighbor, self, rightNeighbor);
      break;
    case 90:
      new_brightness = rule90(leftNeighbor, self, rightNeighbor);
      break;
    case 91:
      new_brightness = rule91(leftNeighbor, self, rightNeighbor);
      break;
    case 101:
      new_brightness = rule101(leftNeighbor, self, rightNeighbor);
      break;
    case 105:
      new_brightness = rule105(leftNeighbor, self, rightNeighbor);
      break;
    case 109:
      new_brightness = rule109(leftNeighbor, self, rightNeighbor);
      break;
    case 110:
      new_brightness = rule110(leftNeighbor, self, rightNeighbor);
      break;
    case 113:
      new_brightness = rule113(leftNeighbor, self, rightNeighbor);
      break;
    case 124:
      new_brightness = rule124(leftNeighbor, self, rightNeighbor);
      break;
    case 129:
      new_brightness = rule129(leftNeighbor, self, rightNeighbor);
      break;
    case 150:
      new_brightness = rule150(leftNeighbor, self, rightNeighbor);
      break;
    case 157:
      new_brightness = rule157(leftNeighbor, self, rightNeighbor);
      break;
    case 160:
      new_brightness = rule160(leftNeighbor, self, rightNeighbor);
      break;
    case 168:
      new_brightness = rule168(leftNeighbor, self, rightNeighbor);
      break;
    case 169:
      new_brightness = rule169(leftNeighbor, self, rightNeighbor);
      break;
    case 181:
      new_brightness = rule181(leftNeighbor, self, rightNeighbor);
      break;
    case 182:
      new_brightness = rule182(leftNeighbor, self, rightNeighbor);
      break;
    case 188:
      new_brightness = rule188(leftNeighbor, self, rightNeighbor);
      break;
    case 194:
      new_brightness = rule194(leftNeighbor, self, rightNeighbor);
      break;
    case 216:
      new_brightness = rule216(leftNeighbor, self, rightNeighbor);
      break;
    case 225:
      new_brightness = rule225(leftNeighbor, self, rightNeighbor);
      break;
    case 232:
      new_brightness = rule232(leftNeighbor, self, rightNeighbor);
      break;
    case 235:
      new_brightness = rule235(leftNeighbor, self, rightNeighbor);
      break;
    case 254:
      new_brightness = rule254(leftNeighbor, self, rightNeighbor);
      break;
    default:
      break;
  } // end switch

  return(new_brightness);
} // end applyBrightness
