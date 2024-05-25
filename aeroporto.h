#ifndef INC_2_EDA_PROJECT_AEROPORTO_H
#define INC_2_EDA_PROJECT_AEROPORTO_H
#include "aviao.h"

void imprimirArvoreInOrder(Passageiro* raiz);
Passageiro* construirArvoreBinariaDosPassageiros(Aviao* listaPista);


void aeroportoMenu();

void menuNacionalidades();

void mostrarPassageiroVoo(Aviao* listaAprox, std::string numVoo);

bool validarprimNome(Aviao* listaAprox, std::string& primNome, std::string& nomeVoo);

bool validarsegNome(Aviao* listaAprox, std::string& segNome, std::string& nomeVoo);

void editarnacionalidade(Aviao* listaAprox);

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
