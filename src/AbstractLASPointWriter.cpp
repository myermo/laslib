//
// Created by miguelyermo on 20/02/23.
//

#include "AbstractLASPointWriter.h"
#include "LASPoint.h"

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