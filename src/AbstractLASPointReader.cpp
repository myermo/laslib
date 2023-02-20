//
// Created by miguelyermo on 4/12/22.
//

#include "AbstractLASPointReader.h"
#include <memory>

// Auxiliar functions

// Read X Y Z I
void readXYZI(std::fstream& lasFile, LASPoint &point) {

  int32_t x, y, z;
  uint16_t I;

  lasFile.read(reinterpret_cast<char*>(&x), 4);
  lasFile.read(reinterpret_cast<char*>(&y), 4);
  lasFile.read(reinterpret_cast<char*>(&z), 4);
  lasFile.read(reinterpret_cast<char*>(&I), 2);

  point.setX(x);
  point.setY(y);
  point.setZ(z);
  point.setI(I);
}

// Read RGB fields
void readRGB(std::fstream& lasFile, LASPoint &point)
{

  uint16_t r, g, b;

  lasFile.read(reinterpret_cast<char*>(&r), 2);
  lasFile.read(reinterpret_cast<char*>(&g), 2);
  lasFile.read(reinterpret_cast<char*>(&b), 2);

  point.setR(r);
  point.setG(g);
  point.setB(b);
}

// Read Wave Packets
void readWavePackets(std::fstream& lasFile, LASPoint &point)
{

  unsigned char wavePacketDescriptorIndex;
  uint64_t byteOffsetToWaveformData;
  uint32_t waveformDataPacketSize;
  float returnPointWaveformLocation, xt, yt, zt;

  lasFile.read(reinterpret_cast<char*>(&wavePacketDescriptorIndex), 1);
  lasFile.read(reinterpret_cast<char*>(&byteOffsetToWaveformData), 8);
  lasFile.read(reinterpret_cast<char*>(&waveformDataPacketSize), 4);
  lasFile.read(reinterpret_cast<char*>(&returnPointWaveformLocation), 8);
  lasFile.read(reinterpret_cast<char*>(&xt), 4);
  lasFile.read(reinterpret_cast<char*>(&yt), 4);
  lasFile.read(reinterpret_cast<char*>(&zt), 4);

  point.setWavePacketDescriptorIndex(wavePacketDescriptorIndex);
  point.setByteOffsetToWaveformData(byteOffsetToWaveformData);
  point.setWaveformDataPacketSize(waveformDataPacketSize);
  point.setReturnPointWaveformLocation(returnPointWaveformLocation);
  point.setXt(xt);
  point.setYt(yt);
  point.setZt(zt);
}

// implement getPointReader for LASPointReader_1
bool LASPointReader_0::readPoint()
{
  uint8_t packet{}, classification{}, scanAngleRank{}, userData{};
  uint16_t pointSourceID{};

  // read point
  readXYZI(lasFile, point);

  lasFile.read(reinterpret_cast<char*>(&packet), 1);

  point.setReturnNumber(packet);
  point.setNumberOfReturns(packet);
  point.setScanDirectionFlag(packet);
  point.setEdgeOfFlightLine(packet);


  lasFile.read(reinterpret_cast<char*>(&classification), 1);

  point.setClassification(classification);

  lasFile.read(reinterpret_cast<char*>(&scanAngleRank), 1);
  lasFile.read(reinterpret_cast<char*>(&userData), 1);
  lasFile.read(reinterpret_cast<char*>(&pointSourceID), 2);

  point.setScanAngleRank(scanAngleRank);
  point.setUserData(userData);
  point.setPointSourceID(pointSourceID);

  // check if we reached the end of the file
  return lasFile.good();
}

bool LASPointReader_1::readPoint()
{
  reader_0.readPoint();

  double gpsTime;

  lasFile.read(reinterpret_cast<char*>(&gpsTime), 8);

  point.setGPSTime(gpsTime);

  return lasFile.good();
}

bool LASPointReader_2::readPoint()
{
  reader_0.readPoint();

  readRGB(lasFile, point);
  return lasFile.good();
}

