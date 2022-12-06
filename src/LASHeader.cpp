//
// Created by miguelyermo on 4/12/22.
//

#include "LASHeader.h"
#include <iostream>
#include <iomanip>

void LASHeader::readHeader(std::ifstream& fileStream)
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

// Read campos only belonging to LAS 1.4
if (versionMajor >= 1 && versionMinor >= 4)
{
  // Read the start of wave data packet record
  fileStream.read(reinterpret_cast<char*>(&startOfWaveformDataPacketRecord), 8);

  // Read the start of first extended variable length record
  fileStream.read(reinterpret_cast<char*>(&startOfFirstExtendedVariableLengthRecord), 8);

  // Read the number of extended variable length records
  fileStream.read(reinterpret_cast<char*>(&numberOfExtendedVariableLengthRecords), 4);

  // Read the number of point records
  fileStream.read(reinterpret_cast<char*>(&numberOfPointRecords), 8);

  // Read the number of points by return
  fileStream.read(reinterpret_cast<char*>(&numberOfPointsByReturn), 120);
}
}

void LASHeader::print() {
  // Print the header
  std::cout << std::setprecision(2) << std::fixed;

  std::cout << "File signature: " << fileSignature << std::endl;
  std::cout << "File source ID: " << fileSourceID << std::endl;
  std::cout << "Global encoding: " << globalEncoding << std::endl;
  std::cout << "Project ID GUID data 1: " << projectID_GUID_data_1 << std::endl;
  std::cout << "Project ID GUID data 2: " << projectID_GUID_data_2 << std::endl;
  std::cout << "Project ID GUID data 3: " << projectID_GUID_data_3 << std::endl;
  std::cout << "Project ID GUID data 4: " << projectID_GUID_data_4 << std::endl;
  std::cout << "Version major: " << static_cast<int>(versionMajor) << std::endl;
  std::cout << "Version minor: " << static_cast<int>(versionMinor) << std::endl;
  std::cout << "System identifier: " << systemIdentifier << std::endl;
  std::cout << "Generating software: " << generatingSoftware << std::endl;
  std::cout << "File creation day of year: " << fileCreationDayOfYear << std::endl;
  std::cout << "File creation year: " << fileCreationYear << std::endl;
  std::cout << "Header size: " << headerSize << std::endl;
  std::cout << "Offset to point data: " << offsetToPointData << std::endl;
  std::cout << "Number of variable length records: " << numberOfVariableLengthRecords << std::endl;
  std::cout << "Point data record format: " << static_cast<int>(pointDataRecordFormat) << std::endl;
  std::cout << "Point data record length: " << pointDataRecordLength << std::endl;
  std::cout << "Legacy number of point records: " << legacyNumberOfPointRecords << std::endl;
  std::cout << "Legacy number of points by return: " << legacyNumberOfPointsByReturn[0] << " "
  << legacyNumberOfPointsByReturn[1] << " " << legacyNumberOfPointsByReturn[2] << " " << legacyNumberOfPointsByReturn[3] << " "
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

  uint32_t LASHeader::getOffsetToPointData() const {
  return offsetToPointData;
}

unsigned char LASHeader::getPointDataRecordFormat() const
{
  return pointDataRecordFormat;
};

uint16_t LASHeader::getOffsetToVLR() const
{
  return headerSize;
};

uint64_t LASHeader::getOffsetToEVLR() const
{
  return startOfFirstExtendedVariableLengthRecord;
}

const char* LASHeader::getFileSignature() const
{
  return fileSignature;
}

uint16_t LASHeader::getFileSourceId() const
{
  return fileSourceID;
}

uint16_t LASHeader::getGlobalEncoding() const
{
  return globalEncoding;
}

uint32_t LASHeader::getProjectIdGuidData1() const
{
  return projectID_GUID_data_1;
}

uint16_t LASHeader::getProjectIdGuidData2() const
{
  return projectID_GUID_data_2;
}

uint16_t LASHeader::getProjectIdGuidData3() const
{
  return projectID_GUID_data_3;
}

const unsigned char* LASHeader::getProjectIdGuidData4() const
{
  return projectID_GUID_data_4;
}

unsigned char LASHeader::getVersionMajor() const
{
  return versionMajor;
}

unsigned char LASHeader::getVersionMinor() const
{
  return versionMinor;
}

const char* LASHeader::getSystemIdentifier() const
{
  return systemIdentifier;
}

const char* LASHeader::getGeneratingSoftware() const
{
  return generatingSoftware;
}

uint16_t LASHeader::getFileCreationDayOfYear() const
{
  return fileCreationDayOfYear;
}

uint16_t LASHeader::getFileCreationYear() const
{
  return fileCreationYear;
}

uint16_t LASHeader::getHeaderSize() const
{
  return headerSize;
}

uint32_t LASHeader::getNumberOfVariableLengthRecords() const
{
  return numberOfVariableLengthRecords;
}

uint16_t LASHeader::getPointDataRecordLength() const
{
  return pointDataRecordLength;
}

uint32_t LASHeader::getLegacyNumberOfPointRecords() const
{
  return legacyNumberOfPointRecords;
}

const uint32_t* LASHeader::getLegacyNumberOfPointsByReturn() const
{
  return legacyNumberOfPointsByReturn;
}

double LASHeader::getXScaleFactor() const
{
  return xScaleFactor;
}

double LASHeader::getYScaleFactor() const
{
  return yScaleFactor;
}

double LASHeader::getZScaleFactor() const
{
  return zScaleFactor;
}

double LASHeader::getXOffset() const
{
  return xOffset;
}

double LASHeader::getYOffset() const
{
  return yOffset;
}

double LASHeader::getZOffset() const
{
  return zOffset;
}

double LASHeader::getMaxX() const
{
  return maxX;
}

double LASHeader::getMinX() const
{
  return minX;
}

double LASHeader::getMaxY() const
{
  return maxY;
}

double LASHeader::getMinY() const
{
  return minY;
}

double LASHeader::getMaxZ() const
{
  return maxZ;
}

double LASHeader::getMinZ() const
{
  return minZ;
}

uint64_t LASHeader::getStartOfWaveformDataPacketRecord() const
{
  return startOfWaveformDataPacketRecord;
}

uint64_t LASHeader::getStartOfFirstExtendedVariableLengthRecord() const
{
  return startOfFirstExtendedVariableLengthRecord;
}

uint32_t LASHeader::getNumberOfExtendedVariableLengthRecords() const
{
  return numberOfExtendedVariableLengthRecords;
}

uint64_t LASHeader::getNumberOfPointRecords() const
{
  return numberOfPointRecords;
}

const uint64_t* LASHeader::getNumberOfPointsByReturn() const
{
  return numberOfPointsByReturn;
};