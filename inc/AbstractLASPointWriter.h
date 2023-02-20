//
// Created by miguelyermo on 20/02/23.
//

#pragma once

#include <fstream>
#include <memory>

#include "LASFormats.h"

class LASPoint; // forward declaration
class LASHeader; // forward declaration

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

class LASPointWriter_1 : public AbstractLASPointWriter {

  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  explicit LASPointWriter_1(std::fstream& file) : AbstractLASPointWriter(file) {};

private:
  LASPointWriter_0 writer_0{lasFile};

  // *** METHODS *** //
public:
  void writePoint(const LASPoint& point) override;
};

class LASPointWriter_2 : public AbstractLASPointWriter {

  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  explicit LASPointWriter_2(std::fstream& file) : AbstractLASPointWriter(file) {};

private:
  LASPointWriter_0 writer_0{lasFile};

  // *** METHODS *** //
public:
  void writePoint(const LASPoint& point) override;
};

class LASPointWriter_3 : public AbstractLASPointWriter {

  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  explicit LASPointWriter_3(std::fstream& file) : AbstractLASPointWriter(file) {};

private:
  LASPointWriter_0 writer_0{lasFile};
  LASPointWriter_1 writer_1{lasFile};
  LASPointWriter_2 writer_2{lasFile};

  // *** METHODS *** //
public:
  void writePoint(const LASPoint& point) override;
};

class LASPointWriter_4 : public AbstractLASPointWriter {

  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  explicit LASPointWriter_4(std::fstream& file) : AbstractLASPointWriter(file) {};

private:
  LASPointWriter_1 writer_1{lasFile};

  // *** METHODS *** //
public:
  void writePoint(const LASPoint& point) override;
};

class LASPointWriter_5 : public AbstractLASPointWriter {

  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  explicit LASPointWriter_5(std::fstream& file) : AbstractLASPointWriter(file) {};

private:
  LASPointWriter_3 writer_3{lasFile};

  // *** METHODS *** //
public:
  void writePoint(const LASPoint& point) override;
};

class LASPointWriter_6 : public AbstractLASPointWriter {

  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  explicit LASPointWriter_6(std::fstream& file) : AbstractLASPointWriter(file) {};

  // *** METHODS *** //
public:
  void writePoint(const LASPoint& point) override;
};

class LASPointWriter_7 : public AbstractLASPointWriter {

  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  explicit LASPointWriter_7(std::fstream& file) : AbstractLASPointWriter(file) {};

private:
  LASPointWriter_6 writer_6{lasFile};

  // *** METHODS *** //
public:
  void writePoint(const LASPoint& point) override;
};

class LASPointWriter_8 : public AbstractLASPointWriter {

  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  explicit LASPointWriter_8(std::fstream& file) : AbstractLASPointWriter(file) {};

  // *** METHODS *** //
public:
  void writePoint(const LASPoint& point) override;

private:
  LASPointWriter_7 writer_7{lasFile};
};

class LASPointWriter_9 : public AbstractLASPointWriter {

  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  explicit LASPointWriter_9(std::fstream& file) : AbstractLASPointWriter(file) {};

private:
  LASPointWriter_6 writer_6{lasFile};

  // *** METHODS *** //
public:
  void writePoint(const LASPoint& point) override;
};

class LASPointWriter_10 : public AbstractLASPointWriter {

  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  explicit LASPointWriter_10(std::fstream& file) : AbstractLASPointWriter(file) {};

private:
  LASPointWriter_8 writer_8{lasFile};

  // *** METHODS *** //
public:
  void writePoint(const LASPoint& point) override;
};

std::unique_ptr<AbstractLASPointWriter> createLASPointWriter(std::fstream& file, const LASPointFormat& format);