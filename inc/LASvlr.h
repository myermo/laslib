//
// Created by miguelyermo on 5/12/22.
//


#pragma once

#include <cstdint>
#include <vector>
#include <memory>

class LASvlr
{
  // *** ATTRIBUTES *** //
  public:
    class Impl;
    std::unique_ptr<Impl> impl{};


  // *** CONSTRUCTION / DESTRUCTION *** //
  LASvlr();
  ~LASvlr();

  // *** GETTERS / SETTERS *** //
  [[ nodiscard ]] uint16_t getReserved() const;
  [[ nodiscard ]] const char* getUserId() const;
  [[ nodiscard ]] uint16_t getRecordId() const;
  [[ nodiscard ]] uint16_t getRecordLengthAfterHeader() const;
  [[ nodiscard ]] const char* getDescription() const;
  [[ nodiscard ]] const std::vector<char>& getData() const;

  void setReserved(uint16_t reserved) const;
  void setUserId(const char* userId) const;
  void setRecordId(uint16_t recordId) const;
  void setRecordLengthAfterHeader(uint16_t recordLengthAfterHeader) const;
  void setDescription(const char* description) const;
  void setData(const std::vector<char>& data) const;
};


