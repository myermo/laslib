//
// Created by miguelyermo on 7/12/22.
//

#include "LASevlr.h"
#include <cstring>

class LASevlr::Impl
{
public:
  uint16_t reserved{};
  char userID[16]{};
  uint16_t recordID{};
  uint64_t recordLengthAfterHeader{};
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

  uint64_t getRecordLengthAfterHeader() const
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

  void setRecordLengthAfterHeader(uint64_t recordLengthAfterHeader)
  {
    Impl::recordLengthAfterHeader = recordLengthAfterHeader;
  }

  void setData(const std::vector<char> &data)
  {
    Impl::data = data;
  }
};


// *** CONSTRUCTION / DESTRUCTION *** //
LASevlr::LASevlr() : impl{std::make_unique<Impl>()}{}
LASevlr::~LASevlr() = default;

// *** GETTERS / SETTERS *** //
uint16_t LASevlr::getReserved() const
{
  return impl->getReserved();
}

const char* LASevlr::getUserId() const
{
  return impl->getUserId();
}

uint16_t LASevlr::getRecordId() const
{
  return impl->getRecordId();
}

uint64_t LASevlr::getRecordLengthAfterHeader() const
{
  return impl->getRecordLengthAfterHeader();
}

const char* LASevlr::getDescription() const
{
  return impl->getDescription();
}

const std::vector<char> &LASevlr::getData() const
{
  return impl->getData();
}

void LASevlr::setReserved(uint16_t reserved) const
{
  impl->reserved = reserved;
}

void LASevlr::setUserId(const char* userId) const
{
  std::memcpy(impl->userID, userId, 16);
}

void LASevlr::setRecordId(uint16_t recordId) const
{
  impl->recordID = recordId;
}

void LASevlr::setRecordLengthAfterHeader(uint64_t recordLengthAfterHeader) const
{
  impl->recordLengthAfterHeader = recordLengthAfterHeader;
}

void LASevlr::setData(const std::vector<char> &data) const
{
  impl->data = data;
}

void LASevlr::setDescription(const char* description) const
{
  std::memcpy(impl->description, description, 32);
}