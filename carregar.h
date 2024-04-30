#ifndef INC_2_EDA_PROJECT_CARREGAR_H
#define INC_2_EDA_PROJECT_CARREGAR_H
#include "aviao.h"


void carregarListaAprox(Aviao*& listaAprox, const std::string& nomeArquivo);

void carregarListaPista(Aviao*& listaPista, const std::string& nomeArquivo);

void carregarListaPartida(Aviao*& listaPartida, const std::string& nomeArquivo);

void limparListaAvioes(Aviao*& listaAvioes);

#endif //INC_2_EDA_PROJECT_CARREGAR_H
