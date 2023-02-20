//
// Created by miguelyermo on 18/02/23.
//


#pragma once

#include <iostream>
#include "LASHeader.h"
#include "AbstractLASPointWriter.h"
#include "LASFormats.h"

class LASPoint; // forward declaration




class LASWriter {
public:
  // *** ATTRIBUTES *** //
  std::fstream lasFile;
  std::unique_ptr<AbstractLASPointWriter> pointWriter;

  // *** CONSTRUCTION / DESTRUCTION *** //
  LASWriter();
  LASWriter(const std::string& filename, const LASVersion version = LASVersion::V_1_4);

  // *** METHODS *** //
  void writeHeader(const std::shared_ptr<LASHeader>& header);
  void writePoint(const LASPoint& point) const;

  // *** OPERATORS *** //

  // *** GETTERS / SETTERS *** //
};
