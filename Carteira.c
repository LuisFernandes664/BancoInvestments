//
// Created by ivodu on 11/01/2022.
//

#include "Carteira.h"
#include <stdio.h>
#include <string.h>

Carteira CriarCarteiras(){

    Carteiras a;

    printf(("Introduza o nome da carteira:"));
    fgets(a.nomecarteira,stdin);
    a.nomecarteira[strnlen(a.nomecarteira)-1] = '\0';

    printf("Introduza numero da carteira: ");
    scanf("%d", &a.idcarteira);
}

void printCarteiras(Carteiras a){

    printf("Numero da carteira: %d\n", a.NumIndent);
    printf("Nome da carteira: %s\n", a.nomecarteira);

}



