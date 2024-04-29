#include "simulacao.h"
#include "aviao.h"


void moverUltimoParaListaPista(Aviao** ListaAprox, Aviao** listaPista) {
    // Encontrar o último elemento da lista de aprox
    Aviao* anterior = nullptr;
    Aviao* atual = *ListaAprox;
    while (atual->proximoAviao != nullptr) {
        anterior = atual;
        atual = atual->proximoAviao;
    }

    // O último elemento da lista de aprox agora aponta para o primeiro da lista de pista
    atual->proximoAviao = *listaPista;

    // O último elemento da lista de aprox se torna o primeiro da lista de pista
    *listaPista = *ListaAprox;

    // O elemento anterior ao último na lista de aprox agora aponta para NULL
    if (anterior != nullptr) {
        anterior->proximoAviao = nullptr;
    }
}