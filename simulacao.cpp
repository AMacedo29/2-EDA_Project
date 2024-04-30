#include "simulacao.h"
#include "aviao.h"


void moverUltimoParaListaPista(Aviao** ListaAprox, Aviao** listaPista) {
    if (*ListaAprox == nullptr) {
        return;
    }

    Aviao* anterior = nullptr;
    Aviao* atual = *ListaAprox;
    while (atual->proximoAviao != nullptr) {
        anterior = atual;
        atual = atual->proximoAviao;
    }

    atual->proximoAviao = *listaPista;
    *listaPista = *ListaAprox;
    *listaPista = atual;

    if (anterior != nullptr) {
        anterior->proximoAviao = nullptr;
    }
}

void moverUltimoParaListaPartidas(Aviao** listaPista, Aviao** listaPartida) {
    if (*listaPista == nullptr) {
        return;
    }

    Aviao* ultimoPista = nullptr;
    Aviao* atual = *listaPista;

    while (atual->proximoAviao != nullptr) {
        ultimoPista = atual;
        atual = atual->proximoAviao;
    }

    if (ultimoPista == nullptr) {
        *listaPista = nullptr;
    } else {
        ultimoPista->proximoAviao = nullptr;
    }

    if (*listaPartida == nullptr) {
        *listaPartida = atual;
    } else {
        atual->proximoAviao = *listaPartida;
        *listaPartida = atual;
    }
}

int countAvioes(Aviao* lista) {
    int count = 0;
    while (lista != nullptr) {
        count++;
        lista = lista->proximoAviao;
    }
    return count;
}

void removeUltimo(Aviao** lista) {
    if (*lista == nullptr) {
        return;
    }

    Aviao* anterior = nullptr;
    Aviao* atual = *lista;

    while (atual->proximoAviao != nullptr) {
        anterior = atual;
        atual = atual->proximoAviao;
    }

    if (anterior != nullptr) {
        anterior->proximoAviao = nullptr;
    } else {
        *lista = nullptr;
    }

    delete atual;
}

