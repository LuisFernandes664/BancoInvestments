//
// Created by João Raminhos on 11/01/2022.
//

#include "Banco.h"
#include <stdio.h>
#include "helper.h"

int acrescentarCliente(Banco *b, Cliente c){
    if(b->qtClientes == MAX_BANCO){
        return 1;
    }

    b->clientes[b->qtClientes] = c;
    b->qtClientes++;
    return 0;
}

void iniBanco(Banco *b){
    b->qtClientes = 0;
}

void listaClientes(Banco b){
    for (int i = 0; i < b.qtClientes;i++) {
        printf("%d - ", i+1);
        printCliente(b.clientes[i]);
    }
}

int procurarCliente(Banco b){
    int numero;
    printf("Introduza o numero do cliente: ");
    scanf("%d", &numero);
    limpaBuffer();
    for (int i = 0; i < b.qtClientes; i++) {
        if(b.clientes == NumCliente){
            return i;
        }
    }
    return -1;
}

void menuProcurarCliente(Banco b){
    int posicaoCliente = procurarCliente(b);
    if(posicaoCliente == -1){
        printf("Cliente nao existente\n");
    } else{
        printCliente(b.clientes[posicaoCliente]);
    }
}

void save(Banco *b){
    FILE * file = fopen("Banco.bin", "bhf+");
    if(file  ==NULL || b == NULL){
        return;
    }
    fwrite(b, sizeof (Banco), 1, file);
    fclose(file);
}

void read(Banco * b){
    FILE *file = fopen("Banco.bin", "bhf+");
    if(file == NULL){
        return;
    }

    fread(b, sizeof(Banco), 1, file);
    fclose(file);
}