//
// Created by miguelyermo on 18/02/23.
//


#pragma once

#include <iostream>
#include "LASHeader.h"
#include "AbstractLASPointWriter.h"
#include "LASFormats.h"

class LASWriter {
private:
  class Impl; // forward declaration of implementation
  std::unique_ptr<Impl> impl; // unique pointer to implementation

  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  LASWriter(const std::string& filename, LASVersion version = LASVersion::V_1_4);
  ~LASWriter();
  // *** METHODS *** //
  void writeHeader(const std::shared_ptr<LASHeader>& header);

  // *** GETTERS / SETTERS *** //
  std::unique_ptr<AbstractLASPointWriter> getPointWriter(LASPointFormat format);
};
