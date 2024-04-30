#include "gravar.h"
#include "aviao.h"
#include "passageiros.h"
#include "fstream"

// Função para gravar a lista de aviões em um arquivo
void gravarListaAprox(Aviao* listaAvioes, const std::string& nomeArquivo) {
    std::ofstream arquivo(nomeArquivo);

    // Verifica se o arquivo foi aberto com sucesso
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para escrita." << std::endl;
        return;
    }

    // Percorre a lista de aviões e grava os dados de cada avião no arquivo
    Aviao* aviaoAtual = listaAvioes;
    while (aviaoAtual != nullptr) {
        arquivo << "Nome do voo: " << aviaoAtual->nomeVoo << std::endl;
        arquivo << "Modelo do avião: " << aviaoAtual->modeloAviao << std::endl;
        arquivo << "Origem: " << aviaoAtual->origem << std::endl;
        arquivo << "Destino: " << aviaoAtual->destino << std::endl;
        arquivo << "Capacidade: " << aviaoAtual->capacidade << std::endl;
        arquivo << std::endl;

        // Avança para o próximo avião na lista
        aviaoAtual = aviaoAtual->proximoAviao;
    }

    // Fecha o arquivo após concluir a gravação
    arquivo.close();
}