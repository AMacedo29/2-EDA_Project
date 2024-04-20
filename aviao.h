#ifndef INC_2_EDA_PROJECT_AVIAO_H
#define INC_2_EDA_PROJECT_AVIAO_H
#include <iostream>
#include <string>
#include "passageiros.h"

using namespace std;


struct Aviao{
    string nomeVoo;
    string modeloAviao;
    string origem;
    string destino;
    int capacidade; // entre 5 e 15 (sempre cheios pag2 do encunciado)
    //Falata o "Conjunto de passageiros"
    Aviao* proximoAviao; // Ponteiro para o proximo avião da lista ligada
    Passageiro* proximoPassageiro; //Ponteiro para o prixmo passageiro da lista liaga
};

void adicionarAviao(Aviao*& lista, Aviao* novoAviao);

void imprimirAvioes(Aviao* lista);

Aviao* gerarAviaoAleatorio();

#endif //INC_2_EDA_PROJECT_AVIAO_H
