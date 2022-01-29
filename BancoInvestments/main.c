#include <stdio.h>
#include <stdlib.h>
#include "Banco.h"
#include "helper.h"
#include "login.h"
#include "clientes.h"

int main() {
    Banco hf;
    iniBanco(&hf);
    read(&hf);
    Cliente c;
    int opcao;
    do {
        printf("#### Gestao Clientes ####\n");
        printf("1 - Criar cliente\n");
        printf("2 - Lista de clientes\n");
        printf("3 - Procurar cliente\n");
        printf("0 - Sair\n");
        printf("Introduza a opcao: ");
        scanf("%d", &opcao);
        limpaBuffer();
        switch (opcao) {
            case 1:
                c = criarCliente();
                acrescentarCliente(&hf, c);
                break;
            case 2:
                listaClientes(hf);
                break;
            case 3:
                menuProcurarCliente(hf);
                break;
            case 0:
                save(&hf);
                break;
            default:
                printf("Opcao Invalida\n");
                break;
        }
    } while (opcao != 0);
    //system("PAUSE");
    return 0;
}
