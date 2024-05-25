#include "aviao.h"
#include "utils.h"
#include "passageiros.h"

/**
 * Cria um novo avião.
 *
 * @return Ponteiro para o novo avião criado.
 * O avião gerado contém um nome de voo aleatório, modelo de avião aleatório, origem aleatória,
 * destino fixo como "Aeroporto EDA", capacidade aleatória entre 10 e 15 passageiros, e uma lista de passageiros vazia.
 */
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

/**
 * Insere um novo avião na lista de aproximação.
 *
 * @param aNodo Ponteiro para o ponteiro do início da ListaAprox.
 * @param ListaAprox Referência para a ListaAprox.
 * @return Ponteiro para o início da ListaAprox, incluindo o avião recém-inserido.
 * Se a lista estava vazia, o avião é inserido como o primeiro elemento e os passageiros são adicionados.
 * Caso contrário, o avião é inserido no início da lista, mantendo a ordem dos aviões, e os passageiros são adicionados.
 */
Aviao* inserirAviaoAprox(Aviao** aNodo, Aviao* &ListaAprox) {
    Aviao *novo = novoAviao();
    if (*aNodo == nullptr) {
        *aNodo = novo;
        for (int i = 0; i < novo->capacidade; ++i) {
            adicionarPassageiro(novo->proximoPassageiro);
        }
    } else {
        novo->proximoAviao = *aNodo;
        *aNodo = novo;
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
 * @param listaDeOrigem Ponteiro para o ponteiro da lista de onde o aviao será removido.
 * @param listaDeDestino Ponteiro para o ponteiro da lista para onde o aviao será movido.
 * @param nomeVoo Nome do voo do aviao a ser movido.
 * @param modeloAviao Modelo do aviao a ser movido.
 */
void moverAviao(Aviao** listaDeOrigem, Aviao** listaDeDestino, std::string& nomeVoo, std::string& modeloAviao) {
    Aviao* anterior = nullptr;
    Aviao* atual = *listaDeOrigem;
    bool encontrado = false;

    do {
        anterior = nullptr;
        atual = *listaDeOrigem;
        while (atual && !(atual->nomeVoo == nomeVoo && atual->modeloAviao == modeloAviao)) {
            anterior = atual;
            atual = atual->proximoAviao;
        }
        if (atual) {
            if (anterior) {
                anterior->proximoAviao = atual->proximoAviao;
            } else {
                *listaDeOrigem = atual->proximoAviao;
            }

            atual->proximoAviao = *listaDeDestino;
            *listaDeDestino = atual;
            encontrado = true;
        } else {
            std::cout << "\nO aviao com o voo " << nomeVoo << " e o modelo " << modeloAviao << " nao foi encontrado na lista." << std::endl;
            std::cout << "Por favor, insira novamente os dados do aviao." << std::endl;
            std::cout << "Digite o Voo a ser movido (Pista): ";
            std::cin >> nomeVoo;
            converterParaMaiusculas(nomeVoo);
            std::cout << "Digite o Modelo do aviao a ser movido (Pista): ";
            std::cin >> modeloAviao;
            converterParaMaiusculas(modeloAviao);
        }
    } while (!encontrado);
}


/**
 * Move um aviao de uma lista para outra lista.
 *
 * @param listaDeOrigem Ponteiro para o ponteiro da lista de onde o aviao será removido.
 * @param listaDeDestino Ponteiro para o ponteiro da lista para onde o aviao será movido.
 * @param emergencia É o destino do aviao de emergencia
 */
void moverAviaoEmergencia(Aviao** listaDeOrigem, Aviao** listaDeDestino, const std::string& emergencia){
    Aviao* anterior = nullptr;
    Aviao* atual = *listaDeOrigem;

    while(atual && !(atual->destino == emergencia)){
        anterior = atual;
        atual = atual->proximoAviao;
    }
    if (atual){
        if (anterior){
            anterior->proximoAviao = atual->proximoAviao;
        }else{
            *listaDeOrigem = atual->proximoAviao;
        }

        atual -> proximoAviao = *listaDeDestino;
        *listaDeDestino = atual;
    }
}

/**
 * Remove um avião de uma lista.
 *
 * @param lista Ponteiro para o ponteiro da lista de onde o aviao será removido.
 * @param nomeVoo Nome do voo do aviao a ser removido.
 * @param modeloAviao Modelo do aviao a ser removido.
 */
void removerAviao(Aviao** lista, std::string& nomeVoo, std::string& modeloAviao) {
    Aviao* anterior = nullptr;
    Aviao* atual = *lista;
    bool encontrado = false;

    do{
        anterior = nullptr;
        atual = *lista;

        while(atual && !(atual->nomeVoo == nomeVoo && atual->modeloAviao == modeloAviao)){
            anterior = atual;
            atual = atual->proximoAviao;
        }

        if (atual){
            if (anterior){
                anterior->proximoAviao = atual->proximoAviao;
            }else{
                *lista = atual->proximoAviao;
            }
            delete atual;
            std::cout << "O aviao com o voo " << nomeVoo << " e o modelo " << modeloAviao << " foi removido da lista." << std::endl;
            encontrado = true;
        }else{
            std::cout << "\nO aviao com o voo " << nomeVoo << " e o modelo " << modeloAviao << " nao foi encontrado na lista." << std::endl;
            std::cout << "Por favor, insira novamente os dados do aviao." << std::endl;
            std::cout << "Digite o Voo a ser removido (Partida): ";
            std::cin >> nomeVoo;
            converterParaMaiusculas(nomeVoo);
            std::cout << "Digite o Modelo do aviao a ser removido (Partida): ";
            std::cin >> modeloAviao;
            converterParaMaiusculas(modeloAviao);
        }
    }while(!encontrado);
}


/**
 * Serve para converter uma string para letras maiusculas.
 *
 * @param str É a string a ser convertida para letras maiusculas.
 */
void converterParaMaiusculas(std::string& str){
    for(char& caractere : str){
        caractere = std::toupper(caractere);
    }
}