//
// Created by João Raminhos on 11/01/2022.
//

#ifndef BANCOHFINVESTMENTS_BANCO_H
#define BANCOHFINVESTMENTS_BANCO_H
#define MAX_BANCO 300
#include "Clientes.h"

typedef struct sBanco{
    Cliente clientes[MAX_BANCO];
    int qtClientes;
} Banco;

void iniBanco(Banco *b);
int acrescentarCliente(Banco *b, Cliente a);
void listaClientes(Banco b);
int procurarCliente(Banco b);
void menuProcurarCliente(Banco b);

void save(Banco * b);
void read(Banco * b);
#endif //BANCOHFINVESTMENTS_BANCO_H
