//
// Created by miguelyermo on 4/12/22.
//


#pragma once

#include <fstream>


class LASHeader
{
  // *** Attributes *** //
private:
  char fileSignature[4]{};
  u_int16_t fileSourceID{};
  u_int16_t globalEncoding{};
  u_int32_t projectID_GUID_data_1{};
  u_int16_t projectID_GUID_data_2{};
  u_int16_t projectID_GUID_data_3{};
  unsigned char projectID_GUID_data_4[8]{};
  unsigned char versionMajor{};
  unsigned char versionMinor{};
  char systemIdentifier[32]{};
  char generatingSoftware[32]{};
  u_int16_t fileCreationDayOfYear{};
  u_int16_t fileCreationYear{};
  u_int16_t headerSize{};
  u_int32_t offsetToPointData{};
  u_int32_t numberOfVariableLengthRecords{};
  unsigned char pointDataRecordFormat{};
  u_int16_t pointDataRecordLength{};
  u_int32_t legacyNumberOfPointRecords{};
  u_int32_t legacyNumberOfPointsByReturn[5]{};
  double xScaleFactor{};
  double yScaleFactor{};
  double zScaleFactor{};
  double xOffset{};
  double yOffset{};
  double zOffset{};
  double maxX{};
  double minX{};
  double maxY{};
  double minY{};
  double maxZ{};
  double minZ{};
//  u_int64_t startOfWaveformDataPacketRecord{};
//  u_int64_t startOfFirstExtendedVariableLengthRecord{};
//  u_int32_t numberOfExtendedVariableLengthRecords{};
//  u_int64_t numberOfPointRecords{};
//  u_int64_t numberOfPointsByReturn[15]{};


  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  LASHeader() = default;
  ~LASHeader() = default;

  // *** METHODS *** //
  void readHeader(std::ifstream &fileStream);
  void print();

  // *** GETTERS / SETTERS *** //
  [[nodiscard]] u_int32_t getOffsetToPointData() const;

  [[nodiscard]] unsigned char getPointDataRecordFormat() const;
};
