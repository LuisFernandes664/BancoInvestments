cmake_minimum_required(VERSION 3.21)
project(BancoInvestments C)

set(CMAKE_C_STANDARD 90)

add_executable(BancoInvestments main.c helper.c helper.h Clientes.c Clientes.h Carteira.c Carteira.h Banco.c Banco.h login.c login.h moeda.c moeda.h)
