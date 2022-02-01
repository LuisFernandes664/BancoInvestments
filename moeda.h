//
// Created by Win10 on 29/01/2022.
//

#ifndef BANCOINVESTMENTS_MOEDA_H
#define BANCOINVESTMENTS_MOEDA_H

#define MAX_MOEDA 20
#define MAX_VALOR 1000

typedef struct sMoeda{
    int idMoeda;
    char descritivo [MAX_MOEDA];
    int seuValor;
    //int quantidadaMoeda[50];
    //int ativo;
} Moeda;

typedef struct sListmoedas{
    Moeda moeda[MAX_MOEDA];
    int tamanho;
} ListMoedas;

//ListMoedas listMoedas;

void addMoedaList(Moeda m);
Moeda criarMoeda();
void ComecaListMoedas();
void printMoeda(Moeda m);
void inserirMoedas(Moeda * m);
void printValores(Moeda m);
void saveMoedasList();
void saveMoedasList();
void readMoedaList();
void listAllMoedas();

#endif //BANCOINVESTMENTS_MOEDA_H
