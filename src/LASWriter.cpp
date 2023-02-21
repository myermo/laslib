//
// Created by miguelyermo on 18/02/23.
//

#include "LASWriter.h"
#include "LASPoint.h"
#include "LASFormats.h"
#include "AbstractLASPointWriter.h"

LASWriter::LASWriter () {};
LASWriter::LASWriter (const std::string& _filename, const LASVersion version) {
  lasFile.open(_filename, std::fstream::out | std::ios::binary);

  if (!lasFile.is_open()) {
    // throw exception
    throw std::runtime_error("LASLIB: Error opening file");
  }
};

void LASWriter::writeHeader(const std::shared_ptr<LASHeader>& header) {
  header->writeHeader(lasFile);
}

std::unique_ptr<AbstractLASPointWriter> LASWriter::getPointWriter(const LASPointFormat format) {
  return createLASPointWriter(lasFile, format);
}