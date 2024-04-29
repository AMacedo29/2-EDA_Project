#include <iostream>
#include "aeroporto.h"
#include "aviao.h"
#include "utils.h"
#include "simulacao.h"


void aeroportoMenu(){
    imprimirListaAprox();
    Aviao* ListaAprox = nullptr;
    Aviao* listaPista = nullptr;

    char escolha;
    bool sair = false;

    do{
        std::cout << "Digite a sua escolha (e)mergencias (o)pcoes (g)ravar (s)eguinte" << std::endl;
        std::cin >> escolha;

        //Convertendo a escolha para minusculas
        escolha = tolower(escolha);

    switch(escolha) {
        case 'e':
            std::cout <<" ainda n tem nada " << std::endl;
            break;
        case 'o':
            std::cout << "ainda n tem nada " << std::endl;
            break;
        case 'g':
            std::cout << "ainda n tem nada " << std::endl;
            break;
        case 's':
            imprimirListaAprox();
            moverUltimoParaListaPista(&ListaAprox, &listaPista);
            imprimirListaPista(listaPista);
            break;
        case 'b':
            std::cout << "Escolheu a opcao Sair. Adeus!" << std::endl;
            sair = true;
            return;
        default:
            std::cout << "Opção inválida!" << std::endl;
            break;
        }
    }while (!sair);
}

void imprimirListaAprox(){
    std::cout << "(e)mergencias (o)pcoes (g)ravar" << std::endl;
    std::cout << "---------------" << std::endl;
    std::cout << "Em aproximacao" << std::endl;
    std::cout << "---------------" << std::endl;

    srand(time(nullptr)); // Deve ser chamada apenas uma vez no início do programa por isso fica aqui

    Aviao* ListaAprox = nullptr;

    // Inserir 10 aviões na lista de aproximação
    for (int i = 0; i < 10; ++i) {
        ListaAprox = inserirAviaoAprox(&ListaAprox, ListaAprox);
    }

    // Imprimir os detalhes dos aviões na lista de aproximação
    Aviao* aviaoAtual = ListaAprox;
    while (aviaoAtual != nullptr) {
        std::cout << "Voo: " << aviaoAtual->nomeVoo << std::endl;
        std::cout << "Modelo: " << aviaoAtual->modeloAviao << std::endl;
        std::cout << "Origem: " << aviaoAtual->origem << std::endl;
        std::cout << "Destino: " << aviaoAtual->destino << std::endl;
        std::cout << endl;
        aviaoAtual = aviaoAtual->proximoAviao;
    }

}

void imprimirListaPista(Aviao* listaPista){
    std::cout << "---------------" << std::endl;
    std::cout << "Na pista" << std::endl;
    std::cout << "---------------" << std::endl;
    while (listaPista != nullptr) {
        std::cout << "Voo: " << listaPista->nomeVoo << std::endl;
        std::cout << "Modelo: " << listaPista->modeloAviao << std::endl;
        std::cout << "Origem: " << listaPista->origem << std::endl;
        std::cout << "Destino: " << listaPista->destino << std::endl;
        listaPista = listaPista->proximoAviao;
    }

}

void imprimirListaPartida(){
    std::cout << "---------------" << std::endl;
    std::cout << "A descolar" << std::endl;
    std::cout << "---------------" << std::endl;

}