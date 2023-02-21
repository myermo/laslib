//
// Created by miguelyermo on 18/02/23.
//

#include "LASWriter.h"
#include "LASPoint.h"
#include "LASFormats.h"
#include "AbstractLASPointWriter.h"

struct LASWriter::Impl {
private:
  std::fstream lasFile{};

public:
  Impl(const std::string& filename, const LASVersion version) {
    lasFile.open(filename, std::fstream::out | std::ios::binary);

    if (!lasFile.is_open()) {
      // throw exception
      throw std::runtime_error("LASLIB: Error opening file");
    }
  }

  void writeHeader(const std::shared_ptr<LASHeader>& header) {
    header->writeHeader(lasFile);
  }

  std::unique_ptr<AbstractLASPointWriter> getPointWriter(const LASPointFormat format) {
    return createLASPointWriter(lasFile, format);
  }
};

LASWriter::LASWriter (const std::string& filename, LASVersion version) :
  impl(std::make_unique<Impl>(filename, version)) {}

LASWriter::~LASWriter() = default;

void LASWriter::writeHeader(const std::shared_ptr<LASHeader>& header) {
  impl->writeHeader(header);
}

std::unique_ptr<AbstractLASPointWriter> LASWriter::getPointWriter(const LASPointFormat format) {
  return impl->getPointWriter(format);
}