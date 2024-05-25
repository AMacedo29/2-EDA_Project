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
    Aviao* proximoAviao; // Ponteiro para o proximo avião da lista ligada
    Passageiro* proximoPassageiro; //Ponteiro para o proximo passageiro da lista liaga
};


Aviao* novoAviao();

Aviao* inserirAviaoAprox(Aviao** aNodo, Aviao* &ListaAprox);

Aviao* novoAviaoEmergencia();

Aviao* inserirAviaoAproxEmergencia(Aviao** aNodo, Aviao* &ListaAprox);

void moverAviao(Aviao** origem, Aviao** destino,  std::string& nomeVoo,  std::string& modeloAviao);

void removerAviao(Aviao** lista,  std::string& nomeVoo,  std::string& modeloAviao);

void moverAviaoEmergencia(Aviao** origem, Aviao** destino ,const std::string& emergencia);

void converterParaMaiusculas(std::string& str);

#endif //INC_2_EDA_PROJECT_AVIAO_H
