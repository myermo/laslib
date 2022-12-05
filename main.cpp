//
// Created by miguelyermo on 4/12/22.
//

#include "LASReader.h"
#include <iostream>
#include <chrono>

int main()
{

  LASReader lasReader("./alcoy.las");

  auto start = std::chrono::high_resolution_clock::now();

  size_t i{};

  auto reader = lasReader.getPointReader();

  while(reader->readPoint()) {
    ++i;
  }

  // print number of points
  std::cout << "Number of points: " << i << std::endl;

  auto end = std::chrono::high_resolution_clock::now();


  // print time in milliseconds
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;

  return 0;
}