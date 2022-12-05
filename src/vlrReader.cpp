//
// Created by miguelyermo on 5/12/22.
//

#include "vlrReader.h"

bool vlrReader::readVlr()
{
  lasFile.read(reinterpret_cast<char*>(&vlr.reserved), sizeof(vlr.reserved));
  lasFile.read(vlr.userID, sizeof(vlr.userID));
  lasFile.read(reinterpret_cast<char*>(&vlr.recordID), sizeof(vlr.recordID));
  lasFile.read(reinterpret_cast<char*>(&vlr.recordLengthAfterHeader), sizeof(vlr.recordLengthAfterHeader));
  lasFile.read(vlr.description, sizeof(vlr.description));

  // Read the data
  vlr.data.reserve(vlr.recordLengthAfterHeader);
  lasFile.read(vlr.data.data(), vlr.recordLengthAfterHeader);

  return true;
}

bool evlrReader::readEvlr()
{
  lasFile.read(reinterpret_cast<char*>(&evlr.reserved), sizeof(evlr.reserved));
  lasFile.read(evlr.userID, sizeof(evlr.userID));
  lasFile.read(reinterpret_cast<char*>(&evlr.recordID), sizeof(evlr.recordID));
  lasFile.read(reinterpret_cast<char*>(&evlr.recordLengthAfterHeader), sizeof(evlr.recordLengthAfterHeader));
  lasFile.read(evlr.description, sizeof(evlr.description));

  // Read the data
  evlr.data.reserve(evlr.recordLengthAfterHeader);
  lasFile.read(evlr.data.data(), evlr.recordLengthAfterHeader);

  return true;
}