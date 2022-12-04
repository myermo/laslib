//
// Created by miguelyermo on 4/12/22.
//

#include "LASReader.h"
#include "LASHeader.h"

#include <iostream>
#include <memory>

LASReader::LASReader(const std::string &filePath) {

  // open filepath in binary mode and store it in lasFile
  lasFile.open(filePath, std::ios::binary);

  // check if file was correctly opened
  if (!lasFile.is_open()) {
    std::cerr << "LASLIB: Error opening file" << std::endl;
    exit(-1);
  }

  // check magic number of las file
  char magicNumber[4];
  lasFile.read(magicNumber, 4);
  if (magicNumber[0] != 'L' || magicNumber[1] != 'A' || magicNumber[2] != 'S' || magicNumber[3] != 'F') {
    std::cerr << "LASLIB: the file is not a LAS file" << std::endl;
    exit(-2);
  }

  // set file pointer to the beginning of the file
  lasFile.seekg(0, std::ios::beg);

  // read header
  lasHeader = std::make_unique<LASHeader>();
  lasHeader->readHeader(lasFile);

  // set file pointer to the beginning of the point data
  lasFile.seekg(lasHeader->getOffsetToPointData(), std::ios::beg);

  // create reader
  reader = LASPointReaderFactory::createReader(lasFile, point, chooseFormat(lasHeader->getPointDataRecordFormat()));

}

LASReader::~LASReader() = default;

// TODO: What happens if I call this method before reading the header?
void LASReader::printHeader() {
  lasHeader->print();
}

bool LASReader::readPoint() {
  return reader->readPoint();
}