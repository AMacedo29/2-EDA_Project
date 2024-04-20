#include "aviao.h"
#include "utils.h"
#include "passageiros.h"

using namespace std;


/**
 * Função para adicionar um avião à lista ligada (no inicio)
 *
 * @param lista Um ponteiro para o ponteiro do início da lista ligada de aviões.
 * @param novoAviao Um ponteiro para o novo avião a ser adicionado à lista.
 */
void adicionarAviao(Aviao*& lista, Aviao* novoAviao) {
    novoAviao->proximoAviao = lista;
    lista = novoAviao;
}

/**
 * Função para imprimir os aviões na lista ligada
 *
 * @param lista Um ponteiro para o primeiro avião na lista ligada de aviões.
 */
void imprimirAvioes(Aviao* lista) {
    Aviao* atual = lista;
    while (atual != nullptr) {
        cout << "Nome do voo: " << atual->nomeVoo << endl;
        cout << "Modelo do aviao: " << atual->modeloAviao << endl;
        cout << "Origem: " << atual->origem << endl;
        cout << "Destino: " << atual->destino << endl;
        cout << "Capacidade: " << atual->capacidade << endl;
        cout << endl;  // É para os prints n ficarem colados
        atual = atual->proximoAviao; // Atualiza o apontador apra o prox avião
    }
}


/**
 * Função para gerar um avião de forma aleatória
 *
 * @returnUm ponteiro para o novo avião gerado.
 */
Aviao* gerarAviaoAleatorio() {
    Aviao* novoAviao = new Aviao;
    novoAviao->nomeVoo = getRandomVoo();
    novoAviao->modeloAviao = getRandomModelo();
    novoAviao->origem = getRandomOrigem();
    novoAviao->destino = getRandomDestino();
    novoAviao->capacidade = randomNumber(5,15);
    novoAviao->proximoPassageiro = nullptr;
    novoAviao->proximoAviao = nullptr;

    return novoAviao;
}