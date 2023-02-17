//
// Created by miguelyermo on 4/12/22.
//

#include "LASFile.h"
#include <iostream>
#include <chrono>

int main()
{

  LASFile lasFile("./alcoy.las");

  auto start = std::chrono::high_resolution_clock::now();

  size_t i{};

  auto header = lasFile.getLasHeader();
  header->print();
  auto reader = lasFile.getPointReader();
  while(reader->readPoint()) {
    ++i;
//    reader->point.printPoint();
  }

  // print number of points
  std::cout << "Number of points: " << i << std::endl;

  auto end = std::chrono::high_resolution_clock::now();


  // print time in milliseconds
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;

  uint16_t fileSourceId = 0;
  uint16_t globalEncoding = 0;
  uint32_t projectId1 = 0;
  uint16_t projectId2 = 0;
  uint16_t projectId3 = 0;
  uint8_t projectId4[8] = {0};
  uint8_t versionMajor = 1;
  uint8_t versionMinor = 2;
  uint16_t dayOfYear = 222;
  uint16_t year = 2023;
  uint16_t headerSize = 227;
  uint32_t offsetToPointData = 227;
  uint32_t numberOfVariableLengthRecords = 0;
  uint8_t pointDataRecordFormat = 0;
  uint16_t pointDataRecordLength = 20;
  uint32_t numberOfPointRecords = 1000000;
  uint32_t numberOfPointsByReturn[5] = {910423, 84016, 5480, 81, 0};

  double x_scale = 0.01;
  double y_scale = 0.01;
  double z_scale = 0.01;
  double x_offset = 700000;
  double y_offset = 4200000;
  double z_offset = 0;
  double x_max = 715673.65;
  double x_min = 715244.96;
  double y_max = 4287082.97;
  double y_min = 4286623.63;
  double z_max = 874.12;
  double z_min = 836.42;

  // Write las file
  std::ofstream lasFileOut("./alcoy_out.las", std::ios::binary);
  lasFileOut.write("LASF", 4);
  lasFileOut.write(reinterpret_cast<char*>(&fileSourceId), sizeof(fileSourceId));
  lasFileOut.write(reinterpret_cast<char*>(&globalEncoding), sizeof(globalEncoding));
  lasFileOut.write(reinterpret_cast<char*>(&projectId1), sizeof(projectId1));
  lasFileOut.write(reinterpret_cast<char*>(&projectId2), sizeof(projectId2));
  lasFileOut.write(reinterpret_cast<char*>(&projectId3), sizeof(projectId3));
  lasFileOut.write(reinterpret_cast<char*>(&projectId4), sizeof(projectId4));
  lasFileOut.write(reinterpret_cast<char*>(&versionMajor), sizeof(versionMajor));
  lasFileOut.write(reinterpret_cast<char*>(&versionMinor), sizeof(versionMinor));
  lasFileOut.write("laslib by Miguel Yermo", 32);
  lasFileOut.write("my_laslib", 32);
  lasFileOut.write(reinterpret_cast<char*>(&dayOfYear), sizeof(dayOfYear));
  lasFileOut.write(reinterpret_cast<char*>(&year), sizeof(year));
  lasFileOut.write(reinterpret_cast<char*>(&headerSize), sizeof(headerSize));
  lasFileOut.write(reinterpret_cast<char*>(&offsetToPointData), sizeof(offsetToPointData));
  lasFileOut.write(reinterpret_cast<char*>(&numberOfVariableLengthRecords), sizeof(numberOfVariableLengthRecords));
  lasFileOut.write(reinterpret_cast<char*>(&pointDataRecordFormat), sizeof(pointDataRecordFormat));
  lasFileOut.write(reinterpret_cast<char*>(&pointDataRecordLength), sizeof(pointDataRecordLength));
  lasFileOut.write(reinterpret_cast<char*>(&numberOfPointRecords), sizeof(numberOfPointRecords));
  lasFileOut.write(reinterpret_cast<char*>(&numberOfPointsByReturn), sizeof(numberOfPointsByReturn));
  lasFileOut.write(reinterpret_cast<char*>(&x_scale), sizeof(x_scale));
  lasFileOut.write(reinterpret_cast<char*>(&y_scale), sizeof(y_scale));
  lasFileOut.write(reinterpret_cast<char*>(&z_scale), sizeof(z_scale));
  lasFileOut.write(reinterpret_cast<char*>(&x_offset), sizeof(x_offset));
  lasFileOut.write(reinterpret_cast<char*>(&y_offset), sizeof(y_offset));
  lasFileOut.write(reinterpret_cast<char*>(&z_offset), sizeof(z_offset));
  lasFileOut.write(reinterpret_cast<char*>(&x_max), sizeof(x_max));
  lasFileOut.write(reinterpret_cast<char*>(&x_min), sizeof(x_min));
  lasFileOut.write(reinterpret_cast<char*>(&y_max), sizeof(y_max));
  lasFileOut.write(reinterpret_cast<char*>(&y_min), sizeof(y_min));
  lasFileOut.write(reinterpret_cast<char*>(&z_max), sizeof(z_max));
  lasFileOut.write(reinterpret_cast<char*>(&z_min), sizeof(z_min));




  return 0;
}