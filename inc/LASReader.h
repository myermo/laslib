//
// Created by miguelyermo on 4/12/22.
//


#pragma once

#include "LASHeader.h"
#include "LASPoint.h"
#include "LASvlr.h"
#include "vlrReader.h"
#include "AbstractLASPointReader.h"

#include <string>
#include <memory>

/**
 * @brief Class that reads a LAS file. It provides the interface to read the header and the points of a given LAS file.
 * @see LASHeader
 * @see LASPointReader
 */
class LASReader
{
private:
  // *** ATTRIBUTES *** //
  class Impl; // forward declaration of implementation
  std::unique_ptr<Impl> impl; // unique pointer to implementation

  // *** CONSTRUCTION / DESTRUCTION *** //
  public:
    explicit LASReader(const std::string& filePath);
    ~LASReader();

  // *** GETTERS / SETTERS *** //
  public:
  /**
   * @brief Returns the header of the LAS file
   * @return
   */
  [[nodiscard]] std::shared_ptr<LASHeader> getLasHeader() const;

    /**
     * @brief Returns the point reader of the LAS file
     * @return
     */
    std::shared_ptr<AbstractLASPointReader> getPointReader();
};
