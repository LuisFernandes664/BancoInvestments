//
// Created by Win10 on 04/01/2022.
//

#include "Clientes.h"
#include <stdio.h>
#include <string.h>

Clientes criarCliente(){
    Clientes a;
    printf("Introduza o nome: ");
    fgets(a.nome, MAX_NOME -1, stdin);
    a.nome[strlen(a.nome) -1 ] = '\0';


    printf("Introduza a morada: ");
    fgets(a.morada, MAX_MORADA -1, stdin);
    a.morada[strlen(a.morada) -1 ] = '\0';


    printf("Introduza Numero de Contribuinte: ");
    scanf("%d", &a.NumContrib);
    //VER - LIMITAR TAMANHO DE NUMCONTRIB///a.NumContrib[strlen(a.NumContrib) -1 ] = '\0';

    printf("Introduza o CC: ");
    scanf("%d", &a.NumIndent);
    printf("Introduza Numero do Passaporte: ");
    scanf("%d", &a.NumPassap);
    //int num = 1;
    ////FALTA NUMERO DE CLIENTE
    //i++;
    printf("Introduza IBAN: ");
    scanf("%d", &a.IBAN);
}

void printCliente(Clientes a){
    printf("##################\n");
    printf("Nome Cliente: %s\n", a.nome);
    printf("Morada cliente: %s\n", a.morada);
    printf("Numero Contribuinte: %d\n", a.NumContrib);
    printf("Numero de Identificacao: %d\n", a.NumIndent);
    printf("Numero de passaporte: %d\n", a.NumPassap);
    printf("##################\n");
}
