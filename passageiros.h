#ifndef INC_2_EDA_PROJECT_PASSAGEIROS_H
#define INC_2_EDA_PROJECT_PASSAGEIROS_H
#include <iostream>
#include <string>

using namespace std;

struct Passageiro{
    int numeroDoBilhete; //TK1000000
    string primeiroNome;
    string segundoNome;
    string nacionalidade;
    Passageiro* next; // Ponteiro para o próximo passageiro da lista
    Passageiro* esq;  // Ponteiro para o filho da esquerdo na árvore
    Passageiro* dir;  // Ponteiro para o filho da direito na árvore
};


#endif //INC_2_EDA_PROJECT_PASSAGEIROS_H
