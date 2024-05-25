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
    Passageiro* novoPassageiro = new Passageiro;
    novoPassageiro->numeroDoBilhete = gerarBilheteAleatorio();
    novoPassageiro->primeiroNome = getRandomPrimeiroNome();
    novoPassageiro->segundoNome = getRandomSegundoNome();
    novoPassageiro->nacionalidade = getRandomNacionalidade();
    novoPassageiro->next = nullptr;

    if (proximoPassageiro == nullptr) {
        proximoPassageiro = novoPassageiro;
    } else {

        Passageiro* ultimoPassageiro = proximoPassageiro;
        while (ultimoPassageiro->next != nullptr) {
            ultimoPassageiro = ultimoPassageiro->next;
        }
        ultimoPassageiro->next = novoPassageiro;
    }
}

/**
 * Cria uma lista ligada de nacionalidades a partir da lista ligada de passageiros.
 *
 * @param passageiro Ponteiro para o início da lista ligada de passageiros.
 * A função percorre esta lista para extrair as nacionalidades dos passageiros.
 * @return Ponteiro para o início da lista de nacionalidades.
 * Cada nó da lista de nacionalidades contém uma nacionalidade única encontrada na lista de passageiros.
 */
Passageiro* listaNacionalidades(Passageiro*& passageiro) {
    Passageiro* nacionalidades = nullptr;
    Passageiro* atual = passageiro;

    while (atual != nullptr) {
        std::string novaNacionalidade = getRandomNacionalidade();

        Passageiro* temp = nacionalidades;
        bool existe = false;
        while (temp != nullptr) {
            if (temp->nacionalidade == novaNacionalidade) {
                existe = true;
                break;
            }
            temp = temp->next;
        }

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

/**
 * Insere um passageiro na lista de nacionalidades ou em sua árvore de passageiros associada.
 *
 * @param listaNacionalidades Ponteiro para o início da lista de nacionalidades.
 * A função percorre esta lista para encontrar a nacionalidade do passageiro.
 * Se a nacionalidade já existir na lista, o passageiro é inserido na árvore de passageiros associada.
 * Caso contrário, uma nova entrada é criada na lista de nacionalidades e o passageiro é inserido em sua árvore de passageiros.
 * @param passageiro Ponteiro para o passageiro a ser inserido na lista de nacionalidades ou em sua árvore de passageiros associada.
 */
void inserirPassageiroNaListaNacionalidades(Passageiro*& listaNacionalidades, Passageiro* passageiro) {
    Passageiro* temp = listaNacionalidades;
    while (temp != nullptr) {
        if (temp->nacionalidade == passageiro->nacionalidade) {
            inserirPassageiroNaArvore(temp->esq, passageiro);
            return;
        }
        temp = temp->next;
    }

    Passageiro* novoNo = new Passageiro;
    novoNo->nacionalidade = passageiro->nacionalidade;
    novoNo->esq = nullptr;
    novoNo->dir = nullptr;
    novoNo->next = listaNacionalidades;
    listaNacionalidades = novoNo;

    inserirPassageiroNaArvore(novoNo->esq, passageiro);
}


/**
 * Insere um passageiro em uma árvore binária de busca ordenada por nome.
 *
 * @param no Ponteiro para a raiz da árvore onde o passageiro será inserido.
 * @param passageiro Ponteiro para o passageiro a ser inserido na árvore.
 * O passageiro é inserido de acordo com seu primeiro nome, mantendo a ordem alfabética na árvore.
 */
void inserirPassageiroNaArvore(Passageiro*& no, Passageiro* passageiro) {
    if (no == nullptr) {
        no = passageiro;
    } else {
        if (passageiro->primeiroNome < no->primeiroNome) {
            inserirPassageiroNaArvore(no->esq, passageiro);
        } else {
            inserirPassageiroNaArvore(no->dir, passageiro);
        }
    }
}

/**
 *
 * @param no Ponteiro para o nó raiz da árvore a ser impressa.
 * @param nivel Nível de profundidade atual na árvore (começa em 0 para a raiz).
 */
void imprimeArvore(Passageiro* no, int nivel) {
    if (no == nullptr) {
        std::cout << std::endl;
        return;
    }

    imprimeArvore(no->dir, nivel + 1);
    for (int i = 0; i < nivel; i++) {
        std::cout << "\t";
    }
    std::cout << no->primeiroNome << " " << no->segundoNome << " (" << no->nacionalidade << ")" << std::endl;
    imprimeArvore(no->esq, nivel + 1);
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