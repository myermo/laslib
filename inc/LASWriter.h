//
// Created by miguelyermo on 18/02/23.
//


#pragma once

#include <iostream>
#include "LASHeader.h"




class LASWriter {
public:
  // *** ATTRIBUTES *** //
  std::fstream lasFile;

  // *** CONSTRUCTION / DESTRUCTION *** //
  LASWriter();
  LASWriter(const std::string& filename);

  // *** METHODS *** //
  void writeHeader(const std::shared_ptr<LASHeader>& header);

  // *** OPERATORS *** //

  // *** GETTERS / SETTERS *** //
};
