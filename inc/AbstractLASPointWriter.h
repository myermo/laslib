//
// Created by miguelyermo on 20/02/23.
//

#pragma once

#include <fstream>

class LASPoint; // forward declaration


class AbstractLASPointWriter {
public:
  // *** ATTRIBUTES *** //
  std::fstream& lasFile;

// *** CONSTRUCTION / DESTRUCTION *** //
public:
  explicit AbstractLASPointWriter(std::fstream& file) : lasFile(file) {};

  // *** METHODS *** //
  virtual void writePoint(const LASPoint& point) = 0;
};

class LASPointWriter_0 : public AbstractLASPointWriter {

  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  explicit LASPointWriter_0(std::fstream& file) : AbstractLASPointWriter(file) {};

  // *** METHODS *** //
  void writePoint(const LASPoint& point) override;
};