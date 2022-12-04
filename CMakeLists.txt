cmake_minimum_required(VERSION 3.24)
project(laslib)

set(CMAKE_CXX_STANDARD 17)

add_library(laslib LASHeader.h LASHeader.cpp LASReader.cpp LASReader.h LASPoint.cpp LASPoint.h AbstractLASPointReader.cpp AbstractLASPointReader.h)

add_executable(laslib_test main.cpp)

target_link_libraries(laslib_test laslib)
