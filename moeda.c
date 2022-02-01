//
// Created by Win10 on 29/01/2022.
//

#include "moeda.h"
#include <string.h>
#include <stdio.h>
#include "helper.h"

void addMoedaList(Moeda m);

ListMoedas listMoedas;

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
    //listMoedas.moeda[listMoedas.tamanho] = m;
    //listMoedas.tamanho++;
    ComecaListMoedas();

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

void listAllMoedas() {
    int i;
    for (i = 0; i < listMoedas.tamanho; i++) {
        printMoeda(listMoedas.moeda[i]);
    }
}

void inserirMoedas(Moeda * m){
    /*for (int i = 0; i < MAX_VALOR; ++i) {
        printf("Introduza o valor %d", i+1);
        scanf("%f", &m->seuValor[i]);
        limpaBuffer();
    }*/
    printf("Introduzir valor moeda: ");
    scanf("%f", &m->seuValor);
    limpaBuffer();
}

void printValores(Moeda m){
    printf("############\n");
    printf("Valor: %.2f\n", m.seuValor);
    printf("############\n");
}


// guardar a moeda no ficheiro binario moedas.bin
void saveMoedasList() {
    // abrir o ficheiro binario em modo escrita (w)
    // se nao existir, vai criar o ficheiro
    FILE *file = fopen("Moedas.bin", "wb+");

    //se o file for NULL significa que deu erro a abrir ou a criar o ficheiro
    if (file == NULL || listMoedas.tamanho == 0) {
        return;
    }

    // escreve toda a estrutura da Turma para o ficheiro.
    fwrite(&listMoedas, sizeof(listMoedas), 1, file);
    // IMPORTANTE: fechar o ficheiro
    fclose(file);
}
void readMoedaList() {
    FILE *file = fopen("Moedas.bin", "rb+");

    if (file == NULL) {
        listMoedas.tamanho = 0;
        return;
    }
    fread(&listMoedas, sizeof(listMoedas), 1, file);
    fclose(file);
}