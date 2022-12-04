//
// Created by miguelyermo on 4/12/22.
//

#include "LASHeader.h"
#include <fstream>

int main()
{

  // open binary file alcoy.las
  std::ifstream fileStream("./alcoy.las", std::ios::binary);

  LASHeader lasHeader;

  lasHeader.readHeader(fileStream);

  return 0;
}