//
// Created by miguelyermo on 4/12/22.
//

#include "LASReader.h"

int main()
{

  LASReader lasReader("./alcoy.las");

  lasReader.printHeader();

  lasReader.readPoint();

  return 0;
}