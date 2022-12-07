//
// Created by miguelyermo on 7/12/22.
//

#pragma once

#include <cstdint>
#include <vector>
#include <memory>

class LASevlr
{
  // *** ATTRIBUTES *** //
public:
  class Impl;
  std::unique_ptr<Impl> impl{};

  // *** CONSTRUCTION / DESTRUCTION *** //
  LASevlr();
  ~LASevlr();

  // *** GETTERS / SETTERS *** //
  [[ nodiscard ]] uint16_t getReserved() const;
  [[ nodiscard ]] const char* getUserId() const;
  [[ nodiscard ]] uint16_t getRecordId() const;
  [[ nodiscard ]] uint64_t getRecordLengthAfterHeader() const;
  [[ nodiscard ]] const char* getDescription() const;
  [[ nodiscard ]] const std::vector<char>& getData() const;

  void setReserved(uint16_t reserved) const;
  void setUserId(const char* userId) const;
  void setRecordId(uint16_t recordId) const;
  void setRecordLengthAfterHeader(uint64_t recordLengthAfterHeader) const;
  void setDescription(const char* description) const;
  void setData(const std::vector<char>& data) const;
};