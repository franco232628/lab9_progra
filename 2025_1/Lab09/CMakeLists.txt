cmake_minimum_required(VERSION 4.0)
project(Lab09)

set(CMAKE_CXX_STANDARD 14)

include_directories(Bibliotecas)

add_executable(Lab09
        Bibliotecas/Empresa.cpp
        Bibliotecas/Empresa.hpp
        Bibliotecas/Infraccion.cpp
        Bibliotecas/Infraccion.hpp
        Bibliotecas/MinisterioDeTransporte.cpp
        Bibliotecas/MinisterioDeTransporte.hpp
        Bibliotecas/Multa.cpp
        Bibliotecas/Multa.hpp
        Bibliotecas/Vehiculo.cpp
        Bibliotecas/Vehiculo.hpp
        main.cpp)
