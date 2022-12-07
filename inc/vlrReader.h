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
  std::ifstream& lasFile;
  LASvlr& vlr;

  // *** CONSTRUCTION / DESTRUCTION *** //
    explicit vlrReader(std::ifstream& lasFile, LASvlr& vlr)
    : lasFile(lasFile), vlr(vlr) {}

  // *** METHODS *** //
public:
  bool readVlr();

  // *** GETTERS / SETTERS *** //
};

class evlrReader
{
  public:
  std::ifstream& lasFile;
  LASevlr& evlr;

  // *** CONSTRUCTION / DESTRUCTION *** //
  explicit evlrReader(std::ifstream& lasFile, LASevlr& evlr)
  : lasFile(lasFile), evlr(evlr) {}

  // *** METHODS *** //
  public:
  bool readEvlr();
};
