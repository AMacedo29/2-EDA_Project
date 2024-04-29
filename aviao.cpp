#include "aviao.h"
#include "utils.h"
#include "passageiros.h"


Aviao* novoAviao(){
    Aviao* elemento = new Aviao;
    elemento->proximoAviao = NULL;
    elemento->nomeVoo = getRandomVoo();
    elemento->modeloAviao = getRandomModelo();
    elemento->origem = getRandomOrigem();
    elemento->destino = getRandomDestino();
    elemento->capacidade = randomNumber(5,15);

    return elemento;
}

Aviao* inserirAviaoAprox(Aviao** aNodo, Aviao* &ListaAprox) {
    Aviao *novo = novoAviao();
    if (*aNodo == nullptr) {
        *aNodo = novo;
    } else {
        novo->proximoAviao = *aNodo;
        *aNodo = novo;
    }
    return *aNodo;
}
