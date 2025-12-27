cmake_minimum_required(VERSION 4.1)
project(TrabalhoOrdenacao C)

set(CMAKE_C_STANDARD 11)

add_executable(TrabalhoOrdenacao
        TAD_ordenacao/ordenacao.h
        TAD_ordenacao/ordenacao.c
        TAD_ordenacao/main.c)
