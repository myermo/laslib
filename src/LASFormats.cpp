//
// Created by miguelyermo on 20/02/23.
//

#include "LASFormats.h"

LASPointFormat chooseFormat(unsigned char format) {
  switch (format) {
    case 0:
      return LASPointFormat::Format0;
    case 1:
      return LASPointFormat::Format1;
    case 2:
      return LASPointFormat::Format2;
    case 3:
      return LASPointFormat::Format3;
    case 4:
      return LASPointFormat::Format4;
    case 5:
      return LASPointFormat::Format5;
    case 6:
      return LASPointFormat::Format6;
    case 7:
      return LASPointFormat::Format7;
    case 8:
      return LASPointFormat::Format8;
    case 9:
      return LASPointFormat::Format9;
    case 10:
      return LASPointFormat::Format10;
    default:
      return LASPointFormat::Format0;
  }
}