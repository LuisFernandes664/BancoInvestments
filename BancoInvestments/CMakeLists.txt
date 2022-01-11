cmake_minimum_required(VERSION 3.21)
project(BancoHFInvestments C)

set(CMAKE_C_STANDARD 99)

add_executable(BancoHFInvestments main.c Clientes.c Clientes.h helper.c helper.h)
