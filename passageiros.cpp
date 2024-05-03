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
void adicionarPassageiro(Aviao* aviao) {
    // Verifica se o número de passageiros já atingiu a capacidade máxima do avião
    if (contarPassageiros(aviao) >= aviao->capacidade) {
        std::cout << "O avião já atingiu a capacidade máxima de passageiros." << std::endl;
        return;
    }

    // Cria um novo passageiro
    Passageiro* novoPassageiro = new Passageiro;
    novoPassageiro->numeroDoBilhete = gerarBilheteAleatorio();
    novoPassageiro->primeiroNome = getRandomPrimeiroNome();
    novoPassageiro->segundoNome = getRandomSegundoNome();
    novoPassageiro->nacionalidade = getRandomNacionalidade();
    novoPassageiro->next = nullptr;

    // Se não houver passageiros na lista, o novo passageiro será o primeiro
    if (aviao->proximoPassageiro == nullptr) {
        aviao->proximoPassageiro = novoPassageiro;
    } else {
        // Caso contrário, percorra a lista até o último passageiro e adicione o novo passageiro lá
        Passageiro* ultimoPassageiro = aviao->proximoPassageiro;
        while (ultimoPassageiro->next != nullptr) {
            ultimoPassageiro = ultimoPassageiro->next;
        }
        ultimoPassageiro->next = novoPassageiro;
    }

    // Exibe informações sobre o novo passageiro
    std::cout << "Novo passageiro adicionado ao avião:" << std::endl;
    std::cout << "Bilhete: " << novoPassageiro->numeroDoBilhete << std::endl;
    std::cout << "Nome: " << novoPassageiro->primeiroNome << " " << novoPassageiro->segundoNome << std::endl;
    std::cout << "Nacionalidade: " << novoPassageiro->nacionalidade << std::endl;
    std::cout << std::endl;
}


