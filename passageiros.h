#ifndef INC_2_EDA_PROJECT_PASSAGEIROS_H
#define INC_2_EDA_PROJECT_PASSAGEIROS_H
#include <iostream>
#include <string>
#include "aviao.h"

using namespace std;

struct Passageiro{
    string numeroDoBilhete; //TK1000000
    string primeiroNome;
    string segundoNome;
    string nacionalidade;
    Passageiro* next; // Ponteiro para o próximo passageiro da lista
    Passageiro* esq;  // Ponteiro para o filho da esquerdo na árvore
    Passageiro* dir;  // Ponteiro para o filho da direito na árvore
};

void novoPassageiro();

int contarPassageiros();

void adicionarPassageiro();


#endif //INC_2_EDA_PROJECT_PASSAGEIROS_H
