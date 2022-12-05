//
// Created by miguelyermo on 4/12/22.
//

#include "LASFile.h"
#include "LASHeader.h"
#include "vlrReader.h"

#include <iostream>
#include <memory>

LASFile::LASFile(const std::string &filePath) {

  // open filepath in binary mode and store it in lasFile
  lasFile.open(filePath, std::ios::binary);

  // check if file was correctly opened
  if (!lasFile.is_open()) {

    // throw exception
    throw std::runtime_error("LASLIB: Error opening file");
  }

  // check magic number of las file
  char magicNumber[4];
  lasFile.read(magicNumber, 4);
  if (magicNumber[0] != 'L' || magicNumber[1] != 'A' || magicNumber[2] != 'S' || magicNumber[3] != 'F') {
    // throw exception
    throw std::runtime_error("LASLIB: the file is not a LAS file");
  }

  // set file pointer to the beginning of the file
  lasFile.seekg(0, std::ios::beg);

  // read header
  lasHeader = std::make_unique<LASHeader>();
  lasHeader->readHeader(lasFile);
}

LASFile::~LASFile() = default;


std::shared_ptr<AbstractLASPointReader> LASFile::getPointReader() {
  // set file pointer to the beginning of the point data
  lasFile.seekg(lasHeader->getOffsetToPointData(), std::ios::beg);
  // create reader
  return LASPointReaderFactory::createReader(lasFile, point, chooseFormat(lasHeader->getPointDataRecordFormat()));
}

std::shared_ptr<vlrReader> LASFile::getVlrReader() {

  // set file pointer to the beginning of the vlr
  lasFile.seekg(lasHeader->getOffsetToVLR(), std::ios::beg);

  return std::make_shared<vlrReader>(lasFile, vlr);
}

std::shared_ptr<evlrReader> LASFile::getEvlrReader() {

  //set file pointer to the beginning of the evlr
  lasFile.seekg(lasHeader->getOffsetToEVLR(), std::ios::beg);

  return std::make_shared<evlrReader>(lasFile, evlr);
}

const std::unique_ptr<LASHeader> &LASFile::getLasHeader() const
{
  return lasHeader;
}
