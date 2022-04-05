cmake_minimum_required(VERSION 3.20)
project(DA_Logistics)

set(CMAKE_CXX_STANDARD 14)

add_executable(DA_Logistics main.cpp Data.cpp Data.h NStaff.cpp NStaff.h)
