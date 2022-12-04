//
// Created by miguelyermo on 4/12/22.
//

#include "AbstractLASPointReader.h"

#include <memory>

// implement readPoint for LASPointReader_1
bool LASPointReader_0::readPoint()
{
  uint8_t packet{};
  uint8_t classification{};

  // read point

  lasFile.read(reinterpret_cast<char*>(&point.x), 4);
  lasFile.read(reinterpret_cast<char*>(&point.y), 4);
  lasFile.read(reinterpret_cast<char*>(&point.z), 4);
  lasFile.read(reinterpret_cast<char*>(&point.intensity), 2);
  lasFile.read(reinterpret_cast<char*>(&packet), 1);

  // get 3 first bits of packet
  point.returnNumber = packet & 0b00000111;

  // get 3 next bits of packet
  point.numberOfReturns = (packet & 0b00111000) >> 3;

  // get 1 next bit of packet
  point.scanDirectionFlag = (packet & 0b01000000) >> 6;

  // get 1 next bit of packet
  point.edgeOfFlightLine = (packet & 0b10000000) >> 7;


  lasFile.read(reinterpret_cast<char*>(&classification), 1);

  // get 5 first bits of classification
  point.classification = classification & 0b00011111;

  // get 1 next bit of classification
  point.syntehticFlag = (classification & 0b00100000) >> 5;

  // get 1 next bit of classification
  point.keyPointFlag = (classification & 0b01000000) >> 6;

  // get 1 next bit of classification
  point.withheldFlag = (classification & 0b10000000) >> 7;

  lasFile.read(reinterpret_cast<char*>(&point.scanAngleRank), 1);
  lasFile.read(reinterpret_cast<char*>(&point.userData), 1);
  lasFile.read(reinterpret_cast<char*>(&point.pointSourceID), 2);


  // check if we reached the end of the file
  return !lasFile.eof();
}

bool LASPointReader_1::readPoint()
{
  reader_0.readPoint();
  lasFile.read(reinterpret_cast<char*>(&point.gpsTime), 8);

  return !lasFile.eof();
}

bool LASPointReader_2::readPoint()
{
  reader_0.readPoint();
  lasFile.read(reinterpret_cast<char*>(&point.red), 2);
  lasFile.read(reinterpret_cast<char*>(&point.green), 2);
  lasFile.read(reinterpret_cast<char*>(&point.blue), 2);

  return !lasFile.eof();
}

bool LASPointReader_3::readPoint()
{
  reader_0.readPoint();
  reader_1.readPoint();
  reader_2.readPoint();

  return !lasFile.eof();
}

std::unique_ptr<AbstractLASPointReader>
LASPointReaderFactory::createReader(std::ifstream &lasFile, LASPoint &point,
                                    PointDataRecordFormat format)
{
  switch (format)
  {
    case PointDataRecordFormat::Format0:
      return std::make_unique<LASPointReader_0>(lasFile, point);
    case PointDataRecordFormat::Format1:
      return std::make_unique<LASPointReader_1>(lasFile, point);
    case PointDataRecordFormat::Format2:
      return std::make_unique<LASPointReader_2>(lasFile, point);
    case PointDataRecordFormat::Format3:
      return std::make_unique<LASPointReader_3>(lasFile, point);
    default:
      return nullptr;
  }
}

PointDataRecordFormat chooseFormat(unsigned char format)
{
  switch (format)
  {
    case 0:
      return PointDataRecordFormat::Format0;
    case 1:
      return PointDataRecordFormat::Format1;
    case 2:
      return PointDataRecordFormat::Format2;
    case 3:
      return PointDataRecordFormat::Format3;
    default:
      return PointDataRecordFormat::Format0;
  }
}