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
