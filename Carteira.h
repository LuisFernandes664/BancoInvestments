//
// Created by ivodu on 11/01/2022.
//

#ifndef BANCOHFINVESTMENTS_CARTEIRA_H
#define BANCOHFINVESTMENTS_CARTEIRA_H

#define MAX NOME 20

typedef struct sCarteira{
    int idcarteira;
    char nomecarteira;
    int quantidademoeda;
    int nomemoeda;
} Carteira;

Carteira CriarCarteiras();
void printCarteiras(Carteiras a);

#endif //BANCOHFINVESTMENTS_CARTEIRA_H

