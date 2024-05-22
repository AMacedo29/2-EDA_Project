#ifndef INC_2_EDA_PROJECT_EMERGENCIAS_H
#define INC_2_EDA_PROJECT_EMERGENCIAS_H
#include "aviao.h"

void menuOpcoes();

extern bool aeroportoFechado;

extern int diasRestantesAeroportoFechado;

void fecharAeroporto();

void inverterLista(Aviao*& head);

void inverterPrioridade(Aviao*& listaPista);

#endif //INC_2_EDA_PROJECT_EMERGENCIAS_H
