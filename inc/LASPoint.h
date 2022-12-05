//
// Created by miguelyermo on 4/12/22.
//


#pragma once

#include <cstdint>

class LASPoint
{
  // *** ATTRIBUTES *** //
public:

  // Start of Point Data Record Format 0
  int32_t x{};
  int32_t y{};
  int32_t z{};
  uint16_t intensity{};
  unsigned char returnNumber: 3;
  unsigned char numberOfReturns: 3;
  unsigned char scanDirectionFlag: 1;
  unsigned char edgeOfFlightLine: 1;
  unsigned char classification: 5;
  unsigned char syntehticFlag: 1;
  unsigned char keyPointFlag: 1;
  unsigned char withheldFlag: 1;
  uint8_t scanAngleRank{};
  uint8_t userData{};
  uint16_t pointSourceID{};

  // Start of Point Data Record Format 1
  double gpsTime{};

  // Start of Point Data Record Format 2
  uint16_t red{};
  uint16_t green{};
  uint16_t blue{};
  uint16_t nir{};

  // Start of Point Data Record Format 3
  // Point Data Record Format 3 is the same as Point Data Record Format 2 with
  // the addition of the GPS Time field.

  // Start of Point Data Record Format 4
  unsigned char wavePacketDescriptorIndex{};
  uint64_t byteOffsetToWaveformData{};
  uint32_t waveformDataPacketSize{};
  float returnPointWaveformLocation{};
  float xt{};
  float yt{};
  float zt{};

  // Start of Point Data Record Format 6
  unsigned char extended_returnNumber: 4;
  unsigned char extended_numberOfReturns: 4;
  unsigned char extended_classificationFlags: 4;
  unsigned char extended_scannerChannel: 2;
  unsigned char extended_scanDirectionFlag: 1;
  unsigned char extended_edgeOfFlightLine: 1;
  unsigned char extended_classification{};
  uint16_t extended_scanAngleRank{};

public:

  // *** CONSTRUCTION / DESTRUCTION *** //
  LASPoint() = default;

  // *** METHODS *** //
  void printPoint() const;


  // *** GETTERS / SETTERS *** //

};
