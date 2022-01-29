//
// Created by Win10 on 29/01/2022.
//

#ifndef BANCOINVESTMENTS_CARTEIRA_H
#define BANCOINVESTMENTS_CARTEIRA_H
#define MAX_NOME 20
#define MAX_CARTEIRA 100
#include "moeda.h"

typedef struct sCarteira{
    Moeda moeda [MAX_CARTEIRA];
    int idcarteira;
    char nomecarteira;
    int quantidadaMoeda;
    int nomeMoeda;
} Carteira;

int acrescentaMoedas(Carteira *c, Moeda m);
void initCarteira(Carteira *c);
void listarCarteira(Carteira c);
int procuraMoedaNaCarteira(Carteira c);
void menuProcurarMoeda(Carteira c);
void menuInserirValor(Carteira * c);
void printCarteiras(Carteira a);

void save(Carteira *c);
void read(Carteira * c);

#endif //BANCOINVESTMENTS_CARTEIRA_H
