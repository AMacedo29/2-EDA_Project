#include "simulacao.h"
#include "aviao.h"
#include "utils.h"
#include "passageiros.h"

/**
 * Move o último avião da lista de aproximação para a lista de aviões na pista.
 *
 * @param ListaAprox Ponteiro para o ponteiro do início da lista de aviões em aproximação.
 * @param listaPista Ponteiro para o ponteiro do início da lista de aviões na pista.
 */
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

/**
 * Insere os passageiros de um avião na árvore de nacionalidades.
 *
 * @param aviao Ponteiro para o avião do qual os passageiros serão inseridos na árvore de nacionalidades.
 */
void inserirPassageirosNaArvoreDeNacionalidades(Aviao* aviao) {
    if (aviao == nullptr || aviao->proximoPassageiro == nullptr) {
        return;
    }

    Passageiro* passageiroAtual = aviao->proximoPassageiro;
    Passageiro* nacionalidades = listaNacionalidades(aviao->proximoPassageiro);
    while (passageiroAtual != nullptr) {
        Passageiro* passageiroParaInserir = new Passageiro(*passageiroAtual);
        inserirPassageiroNaListaNacionalidades(nacionalidades, passageiroParaInserir);
        passageiroAtual = passageiroAtual->next;
    }
}

/**
 * Remove os passageiros antigos de cada avião na lista de pista e adiciona novos passageiros.
 *
 * @param listaPista Ponteiro para o ponteiro do início da lista de aviões na pista.
 */
void chegadaPassageiros(Aviao** listaPista){
    if (*listaPista == nullptr) {
        return;
    }

    Aviao* atual = *listaPista;
    while (atual != nullptr) {
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

/**
 * Move o último avião da lista de pista para a lista de partidas.
 *
 * @param listaPista Ponteiro para o ponteiro do início da lista de aviões na pista.
 * @param listaPartida Ponteiro para o ponteiro do início da lista de aviões de partida.
 */
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

/**
 * Conta o número de aviões de uma lista ligada.
 *
 * @param lista Ponteiro para o início da lista de aviões.
 * @return O número de aviões na lista.
 * Se a lista estiver vazia, retorna 0.
 */
int countAvioes(Aviao* lista) {
    int count = 0;
    while (lista != nullptr) {
        count++;
        lista = lista->proximoAviao;
    }
    return count;
}

/**
 * Remove o último avião de uma lista ligada.
 *
 * @param lista Ponteiro para o ponteiro do início da lista de aviões.
 */
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

