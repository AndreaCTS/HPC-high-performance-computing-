cmake_minimum_required(VERSION 3.5)

project(Taller_Eigen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Taller_Eigen main.cpp)

install(TARGETS Taller_Eigen
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
