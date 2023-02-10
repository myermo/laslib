//
// Created by miguelyermo on 4/12/22.
//

#include "LASFile.h"
#include <iostream>
#include <chrono>

int main()
{

  LASFile lasFile("./alcoy.las");

  auto start = std::chrono::high_resolution_clock::now();

  size_t i{};

  auto header = lasFile.getLasHeader();
  header->print();
  auto reader = lasFile.getPointReader();
  while(reader->readPoint()) {
    ++i;
//    reader->point.printPoint();
  }

  // print number of points
  std::cout << "Number of points: " << i << std::endl;

  auto end = std::chrono::high_resolution_clock::now();


  // print time in milliseconds
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;

  return 0;
}