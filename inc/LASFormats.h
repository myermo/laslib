//
// Created by miguelyermo on 20/02/23.
//

#pragma once

// enumeration of LAS versions
enum LASVersion
{
  V_1_0 = 10,
  V_1_1 = 11,
  V_1_2 = 12,
  V_1_3 = 13,
  V_1_4 = 14
};

// enumeration of point data record formats
enum LASPointFormat
{
  Format0 = 0,
  Format1 = 1,
  Format2 = 2,
  Format3 = 3,
  Format4 = 4,
  Format5 = 5,
  Format6 = 6,
  Format7 = 7,
  Format8 = 8,
  Format9 = 9,
  Format10 = 10
};

LASPointFormat chooseFormat(unsigned char format);