cmake_minimum_required(VERSION 3.24)
project(laslib)

set(CMAKE_CXX_STANDARD 17)

# set memory sanitizer

file(GLOB_RECURSE SRC_FILES src/*.cpp)



# check if debug build
if(CMAKE_BUILD_TYPE MATCHES Debug)
    message("Debug build")
    add_executable(laslib_test_debug ${SRC_FILES} main.cpp)
    target_include_directories(laslib_test_debug PUBLIC inc)
else()
    message("Release build")
    add_library(laslib STATIC ${SRC_FILES})
    target_include_directories(laslib PUBLIC inc)
    set_target_properties(laslib PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
    set_target_properties(laslib PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

    add_executable(laslib_test main.cpp)
    target_link_libraries(laslib_test laslib)

    install(TARGETS laslib
            ARCHIVE DESTINATION lib
            LIBRARY DESTINATION lib
            RUNTIME DESTINATION bin)

    install(DIRECTORY inc/ DESTINATION include)
endif()





