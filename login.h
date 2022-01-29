//
// Created by Win10 on 29/01/2022.
//

#ifndef BANCOINVESTMENTS_LOGIN_H
#define BANCOINVESTMENTS_LOGIN_H

#include "Clientes.h"
#define MAX_USERNAME 50
#define MAX_PASSWORD 100
#define MAX_USERS 200

typedef enum eUserType {Clientes =1, Manager =2} UserType;

typedef struct sUser{
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    UserType type;
    int clientId;
} User;

typedef struct sUserList{
    User user[MAX_USERS];
    int tam;
} UserList;

UserList userList;
void createNewUser();
void initUserList();
int validateLogin(char* username, char* password);
void saveUserList();
void listAllUsers();
void deleteUser(char* username);
User* findUser(char* username);

#endif //BANCOINVESTMENTS_LOGIN_H
