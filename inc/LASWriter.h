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

  /**
   * @brief Writes the header of the LASFile
   * @see LASHeader
   */
  void writeHeader(const std::shared_ptr<LASHeader>& header);

  // *** GETTERS / SETTERS *** //
  /**
   * @brief Returns a point writer for the given point format
   * @param format: Point format
   * @see LASPointFormat
   */
  std::unique_ptr<AbstractLASPointWriter> getPointWriter(LASPointFormat format);
};
