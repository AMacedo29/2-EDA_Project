#include "gravar.h"
#include "aviao.h"
#include "passageiros.h"
#include "fstream"


/**
 * Grava os dados de uma lista de aviões em um arquivo
 *
 * @param listaAvioes Um ponteiro para o início da lista de aviões
 * @param nomeArquivo O nome do arquivo onde os dados serão gravados
 */
void gravarLista(Aviao* listaAvioes, const std::string& nomeArquivo) {
    std::ofstream arquivo(nomeArquivo);

    // Verifica se o arquivo foi aberto com sucesso
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para escrita." << std::endl;
        return;
    }

    // Percorre a lista e grava os dados de cada avião no arquivo
    Aviao* aviaoAtual = listaAvioes;
    while (aviaoAtual != nullptr) {
        arquivo <<  aviaoAtual->nomeVoo << std::endl;
        arquivo <<  aviaoAtual->modeloAviao << std::endl;
        arquivo <<  aviaoAtual->origem << std::endl;
        arquivo <<  aviaoAtual->destino << std::endl;
        arquivo <<  aviaoAtual->capacidade << std::endl;
        arquivo << std::endl;
/* //dar fix dps
        // Percorre a lista de passageiros do avião e grava os dados de cada passageiro
        Passageiro* passageiroAtual = aviaoAtual->proximoPassageiro;
        while (passageiroAtual != nullptr) {
            arquivo << passageiroAtual->numeroDoBilhete << std::endl;
            arquivo << passageiroAtual->primeiroNome << std::endl;
            arquivo << passageiroAtual->segundoNome << std::endl;
            arquivo << passageiroAtual->nacionalidade << std::endl;
            arquivo << std::endl;
            passageiroAtual = passageiroAtual->next;
        }

        arquivo << std::endl;
*/
        // Avança para o próximo avião na lista
        aviaoAtual = aviaoAtual->proximoAviao;
    }

    // Fecha o arquivo após concluir a gravação
    arquivo.close();
}
