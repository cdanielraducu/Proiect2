cmake_minimum_required(VERSION 3.15)
project(Restaurant_ProiectV2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Restaurant_ProiectV2 main.cpp Client.cpp Client.h GrupClienti.cpp GrupClienti.h Comanda.cpp Comanda.h Chelner.cpp Chelner.h Masa.cpp Masa.h Restaurant.cpp Restaurant.h)