//
// Created by miguelyermo on 4/12/22.
//


#pragma once

#include <fstream>
#include <cstdint>


class LASHeader
{
  // *** Attributes *** //
private:
  char fileSignature[4]{};
  uint16_t fileSourceID{};
  uint16_t globalEncoding{};
  uint32_t projectID_GUID_data_1{};
  uint16_t projectID_GUID_data_2{};
  uint16_t projectID_GUID_data_3{};
  unsigned char projectID_GUID_data_4[8]{};
  unsigned char versionMajor{};
  unsigned char versionMinor{};
  char systemIdentifier[32]{};
  char generatingSoftware[32]{};
  uint16_t fileCreationDayOfYear{};
  uint16_t fileCreationYear{};
  uint16_t headerSize{};
  uint32_t offsetToPointData{};
  uint32_t numberOfVariableLengthRecords{};
  unsigned char pointDataRecordFormat{};
  uint16_t pointDataRecordLength{};
  uint32_t legacyNumberOfPointRecords{};
  uint32_t legacyNumberOfPointsByReturn[5]{};
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
  uint64_t startOfWaveformDataPacketRecord{};
  uint64_t startOfFirstExtendedVariableLengthRecord{};
  uint32_t numberOfExtendedVariableLengthRecords{};
  uint64_t numberOfPointRecords{};
  uint64_t numberOfPointsByReturn[15]{};


  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  LASHeader() = default;
  ~LASHeader() = default;

  // *** METHODS *** //
  void readHeader(std::ifstream &fileStream);
  void print();

  // *** GETTERS / SETTERS *** //
  [[nodiscard]] uint32_t getOffsetToPointData() const;

  [[nodiscard]] unsigned char getPointDataRecordFormat() const;
};
