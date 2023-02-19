//
// Created by miguelyermo on 5/12/22.
//


#pragma once

#include <fstream>
#include "LASvlr.h"
#include "LASevlr.h"

class vlrReader
{
public:
  std::fstream& lasFile;
  LASvlr& vlr;

  // *** CONSTRUCTION / DESTRUCTION *** //
    explicit vlrReader(std::fstream& lasFile, LASvlr& vlr)
    : lasFile(lasFile), vlr(vlr) {}

  // *** METHODS *** //
public:
  bool readVlr();

  // *** GETTERS / SETTERS *** //
};

class evlrReader
{
  public:
  std::fstream& lasFile;
  LASevlr& evlr;

  // *** CONSTRUCTION / DESTRUCTION *** //
  explicit evlrReader(std::fstream& lasFile, LASevlr& evlr)
  : lasFile(lasFile), evlr(evlr) {}

  // *** METHODS *** //
  public:
  bool readEvlr();
};
