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

  // *** CONSTRUCTION / DESTRUCTION *** //
  LASWriter();
  LASWriter(const std::string& filename, const LASVersion version = LASVersion::V_1_4);

  // *** METHODS *** //
  void writeHeader(const std::shared_ptr<LASHeader>& header);
  // *** OPERATORS *** //

  // *** GETTERS / SETTERS *** //
  std::unique_ptr<AbstractLASPointWriter> getPointWriter(LASPointFormat format);
};
