//
// Created by Win10 on 29/01/2022.
//

#include "Clientes.h"
#include <stdio.h>
#include <string.h>

Cliente criarCliente(){
    Cliente c;
    printf("Introduza o nome: ");
    fgets(c.nome, MAX_NOME -1, stdin);
    c.nome[strlen(c.nome) -1 ] = '\0';


    printf("Introduza a morada: ");
    fgets(c.morada, MAX_MORADA -1, stdin);
    c.morada[strlen(c.morada) -1 ] = '\0';


    printf("Introduza Numero de Contribuinte: ");
    scanf("%d", &c.NumContrib);
    //VER - LIMITAR TAMANHO DE NUMCONTRIB///a.NumContrib[strlen(a.NumContrib) -1 ] = '\0';

    printf("Introduza o CC: ");
    scanf("%d", &c.NumIndent);
    printf("Introduza Numero do Passaporte: ");
    scanf("%d", &c.NumPassap);

    printf("Introduza IBAN: ");
    scanf("%d", &c.IBAN);

    printf("Introduza Numero de Cliente: ");
    scanf("%d", &c.NumCliente);
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
