#include "aviao.h"
#include "utils.h"
#include "passageiros.h"


Aviao* novoAviao(){
    Aviao* elemento = new Aviao;
    elemento->proximoAviao = NULL;
    elemento->nomeVoo = getRandomVoo();
    elemento->modeloAviao = getRandomModelo();
    elemento->origem = getRandomOrigem();
    elemento->destino = "Aeroporto EDA";
    elemento->capacidade = randomNumber(10,15);
    elemento->proximoPassageiro = nullptr;

    return elemento;
}

Aviao* inserirAviaoAprox(Aviao** aNodo, Aviao* &ListaAprox) {
    Aviao *novo = novoAviao();
    if (*aNodo == nullptr) {
        *aNodo = novo;
    } else {
        novo->proximoAviao = *aNodo;
        *aNodo = novo;
        // Adicionar passageiros ao avião
        for (int i = 0; i < novo->capacidade; ++i) {
            adicionarPassageiro(novo->proximoPassageiro);
        }
    }
    return *aNodo;
}

///////////////////////////////////////////////////////////////////////////////


/**
 * Cria e retorna um novo aviao de emergência. (O codigo era do colega so mudei 1 coisa para isto ficar a dar como eu queria).
 *
 * @return  Retorna o ponteiro para o novo aviao criado.
 */
Aviao* novoAviaoEmergencia(){
    Aviao* elemento = new Aviao;
    elemento->proximoAviao = NULL;
    elemento->nomeVoo = getRandomVoo();
    elemento->modeloAviao = getRandomModelo();
    elemento->origem = getRandomOrigem();
    elemento->destino = "Aeroporto EDA Emergencia";
    elemento->capacidade = randomNumber(10,15);
    elemento->proximoPassageiro = nullptr;

    return elemento;
}


/**
 * Insere um novo avião de emergência na lista de aproximação (O codigo era do colega so mudei 1 coisa para isto ficar a dar como eu queria).
 *
 * @param aNodo Ponteiro para o ponteiro do inicio da ListaAprox.
 * @param ListaAprox Referencia para a ListaAprox.
 * @return Ponteiro para o inicio da ListAprox, incluindo o aviao de emergencia.
 */
Aviao* inserirAviaoAproxEmergencia(Aviao** aNodo, Aviao* &ListaAprox) {
    Aviao *novo = novoAviaoEmergencia();

    if (*aNodo == nullptr) {
        *aNodo = novo;
    } else {
        novo->proximoAviao = *aNodo;
        *aNodo = novo;
        // Adicionar passageiros ao avião
        for (int i = 0; i < novo->capacidade; ++i) {
            adicionarPassageiro(novo->proximoPassageiro);
        }
    }
    return *aNodo;
}


/**
 * Move um aviao de uma lista para outra lista.
 *
 * @param origem Ponteiro para o ponteiro da lista de onde o aviao será removido.
 * @param destino Ponteiro para o ponteiro da lista para onde o aviao será movido.
 * @param nomeVoo Nome do voo do aviao a ser movido.
 * @param modeloAviao Modelo do aviao a ser movido.
 */
void moverAviao(Aviao** origem, Aviao** destino, const std::string& nomeVoo, const std::string& modeloAviao) {
    Aviao* anterior = nullptr;
    Aviao* atual = *origem;

    while (atual && !(atual->nomeVoo == nomeVoo && atual->modeloAviao == modeloAviao)) {
        anterior = atual;
        atual = atual->proximoAviao;
    }
    if (atual) {
        if (anterior) {
            anterior->proximoAviao = atual->proximoAviao;
        } else {
            *origem = atual->proximoAviao;
        }

        atual->proximoAviao = *destino;
        *destino = atual;
    } else {
        std::cout << "Aviao com o voo " << nomeVoo << " e o modelo " << modeloAviao << " nao foi encontrado na lista." << std::endl;
    }
}


/**
 * Remove um avião de uma lista.
 *
 * @param lista Ponteiro para o ponteiro da lista de onde o aviao será removido.
 * @param nomeVoo Nome do voo do aviao a ser removido.
 * @param modeloAviao Modelo do aviao a ser removido.
 */
void removerAviao(Aviao** lista, const std::string& nomeVoo, const std::string& modeloAviao) {
    Aviao* anterior = nullptr;
    Aviao* atual = *lista;

    while (atual && !(atual->nomeVoo == nomeVoo && atual->modeloAviao == modeloAviao)) {
        anterior = atual;
        atual = atual->proximoAviao;
    }
    if (atual) {
        if (anterior) {
            anterior->proximoAviao = atual->proximoAviao;
        } else {
            *lista = atual->proximoAviao;
        }
        delete atual;
    } else {
        std::cout << "Avião com voo " << nomeVoo << " e modelo " << modeloAviao << " não encontrado na lista." << std::endl;
    }
}