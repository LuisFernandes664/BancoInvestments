//
// Created by Win10 on 04/01/2022.
//

#include "Clientes.h"
#include <stdio.h>
#include <string.h>

Cliente criarCliente(){
    Cliente a;
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

    printf("Introduza IBAN: ");
    scanf("%d", &a.IBAN);

    printf("Introduza Numero de Cliente: ");
    scanf("%d", &a.NumCliente);
    //int num = 1;
    ////FALTA NUMERO DE CLIENTE automatico (ID)
    //i++;
}

void printCliente(Cliente a){
    printf("##################\n");
    printf("Nome Cliente: %s\n", a.nome);
    printf("Morada cliente: %s\n", a.morada);
    printf("Numero Contribuinte: %d\n", a.NumContrib);
    printf("Numero de Identificacao: %d\n", a.NumIndent);
    printf("Numero de passaporte: %d\n", a.NumPassap);
    printf("Numero de cliente: %d\n", a.NumCliente);
    printf("##################\n");
}
