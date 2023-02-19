//
// Created by miguelyermo on 5/12/22.
//


#pragma once

#include <iostream>
#include <fstream>
#include <cstdint>
#include <vector>
#include <memory>
#include <sstream>

class LASvlr
{
  // *** ATTRIBUTES *** //
  public:
    class Impl;
    std::unique_ptr<Impl> impl{};


  // *** CONSTRUCTION / DESTRUCTION *** //
  LASvlr();
  ~LASvlr();
  LASvlr(const LASvlr& other);

  // *** METHODS *** //
  void read(std::fstream& lasFile);
  void print() const;


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

class ExtraBytes
{
  unsigned char reserved[2]{};
  unsigned char dataType{};
  unsigned char options{};
  char name[32]{};
  unsigned char unused[4]{};
  uint8_t noData[3]{};
  uint8_t min[3]{};
  uint8_t max[3]{};
  double scale[3]{};
  double offset[3]{};
  char description[32]{};

  public:
  ExtraBytes() = default;
  ~ExtraBytes() = default;

  void read(std::fstream& lasFile)
  {
    lasFile.read(reinterpret_cast<char*>(reserved), 2);
    lasFile.read(reinterpret_cast<char*>(&dataType), 1);
    lasFile.read(reinterpret_cast<char*>(&options), 1);
    lasFile.read(reinterpret_cast<char*>(name), 32);
    lasFile.read(reinterpret_cast<char*>(unused), 4);
    lasFile.read(reinterpret_cast<char*>(noData), 24);
    lasFile.read(reinterpret_cast<char*>(min), 24);
    lasFile.read(reinterpret_cast<char*>(max), 24);
    lasFile.read(reinterpret_cast<char*>(scale), 24);
    lasFile.read(reinterpret_cast<char*>(offset), 24);
    lasFile.read(reinterpret_cast<char*>(description), 32);
  }

  static std::string printDataTypeName(const unsigned char dt)
  {
    std::stringstream ss{};
    switch (dt) {
      case 0:
        ss << "undocumented extra bytes";
        break;
      case 1:
        ss << "unsigned char";
        break;
      case 2:
        ss << "char";
        break;
      case 3:
        ss << "unsigned short";
        break;
      case 4:
        ss << "short";
        break;
      case 5:
        ss << "unsigned long";
        break;
      case 6:
        ss << "long";
        break;
      case 7:
        ss << "unsigned long long";
        break;
      case 8:
        ss << "long long";
        break;
      case 9:
        ss << "float";
        break;
      case 10:
        ss << "double";
        break;
      case 11:
        ss << "unsigned char[2]";
        break;
      case 12:
        ss << "char[2]";
        break;
      case 13:
        ss << "unsigned short[2]";
        break;
      case 14:
        ss << "short[2]";
        break;
      case 15:
        ss << "unsigned long[2]";
        break;
      case 16:
        ss << "long[2]";
        break;
      case 17:
        ss << "unsigned long long[2]";
        break;
      case 18:
        ss << "long long[2]";
        break;
      case 19:
        ss << "float[2]";
        break;
      case 20:
        ss << "double[2]";
        break;
      case 21:
        ss << "unsigned char[3]";
        break;
      default:
        std::cout << "Unknown data type";
        break;
    }

    return ss.str();
  }

  void print() const {
    std::cout << "Data type: " << static_cast<int>(dataType) << " (" << printDataTypeName(dataType) << "), name \"" <<
    name << "\", description: \"" << description << "\", scale: \"" << *scale << "\", offset: " << *offset << "\"" << std::endl;
  }
};


