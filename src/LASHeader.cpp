//
// Created by miguelyermo on 4/12/22.
//

#include "LASHeader.h"
#include <iostream>
#include <iomanip>

class LASHeader::Impl
{
public:
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
  Impl() = default;

  void readHeader(std::ifstream &fileStream)
  {
    // Read the file signature
    fileStream.read(reinterpret_cast<char*>(&fileSignature), 4);

    // Read the file source ID
    fileStream.read(reinterpret_cast<char*>(&fileSourceID), 2);

    // Read the global encoding
    fileStream.read(reinterpret_cast<char*>(&globalEncoding), 2);

    // Read the project ID GUID data 1
    fileStream.read(reinterpret_cast<char*>(&projectID_GUID_data_1), 4);

    // Read the project ID GUID data 2
    fileStream.read(reinterpret_cast<char*>(&projectID_GUID_data_2), 2);

    // Read the project ID GUID data 3
    fileStream.read(reinterpret_cast<char*>(&projectID_GUID_data_3), 2);

    // Read the project ID GUID data 4
    fileStream.read(reinterpret_cast<char*>(&projectID_GUID_data_4), 8);

    // Read the version major
    fileStream.read(reinterpret_cast<char*>(&versionMajor), 1);

    // Read the version minor
    fileStream.read(reinterpret_cast<char*>(&versionMinor), 1);

    // Read the system identifier
    fileStream.read(reinterpret_cast<char*>(&systemIdentifier), 32);

    // Read the generating software
    fileStream.read(reinterpret_cast<char*>(&generatingSoftware), 32);

    // Read the file creation day of year
    fileStream.read(reinterpret_cast<char*>(&fileCreationDayOfYear), 2);

    // Read the file creation year
    fileStream.read(reinterpret_cast<char*>(&fileCreationYear), 2);

    // Read the header size
    fileStream.read(reinterpret_cast<char*>(&headerSize), 2);

    // Read the offset to point data
    fileStream.read(reinterpret_cast<char*>(&offsetToPointData), 4);

    // Read the number of variable length records
    fileStream.read(reinterpret_cast<char*>(&numberOfVariableLengthRecords), 4);

    // Read the point data record format
    fileStream.read(reinterpret_cast<char*>(&pointDataRecordFormat), 1);

    // Read the point data record length
    fileStream.read(reinterpret_cast<char*>(&pointDataRecordLength), 2);

    // Read the legacy number of point records
    fileStream.read(reinterpret_cast<char*>(&legacyNumberOfPointRecords), 4);

    // Read the legacy number of points by return
    fileStream.read(reinterpret_cast<char*>(&legacyNumberOfPointsByReturn), 20);

    // Read the x scale factor
    fileStream.read(reinterpret_cast<char*>(&xScaleFactor), 8);

    // Read the y scale factor
    fileStream.read(reinterpret_cast<char*>(&yScaleFactor), 8);

    // Read the z scale factor
    fileStream.read(reinterpret_cast<char*>(&zScaleFactor), 8);

    // Read the x offset
    fileStream.read(reinterpret_cast<char*>(&xOffset), 8);

    // Read the y offset
    fileStream.read(reinterpret_cast<char*>(&yOffset), 8);

    // Read the z offset
    fileStream.read(reinterpret_cast<char*>(&zOffset), 8);

    // Read the max x
    fileStream.read(reinterpret_cast<char*>(&maxX), 8);

    // Read the min x
    fileStream.read(reinterpret_cast<char*>(&minX), 8);

    // Read the max y
    fileStream.read(reinterpret_cast<char*>(&maxY), 8);

    // Read the min y
    fileStream.read(reinterpret_cast<char*>(&minY), 8);

    // Read the max z
    fileStream.read(reinterpret_cast<char*>(&maxZ), 8);

    // Read the min z
    fileStream.read(reinterpret_cast<char*>(&minZ), 8);

    // Read fields only belonging to LAS 1.4 or greater
    if (versionMajor >= 1 && versionMinor >= 4)
    {
      // Read the start of wave data packet record
      fileStream.read(reinterpret_cast<char*>(&startOfWaveformDataPacketRecord),
                      8);

      // Read the start of first extended variable length record
      fileStream.read(
        reinterpret_cast<char*>(&startOfFirstExtendedVariableLengthRecord), 8);

      // Read the number of extended variable length records
      fileStream.read(
        reinterpret_cast<char*>(&numberOfExtendedVariableLengthRecords), 4);

      // Read the number of point records
      fileStream.read(reinterpret_cast<char*>(&numberOfPointRecords), 8);

      // Read the number of points by return
      fileStream.read(reinterpret_cast<char*>(&numberOfPointsByReturn), 120);
    }
  }

