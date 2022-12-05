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
  Format3 = 3,
  Format4 = 4,
  Format5 = 5,
  Format6 = 6,
  Format7 = 7,
  Format8 = 8,
  Format9 = 9,
  Format10 = 10
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

class LASPointReader_4 : public AbstractLASPointReader
{
  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  LASPointReader_4(std::ifstream &lasFile, LASPoint &point)
    : AbstractLASPointReader(lasFile, point)
  {}

  // *** Attributes *** //
private:
  LASPointReader_0 reader_1{lasFile, point};

  // *** METHODS *** //
public:
  bool readPoint() override;
};

class LASPointReader_5 : public AbstractLASPointReader
{
  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  LASPointReader_5(std::ifstream &lasFile, LASPoint &point)
    : AbstractLASPointReader(lasFile, point)
  {}

  // *** Attributes *** //
private:
  LASPointReader_3 reader_3{lasFile, point};

  // *** METHODS *** //
public:
  bool readPoint() override;
};

class LASPointReader_6 : public AbstractLASPointReader
{
  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  LASPointReader_6(std::ifstream &lasFile, LASPoint &point)
    : AbstractLASPointReader(lasFile, point)
  {}

  // *** METHODS *** //
public:
  bool readPoint() override;
};

class LASPointReader_7 : public AbstractLASPointReader
{
  // *** ATTRIBUTES *** //
private:
  LASPointReader_6 reader_6{lasFile, point};

  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  LASPointReader_7(std::ifstream &lasFile, LASPoint &point)
    : AbstractLASPointReader(lasFile, point)
  {}

  // *** METHODS *** //
public:
  bool readPoint() override;
};

class LASPointReader_8 : public AbstractLASPointReader
{
  // *** ATTRIBUTES *** //
private:
  LASPointReader_7 reader_7{lasFile, point};

  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  LASPointReader_8(std::ifstream &lasFile, LASPoint &point)
    : AbstractLASPointReader(lasFile, point)
  {}

  // *** METHODS *** //
public:
  bool readPoint() override;
};

class LASPointReader_9 : public AbstractLASPointReader
{
  // *** ATTRIBUTES *** //
private:
  LASPointReader_6 reader_6{lasFile, point};

  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  LASPointReader_9(std::ifstream &lasFile, LASPoint &point)
    : AbstractLASPointReader(lasFile, point)
  {}

  // *** METHODS *** //
public:
  bool readPoint() override;
};

class LASPointReader_10 : public AbstractLASPointReader
{
  // *** ATTRIBUTES *** //
private:
  LASPointReader_8 reader_8{lasFile, point};

  // *** CONSTRUCTION / DESTRUCTION *** //
public:
  LASPointReader_10(std::ifstream &lasFile, LASPoint &point)
    : AbstractLASPointReader(lasFile, point)
  {}

  // *** METHODS *** //
public:
  bool readPoint() override;
};

// abstract las point reader factory
class LASPointReaderFactory
{
  // *** METHODS *** //
public:
  static std::shared_ptr<AbstractLASPointReader>
  createReader(std::ifstream &lasFile, LASPoint &point,
               PointDataRecordFormat format);
};

PointDataRecordFormat chooseFormat(unsigned char format);

