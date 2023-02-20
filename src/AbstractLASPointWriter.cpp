//
// Created by miguelyermo on 20/02/23.
//

#include "AbstractLASPointWriter.h"
#include "LASPoint.h"

// Write X Y Z I
void writeXYZI(std::fstream& lasFile, const LASPoint& point) {
  uint32_t x = point.getX();
  uint32_t y = point.getY();
  uint32_t z = point.getZ();
  uint16_t intensity = point.getI();
  lasFile.write(reinterpret_cast<char*>(&x), sizeof(x));
  lasFile.write(reinterpret_cast<char*>(&y), sizeof(y));
  lasFile.write(reinterpret_cast<char*>(&z), sizeof(z));
  lasFile.write(reinterpret_cast<char*>(&intensity), sizeof(intensity));
}

// Write RGB fields
void writeRGB(std::fstream& lasFile, const LASPoint& point) {
  uint16_t r = point.getR();
  uint16_t g = point.getG();
  uint16_t b = point.getB();
  lasFile.write(reinterpret_cast<char*>(&r), sizeof(r));
  lasFile.write(reinterpret_cast<char*>(&g), sizeof(g));
  lasFile.write(reinterpret_cast<char*>(&b), sizeof(b));
}

// Write Wave Packets
void writeWavePackets(std::fstream& lasFile, const LASPoint& point) {
  unsigned char wavePacketDescriptorIndex = point.getWavePacketDescriptorIndex();
  uint64_t byteOffsetToWaveformData = point.getByteOffsetToWaveformData();
  uint32_t waveformDataPacketSize = point.getWaveformDataPacketSize();
  float returnPointWaveformLocation = point.getReturnPointWaveformLocation();
  float xt = point.getXt();
  float yt = point.getYt();
  float zt = point.getZt();
  lasFile.write(reinterpret_cast<char*>(&wavePacketDescriptorIndex), sizeof(wavePacketDescriptorIndex));
  lasFile.write(reinterpret_cast<char*>(&byteOffsetToWaveformData), sizeof(byteOffsetToWaveformData));
  lasFile.write(reinterpret_cast<char*>(&waveformDataPacketSize), sizeof(waveformDataPacketSize));
  lasFile.write(reinterpret_cast<char*>(&returnPointWaveformLocation), sizeof(returnPointWaveformLocation));
  lasFile.write(reinterpret_cast<char*>(&xt), sizeof(xt));
  lasFile.write(reinterpret_cast<char*>(&yt), sizeof(yt));
  lasFile.write(reinterpret_cast<char*>(&zt), sizeof(zt));
}

void LASPointWriter_0::writePoint(const LASPoint& point) {
  writeXYZI(lasFile, point);
  uint8_t packet{};
  packet = point.getReturnNumber();
  packet |= point.getNumberOfReturns() << 3;
  packet |= point.getScanDirectionFlag() << 6;
  packet |= point.getEdgeOfFlightLine() << 7;
  lasFile.write(reinterpret_cast<char*>(&packet), sizeof(packet));

  uint8_t classification = point.getClassification();
  uint8_t scanAngleRank = point.getScanAngleRank();
  uint8_t userData = point.getUserData();
  uint16_t pointSourceId = point.getPointSourceID();
  lasFile.write(reinterpret_cast<char*>(&classification), sizeof(classification));
  lasFile.write(reinterpret_cast<char*>(&scanAngleRank), sizeof(scanAngleRank));
  lasFile.write(reinterpret_cast<char*>(&userData), sizeof(userData));
  lasFile.write(reinterpret_cast<char*>(&pointSourceId), sizeof(pointSourceId));
}

void LASPointWriter_1::writePoint(const LASPoint& point) {

  writer_0.writePoint(point);
  double gpsTime = point.getGPSTime();
  lasFile.write(reinterpret_cast<char*>(&gpsTime), sizeof(gpsTime));
}

void LASPointWriter_2::writePoint(const LASPoint& point) {
  writer_0.writePoint(point);
  writeRGB(lasFile, point);
}

