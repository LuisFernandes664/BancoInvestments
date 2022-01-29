//
// Created by Win10 on 29/01/2022.
//

#ifndef BANCOINVESTMENTS_BANCO_H
#define BANCOINVESTMENTS_BANCO_H

#define MAX_BANCO 300
#include "Clientes.h"

typedef struct sBanco{
    Cliente clientes[MAX_BANCO];
    int qtClientes;
} Banco;

void iniBanco(Banco *b);
int acrescentarCliente(Banco *b, Cliente c);
void listaClientes(Banco b);
int procurarCliente(Banco b);
void menuProcurarCliente(Banco b);

void save(Banco * b);
void read(Banco * b);

#endif //BANCOINVESTMENTS_BANCO_H
