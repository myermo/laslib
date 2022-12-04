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
}

LASReader::~LASReader() = default;

// TODO: What happens if I call this method before reading the header?
void LASReader::printHeader() {
  lasHeader->print();
}

bool LASReader::readPoint() {

  uint8_t packet;

  // read point
  lasFile.read(reinterpret_cast<char*>(&point.x), 4);
  lasFile.read(reinterpret_cast<char*>(&point.y), 4);
  lasFile.read(reinterpret_cast<char*>(&point.z), 4);
  lasFile.read(reinterpret_cast<char*>(&point.intensity), 2);
  lasFile.read(reinterpret_cast<char*>(&packet), 1);

  // get 3 first bits of packet
  point.returnNumber = packet & 0b00000111;

  // get 3 next bits of packet
  point.numberOfReturns = (packet & 0b00111000) >> 3;

  // get 1 next bit of packet
  point.scanDirectionFlag = (packet & 0b01000000) >> 6;

  // get 1 next bit of packet
  point.edgeOfFlightLine = (packet & 0b10000000) >> 7;


  lasFile.read(reinterpret_cast<char*>(&point.classification), 1);
  lasFile.read(reinterpret_cast<char*>(&point.scanAngleRank), 1);
  lasFile.read(reinterpret_cast<char*>(&point.userData), 1);
  lasFile.read(reinterpret_cast<char*>(&point.pointSourceID), 2);


  // check if we reached the end of the file
  return !lasFile.eof();
}