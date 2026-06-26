cmake_minimum_required(VERSION 4.0)
project(Laboratorio09_STL_2025_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Laboratorio09_STL_2025_2 main.cpp
        Bibliotecas/Etiqueta.cpp
        Bibliotecas/Etiqueta.hpp
        Bibliotecas/Categoria.cpp
        Bibliotecas/Categoria.hpp
        Bibliotecas/Comentario.cpp
        Bibliotecas/Comentario.hpp
        Bibliotecas/Streamer.cpp
        Bibliotecas/Streamer.hpp
        Bibliotecas/SistemaDeGestion.cpp
        Bibliotecas/SistemaDeGestion.hpp)
