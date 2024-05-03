#include "fstream"
#include "carregar.h"
#include "aviao.h"


/**
 * Limpa a lista
 *
 * @param lista Um ponteiro para o primeiro nó da lista
 */
void limparLista(Aviao*& lista) {
    while (lista != nullptr) {
        Aviao* proximo = lista->proximoAviao;
        delete lista;
        lista = proximo;
    }
}


/**
 * Serve para carregar os dados guardados na lista
 *
 * @param lista Um ponteiro para o início da lista
 * @param nomeArquivo O nome do arquivo de texto com os dados dos aviões
 */
void carregarLista(Aviao*& lista, const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para leitura." << std::endl;
        return;
    }

    Aviao* listaTemp = nullptr;

    std::string nomeVoo, modeloAviao, origem, destino;
    int capacidade;
    std::string dummy; // Variável dummy para descartar linhas desnecessárias

    while (std::getline(arquivo, nomeVoo) &&
           std::getline(arquivo, modeloAviao) &&
           std::getline(arquivo, origem) &&
           std::getline(arquivo, destino) &&
           arquivo >> capacidade) {
        // Descartar a linha em branco após cada conjunto de dados
        std::getline(arquivo, dummy);

        Aviao* novoAviaoPonteiro = novoAviao();
        novoAviaoPonteiro->nomeVoo = nomeVoo;
        novoAviaoPonteiro->modeloAviao = modeloAviao;
        novoAviaoPonteiro->origem = origem;
        novoAviaoPonteiro->destino = destino;
        novoAviaoPonteiro->capacidade = capacidade;

        novoAviaoPonteiro->proximoAviao = listaTemp;
        listaTemp = novoAviaoPonteiro;
    }

    if (arquivo.fail() && !arquivo.eof()) {
        std::cerr << "Erro durante a leitura do arquivo." << std::endl;
        arquivo.close();
        return;
    }

    limparLista(lista); // Limpa a lista original

    Aviao* temp = listaTemp;
    while (temp != nullptr) {
        Aviao* proximo = temp->proximoAviao;
        temp->proximoAviao = lista;
        lista = temp;
        temp = proximo;
    }

    arquivo.close();
}




void carregarListaAprox(Aviao*& ListaAprox) {
    carregarLista(ListaAprox, "C://Users//andre//CLionProjects//2-EDA_Project//cmake-build-debug//listaAprox.txt");
}

void carregarListaPista(Aviao*& listaPista) {
    carregarLista(listaPista, "C://Users//andre//CLionProjects//2-EDA_Project//cmake-build-debug//listaPista.txt");
}

void carregarListaPartida(Aviao*& listaPartida) {
    carregarLista(listaPartida, "C://Users//andre//CLionProjects//2-EDA_Project//cmake-build-debug//listaPartida.txt");
}