  void print()
  {
    // Print the header
    std::cout << std::setprecision(2) << std::fixed;

    std::cout << "File signature: " << fileSignature << std::endl;
    std::cout << "File source ID: " << fileSourceID << std::endl;
    std::cout << "Global encoding: " << globalEncoding << std::endl;
    std::cout << "Project ID GUID data 1: " << projectID_GUID_data_1
              << std::endl;
    std::cout << "Project ID GUID data 2: " << projectID_GUID_data_2
              << std::endl;
    std::cout << "Project ID GUID data 3: " << projectID_GUID_data_3
              << std::endl;
    std::cout << "Project ID GUID data 4: " << projectID_GUID_data_4
              << std::endl;
    std::cout << "Version major: " << static_cast<int>(versionMajor)
              << std::endl;
    std::cout << "Version minor: " << static_cast<int>(versionMinor)
              << std::endl;
    std::cout << "System identifier: " << systemIdentifier << std::endl;
    std::cout << "Generating software: " << generatingSoftware << std::endl;
    std::cout << "File creation day of year: " << fileCreationDayOfYear
              << std::endl;
    std::cout << "File creation year: " << fileCreationYear << std::endl;
    std::cout << "Header size: " << headerSize << std::endl;
    std::cout << "Offset to point data: " << offsetToPointData << std::endl;
    std::cout << "Number of variable length records: "
              << numberOfVariableLengthRecords << std::endl;
    std::cout << "Point data record format: "
              << static_cast<int>(pointDataRecordFormat) << std::endl;
    std::cout << "Point data record length: " << pointDataRecordLength
              << std::endl;
    std::cout << "Legacy number of point records: "
              << legacyNumberOfPointRecords << std::endl;
    std::cout << "Legacy number of points by return: "
              << legacyNumberOfPointsByReturn[0] << " "
              << legacyNumberOfPointsByReturn[1] << " "
              << legacyNumberOfPointsByReturn[2] << " "
              << legacyNumberOfPointsByReturn[3] << " "
              << legacyNumberOfPointsByReturn[4] << std::endl;
    std::cout << "X scale factor: " << xScaleFactor << std::endl;
    std::cout << "Y scale factor: " << yScaleFactor << std::endl;
    std::cout << "Z scale factor: " << zScaleFactor << std::endl;
    std::cout << "X offset: " << xOffset << std::endl;
    std::cout << "Y offset: " << yOffset << std::endl;
    std::cout << "Z offset: " << zOffset << std::endl;
    std::cout << "Max x: " << maxX << std::endl;
    std::cout << "Min x: " << minX << std::endl;
    std::cout << "Max y: " << maxY << std::endl;
    std::cout << "Min y: " << minY << std::endl;
    std::cout << "Max z: " << maxZ << std::endl;
    std::cout << "Min z: " << minZ << std::endl;
  }
};

LASHeader::LASHeader() : impl(std::make_unique<Impl>()) {}
LASHeader::~LASHeader() = default;

void LASHeader::readHeader(std::ifstream &fileStream) const
{
  impl->readHeader(fileStream);
}

void LASHeader::print() const { impl->print(); }

uint32_t LASHeader::getOffsetToPointData() const
{
  return impl->offsetToPointData;
}

