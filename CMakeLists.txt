project(Usutf)
cmake_minimum_required(VERSION 3.1)

set(CMAKE_DEBUG_POSTFIX "d")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O2")
set (CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Usutf.cpp)

set(HEADER_FILES Usutf.h)

include_directories(.)

add_library(Usutf STATIC ${SOURCE_FILES} ${HEADER_FILES})
set_property(TARGET Usutf PROPERTY POSITION_INDEPENDENT_CODE ON)

add_executable(UsutfTest UsutfTest.cpp ${HEADER_FILES})
target_link_libraries(UsutfTest Usutf)
set_target_properties(UsutfTest PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
