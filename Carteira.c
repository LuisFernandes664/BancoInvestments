//
// Created by Win10 on 29/01/2022.
//

#include "Carteira.h"
#include "moeda.h"
#include <stdio.h>
#include <string.h>
#include "helper.h"


int acrescentaMoedas(Carteira *c, Moeda m){
    if(c->quantidadaMoeda == MAX_CARTEIRA){
        return 1; //carteira esta cheia
    }

    c->moeda[c->quantidadaMoeda] = m;
    c->quantidadaMoeda++;
    return 0;
}

void initCarteira(Carteira *c){
    c->quantidadaMoeda = 0;
}

void listarCarteira(Carteira c){
    for (int i = 0; i < c.quantidadaMoeda;i++) {
        printf("%d - ", i+1);
        printMoeda(c.moeda[i]);
    }
}

int procuraMoedaNaCarteira(Carteira c){
    int numero;
    printf("Introduza o numero da moeda: ");
    scanf("%d", &numero);
    limpaBuffer();
    for (int i = 0; i < c.quantidadaMoeda; i++) {
        if(c.moeda[i].idMoeda == numero){
            return i;
        }
    }
    return -1; //Moeda nao existe na Carteira
}

void menuProcurarMoeda(Carteira c){
    int posicaoMoeda = procuraMoedaNaCarteira(c);
    if(posicaoMoeda == -1){
        printf("Moeda inexistente\n");
    } else{
        printMoeda(c.moeda[posicaoMoeda]);
    }
}

void menuInserirValor(Carteira * c){
    int posicaoMoeda = procuraMoedaNaCarteira(*c);
    if(posicaoMoeda == -1){
        printf("Aluno inexistente\n");
    } else{
        inserirMoedas(&c->moeda[posicaoMoeda].seuValor);
    }
}

void printCarteiras(Carteira a){
    printf("##########################\n");
    printf("Numero da carteira: %d\n", a.idcarteira);
    printf("Nome da carteira: %s\n", a.nomecarteira);
    printf("##########################\n");

}


// guardar a carteira no ficheiro binario carteira.bin
void save(Carteira *c){
    // abrir o ficheiro binario em modo escrita (w)
    // se nao existir, vai criar o ficheiro
    FILE * file = fopen("carteira.bin", "wb+");

    //se o file for NULL significa que deu erro a abrir ou a criar o ficheiro
    if(file  ==NULL || c == NULL){
        return;
    }

    // escreve toda a estrutura da Turma para o ficheiro.
    fwrite(c, sizeof (Carteira), 1, file);

    // IMPORTANTE: fechar o ficheiro
    fclose(file);
}

void read(Carteira * c){
    FILE *file = fopen("carteira.bin", "rb+");

    if(file == NULL){
        return;
    }

    fread(c, sizeof(Carteira), 1, file);
    fclose(file);
}