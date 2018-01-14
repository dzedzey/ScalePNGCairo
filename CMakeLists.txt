cmake_minimum_required(VERSION 2.6.3)

#
# Configuration
#
set(NAME "scale-cairo")

project(${NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
 

#
# Sample
#
include_directories(
    /usr/include/
)


add_executable(${NAME}
    scale.cpp
)

target_link_libraries(${NAME} LINK_PRIVATE cairo)

