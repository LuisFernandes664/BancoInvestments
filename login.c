//
// Created by Win10 on 29/01/2022.
//
#include <stdio.h>
#include <string.h>
#include "login.h"
#include "Clientes.h"


UserList userList;


void addToList(User user) {
    userList.user[userList.tam++] = user;
}


void readUserList() {
    FILE *file = fopen("users.bin", "rb+");

    if (file == NULL) {
        userList.tam = 0;
        return;
    }
    fread(&userList, sizeof(UserList), 1, file);
    fclose(file);
}

void initUserList() {
    readUserList();

    if (userList.tam == 0) {
        User admin;
        strcpy(admin.username, "admin");
        strcpy(admin.password, "admin");
        admin.type = Manager;
        admin.clientId = -1;
        addToList(admin);
    }
}


void createNewUser() {
    User user;
    printf("Introduzir nome utilizador: ");
    fgets(user.username, 50, stdin);
    user.username[strlen(user.username) - 1] = '\0';
    printf("Introduzir password: ");
    fgets(user.password, 50, stdin);
    user.password[strlen(user.password) - 1] = '\0';
    printf("Introduza o tipo de cliente( 1- Cliente; 2- Gestor): ");
    scanf("%d", &user.type);
    while (user.type != Clientes && user.type != Manager) {
        printf("Opcao Invalida, introduza novamente: ");
        scanf("%d", &user.type);
    }
    while (getchar() != '\n' && getchar() != EOF);
    if (user.type == Manager) {
        user.clientId = -1;
    } else {
        //Cliente d = criarCliente();
        //user.clientId = d.NumCliente;
        printf("Introduzir o client id:");
        scanf("%d", &user.clientId);
        printf("Client id: %d\n",user.clientId);

    }

    addToList(user);
}

void saveUserList() {
    // abrir o ficheiro binario em modo escrita (w)
    // se nao existir, vai criar o ficheiro
    FILE *file = fopen("users.bin", "wb+");

    //se o file for NULL significa que deu erro a abrir ou a criar o ficheiro
    if (file == NULL || userList.tam == 0) {
        return;
    }

    // escreve toda a estrutura da Turma para o ficheiro.
    fwrite(&userList, sizeof(UserList), 1, file);
    // IMPORTANTE: fechar o ficheiro
    fclose(file);
}

int validateLogin(char *username, char *password) {
    int i;
    for (i = 0; i < userList.tam; i++) {
        if (strcmp(userList.user[i].username, username) == 0
            && strcmp(userList.user[i].password, password) == 0) {
            return userList.user[i].type;
        }
    }
    return -1;
}

void printUser(User user) {
    printf("Username: %s\n", user.username);
    if (user.type == Clientes) {
        printf("Type: Cliente\n");
    } else {
        printf("Type: Manager\n");
    }
    printf("#####\n");
}

void listAllUsers() {
    int i;
    for (i = 0; i < userList.tam; i++) {
        printUser(userList.user[i]);
    }
}

void deleteUser(char *username) {
    int userFound = 0;
    int i;
    for (i = 0; i < userList.tam; i++) {
        if (userFound == 1) { //depois de encontrar o utilizador, todos os outros devem recuar uma posição
            userList.user[i - 1] = userList.user[i];
        } else {
            if (strcmp(userList.user[i].username, username) == 0) {
                userFound = 1;
            }
        }
    }
    if (userFound == 1) {
        userList.tam--;
    }
}

User* findUser(char *username) {
    int i;
    for (i = 0; i < userList.tam; i++) {
        if (strcmp(userList.user[i].username, username) == 0) {
            return &userList.user[i];
        }
    }
    return NULL;
}
