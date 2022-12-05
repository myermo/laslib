//
// Created by miguelyermo on 5/12/22.
//


#pragma once

#include <cstdint>
#include <vector>

class LASvlr
{
  // *** ATTRIBUTES *** //
  public:
    uint16_t reserved{};
    char userID[16]{};
    uint16_t recordID{};
    uint16_t recordLengthAfterHeader{};
    char description[32]{};
    std::vector<char> data{};

  // *** CONSTRUCTION / DESTRUCTION *** //


  // *** METHODS *** //


  // *** GETTERS / SETTERS *** //
};

class LASevlr
{
  // *** ATTRIBUTES *** //
  public:
    uint16_t reserved{};
    char userID[16]{};
    uint16_t recordID{};
    uint64_t recordLengthAfterHeader{};
    char description[32]{};
    std::vector<char> data{};

  // *** CONSTRUCTION / DESTRUCTION *** //
};