bool LASPointReader_3::readPoint()
{
  reader_0.readPoint();
  reader_1.readPoint();
  reader_2.readPoint();

  return lasFile.good();
}

bool LASPointReader_4::readPoint()
{
  reader_1.readPoint();

  readWavePackets(lasFile, point);

  return lasFile.good();
}

bool LASPointReader_5::readPoint()
{
  reader_3.readPoint();

  readWavePackets(lasFile, point);

  return lasFile.good();
}

bool LASPointReader_6::readPoint()
{
  readXYZI(lasFile, point);

  uint16_t packet{};

  lasFile.read(reinterpret_cast<char*>(&packet), 2);

  point.setExtendedReturnNumber(packet);
  point.setExtendedNumberOfReturns(packet);
  point.setExtendedClassificationFlags(packet);
  point.setExtendedScannerChannel(packet);
  point.setExtendedScanDirectionFlag(packet);
  point.setExtendedEdgeOfFlightLine(packet);

  uint8_t extended_classification, userData;
  uint16_t extended_scanAngleRank, pointSourceID;
  double gpsTime;

  lasFile.read(reinterpret_cast<char*>(&extended_classification), 1);
  lasFile.read(reinterpret_cast<char*>(&userData), 1);
  lasFile.read(reinterpret_cast<char*>(&extended_scanAngleRank), 2);
  lasFile.read(reinterpret_cast<char*>(&pointSourceID), 2);
  lasFile.read(reinterpret_cast<char*>(&gpsTime), 8);

  point.setExtendedClassification(extended_classification);
  point.setUserData(userData);
  point.setExtendedScanAngleRank(extended_scanAngleRank);
  point.setPointSourceID(pointSourceID);
  point.setGPSTime(gpsTime);

  // ExtraByte reading should be here

  return lasFile.good();
}

bool LASPointReader_7::readPoint()
{
  reader_6.readPoint();

  readRGB(lasFile, point);

  return lasFile.good();
}

bool LASPointReader_8::readPoint()
{
  reader_7.readPoint();

  uint16_t nir;

  lasFile.read(reinterpret_cast<char*>(&nir), 2);
  point.setNIR(nir);

  return lasFile.good();
}

bool LASPointReader_9::readPoint()
{
  reader_6.readPoint();
  readWavePackets(lasFile, point);

  return lasFile.good();
}

bool LASPointReader_10::readPoint()
{
  reader_8.readPoint();
  readWavePackets(lasFile, point);

  return lasFile.good();
}

std::shared_ptr<AbstractLASPointReader>
LASPointReaderFactory::createReader(std::fstream& lasFile, LASPoint &point,
                                    LASPointFormat format)
{
  switch (format)
  {
    case LASPointFormat::Format0:
      return std::make_shared<LASPointReader_0>(lasFile, point);
    case LASPointFormat::Format1:
      return std::make_shared<LASPointReader_1>(lasFile, point);
    case LASPointFormat::Format2:
      return std::make_shared<LASPointReader_2>(lasFile, point);
    case LASPointFormat::Format3:
      return std::make_shared<LASPointReader_3>(lasFile, point);
    case LASPointFormat::Format4:
      return std::make_shared<LASPointReader_4>(lasFile, point);
    case LASPointFormat::Format5:
      return std::make_shared<LASPointReader_5>(lasFile, point);
    case LASPointFormat::Format6:
      return std::make_shared<LASPointReader_6>(lasFile, point);
    case LASPointFormat::Format7:
      return std::make_shared<LASPointReader_7>(lasFile, point);
    case LASPointFormat::Format8:
      return std::make_shared<LASPointReader_8>(lasFile, point);
    case LASPointFormat::Format9:
      return std::make_shared<LASPointReader_9>(lasFile, point);
    case LASPointFormat::Format10:
      return std::make_shared<LASPointReader_10>(lasFile, point);
    default:
      throw std::runtime_error("Unknown LAS point format");
  }
}