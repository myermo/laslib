//
// Created by miguelyermo on 4/12/22.
//


#pragma once

#include <iomanip>

class LASPoint
{
  // *** ATTRIBUTES *** //
public:

  // Start of Point Data Record Format 0
  int32_t x{};
  int32_t y{};
  int32_t z{};
  u_int16_t intensity{};
  u_int8_t returnNumber: 3;
  unsigned char numberOfReturns: 3;
  unsigned char scanDirectionFlag: 1;
  unsigned char edgeOfFlightLine: 1;
  unsigned char classification: 5;
  unsigned char syntehticFlag: 1;
  unsigned char keyPointFlag: 1;
  unsigned char withheldFlag: 1;
  u_int8_t scanAngleRank{};
  u_int8_t userData{};
  u_int16_t pointSourceID{};

  // Start of Point Data Record Format 1
  double gpsTime{};

  // Start of Point Data Record Format 2
  u_int16_t red{};
  u_int16_t green{};
  u_int16_t blue{};

  // Start of Point Data Record Format 3
  // Point Data Record Format 3 is the same as Point Data Record Format 2 with
  // the addition of the GPS Time field.

public:

  // *** CONSTRUCTION / DESTRUCTION *** //
  LASPoint() = default;

  // *** METHODS *** //
  void printPoint() const;


  // *** GETTERS / SETTERS *** //
};
