//
// Created by Win10 on 04/01/2022.
//

#ifndef BANCOHFINVESTMENTS_CLIENTES_H
#define BANCOHFINVESTMENTS_CLIENTES_H

#define MAX_NOME 50
#define MAX_MORADA 100

typedef struct sCliente{
    char nome[MAX_NOME];
    char morada[MAX_MORADA];
    int NumContrib;
    int NumIndent;
    int NumPassap;
    int IBAN;
    int NumCliente;
} Cliente;

Cliente criarCliente();
void printCliente(Cliente a);

#endif //BANCOHFINVESTMENTS_CLIENTES_H