void LASPointWriter_3::writePoint(const LASPoint& point) {
  writer_0.writePoint(point);
  writer_1.writePoint(point);
  writer_2.writePoint(point);
}

void LASPointWriter_4::writePoint(const LASPoint& point) {
  writer_1.writePoint(point);
  writeWavePackets(lasFile, point);
}

void LASPointWriter_5::writePoint(const LASPoint& point) {
  writer_3.writePoint(point);
  writeWavePackets(lasFile, point);
}

void LASPointWriter_6::writePoint(const LASPoint& point) {
  uint16_t packet{};
  packet |= point.getExtendedReturnNumber();
  packet |= point.getExtendedNumberOfReturns() << 4;
  packet |= point.getExtendedClassificationFlags() << 8;
  packet |= point.getExtendedScannerChannel() << 10;
  packet |= point.getExtendedScanDirectionFlag() << 11;
  packet |= point.getExtendedEdgeOfFlightLine() << 12;

  uint8_t extendedClassification{}, userData{};
  uint16_t extended_scanAngleRank{}, pointSourceId{};
  double gpsTime{};

  extendedClassification = point.getExtendedClassification();
  userData = point.getUserData();
  extended_scanAngleRank = point.getExtendedScanAngleRank();
  pointSourceId = point.getPointSourceID();
  gpsTime = point.getGPSTime();

  writeXYZI(lasFile, point);
  lasFile.write(reinterpret_cast<char*>(&packet), sizeof(packet));
  lasFile.write(reinterpret_cast<char*>(&extendedClassification), sizeof(extendedClassification));
  lasFile.write(reinterpret_cast<char*>(&userData), sizeof(userData));
  lasFile.write(reinterpret_cast<char*>(&extended_scanAngleRank), sizeof(extended_scanAngleRank));
  lasFile.write(reinterpret_cast<char*>(&pointSourceId), sizeof(pointSourceId));
  lasFile.write(reinterpret_cast<char*>(&gpsTime), sizeof(gpsTime));

}

void LASPointWriter_7::writePoint(const LASPoint& point) {
  writer_6.writePoint(point);
  writeRGB(lasFile, point);
}

void LASPointWriter_8::writePoint(const LASPoint& point) {
  writer_7.writePoint(point);

  uint16_t nir = point.getNIR();
  lasFile.write(reinterpret_cast<char*>(&nir), sizeof(nir));
}

void LASPointWriter_9::writePoint(const LASPoint& point) {
  writer_6.writePoint(point);
  writeWavePackets(lasFile, point);
}

void LASPointWriter_10::writePoint(const LASPoint& point) {
  writer_8.writePoint(point);
  writeWavePackets(lasFile, point);
}

std::unique_ptr<AbstractLASPointWriter> createLASPointWriter
  (std::fstream& lasFile, const LASPointFormat format) {
  switch (format) {
    case LASPointFormat::Format0:
      return std::make_unique<LASPointWriter_0>(lasFile);
    case LASPointFormat::Format1:
      return std::make_unique<LASPointWriter_1>(lasFile);
    case LASPointFormat::Format2:
      return std::make_unique<LASPointWriter_2>(lasFile);
    case LASPointFormat::Format3:
      return std::make_unique<LASPointWriter_3>(lasFile);
    case LASPointFormat::Format4:
      return std::make_unique<LASPointWriter_4>(lasFile);
    case LASPointFormat::Format5:
      return std::make_unique<LASPointWriter_5>(lasFile);
    case LASPointFormat::Format6:
      return std::make_unique<LASPointWriter_6>(lasFile);
    case LASPointFormat::Format7:
      return std::make_unique<LASPointWriter_7>(lasFile);
    case LASPointFormat::Format8:
      return std::make_unique<LASPointWriter_8>(lasFile);
    case LASPointFormat::Format9:
      return std::make_unique<LASPointWriter_9>(lasFile);
    case LASPointFormat::Format10:
      return std::make_unique<LASPointWriter_10>(lasFile);
    default:
      throw std::runtime_error("Unknown LAS point format");
  }

}