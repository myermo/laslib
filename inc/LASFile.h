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

class LASFile
{
private:
  // *** ATTRIBUTES *** //

  class Impl; // forward declaration of implementation
  std::unique_ptr<Impl> impl; // unique pointer to implementation

  // *** CONSTRUCTION / DESTRUCTION *** //
  public:
    explicit LASFile(const std::string& filePath);
    ~LASFile();

  // *** GETTERS / SETTERS *** //
  public:
    std::shared_ptr<LASHeader> getLasHeader() const;
    std::shared_ptr<AbstractLASPointReader> getPointReader();
    std::shared_ptr<vlrReader> getVlrReader();
    std::shared_ptr<evlrReader> getEvlrReader();
};
