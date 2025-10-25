cmake_minimum_required(VERSION 3.10)
project(Biblioteca)
set(CMAKE_CXX_STANDARD 11)

include_directories(include)
add_executable(biblioteca main.cpp src/funciones.cpp)
