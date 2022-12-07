//
// Created by miguelyermo on 4/12/22.
//

#include "LASPoint.h"
#include <iostream>
#include <memory>



// pimpl idiom
class LASPoint::Impl
{
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

  // *** CONSTRUCTION / DESTRUCTION *** //
  Impl() = default;

  // *** METHODS *** //
  void printPoint() const {
    std::cout << (int) x << " " << (int) y << " " << (int) z << " "
              << (int) intensity << " " << (int) returnNumber << " "
              << (int) numberOfReturns << " " << (int) scanDirectionFlag << " "
              << (int) edgeOfFlightLine << " " << (int) classification << " "
              << (int) scanAngleRank << " " << (int) userData << " "
              << (int) pointSourceID << std::endl;
  }
};

LASPoint::LASPoint() : impl(std::make_unique<Impl>()) {}
LASPoint::~LASPoint() = default;

// *** METHODS *** //
void LASPoint::printPoint() const {
  impl->printPoint();
}

// *** GETTERS / SETTERS *** //
int32_t LASPoint::getX() const { return impl->x; }
int32_t LASPoint::getY() const { return impl->y; }
int32_t LASPoint::getZ() const { return impl->z; }
uint16_t LASPoint::getI() const { return impl->intensity; }
uint16_t LASPoint::getR() const { return impl->red; }
uint16_t LASPoint::getG() const { return impl->green; }
uint16_t LASPoint::getB() const { return impl->blue; }
uint16_t LASPoint::getNIR() const { return impl->nir; }
uint8_t LASPoint::getReturnNumber() const {return impl->returnNumber; }
uint8_t LASPoint::getNumberOfReturns() const {return impl->numberOfReturns; }
uint8_t LASPoint::getScanDirectionFlag() const { return impl->scanDirectionFlag; }
uint8_t LASPoint::getEdgeOfFlightLine() const { return impl->edgeOfFlightLine; }
uint8_t LASPoint::getClassification() const {return impl->classification; }
uint8_t LASPoint::getScanAngleRank() const {return impl->scanAngleRank; }
uint8_t LASPoint::getUserData() const {return impl->userData; }
uint16_t LASPoint::getPointSourceID() const {return impl->pointSourceID; }
double LASPoint::getGPSTime() const {return impl->gpsTime; }
unsigned char LASPoint::getWavePacketDescriptorIndex() const {return impl->wavePacketDescriptorIndex; }
uint64_t LASPoint::getByteOffsetToWaveformData() const {return impl->byteOffsetToWaveformData; }
uint32_t LASPoint::getWaveformDataPacketSize() const {return impl->waveformDataPacketSize; }
float LASPoint::getReturnPointWaveformLocation() const {return impl->returnPointWaveformLocation; }
float LASPoint::getXt() const {return impl->xt; }
float LASPoint::getYt() const {return impl->yt; }
float LASPoint::getZt() const {return impl->zt; }
uint16_t LASPoint::getExtendedReturnNumber() const { return impl->extended_returnNumber; }
uint16_t LASPoint::getExtendedNumberOfReturns() const {return impl->extended_numberOfReturns; }
uint16_t LASPoint::getExtendedClassificationFlags() const {return impl->extended_classificationFlags; }
uint16_t LASPoint::getExtendedScannerChannel() const {return impl->extended_scannerChannel; }
uint16_t LASPoint::getExtendedScanDirectionFlag() const {return impl->extended_scanDirectionFlag; }
uint16_t LASPoint::getExtendedEdgeOfFlightLine() const {return impl->extended_edgeOfFlightLine; }
uint8_t LASPoint::getExtendedClassification() const {return impl->extended_classification; }
uint16_t LASPoint::getExtendedScanAngleRank() const {return impl->extended_scanAngleRank; }


void LASPoint::setX(int32_t x) const { impl->x = x; }
void LASPoint::setY(int32_t y) const { impl->y = y; }
void LASPoint::setZ(int32_t z) const { impl->z = z; }
void LASPoint::setI(uint16_t i) const { impl->intensity = i; }

