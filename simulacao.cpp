#include "simulacao.h"
#include "aviao.h"
#include "utils.h"
#include "passageiros.h"


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

    // Serve para mudar a origem, o destino e o numero(nos temos nome) de voo dos avioes
    atual->destino = getRandomDestino();
    atual->origem = "Aeroporto EDA";
    atual->nomeVoo = getRandomVoo();

    atual->proximoAviao = *listaPista;
    *listaPista = *ListaAprox;
    *listaPista = atual;

    if (anterior != nullptr) {
        anterior->proximoAviao = nullptr;
    }
    chegadaPassageiros(listaPista);
}

void chegadaPassageiros(Aviao** listaPista){
    if (*listaPista == nullptr) {
        return;
    }

    Aviao* atual = *listaPista;
    while (atual != nullptr) {
        // Remover passageiros antigos
        Passageiro* passageiroAtual = atual->proximoPassageiro;
        while (passageiroAtual != nullptr) {
            Passageiro* temp = passageiroAtual;
            passageiroAtual = passageiroAtual->next;
            delete temp;
        }
        atual->proximoPassageiro = nullptr;

        for (int i = 0; i < atual->capacidade; ++i) {
            adicionarPassageiro(atual->proximoPassageiro);
        }

        atual = atual->proximoAviao;
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

