//
// Created by miguelyermo on 5/12/22.
//


#pragma once

#include <cstdint>

class LASvlr
{
  // *** ATTRIBUTES *** //
  public:
    uint16_t reserved{};
    char userID[16]{};
    uint16_t recordID{};
    uint16_t recordLengthAfterHeader{};
    char description[32]{};

    // *** CONSTRUCTION / DESTRUCTION *** //

  // *** CONSTRUCTION / DESTRUCTION *** //


  // *** METHODS *** //


  // *** GETTERS / SETTERS *** //
};
