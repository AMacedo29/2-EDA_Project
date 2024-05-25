#ifndef INC_2_EDA_PROJECT_SIMULACAO_H
#define INC_2_EDA_PROJECT_SIMULACAO_H
#include "aviao.h"

void moverUltimoParaListaPista(Aviao** ListaAprox, Aviao** listaPista);
int countAvioes(Aviao* lista);
void moverUltimoParaListaPartidas(Aviao** listaPista, Aviao** listaPartida);
void removeUltimo(Aviao** lista);
void chegadaPassageiros(Aviao** listaPista);
void inserirPassageirosNaArvoreDeNacionalidades(Aviao* aviao);



#endif //INC_2_EDA_PROJECT_SIMULACAO_H
