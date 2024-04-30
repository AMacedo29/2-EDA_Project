#include <iostream>
#include "aeroporto.h"
#include "aviao.h"
#include "utils.h"
#include "simulacao.h"
#include "gravar.h"

void aeroportoMenu(){
    Aviao* ListaAprox = nullptr;
    Aviao* listaPista = nullptr;
    Aviao* listaPartida = nullptr;
    addListaAprox(ListaAprox);
    imprimirListaAprox(ListaAprox);
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
            gravarListaAprox(ListaAprox, "listaAprox.txt");
            gravarListaPista(listaPista, "listaPista.txt");
            gravarListaPartida(listaPartida, "listaPartida.txt");
            std::cout << "Listas gravadas com sucesso!" << std::endl;
            break;
        case 's':
            if (countAvioes(ListaAprox) < 10){
                ListaAprox = inserirAviaoAprox(&ListaAprox, ListaAprox);
            }
            imprimirListaAprox(ListaAprox);
            if (countAvioes(listaPista) < 7 && ListaAprox != nullptr) {
                moverUltimoParaListaPista(&ListaAprox, &listaPista);;
            }
            imprimirListaPista(listaPista);
            if (countAvioes(listaPartida) < 5 && countAvioes(listaPista) >= 7 && ListaAprox != nullptr ) {
                moverUltimoParaListaPartidas(&listaPista, &listaPartida);
            }
            imprimirListaPartida(listaPartida);
            if (countAvioes(listaPista) > 5){
                removeUltimo(&listaPartida);
            }
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



void addListaAprox(Aviao*& ListaAprox){
    srand(time(nullptr));
    if (ListaAprox == nullptr) {
        for (int i = 0; i < 10; ++i) {
            ListaAprox = inserirAviaoAprox(&ListaAprox, ListaAprox);
        }
    }
}

void imprimirListaAprox(Aviao* ListaAprox){
    std::cout << "(e)mergencias (o)pcoes (g)ravar" << std::endl;
    std::cout << "---------------" << std::endl;
    std::cout << "Em aproximacao" << std::endl;
    std::cout << "---------------" << std::endl;

    Aviao* aviaoAtual = ListaAprox;
    while (aviaoAtual != nullptr) {
        std::cout << "Voo: " << aviaoAtual->nomeVoo << std::endl;
        std::cout << "Modelo: " << aviaoAtual->modeloAviao << std::endl;
        std::cout << "Origem: " << aviaoAtual->origem << std::endl;
        std::cout << "Destino: " << aviaoAtual->destino << std::endl;
        std::cout << std::endl;
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
        std::cout << std::endl;
        listaPista = listaPista->proximoAviao;
    }
}

void imprimirListaPartida(Aviao* listaPartida){
    std::cout << "---------------" << std::endl;
    std::cout << "A descolar" << std::endl;
    std::cout << "---------------" << std::endl;
    while (listaPartida != nullptr) {
        std::cout << "Voo: " << listaPartida->nomeVoo << std::endl;
        std::cout << "Modelo: " << listaPartida->modeloAviao << std::endl;
        std::cout << "Origem: " << listaPartida->origem << std::endl;
        std::cout << "Destino: " << listaPartida->destino << std::endl;
        std::cout << std::endl;
        listaPartida = listaPartida->proximoAviao;
    }

}