//
// Created by Win10 on 04/01/2022.
//

#include "helper.h"
#include <stdio.h>

void limpaBuffer(){
    while (getchar() != '\n' && getchar() != EOF);
}