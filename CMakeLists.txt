cmake_minimum_required(VERSION 3.3)
project(C_Gr4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Exerc_3_3.cpp)
add_executable(C_Gr4 ${SOURCE_FILES} Exerc_3_3.cpp)