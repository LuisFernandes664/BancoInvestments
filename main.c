#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Banco.h"
#include "helper.h"
#include "login.h"
#include "clientes.h"
#include "Carteira.h"
#include "moeda.h"

void menuCliente();
void menuManager();

void deleteUserMenu();
void editUserMenu();

int main() {
    Banco hf;
    iniBanco(&hf);
    ListMoedas list;
    ComecaListMoedas();
    read(&hf);


    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    int loginType;
    initUserList();
    printf("Bem vindo ao BankHF\n");
    printf("Login\n");
    printf("Utilizador: ");
    fgets(username, MAX_USERNAME -1, stdin );
    username[strlen(username) -1 ] = '\0';
    printf("Password: ");
    fgets(password, MAX_PASSWORD -1, stdin );
    password[strlen(password) -1 ] = '\0';

    loginType = validateLogin(username, password);
    switch (loginType) {
        case Clientes:
            criarCliente();
            menuCliente();
            break;
        case Manager:
            menuManager();
            break;
        default:
            printf("Login Falhado!!!\n");
            return -1;
    }

    return 0;
}

void menuCliente(){
    Carteira c;
    initCarteira(&c);
    Moeda m;


    printf("####MENU CLIENTE####\n");

    int option = 0;
    do{
        printf("0 - Sair\n");
        printf("1 - Consultar Carteira\n");
        printf("2 - Comprar moedas\n");
        printf("Introduza uma opcao: ");
        scanf("%d", &option);
        while (getchar() != '\n' && getchar() != EOF);
        switch (option) {
            case 0:
                break;
            case 1:
                //listarCarteira(c);
                break;
            case 2:
                acrescentaMoedas(&c,m);
                break;
            default:
                printf("Opcao invalida!!!\n");
        }
    } while (option != 0);
}
void menuManager(){
    Moeda m;
    printf("MENU MANAGER\n");
    int option = 0;
    do{
        printf("1 - Criar utilizador\n");
        printf("2 - Editar utilizador\n");
        printf("3 - Eliminar utilizador\n");
        printf("4 - Listar utilizadores\n");
        printf("5 - Criar Moeda\n");
        printf("6 - Listar Moedas\n");
        printf("0 - Sair\n");
        printf("Introduza uma opcao: ");
        scanf("%d", &option);
        while (getchar() != '\n' && getchar() != EOF);
        switch (option) {
            case 1:
                createNewUser();
                break;
            case 2:
                editUserMenu();
                break;
            case 3:
                deleteUserMenu();
                break;
            case 4:
                listAllUsers();
                break;
            case 5:
                criarMoeda();
                //ComecaListMoedas();
                //addMoedaList(m);
                //saveMoedasList();
                break;
            case 6:
                printMoeda(m);
                readMoedaList();
            case 0:
                saveUserList();
                break;
            default:
                printf("Opcao invalida!!!\n");
                break;
        }
    } while (option != 0);
}


void deleteUserMenu(){
    char username[MAX_USERNAME];
    printf("Introduza o username: ");
    fgets(username, MAX_USERNAME -1, stdin);
    username[strlen(username) -1 ] = '\0';
    deleteUser(username);
}

void editarUserSubMenu(User* user){
    int option, validated = 0;
    char oldPassword[MAX_PASSWORD], newPassword[MAX_PASSWORD], confirmPassword[MAX_PASSWORD];

    printf("1- Alterar password\n");
    printf("2- Alterar tipo utilizador\n");
    printf("Introduza a opcao: ");
    scanf("%d", &option);
    while (getchar() != '\n' && getchar() != EOF);
    switch (option) {
        case 1:
            do {
                printf("Introduza a password antiga: ");
                fgets(oldPassword, MAX_PASSWORD - 1, stdin);
                oldPassword[strlen(oldPassword) - 1] = '\0';
                printf("Introduza a nova password: ");
                fgets(newPassword, MAX_PASSWORD - 1, stdin);
                newPassword[strlen(newPassword) - 1] = '\0';
                printf("Confirme a nova password: ");
                fgets(confirmPassword, MAX_PASSWORD - 1, stdin);
                confirmPassword[strlen(confirmPassword) - 1] = '\0';
                if(strcmp(oldPassword, user->password) != 0){
                    printf("Password ou username invalidos\n");
                } else if(strcmp(newPassword, confirmPassword) != 0){
                    printf("Nova password nao confirmada\n");
                } else{
                    strcpy(user->password, newPassword);
                    validated = 1;
                }
            } while (validated != 1);
            break;
        case 2:
            if(user->type == Clientes){
                user->type = Manager;
                printf("O utilizador mudou de Cliente para Manager\n");
            } else {
                user->type = Clientes;
                printf("O utilizador mudou de Manager para Cliente\n");
            }
            break;
    }
}

void editUserMenu() {
    char username[MAX_USERNAME];
    printf("Introduza o username: ");
    fgets(username, MAX_USERNAME - 1, stdin);
    username[strlen(username) - 1] = '\0';
    User *user = findUser(username);
    editarUserSubMenu(user);
}