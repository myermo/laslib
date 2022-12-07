//
// Created by miguelyermo on 4/12/22.
//


#pragma once

#include <fstream>
#include <cstdint>
#include <memory>

class LASHeader
{
public:
  class Impl;
  std::unique_ptr<Impl> impl{};


  // *** CONSTRUCTION / DESTRUCTION *** //
  LASHeader();
  ~LASHeader();

  // *** METHODS *** //
  void readHeader(std::ifstream &fileStream) const;
  void print() const;

  // *** GETTERS / SETTERS *** //
  [[nodiscard]] uint32_t getOffsetToPointData() const;
  [[nodiscard]] uint16_t getOffsetToVLR() const;
  [[nodiscard]] uint64_t getOffsetToEVLR() const;
  [[nodiscard]] unsigned char getPointDataRecordFormat() const;
  [[nodiscard]] const char* getFileSignature() const;
  [[nodiscard]] uint16_t getFileSourceId() const;
  [[nodiscard]] uint16_t getGlobalEncoding() const;
  [[nodiscard]] uint32_t getProjectIdGuidData1() const;
  [[nodiscard]] uint16_t getProjectIdGuidData2() const;
  [[nodiscard]] uint16_t getProjectIdGuidData3() const;
  [[nodiscard]] const unsigned char* getProjectIdGuidData4() const;
  [[nodiscard]] unsigned char getVersionMajor() const;
  [[nodiscard]] unsigned char getVersionMinor() const;
  [[nodiscard]] const char* getSystemIdentifier() const;
  [[nodiscard]] const char* getGeneratingSoftware() const;
  [[nodiscard]] uint16_t getFileCreationDayOfYear() const;
  [[nodiscard]] uint16_t getFileCreationYear() const;
  [[nodiscard]] uint16_t getHeaderSize() const;
  [[nodiscard]] uint32_t getNumberOfVariableLengthRecords() const;
  [[nodiscard]] uint16_t getPointDataRecordLength() const;
  [[nodiscard]] uint32_t getLegacyNumberOfPointRecords() const;
  [[nodiscard]] const uint32_t* getLegacyNumberOfPointsByReturn() const;
  [[nodiscard]] double getXScaleFactor() const;
  [[nodiscard]] double getYScaleFactor() const;
  [[nodiscard]] double getZScaleFactor() const;
  [[nodiscard]] double getXOffset() const;
  [[nodiscard]] double getYOffset() const;
  [[nodiscard]] double getZOffset() const;
  [[nodiscard]] double getMaxX() const;
  [[nodiscard]] double getMinX() const;
  [[nodiscard]] double getMaxY() const;
  [[nodiscard]] double getMinY() const;
  [[nodiscard]] double getMaxZ() const;
  [[nodiscard]] double getMinZ() const;
  [[nodiscard]] uint64_t getStartOfWaveformDataPacketRecord() const;
  [[nodiscard]] uint64_t getStartOfFirstExtendedVariableLengthRecord() const;
  [[nodiscard]] uint32_t getNumberOfExtendedVariableLengthRecords() const;
  [[nodiscard]] uint64_t getNumberOfPointRecords() const;
  [[nodiscard]] const uint64_t* getNumberOfPointsByReturn() const;
};
