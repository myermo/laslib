//
// Created by miguelyermo on 4/12/22.
//


#pragma once

#include <cstdint>
#include <memory>

class LASPoint
{
  // *** ATTRIBUTES *** //
public:
  class Impl;
  std::unique_ptr<Impl> impl;
  // *** CONSTRUCTION / DESTRUCTION *** //
  LASPoint();
  ~LASPoint();

  // *** METHODS *** //
  void printPoint() const;

  // *** GETTERS / SETTERS *** //
  [[ nodiscard ]] int32_t getX() const;
  [[ nodiscard ]] int32_t getY() const;
  [[ nodiscard ]] int32_t getZ() const;
  [[ nodiscard ]] uint16_t getI() const;
  [[ nodiscard ]] uint16_t getR() const;
  [[ nodiscard ]] uint16_t getG() const;
  [[ nodiscard ]] uint16_t getB() const;
  [[ nodiscard ]] uint16_t getNIR() const;
  [[ nodiscard ]] uint8_t getReturnNumber() const;
  [[ nodiscard ]] uint8_t getNumberOfReturns() const;
  [[ nodiscard ]] uint8_t getScanDirectionFlag() const;
  [[ nodiscard ]] uint8_t getEdgeOfFlightLine() const;
  [[ nodiscard ]] uint8_t getClassification() const;
  [[ nodiscard ]] uint8_t getScanAngleRank() const;
  [[ nodiscard ]] uint8_t getUserData() const;
  [[ nodiscard ]] uint16_t getPointSourceID() const;
  [[ nodiscard ]] double getGPSTime() const;
  [[ nodiscard ]] unsigned char getWavePacketDescriptorIndex() const;
  [[ nodiscard ]] uint64_t getByteOffsetToWaveformData() const;
  [[ nodiscard ]] uint32_t getWaveformDataPacketSize() const;
  [[ nodiscard ]] float getReturnPointWaveformLocation() const;
  [[ nodiscard ]] float getXt() const;
  [[ nodiscard ]] float getYt() const;
  [[ nodiscard ]] float getZt() const;
  [[ nodiscard ]] uint16_t getExtendedReturnNumber() const;
  [[ nodiscard ]] uint16_t getExtendedNumberOfReturns() const;
  [[ nodiscard ]] uint16_t getExtendedClassificationFlags() const;
  [[ nodiscard ]] uint16_t getExtendedScannerChannel() const;
  [[ nodiscard ]] uint16_t getExtendedScanDirectionFlag() const;
  [[ nodiscard ]] uint16_t getExtendedEdgeOfFlightLine() const;
  [[ nodiscard ]] uint8_t getExtendedClassification() const;
  [[ nodiscard ]] uint16_t getExtendedScanAngleRank() const;


  void setX(int32_t x) const;
  void setY(int32_t y) const;
  void setZ(int32_t z) const;
  void setI(uint16_t i) const;
  void setReturnNumber(uint8_t packet) const;
  void setNumberOfReturns(uint8_t packet) const;
  void setScanDirectionFlag(uint8_t packet) const;
  void setEdgeOfFlightLine(uint8_t packet) const;
  void setClassification(uint8_t classification) const;
  void setScanAngleRank(uint8_t scanAngleRank) const;
  void setUserData(uint8_t userData) const;
  void setPointSourceID(uint16_t pointSourceID) const;
  void setR(uint16_t r) const;
  void setG(uint16_t g) const;
  void setB(uint16_t b) const;
  void setNIR(uint16_t nir) const;
  void setGPSTime(double gpsTime) const;
  void setWavePacketDescriptorIndex(unsigned char wavePacketDescriptorIndex) const;
  void setByteOffsetToWaveformData(uint64_t byteOffsetToWaveformData) const;
  void setWaveformDataPacketSize(uint32_t waveformDataPacketSize) const;
  void setReturnPointWaveformLocation(float returnPointWaveformLocation) const;
  void setXt(float xt) const;
  void setYt(float yt) const;
  void setZt(float zt) const;
  void setExtendedReturnNumber(uint16_t extendedReturnNumber) const;
  void setExtendedNumberOfReturns(uint16_t extendedNumberOfReturns) const;
  void setExtendedClassificationFlags(uint16_t extendedClassificationFlags) const;
  void setExtendedScannerChannel(uint16_t extendedScannerChannel) const;
  void setExtendedScanDirectionFlag(uint16_t extendedScanDirectionFlag) const;
  void setExtendedEdgeOfFlightLine(uint16_t extendedEdgeOfFlightLine) const;
  void setExtendedClassification(uint8_t extendedClassification) const;
  void setExtendedScanAngleRank(uint16_t extendedScanAngle) const;
};
