#include <iostream>
#include "string"
#include "passageiros.h"
#include "utils.h"
#include "aviao.h"


// Parece q isto n me vai servir para nada
// Esta a funcionar bem

void novoPassageiro(){
    std::string numeroDoBilhete = gerarBilheteAleatorio();
    std::string primeiroNome = getRandomPrimeiroNome();
    std::string segundoNome = getRandomSegundoNome();
    std::string nacionalidade = getRandomNacionalidade();

    std::cout << "Bilhete: " << numeroDoBilhete << std::endl;
    std::cout << "Primeiro Nome: " << primeiroNome << std::endl;
    std::cout << "Segundo Nome: " << segundoNome << std::endl;
    std::cout << "Nacionalidade: " << nacionalidade << std::endl;
    std::cout << std::endl;

}


///////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 *Função para contar o número de passageiros a bordo do avião
 *
 * @param aviao Ponteiro para o avião
 * @return O número de passageiros a bordo
 */
int contarPassageiros(Aviao* aviao) {
    int numeroDePassagerios = 0;
    Passageiro* passageiroAtual = aviao->proximoPassageiro;

    // Percorre a lista de passageiros e conta cada um
    while (passageiroAtual != nullptr) {
        numeroDePassagerios++;
        passageiroAtual = passageiroAtual->next;
    }
    return numeroDePassagerios;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 *Adiciona um novo passageiro ao avião (se houver capacidade)
 *
 * @param aviao Ponteiro para o avião em que o passageiro será inserido
 */
void adicionarPassageiro(Passageiro*& proximoPassageiro) {
    // Cria um novo passageiro
    Passageiro* novoPassageiro = new Passageiro;
    novoPassageiro->numeroDoBilhete = gerarBilheteAleatorio();
    novoPassageiro->primeiroNome = getRandomPrimeiroNome();
    novoPassageiro->segundoNome = getRandomSegundoNome();
    novoPassageiro->nacionalidade = getRandomNacionalidade();
    novoPassageiro->next = nullptr;

    // Se a lista estiver vazia, o novo passageiro será o primeiro
    if (proximoPassageiro == nullptr) {
        proximoPassageiro = novoPassageiro;
    } else {
        // Caso contrário, vai até ao último passageiro e adicione o novo passageiro lá
        Passageiro* ultimoPassageiro = proximoPassageiro;
        while (ultimoPassageiro->next != nullptr) {
            ultimoPassageiro = ultimoPassageiro->next;
        }
        ultimoPassageiro->next = novoPassageiro;
    }
}

Passageiro* listaNacionalidades(Passageiro*& passageiro) {
    Passageiro* nacionalidades = nullptr;
    Passageiro* atual = passageiro;

    while (atual != nullptr) {
        std::string novaNacionalidade = getRandomNacionalidade();

        // Verifica se a nacionalidade já está na lista
        Passageiro* temp = nacionalidades;
        bool existe = false;
        while (temp != nullptr) {
            if (temp->nacionalidade == novaNacionalidade) {
                existe = true;
                break;
            }
            temp = temp->next;
        }

        // Adiciona a nova nacionalidade se não estiver na lista
        if (!existe) {
            Passageiro* novo = new Passageiro;
            novo->nacionalidade = novaNacionalidade;
            novo->next = nacionalidades;
            nacionalidades = novo;
        }

        atual = atual->next;
    }

    return nacionalidades;
}

/*
Passageiro* removerCopia(Passageiro* raiz, int num) {
    Passageiro* no = raiz;
    Passageiro* ant = NULL;
    while (no != NULL) {
        if (num == no->dados) {
            return removerCopia(raiz, no, ant);
        }
        else if (num < no->dados) {
            ant = no;
            no = no->esq;
        }
        else {
            ant = no;
            no = no->dir;
        }
    }
    return nullptr;
}

Passageiro* removerCopia(Passageiro* raiz, Passageiro* no, Passageiro* ant) {
    if (ant == NULL) { //remover a raiz
        if (no->esq == NULL && no->dir == NULL)
            raiz = NULL;
        else if (no->esq != NULL && no->dir == NULL)
            raiz = no->esq;
        else if (no->esq == NULL && no->dir != NULL)
            raiz = no->dir;
        else { //efetuar copia
            Passageiro* temp = no->esq;
            ant = raiz;
            while (temp->dir != NULL) {
                ant = temp;
                temp = temp->dir;
            }
            swap(temp->valor, raiz->valor);
            if (ant->valor >= raiz->valor || ant == raiz)
                ant->esq = temp->esq;
            else
                ant->dir = temp->esq;
            no = temp;
        }
    }
    else { // remover qualquer outro nó
        if (no->esq == NULL && no->dir == NULL) {
            if (ant->valor > no->valor)
                ant->esq = NULL;
            else
                ant->dir = NULL;
        }
        else if (no->esq == NULL && no->dir != NULL) {
            if (ant->valor > no->valor)
                ant->esq = no->dir;
            else
                ant->dir = no->dir;
        }
        else if (no->esq != NULL && no->dir == NULL) {
            if (ant->valor > no->valor)
                ant->esq = no->esq;
            else
                ant->dir = no->esq;
        }
        else { // efetuar copia
            Passageiro* temp = no->esq;
            ant = no;
            while (temp->dir != NULL) {
                ant = temp;
                temp = temp->dir;
            }
            swap(temp->valor, no->valor);
            if (ant->valor > no->valor || ant == no)
                ant->esq = temp->esq;
            else
                ant->dir = temp->esq;
            no = temp;
        }

    }
    return no;
}
*/