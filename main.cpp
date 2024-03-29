//
// Created by miguelyermo on 4/12/22.
//

#include "LASReader.h"
#include "LASWriter.h"
#include <iostream>
#include <chrono>

int main()
{
  LASReader reader("./alcoy.las");

  auto start = std::chrono::high_resolution_clock::now();

  size_t i{};

  auto header = reader.getLasHeader();
  header->print();
  auto pReader = reader.getPointReader();

  LASWriter lw("./alcoy_out.las");
  lw.writeHeader(header);
  auto pw = lw.getPointWriter(LASPointFormat::Format0);

  while(pReader->readPoint()) {
    ++i;
    pw->writePoint(pReader->point);
  }

  // print number of points
  std::cout << "Number of points: " << i << std::endl;

  auto end = std::chrono::high_resolution_clock::now();


  // print time in milliseconds
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;

  return 0;
}