unsigned char LASHeader::getPointDataRecordFormat() const
{
  return impl->pointDataRecordFormat;
};

uint16_t LASHeader::getOffsetToVLR() const
{
  return impl->headerSize;
};

uint64_t LASHeader::getOffsetToEVLR() const
{
  return impl->startOfFirstExtendedVariableLengthRecord;
}

const char* LASHeader::getFileSignature() const
{
  return impl->fileSignature;
}

uint16_t LASHeader::getFileSourceId() const
{
  return impl->fileSourceID;
}

uint16_t LASHeader::getGlobalEncoding() const
{
  return impl->globalEncoding;
}

uint32_t LASHeader::getProjectIdGuidData1() const
{
  return impl->projectID_GUID_data_1;
}

uint16_t LASHeader::getProjectIdGuidData2() const
{
  return impl->projectID_GUID_data_2;
}

uint16_t LASHeader::getProjectIdGuidData3() const
{
  return impl->projectID_GUID_data_3;
}

const unsigned char* LASHeader::getProjectIdGuidData4() const
{
  return impl->projectID_GUID_data_4;
}

unsigned char LASHeader::getVersionMajor() const
{
  return impl->versionMajor;
}

unsigned char LASHeader::getVersionMinor() const
{
  return impl->versionMinor;
}

const char* LASHeader::getSystemIdentifier() const
{
  return impl->systemIdentifier;
}

const char* LASHeader::getGeneratingSoftware() const
{
  return impl->generatingSoftware;
}

uint16_t LASHeader::getFileCreationDayOfYear() const
{
  return impl->fileCreationDayOfYear;
}

uint16_t LASHeader::getFileCreationYear() const
{
  return impl->fileCreationYear;
}

uint16_t LASHeader::getHeaderSize() const
{
  return impl->headerSize;
}

uint32_t LASHeader::getNumberOfVariableLengthRecords() const
{
  return impl->numberOfVariableLengthRecords;
}

uint16_t LASHeader::getPointDataRecordLength() const
{
  return impl->pointDataRecordLength;
}

uint32_t LASHeader::getLegacyNumberOfPointRecords() const
{
  return impl->legacyNumberOfPointRecords;
}

const uint32_t* LASHeader::getLegacyNumberOfPointsByReturn() const
{
  return impl->legacyNumberOfPointsByReturn;
}

double LASHeader::getXScaleFactor() const
{
  return impl->xScaleFactor;
}

double LASHeader::getYScaleFactor() const
{
  return impl->yScaleFactor;
}

double LASHeader::getZScaleFactor() const
{
  return impl->zScaleFactor;
}

double LASHeader::getXOffset() const
{
  return impl->xOffset;
}

double LASHeader::getYOffset() const
{
  return impl->yOffset;
}

double LASHeader::getZOffset() const
{
  return impl->zOffset;
}

double LASHeader::getMaxX() const
{
  return impl->maxX;
}

double LASHeader::getMinX() const
{
  return impl->minX;
}

double LASHeader::getMaxY() const
{
  return impl->maxY;
}

double LASHeader::getMinY() const
{
  return impl->minY;
}

double LASHeader::getMaxZ() const
{
  return impl->maxZ;
}

double LASHeader::getMinZ() const
{
  return impl->minZ;
}

uint64_t LASHeader::getStartOfWaveformDataPacketRecord() const
{
  return impl->startOfWaveformDataPacketRecord;
}

uint64_t LASHeader::getStartOfFirstExtendedVariableLengthRecord() const
{
  return impl->startOfFirstExtendedVariableLengthRecord;
}

uint32_t LASHeader::getNumberOfExtendedVariableLengthRecords() const
{
  return impl->numberOfExtendedVariableLengthRecords;
}

uint64_t LASHeader::getNumberOfPointRecords() const
{
  return impl->numberOfPointRecords;
}

const uint64_t* LASHeader::getNumberOfPointsByReturn() const
{
  return impl->numberOfPointsByReturn;
};