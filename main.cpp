//
// Created by miguelyermo on 4/12/22.
//

#include "LASReader.h"
#include "LASWriter.h"
#include <iostream>
#include <chrono>

int main()
{


  // Split file logic in LASReader and LASWriter classes.
  LASReader reader("./alcoy.las");

  auto start = std::chrono::high_resolution_clock::now();

  size_t i{};

  auto header = reader.getLasHeader();
  header->print();
  auto pReader = reader.getPointReader();



  LASWriter lw("./alcoy_out.las");
  lw.writeHeader(header);


  // compute number of current day of the year
  std::time_t t = std::time(nullptr);
  std::tm tm = *std::localtime(&t);
  uint16_t dayOfYear = tm.tm_yday;

  // compute current year
  uint16_t year = tm.tm_year + 1900;

  while(pReader->readPoint()) {
    ++i;
//    reader->point.printPoint();
    uint32_t x = pReader->point.getX();
    uint32_t y = pReader->point.getY();
    uint32_t z = pReader->point.getZ();
    uint16_t intensity = pReader->point.getI();
    uint8_t packet{};
    packet = pReader->point.getReturnNumber();
    packet |= pReader->point.getNumberOfReturns() << 3;
    packet |= pReader->point.getScanDirectionFlag() << 6;
    packet |= pReader->point.getEdgeOfFlightLine() << 7;
    uint8_t classification = pReader->point.getClassification();
    uint8_t scanAngleRank = pReader->point.getScanAngleRank();
    uint8_t userData = pReader->point.getUserData();
    uint16_t pointSourceId = pReader->point.getPointSourceID();

//    lasFileOut.write(reinterpret_cast<char*>(&x), sizeof(x));
//    lasFileOut.write(reinterpret_cast<char*>(&y), sizeof(y));
//    lasFileOut.write(reinterpret_cast<char*>(&z), sizeof(z));
//    lasFileOut.write(reinterpret_cast<char*>(&intensity), sizeof(intensity));
//    lasFileOut.write(reinterpret_cast<char*>(&packet), sizeof(packet));
//    lasFileOut.write(reinterpret_cast<char*>(&classification), sizeof(classification));
//    lasFileOut.write(reinterpret_cast<char*>(&scanAngleRank), sizeof(scanAngleRank));
//    lasFileOut.write(reinterpret_cast<char*>(&userData), sizeof(userData));
//    lasFileOut.write(reinterpret_cast<char*>(&pointSourceId), sizeof(pointSourceId));
  }

  // print number of points
  std::cout << "Number of points: " << i << std::endl;

  auto end = std::chrono::high_resolution_clock::now();


  // print time in milliseconds
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;






  return 0;
}