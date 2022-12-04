//
// Created by miguelyermo on 4/12/22.
//


#pragma once

#include "LASHeader.h"
#include "LASPoint.h"
#include "AbstractLASPointReader.h"

#include <string>
#include <fstream>
#include <memory>

class LASReader
{
private:
  // *** ATTRIBUTES *** //
  std::ifstream lasFile{};
  std::unique_ptr<LASHeader> lasHeader;
  LASPoint point; // Point being currently read
  std::unique_ptr<AbstractLASPointReader> reader;

  // *** CONSTRUCTION / DESTRUCTION *** //
  public:
    LASReader(const std::string& filePath);
    ~LASReader();

  // *** METHODS *** //
  public:
    void printHeader();
    bool readPoint();

  // *** GETTERS / SETTERS *** //
};