void LASPoint::setReturnNumber(uint8_t packet) const
{
  impl->returnNumber = packet & 0x07;
}

void LASPoint::setNumberOfReturns(uint8_t packet) const
{ // TODO: check if is the same as (packet & 0b00111000) >> 3
  impl->numberOfReturns = (packet >> 3) & 0x07;
}

void LASPoint::setScanDirectionFlag(uint8_t packet) const
{
  impl->scanDirectionFlag = (packet >> 6) & 0x01;
}

void LASPoint::setEdgeOfFlightLine(uint8_t packet) const
{
  impl->edgeOfFlightLine = (packet >> 7) & 0x01;
}

void LASPoint::setClassification(uint8_t classification) const
{
  impl->classification = classification & 0x1F;
  impl->syntehticFlag = (classification >> 5) & 0x01;
  impl->keyPointFlag = (classification >> 6) & 0x01;
  impl->withheldFlag = (classification >> 7) & 0x01;
}

void LASPoint::setScanAngleRank(uint8_t scanAngleRank) const
{ impl->scanAngleRank = scanAngleRank; }

void LASPoint::setUserData(uint8_t userData) const
{ impl->userData = userData; }

void LASPoint::setPointSourceID(uint16_t pointSourceID) const
{ impl->pointSourceID = pointSourceID; }

void LASPoint::setR(uint16_t r) const { impl->red = r; }
void LASPoint::setG(uint16_t g) const { impl->green = g; }
void LASPoint::setB(uint16_t b) const { impl->blue = b; }
void LASPoint::setNIR(uint16_t nir) const { impl->nir = nir; }

void LASPoint::setGPSTime(double gpsTime) const { impl->gpsTime = gpsTime; }

void LASPoint::setWavePacketDescriptorIndex
(unsigned char wavePacketDescriptorIndex) const
{ impl->wavePacketDescriptorIndex = wavePacketDescriptorIndex; }

void LASPoint::setByteOffsetToWaveformData
(uint64_t byteOffsetToWaveformData) const
{ impl->byteOffsetToWaveformData = byteOffsetToWaveformData; }

void LASPoint::setWaveformDataPacketSize
(uint32_t waveformDataPacketSize) const
{ impl->waveformDataPacketSize = waveformDataPacketSize; }

void LASPoint::setReturnPointWaveformLocation
(float returnPointWaveformLocation) const
{ impl->returnPointWaveformLocation = returnPointWaveformLocation; }

void LASPoint::setExtendedReturnNumber(uint16_t packet) const
{
  impl->extended_returnNumber = packet & 0x0F;
}

void LASPoint::setExtendedNumberOfReturns(uint16_t packet) const
{
  impl->extended_numberOfReturns = (packet >> 4) & 0x0F;
}

void LASPoint::setExtendedClassificationFlags(uint16_t packet) const
{
  impl->extended_classificationFlags = (packet >> 8) & 0x0F;
}

void LASPoint::setExtendedScannerChannel(uint16_t packet) const
{
  impl->extended_scannerChannel = (packet >> 12) & 0x03;
}

void LASPoint::setExtendedScanDirectionFlag(uint16_t packet) const
{
  impl->extended_scanDirectionFlag = (packet >> 14) & 0x01;
}

void LASPoint::setExtendedEdgeOfFlightLine(uint16_t packet) const
{
  impl->extended_edgeOfFlightLine = (packet >> 15) & 0x01;
}

void LASPoint::setExtendedClassification(uint8_t classification) const
{
  impl->extended_classification = classification;
}

void LASPoint::setExtendedScanAngleRank(uint16_t scanAngleRank) const
{
  impl->extended_scanAngleRank = scanAngleRank;
}

void LASPoint::setXt(float xt) const { impl->xt = xt; }
void LASPoint::setYt(float yt) const { impl->yt = yt; }
void LASPoint::setZt(float zt) const { impl->zt = zt; }
