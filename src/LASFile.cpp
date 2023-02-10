//
// Created by miguelyermo on 4/12/22.
//

#include "LASFile.h"
#include "LASHeader.h"
#include "vlrReader.h"

#include <iostream>
#include <memory>

struct LASFile::Impl
{
private:
  std::ifstream lasFile{};
  std::shared_ptr<LASHeader> lasHeader{};
  LASPoint point{}; // Point being currently read

public:
  // *** CONSTRUCTION / DESTRUCTION *** //
  explicit Impl(const std::string& filePath)
  {
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
    if (magicNumber[0] != 'L' || magicNumber[1] != 'A' ||
        magicNumber[2] != 'S' || magicNumber[3] != 'F') {
      // throw exception
      throw std::runtime_error("LASLIB: the file is not a LAS file");
    }

    // set file pointer to the beginning of the file
    lasFile.seekg(0, std::ios::beg);

    // read header
    lasHeader = std::make_shared<LASHeader>();
    lasHeader->readHeader(lasFile);
  }

  // *** GETTERS / SETTERS *** //
  std::shared_ptr<LASHeader> getLasHeader() const
  {
    return lasHeader;
  }

  std::shared_ptr<AbstractLASPointReader> getPointReader() {
    lasFile.seekg(lasHeader->getOffsetToPointData(), std::ios::beg);

    // Get position of the cursor
    std::cout << "Position: " << lasFile.tellg() << "\n";
    std::cout << "Offset: " << lasHeader->getOffsetToPointData() << "\n";
    return LASPointReaderFactory::createReader(lasFile, point, chooseFormat(lasHeader->getPointDataRecordFormat()));
  }

//  std::shared_ptr<vlrReader> getVlrReader() {
//    lasFile.seekg(lasHeader->getOffsetToVLR(), std::ios::beg);
//    return std::make_shared<vlrReader>(lasFile, vlr);
//  }
//
//  std::shared_ptr<evlrReader> getEvlrReader() {
//    lasFile.seekg(lasHeader->getOffsetToEVLR(), std::ios::beg);
//    return std::make_shared<evlrReader>(lasFile, evlr);
//  }
};

LASFile::LASFile(const std::string &filePath) :
  impl(std::make_unique<Impl>(filePath)) {}

LASFile::~LASFile() = default;

std::shared_ptr<LASHeader> LASFile::getLasHeader() const
{
  return impl->getLasHeader();
}

std::shared_ptr<AbstractLASPointReader> LASFile::getPointReader()
{
  return impl->getPointReader();
}

//std::shared_ptr<vlrReader> LASFile::getVlrReader()
//{
//  return impl->getVlrReader();
//}

//std::shared_ptr<evlrReader> LASFile::getEvlrReader()
//{
//  return impl->getEvlrReader();
//}
