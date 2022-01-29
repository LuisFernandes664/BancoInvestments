//
// Created by Win10 on 29/01/2022.
//

#include "moeda.h"
#include <string.h>
#include <stdio.h>
#include "helper.h"

void addMoedaList(Moeda m);

Moeda criarMoeda(){
    Moeda m;
    m.idMoeda = listMoedas.tamanho;
    printf("Nome da Moeda: ");
    fgets(m.descritivo, MAX_MOEDA, stdin);
    m.descritivo[strlen(m.descritivo) -1 ] = '\0';
    printf("Qual o valor: ");
    scanf("%d", &m.seuValor);
    addMoedaList(m);
    return m;
}

void addMoedaList(Moeda m) {
    listMoedas.tamanho=0;
}

void ComecaListMoedas(){
    listMoedas.tamanho = 0;
}

void printMoeda(Moeda m){
    printf("########################\n");
    printf("ID da Moeda: %s\n", m.idMoeda);
    printf("Nome da Moeda: %s\n", m.descritivo);
    printf("Valor da Moeda: %d\n", m.seuValor);
    printf("########################\n");
}

void inserirMoedas(Moeda * m){
    /*for (int i = 0; i < MAX_VALOR; ++i) {
        printf("Introduza o valor %d", i+1);
        scanf("%f", &m->seuValor[i]);
        limpaBuffer();
    }*/

    printf("Introduzir a nota do teste: ");
    scanf("%f", &m->seuValor);
    limpaBuffer();
}

void printValores(Moeda m){
    printf("############\n");
    printf("Valor: %.2f\n", m.seuValor);
    printf("############\n");
}