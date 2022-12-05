//
// Created by miguelyermo on 4/12/22.
//


#pragma once

#include "LASHeader.h"
#include "LASPoint.h"
#include "LASvlr.h"
#include "AbstractLASPointReader.h"
#include "vlrReader.h"

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
  LASvlr vlr; // Variable length record being currently read
  LASevlr evlr; // Extended variable length record being currently read

  // *** CONSTRUCTION / DESTRUCTION *** //
  public:
    explicit LASReader(const std::string& filePath);
    ~LASReader();

  // *** METHODS *** //
  public:
    std::shared_ptr<AbstractLASPointReader> getPointReader();
    std::shared_ptr<vlrReader> getVlrReader();
    std::shared_ptr<evlrReader> getEvlrReader();

  // *** GETTERS / SETTERS *** //

  const std::unique_ptr<LASHeader> &getLasHeader() const;
};
