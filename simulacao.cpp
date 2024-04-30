#include "simulacao.h"
#include "aviao.h"


void moverUltimoParaListaPista(Aviao** ListaAprox, Aviao** listaPista) {
    // Verificar se a lista de aproximação não é nula
    if (*ListaAprox == nullptr) {
        return; // Não há nada a ser movido
    }

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
    *listaPista = atual;

    // O elemento anterior ao último na lista de aprox agora aponta para NULL
    if (anterior != nullptr) {
        anterior->proximoAviao = nullptr;
    }
}

void moverUltimoParaListaPartidas(Aviao** listaPista, Aviao** listaPartida) {
    // Verificar se a lista de pista não é nula
    if (*listaPista == nullptr) {
        return; // Não há nada a ser movido
    }

    // Encontrar o último elemento da lista de pista
    Aviao* anterior = nullptr;
    Aviao* atual = *listaPista;
    while (atual->proximoAviao != nullptr) {
        anterior = atual;
        atual = atual->proximoAviao;
    }

    // O último elemento da lista de pista agora aponta para o primeiro da lista de partidas
    atual->proximoAviao = *listaPartida;

    // O último elemento da lista de pista se torna o primeiro da lista de partidas
    *listaPartida = *listaPista;

    // Atualizar o ponteiro para a lista de pista
    *listaPista = anterior;

    // O próximo do último elemento na lista de partidas agora é nullptr
    atual->proximoAviao = nullptr;
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
    if (*lista == nullptr || (*lista)->proximoAviao == nullptr) {
        return; // Lista vazia ou com apenas um elemento
    }

    Aviao* atual = *lista;
    Aviao* anterior = nullptr;

    // Percorre a lista até o penúltimo elemento
    while (atual->proximoAviao != nullptr) {
        anterior = atual;
        atual = atual->proximoAviao;
    }

    // O último elemento é 'atual', e o penúltimo é 'anterior'
    // Remove o último elemento ajustando o ponteiro do penúltimo para nullptr
    anterior->proximoAviao = nullptr;
    delete atual; // Libera a memória do último elemento
}

