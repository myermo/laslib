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

bool LASPointReader_4::readPoint()
{
  reader_1.readPoint();

  lasFile.read(reinterpret_cast<char*>(&point.wavePacketDescriptorIndex), 1);
  lasFile.read(reinterpret_cast<char*>(&point.byteOffsetToWaveformData), 8);
  lasFile.read(reinterpret_cast<char*>(&point.waveformDataPacketSize), 4);
  lasFile.read(reinterpret_cast<char*>(&point.returnPointWaveformLocation), 4);
  lasFile.read(reinterpret_cast<char*>(&point.xt), 4);
  lasFile.read(reinterpret_cast<char*>(&point.yt), 4);
  lasFile.read(reinterpret_cast<char*>(&point.zt), 4);


  return !lasFile.eof();
}

bool LASPointReader_5::readPoint()
{
  reader_3.readPoint();

  // TODO: Avoid code duplication with LASPointReader_4
  lasFile.read(reinterpret_cast<char*>(&point.wavePacketDescriptorIndex), 1);
  lasFile.read(reinterpret_cast<char*>(&point.byteOffsetToWaveformData), 8);
  lasFile.read(reinterpret_cast<char*>(&point.waveformDataPacketSize), 4);
  lasFile.read(reinterpret_cast<char*>(&point.returnPointWaveformLocation), 4);
  lasFile.read(reinterpret_cast<char*>(&point.xt), 4);
  lasFile.read(reinterpret_cast<char*>(&point.yt), 4);
  lasFile.read(reinterpret_cast<char*>(&point.zt), 4);

  return !lasFile.eof();
}

bool LASPointReader_6::readPoint()
{

  // TODO: Avoid code duplication
  lasFile.read(reinterpret_cast<char*>(&point.x), 4);
  lasFile.read(reinterpret_cast<char*>(&point.y), 4);
  lasFile.read(reinterpret_cast<char*>(&point.z), 4);
  lasFile.read(reinterpret_cast<char*>(&point.intensity), 2);

  uint16_t packet{};
  uint8_t classification{};

  lasFile.read(reinterpret_cast<char*>(&packet), 2);


  // get 0-3 bits of packet
  point.extended_returnNumber = packet & 0x0F;

  // get 4-7 bits of packet
  point.extended_numberOfReturns = (packet & 0xF0) >> 4;

  // get 8-11 bits of packet
  point.extended_classificationFlags = (packet & 0x0F00) >> 8;

  // get 2 next bits of packet
  point.extended_scannerChannel = (packet & 0x3000) >> 12;

  // get 1 next bits of packet
  point.extended_scanDirectionFlag = (packet & 0x4000) >> 14;

  // get 1 next bits of packet
  point.extended_edgeOfFlightLine = (packet & 0x8000) >> 15;

  lasFile.read(reinterpret_cast<char*>(&point.extended_classification), 1);

  lasFile.read(reinterpret_cast<char*>(&point.userData), 1);
  lasFile.read(reinterpret_cast<char*>(&point.extended_scanAngleRank), 2);
  lasFile.read(reinterpret_cast<char*>(&point.pointSourceID), 2);
  lasFile.read(reinterpret_cast<char*>(&point.gpsTime), 8);



  return !lasFile.eof();
}

bool LASPointReader_7::readPoint()
{
  reader_6.readPoint();

  lasFile.read(reinterpret_cast<char*>(&point.red), 2);
  lasFile.read(reinterpret_cast<char*>(&point.green), 2);
  lasFile.read(reinterpret_cast<char*>(&point.blue), 2);

  return !lasFile.eof();
}

bool LASPointReader_8::readPoint()
{
  reader_7.readPoint();

  lasFile.read(reinterpret_cast<char*>(&point.nir), 2);

  return !lasFile.eof();
}

bool LASPointReader_9::readPoint()
{
  reader_6.readPoint();

  lasFile.read(reinterpret_cast<char*>(&point.wavePacketDescriptorIndex), 1);
  lasFile.read(reinterpret_cast<char*>(&point.byteOffsetToWaveformData), 8);
  lasFile.read(reinterpret_cast<char*>(&point.waveformDataPacketSize), 4);
  lasFile.read(reinterpret_cast<char*>(&point.returnPointWaveformLocation), 4);
  lasFile.read(reinterpret_cast<char*>(&point.xt), 4);
  lasFile.read(reinterpret_cast<char*>(&point.yt), 4);
  lasFile.read(reinterpret_cast<char*>(&point.zt), 4);

  return !lasFile.eof();
}

bool LASPointReader_10::readPoint()
{
  reader_8.readPoint();

  lasFile.read(reinterpret_cast<char*>(&point.wavePacketDescriptorIndex), 1);
  lasFile.read(reinterpret_cast<char*>(&point.byteOffsetToWaveformData), 8);
  lasFile.read(reinterpret_cast<char*>(&point.waveformDataPacketSize), 4);
  lasFile.read(reinterpret_cast<char*>(&point.returnPointWaveformLocation), 4);
  lasFile.read(reinterpret_cast<char*>(&point.xt), 4);
  lasFile.read(reinterpret_cast<char*>(&point.yt), 4);
  lasFile.read(reinterpret_cast<char*>(&point.zt), 4);

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
    case 4:
      return PointDataRecordFormat::Format4;
    case 5:
      return PointDataRecordFormat::Format5;
    case 6:
      return PointDataRecordFormat::Format6;
    case 7:
      return PointDataRecordFormat::Format7;
    case 8:
      return PointDataRecordFormat::Format8;
    case 9:
      return PointDataRecordFormat::Format9;
    case 10:
      return PointDataRecordFormat::Format10;
    default:
      return PointDataRecordFormat::Format0;
  }
}