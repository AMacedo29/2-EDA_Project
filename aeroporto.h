#ifndef INC_2_EDA_PROJECT_AEROPORTO_H
#define INC_2_EDA_PROJECT_AEROPORTO_H
#include "aviao.h"


void aeroportoMenu();

void menuNacionalidades();



void mostrarpassageirosordenados(Aviao* listaPista);

void pesquisarpassageiro(Aviao* listaPista, Aviao* listaAprox);

void mostrarpassageiros(Aviao* listaPista);

void imprimirListaAprox(Aviao* ListaAprox);

void imprimirListaPista(Aviao* listaPista);

void imprimirListaPartida(Aviao* listaPartida);

void addListaAprox(Aviao*& ListaAprox);

extern Aviao* ListaAprox;
extern Aviao* listaPista;
extern Aviao* listaPartida;

#endif //INC_2_EDA_PROJECT_AEROPORTO_H
