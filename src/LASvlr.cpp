//
// Created by miguelyermo on 5/12/22.
//

#include <cstring>
#include "LASvlr.h"

class LASvlr::Impl
{
public:
  uint16_t reserved{};
  char userID[16]{};
  uint16_t recordID{};
  uint16_t recordLengthAfterHeader{};
  char description[32]{};
  std::vector<char> data{};


  // *** CONSTRUCTION / DESTRUCTION *** //
  Impl() = default;

  // *** GETTERS / SETTERS *** //
  uint16_t getReserved() const
  {
    return reserved;
  }

  const char* getUserId() const
  {
    return userID;
  }

  uint16_t getRecordId() const
  {
    return recordID;
  }

  uint16_t getRecordLengthAfterHeader() const
  {
    return recordLengthAfterHeader;
  }

  const char* getDescription() const
  {
    return description;
  }

  const std::vector<char> &getData() const
  {
    return data;
  }

  void setReserved(uint16_t reserved)
  {
    Impl::reserved = reserved;
  }

  void setRecordId(uint16_t recordId)
  {
    Impl::recordID = recordId;
  }

  void setRecordLengthAfterHeader(uint16_t recordLengthAfterHeader)
  {
    Impl::recordLengthAfterHeader = recordLengthAfterHeader;
  }

  void setData(const std::vector<char> &data)
  {
    Impl::data = data;
  }
};

LASvlr::LASvlr() : impl{std::make_unique<Impl>()} {}
LASvlr::~LASvlr() = default;

uint16_t LASvlr::getReserved() const
{
  return impl->getReserved();
}

const char* LASvlr::getUserId() const
{
  return impl->getUserId();
}

uint16_t LASvlr::getRecordId() const
{
  return impl->getRecordId();
}

uint16_t LASvlr::getRecordLengthAfterHeader() const
{
  return impl->getRecordLengthAfterHeader();
}

const char* LASvlr::getDescription() const
{
  return impl->getDescription();
}

const std::vector<char> &LASvlr::getData() const
{
  return impl->getData();
}

void LASvlr::setReserved(uint16_t reserved) const
{
  impl->reserved = reserved;
}

void LASvlr::setUserId(const char* userId) const
{
  std::memcpy(impl->userID, userId, 16);
}

void LASvlr::setRecordId(uint16_t recordId) const
{
  impl->recordID = recordId;
}

void LASvlr::setRecordLengthAfterHeader(uint16_t recordLengthAfterHeader) const
{
  impl->recordLengthAfterHeader = recordLengthAfterHeader;
}

void LASvlr::setData(const std::vector<char> &data) const
{
  impl->data = data;
}

void LASvlr::setDescription(const char* description) const
{
  std::memcpy(impl->description, description, 32);
}