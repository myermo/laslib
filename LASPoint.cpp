//
// Created by miguelyermo on 4/12/22.
//

#include "LASPoint.h"
#include <iostream>

void LASPoint::printPoint() const
{
  std::cout << (int) x << " " << (int) y << " " << (int) z << " "
  << (int) intensity << " " << (int) returnNumber << " "
  << (int) numberOfReturns << " " << (int) scanDirectionFlag << " "
  << (int) edgeOfFlightLine << " " << (int) classification << " "
  << (int) scanAngleRank << " " << (int) userData << " "
  << (int) pointSourceID << std::endl;
}