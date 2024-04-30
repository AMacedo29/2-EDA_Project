#ifndef INC_2_EDA_PROJECT_AVIAO_H
#define INC_2_EDA_PROJECT_AVIAO_H
#include <iostream>
#include <string>
#include "passageiros.h"



struct Aviao{
    std::string nomeVoo;
    std::string modeloAviao;
    std::string origem;
    std::string destino;
    int capacidade; // entre 5 e 15 (sempre cheios pag2 do encunciado)
    //Falata o "Conjunto de passageiros"
    Aviao* proximoAviao; // Ponteiro para o proximo avião da lista ligada
    Passageiro* proximoPassageiro; //Ponteiro para o prixmo passageiro da lista liaga
};


Aviao* novoAviao();

Aviao* inserirAviaoAprox(Aviao** aNodo, Aviao* &ListaAprox);


#endif //INC_2_EDA_PROJECT_AVIAO_H
