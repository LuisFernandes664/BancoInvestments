//
// Created by Win10 on 29/01/2022.
//

#ifndef BANCOINVESTMENTS_CLIENTES_H
#define BANCOINVESTMENTS_CLIENTES_H

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
void printCliente(Cliente c);

#endif //BANCOINVESTMENTS_CLIENTES_H
