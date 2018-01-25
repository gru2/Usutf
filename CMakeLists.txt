project(Usutf)
cmake_minimum_required(VERSION 3.1)

set (CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O2")

set(SOURCE_FILES Usutf.cpp)

set(HEADER_FILES Usutf.h)

include_directories(.)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    message("Release mode.")
    add_library(Usutf STATIC ${SOURCE_FILES} ${HEADER_FILES})
    add_executable(UsutfTest UsutfTest.cpp ${HEADER_FILES})
    target_link_libraries(UsutfTest Usutf)
endif(CMAKE_BUILD_TYPE STREQUAL "Release")
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("Debug mode.")
    add_library(Usutfd STATIC ${SOURCE_FILES} ${HEADER_FILES})
    add_executable(UsutfTestd UsutfTest.cpp ${HEADER_FILES})
    target_link_libraries(UsutfTestd Usutfd)
endif(CMAKE_BUILD_TYPE STREQUAL "Debug") 
