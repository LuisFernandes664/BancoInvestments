#include <stdio.h>
#include "clientes.h"
#include "helper.h"


int main() {

    Clientes a;

    int opcao;
    do {
        printf("#### Gestao Alunos ####\n");
        printf("1 - Criar alunos\n");
        printf("2 - Listar alunos da turma\n");
        printf("3 - Procurar aluno da turma\n");
        printf("4 - Inserir notas\n");
        printf("0 - Sair\n");
        printf("Introduza a opcao: ");
        scanf("%d", &opcao);
        limpaBuffer();

        switch (opcao) {
            case 1:
                criarCliente();

                break;
            case 2:
                printCliente(a);
                break;
            case 3:

                break;
            case 4:

                break;
            case 0:

                break;
            default:
                printf("Opcao Invalida\n");
                break;
        }
    } while (opcao != 0);
    //system("PAUSE");

    /*int num = 1;
    printf("%num", num);
    num++;
    printf("%num", num);*/
    return 0;
}
