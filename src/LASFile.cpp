//
// Created by miguelyermo on 4/12/22.
//

#include "LASReader.h"
#include "LASHeader.h"
#include "vlrReader.h"

#include <filesystem>
#include <fstream>
#include <memory>

namespace fs = std::filesystem;

struct LASReader::Impl {
private:
  std::fstream lasFile{};
  std::shared_ptr<LASHeader> lasHeader{};
  LASPoint point{}; // Point being currently read

public:
  // *** CONSTRUCTION / DESTRUCTION *** //
  explicit Impl(const std::string& filePath) {

      lasFile.open(filePath, std::fstream::in | std::ios::binary);

      // check if file was correctly opened
      if (!lasFile.is_open()) {
        // throw exception
        throw std::runtime_error("LASLIB: Error opening file");
      }

      // check magic number of las file
      char magicNumber[4];
      lasFile.read(magicNumber, 4);
      if (magicNumber[0] != 'L' || magicNumber[1] != 'A' ||
          magicNumber[2] != 'S' || magicNumber[3] != 'F') {
        // throw exception
        throw std::runtime_error("LASLIB: the file is not a LAS file");
      }

      // set file pointer to the beginning of the file
      lasFile.seekg(0, std::ios::beg);
  }

  // *** GETTERS / SETTERS *** //
  std::shared_ptr<LASHeader> getLasHeader() {

    if (!lasHeader) {
      lasHeader = std::make_shared<LASHeader>();
      lasHeader->readHeader(lasFile);
    }

    return lasHeader;
  }

  std::shared_ptr<AbstractLASPointReader> getPointReader() {

    if (!lasHeader) {
      lasHeader = getLasHeader();
    }

    lasFile.seekg(lasHeader->getOffsetToPointData(), std::ios::beg);

    // Get position of the cursor
    return LASPointReaderFactory::createReader(lasFile, point, chooseFormat(
      lasHeader->getPointDataRecordFormat()));
  }
};

LASReader::LASReader(const std::string& filePath) :
  impl(std::make_unique<Impl>(filePath)) {}

LASReader::~LASReader() = default;

std::shared_ptr<LASHeader> LASReader::getLasHeader() const {
  return impl->getLasHeader();
}

std::shared_ptr<AbstractLASPointReader> LASReader::getPointReader() {
  return impl->getPointReader();
}
