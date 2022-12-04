//
// Created by miguelyermo on 4/12/22.
//


#pragma once

#include <iomanip>

class LASPoint
{
  // *** ATTRIBUTES *** //
public:
  u_int32_t x{};
  u_int32_t y{};
  u_int32_t z{};
  u_int16_t intensity{};
  u_int8_t returnNumber: 3;
  unsigned char numberOfReturns: 3;
  unsigned char scanDirectionFlag: 1;
  unsigned char edgeOfFlightLine: 1;
  u_int8_t classification{};
  u_int8_t scanAngleRank{};
  u_int8_t userData{};
  u_int16_t pointSourceID{};


public:

  // *** CONSTRUCTION / DESTRUCTION *** //


  // *** METHODS *** //
  void printPoint() const;


  // *** GETTERS / SETTERS *** //
};
