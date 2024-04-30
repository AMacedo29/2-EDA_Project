#include "fstream"
#include "carregar.h"
#include "aviao.h"
/*
void limparLista(Aviao*& lista) {
    while (lista != nullptr) {
        Aviao* proximo = lista->proximoAviao;
        delete lista;
        lista = proximo;
    }
}

void carregarListaAprox(Aviao*& listaAprox, const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para leitura." << std::endl;
        return;
    }

    // Cria uma lista temporária para armazenar os novos aviões
    Aviao* listaTemp = nullptr;

    std::string nomeVoo, modeloAviao, origem, destino;
    int capacidade;

    while (arquivo >> nomeVoo >> modeloAviao >> origem >> destino >> capacidade) {
        Aviao* novoAviaoPonteiro = novoAviao();
        novoAviaoPonteiro->nomeVoo = nomeVoo;
        novoAviaoPonteiro->modeloAviao = modeloAviao;
        novoAviaoPonteiro->origem = origem;
        novoAviaoPonteiro->destino = destino;
        novoAviaoPonteiro->capacidade = capacidade;

        // Adiciona o novo avião à lista temporária
        novoAviaoPonteiro->proximoAviao = listaTemp;
        listaTemp = novoAviaoPonteiro;
    }

    // Limpa a lista original
    //limparLista(listaAprox);

    // Concatena a lista temporária à lista original
    Aviao* temp = listaTemp;
    while (temp != nullptr) {
        Aviao* proximo = temp->proximoAviao;
        temp->proximoAviao = listaAprox;
        listaAprox = temp;
        temp = proximo;
    }

    arquivo.close();
}

void carregarListaPista(Aviao*& listaPista, const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para leitura." << std::endl;
        return;
    }

    // Cria uma lista temporária para armazenar os novos aviões
    Aviao* listaTemp = nullptr;

    std::string nomeVoo, modeloAviao, origem, destino;
    int capacidade;

    while (arquivo >> nomeVoo >> modeloAviao >> origem >> destino >> capacidade) {
        Aviao* novoAviaoPonteiro = novoAviao();
        novoAviaoPonteiro->nomeVoo = nomeVoo;
        novoAviaoPonteiro->modeloAviao = modeloAviao;
        novoAviaoPonteiro->origem = origem;
        novoAviaoPonteiro->destino = destino;
        novoAviaoPonteiro->capacidade = capacidade;

        // Adiciona o novo avião à lista temporária
        novoAviaoPonteiro->proximoAviao = listaTemp;
        listaTemp = novoAviaoPonteiro;
    }

    // Limpa a lista original
    //limparLista(listaPista);

    // Concatena a lista temporária à lista original
    Aviao* temp = listaTemp;
    while (temp != nullptr) {
        Aviao* proximo = temp->proximoAviao;
        temp->proximoAviao = listaPista;
        listaPista = temp;
        temp = proximo;
    }

    arquivo.close();
}

void carregarListaPartida(Aviao*& listaPartida, const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para leitura." << std::endl;
        return;
    }

    // Cria uma lista temporária para armazenar os novos aviões
    Aviao* listaTemp = nullptr;

    std::string nomeVoo, modeloAviao, origem, destino;
    int capacidade;

    while (arquivo >> nomeVoo >> modeloAviao >> origem >> destino >> capacidade) {
        Aviao* novoAviaoPonteiro = novoAviao();
        novoAviaoPonteiro->nomeVoo = nomeVoo;
        novoAviaoPonteiro->modeloAviao = modeloAviao;
        novoAviaoPonteiro->origem = origem;
        novoAviaoPonteiro->destino = destino;
        novoAviaoPonteiro->capacidade = capacidade;

        // Adiciona o novo avião à lista temporária
        novoAviaoPonteiro->proximoAviao = listaTemp;
        listaTemp = novoAviaoPonteiro;
    }

    // Limpa a lista original
    //limparLista(listaPartida);

    // Concatena a lista temporária à lista original
    Aviao* temp = listaTemp;
    while (temp != nullptr) {
        Aviao* proximo = temp->proximoAviao;
        temp->proximoAviao = listaPartida;
        listaPartida = temp;
        temp = proximo;
    }

    arquivo.close();
}



// primeira

void carregarListaAprox(Aviao*& listaAprox, const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para leitura." << std::endl;
        return;
    }

    std::string nomeVoo, modeloAviao, origem, destino;
    int capacidade;

    while (arquivo >> nomeVoo >> modeloAviao >> origem >> destino >> capacidade) {
        Aviao* novoAviaoPonteiro = novoAviao();
        novoAviaoPonteiro->nomeVoo = nomeVoo;
        novoAviaoPonteiro->modeloAviao = modeloAviao;
        novoAviaoPonteiro->origem = origem;
        novoAviaoPonteiro->destino = destino;
        novoAviaoPonteiro->capacidade = capacidade;

        // Adicione o novo avião à lista de aproximação
        if (listaAprox == nullptr) {
            listaAprox = novoAviaoPonteiro;
        } else {
            Aviao* temp = listaAprox;
            while (temp->proximoAviao != nullptr) {
                temp = temp->proximoAviao;
            }
            temp->proximoAviao = novoAviaoPonteiro;
        }
    }

    arquivo.close();
}

void carregarListaPista(Aviao*& listaPista, const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para leitura." << std::endl;
        return;
    }

    std::string nomeVoo, modeloAviao, origem, destino;
    int capacidade;

    while (arquivo >> nomeVoo >> modeloAviao >> origem >> destino >> capacidade) {
        Aviao* novoAviaoPonteiro = novoAviao();
        novoAviaoPonteiro->nomeVoo = nomeVoo;
        novoAviaoPonteiro->modeloAviao = modeloAviao;
        novoAviaoPonteiro->origem = origem;
        novoAviaoPonteiro->destino = destino;
        novoAviaoPonteiro->capacidade = capacidade;

        // Adicione o novo avião à lista de pista
        if (listaPista == nullptr) {
            listaPista = novoAviaoPonteiro;
        } else {
            Aviao* temp = listaPista;
            while (temp->proximoAviao != nullptr) {
                temp = temp->proximoAviao;
            }
            temp->proximoAviao = novoAviaoPonteiro;
        }
    }

    arquivo.close();
}

void carregarListaPartida(Aviao*& listaPartida, const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para leitura." << std::endl;
        return;
    }

    std::string nomeVoo, modeloAviao, origem, destino;
    int capacidade;

    while (arquivo >> nomeVoo >> modeloAviao >> origem >> destino >> capacidade) {
        Aviao* novoAviaoPonteiro = novoAviao();
        novoAviaoPonteiro->nomeVoo = nomeVoo;
        novoAviaoPonteiro->modeloAviao = modeloAviao;
        novoAviaoPonteiro->origem = origem;
        novoAviaoPonteiro->destino = destino;
        novoAviaoPonteiro->capacidade = capacidade;

        // Adicione o novo avião à lista de partida
        if (listaPartida == nullptr) {
            listaPartida = novoAviaoPonteiro;
        } else {
            Aviao* temp = listaPartida;
            while (temp->proximoAviao != nullptr) {
                temp = temp->proximoAviao;
            }
            temp->proximoAviao = novoAviaoPonteiro;
        }
    }

    arquivo.close();
}




// Função para limpar a lista de aviões
void limparListaAvioes(Aviao*& listaAvioes) {
    Aviao* atual = listaAvioes;
    while (atual != nullptr) {
        Aviao* proximo = atual->proximoAviao;
        delete atual;
        atual = proximo;
    }
    listaAvioes = nullptr; // Define a lista como vazia
}

*/