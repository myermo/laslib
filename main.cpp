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
    lw.writePoint(pReader->point);
  }

  // print number of points
  std::cout << "Number of points: " << i << std::endl;

  auto end = std::chrono::high_resolution_clock::now();


  // print time in milliseconds
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;






  return 0;
}