//
// Created by miguelyermo on 4/12/22.
//


#pragma once

#include <iostream>
#include <fstream>
#include <memory>

#include "LASPoint.h"

// enumeration of point data record formats
enum PointDataRecordFormat
{
  Format0 = 0,
  Format1 = 1,
  Format2 = 2,
  Format3 = 3
};


class AbstractLASPointReader
{
  // *** ATTRIBUTES *** //
protected:
  std::ifstream& lasFile;
  LASPoint& point;

  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  AbstractLASPointReader(std::ifstream &lasFile, LASPoint &point)
    : lasFile(lasFile), point(point)
  {}


  // *** METHODS *** //
  virtual bool readPoint() = 0;
};

class LASPointReader_0 : public AbstractLASPointReader
{

  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  LASPointReader_0(std::ifstream &lasFile, LASPoint &point)
    : AbstractLASPointReader(lasFile, point)
  {}

  // *** METHODS *** //
public:
  bool readPoint() override;
};

class LASPointReader_1 : public AbstractLASPointReader
{

  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  LASPointReader_1(std::ifstream &lasFile, LASPoint &point)
  : AbstractLASPointReader(lasFile, point)
  {}

  // *** Attributes *** //
private:
  LASPointReader_0 reader_0{lasFile, point};

  // *** METHODS *** //
public:
  bool readPoint() override;
};

class LASPointReader_2 : public AbstractLASPointReader
{

  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  LASPointReader_2(std::ifstream &lasFile, LASPoint &point)
  : AbstractLASPointReader(lasFile, point)
  {}
  // *** Attributes *** //
private:
  LASPointReader_0 reader_0{lasFile, point};

  // *** METHODS *** //
public:
  bool readPoint() override;
};

class LASPointReader_3 : public AbstractLASPointReader
{
  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  LASPointReader_3(std::ifstream &lasFile, LASPoint &point)
  : AbstractLASPointReader(lasFile, point)
  {}

  // *** Attributes *** //
private:
  LASPointReader_0 reader_0{lasFile, point};
  LASPointReader_1 reader_1{lasFile, point};
  LASPointReader_2 reader_2{lasFile, point};

  // *** METHODS *** //
public:
  bool readPoint() override;
};

// abstract las point reader factory
class LASPointReaderFactory
{
  // *** METHODS *** //
public:
  static std::unique_ptr<AbstractLASPointReader>
  createReader(std::ifstream &lasFile, LASPoint &point,
               PointDataRecordFormat format);
};

PointDataRecordFormat chooseFormat(unsigned char format);

