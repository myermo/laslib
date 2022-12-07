//
// Created by miguelyermo on 5/12/22.
//

#include "vlrReader.h"

bool vlrReader::readVlr()
{

  uint16_t reserved, recordID, recordLengthAfterHeader;
  char userID[16], description[32];
  std::vector<char> data{};

  lasFile.read(reinterpret_cast<char*>(&reserved), sizeof(reserved));
  lasFile.read(userID, sizeof(userID));
  lasFile.read(reinterpret_cast<char*>(&recordID), sizeof(recordID));
  lasFile.read(reinterpret_cast<char*>(&recordLengthAfterHeader), sizeof(recordLengthAfterHeader));
  lasFile.read(description, sizeof(description));

  vlr.setReserved(reserved);
  vlr.setUserId(userID);
  vlr.setRecordId(recordID);
  vlr.setRecordLengthAfterHeader(recordLengthAfterHeader);
  vlr.setDescription(description);

  // Read the data
  data.reserve(vlr.getRecordLengthAfterHeader());
  lasFile.read(data.data(), vlr.getRecordLengthAfterHeader());

  vlr.setData(data);

  return true;
}

bool evlrReader::readEvlr()
{
  uint16_t reserved, recordID;
  uint64_t recordLengthAfterHeader;
  char userID[16], description[32];
  std::vector<char> data{};


  lasFile.read(reinterpret_cast<char*>(&reserved), sizeof(reserved));
  lasFile.read(userID, sizeof(userID));
  lasFile.read(reinterpret_cast<char*>(&recordID), sizeof(recordID));
  lasFile.read(reinterpret_cast<char*>(&recordLengthAfterHeader), sizeof(recordLengthAfterHeader));
  lasFile.read(description, sizeof(description));

  evlr.setReserved(reserved);
  evlr.setUserId(userID);
  evlr.setRecordId(recordID);
  evlr.setRecordLengthAfterHeader(recordLengthAfterHeader);
  evlr.setDescription(description);

  // Read the data
  data.reserve(evlr.getRecordLengthAfterHeader());
  lasFile.read(data.data(), evlr.getRecordLengthAfterHeader());

  return true;
}