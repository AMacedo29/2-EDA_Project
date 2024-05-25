#include <iostream>
#include "aeroporto.h"
#include "aviao.h"
#include "utils.h"
#include "simulacao.h"
#include "gravar.h"
#include "carregar.h"
#include "passageiros.h"
#include "emergencias.h"


void aeroportoMenu(){
    addListaAprox(ListaAprox);
    imprimirListaAprox(ListaAprox);
    char escolha;
    bool sair = false;

    do{
        std::cout << "Digite a sua escolha (e)mergencias (o)pcoes (g)ravar (s)eguinte (c)arregar" << std::endl;
        std::cin >> escolha;
        //Converte a escolha para minusculas
        escolha = tolower(escolha);

    switch(escolha) {
        case 'e':
            pousoDeEmergencia();
            break;
        case 'o':
            menuOpcoes();
            std::cout << "Escolheu a opcao Opcoes! " << std::endl;
            break;
        case 'g':
            gravarLista(ListaAprox, "listaAprox.txt");
            gravarLista(listaPista, "listaPista.txt");
            gravarLista(listaPartida, "listaPartida.txt");
            break;
        case 's':
            ///////////////////////////////////////////// Estas são do 3.6 /////////////////////////////////////////////

            if (countAvioes(ListaAprox) < 15 && aeroportoFechado == true) {
                ListaAprox = inserirAviaoAprox(&ListaAprox, ListaAprox); // gera avioes msm com o aeroporto fechado até ao max de 15 (pq ele so fica fechado ate 5 dias)
            }

            if (countAvioes(ListaAprox) >= 11 && countAvioes(ListaAprox) <= 15 && aeroportoFechado == false ) {
                ListaAprox = inserirAviaoAprox(&ListaAprox, ListaAprox); // quando o aeroporto volta a abrir a lista tem que receber avioes mesmo tendo passado do seu max
            }

            if (countAvioes(ListaAprox) >= 11 && aeroportoFechado == false) {
                moverUltimoParaListaPista(&ListaAprox, &listaPista); // se a listaAprox tiver + de 10 avioes ela move +1 aviao para a prox lista até ela voltar ao seu max "normal"
            }

            if (countAvioes(listaPista) >= 8 && aeroportoFechado == false) {
                moverUltimoParaListaPartidas(&listaPista, &listaPartida); // vai +1 da listaPista para a listaPartida caso esteja com a capacidade max
            }

            if (countAvioes(listaPartida) >= 6 && aeroportoFechado == false) {
                removeUltimo(&listaPartida); // se a lista estiver mais do que cheia remove o ultimo aviao
            }

            ////////////////////////////////////////////////////////////////////////////////////////////////////////////

            if (countAvioes(ListaAprox) <= 10 && aeroportoFechado == false) {
                ListaAprox = inserirAviaoAprox(&ListaAprox, ListaAprox); // gera avioes com o aeroporto aberto e com menos de 10 avioes na lista
            }

            if (countAvioes(listaPista) <= 7 && ListaAprox != nullptr && aeroportoFechado == false) {
                moverUltimoParaListaPista(&ListaAprox, &listaPista); // se a listaPista tiver 7 ou menos avioes vem 1 aviao da ListaAprox
            }

            if (countAvioes(listaPista) > 7 && aeroportoFechado == false) {
                moverUltimoParaListaPartidas(&listaPista, &listaPartida); // se a listaPista tiver 7 ou mais avioes move 1 aviao para a partida
            }

            if (countAvioes(listaPartida) > 5) {
                removeUltimo(&listaPartida); // se a lista estiver cheia remove o ultimo aviao
            }

            imprimirListaAprox(ListaAprox);
            imprimirListaPista(listaPista);
            imprimirListaPartida(listaPartida);


            if (aeroportoFechado == true) {
                if (diasRestantesAeroportoFechado -1  > 0) { // ele estava a fechar por 1 dia a mais
                    --diasRestantesAeroportoFechado;
                    std::cout << "Aeroporto fechado. Faltam " << diasRestantesAeroportoFechado << " dias para reabrir." << std::endl;
                } else {
                    aeroportoFechado = false;
                    std::cout << "Aeroporto fechado. Faltam 0 dias para reabrir." << std::endl; // como aranjei a outra linha com o -1 rebentei o print da outra linha e este vem para fingir que está tudo bem
                }
            }
            break;
        case 'b':
            std::cout << "Escolheu a opcao Sair. Adeus!" << std::endl;
            sair = true;
            return;
        case 'c':
            carregarListaAprox(ListaAprox);
            std::cout << "Aprox" << std::endl;

            carregarListaPista(listaPista);
            std::cout << "Pista" << std::endl;

            carregarListaPartida(listaPartida);
            std::cout << "Partida" << std::endl;

            imprimirListaAprox(ListaAprox);
            imprimirListaPista(listaPista);
            imprimirListaPartida(listaPartida);

            std::cout << "Dados carregados com sucesso! " << std::endl;
            break;
        default:
            std::cout << "Opcao invalida!" << std::endl;
            break;
        }
    }while (!sair);
}

void menuNacionalidades(){
    char escolha;
    bool sair = false;
    do {
        std::cout << " Digite a sua escolha " << std::endl;
        std::cout << "(a) - Mostrar passageiros" << std::endl;
        std::cout << "(s) - Mostrar passageiros ordenados" << std::endl;
        std::cout << "(d) - Pesquisar passageiros" << std::endl;
        std::cout << "(f) - Editar passageiros" << std::endl;
        std::cout << "(b) - Sair" << std::endl;
        std::cin >> escolha;
        //Converte a escolha para minusculas
        escolha = tolower(escolha);
        switch(escolha){
            case 'a':
                mostrarpassageiros(listaPista);
                break;
            case's':
                mostrarpassageirosordenados(listaPista);
                break;
            case 'd':
                pesquisarpassageiro(listaPista);
                break;
            case 'f':
                std::cout << "(f) - Editar passageiros" << std::endl;
                break;
            case 'b':
                std::cout << "Escolheu a opcao Sair. Adeus!" << std::endl;
                std::cout << " \n";
                sair = true;
                return;
            default:
                break;
        }
    }while (!sair);
}



Aviao* ListaAprox = nullptr;
Aviao* listaPista = nullptr;
Aviao* listaPartida = nullptr;


void addListaAprox(Aviao*& ListaAprox){
    srand(time(nullptr));
    if (ListaAprox == nullptr) {
        for (int i = 0; i < 10; ++i) {
            ListaAprox = inserirAviaoAprox(&ListaAprox, ListaAprox);
            for (int j = 0; j < ListaAprox->capacidade; ++j) {
                adicionarPassageiro(ListaAprox->proximoPassageiro); // Passa o ponteiro para o próximo passageiro
            }
        }
    }
}



void imprimirListaAprox(Aviao* ListaAprox){
    std::cout << "---------------" << std::endl;
    std::cout << "Em aproximacao" << std::endl;
    std::cout << "---------------" << std::endl;

    Aviao* aviaoAtual = ListaAprox;
    while (aviaoAtual != nullptr) {
        std::cout << "Voo: " << aviaoAtual->nomeVoo << std::endl;
        std::cout << "Modelo: " << aviaoAtual->modeloAviao << std::endl;
        std::cout << "Origem: " << aviaoAtual->origem << std::endl;
        std::cout << "Destino: " << aviaoAtual->destino << std::endl;

        // Imprime o nome dos passageiros (apenas o primeiroNome)
        std::cout << "Passageiros: ";
        Passageiro* passageiroAtual = aviaoAtual->proximoPassageiro;
        while (passageiroAtual != nullptr) {
            std::cout << passageiroAtual->primeiroNome;
            if (passageiroAtual->next != nullptr) {
                std::cout << ", ";
            }
            passageiroAtual = passageiroAtual->next;
        }

        std::cout << std::endl;
        aviaoAtual = aviaoAtual->proximoAviao;
        std::cout << " " << std::endl; // É para dar espaço entre os aviões
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

        // Imprime o nome dos passageiros (apenas o primeiroNome)
        std::cout << "Passageiros: ";
        Passageiro* passageiroAtual = listaPista->proximoPassageiro;
        while (passageiroAtual != nullptr) {
            std::cout << passageiroAtual->primeiroNome;
            if (passageiroAtual->next != nullptr) {
                std::cout << ", ";
            }
            passageiroAtual = passageiroAtual->next;
        }

        std::cout << std::endl;
        listaPista = listaPista->proximoAviao;
        std::cout << " " << std::endl; // É para dar espaço entre os aviões
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

        // Imprime o nome dos passageiros (apenas o primeiroNome)
        std::cout << "Passageiros: ";
        Passageiro* passageiroAtual = listaPartida->proximoPassageiro;
        while (passageiroAtual != nullptr) {
            std::cout << passageiroAtual->primeiroNome;
            if (passageiroAtual->next != nullptr) {
                std::cout << ", ";
            }
            passageiroAtual = passageiroAtual->next;
        }

        std::cout << std::endl;
        listaPartida = listaPartida->proximoAviao;
        std::cout << " " << std::endl; // É para dar espaço entre os aviões
    }
}

// Função para mostrar passageiros
// Falta criar uma função para ordenar os passageiros por nacionalidade;

void mostrarpassageirosordenados(Aviao* listaPista) {
    while (listaPista != nullptr) {
        std::cout << "Passageiros: ";
        Passageiro* passageiroAtual = listaPista->proximoPassageiro;
        while (passageiroAtual != nullptr) {
            std::cout << "Numero de Bilhete: " << passageiroAtual->numeroDoBilhete << std::endl;
            std::cout << "Nome: " << passageiroAtual->primeiroNome << " " << passageiroAtual->segundoNome << std::endl;
            std::cout << "Nacionalidade: " << passageiroAtual->nacionalidade << std::endl;
            if (passageiroAtual->next != nullptr) {
                std::cout << ", ";
            }
            passageiroAtual = passageiroAtual->next;
        }

        std::cout << std::endl;
        listaPista = listaPista->proximoAviao;
        std::cout << std::endl; // Linha em branco para separar os aviões
    }
}


// Função para mostrar passageiros
void mostrarpassageiros(Aviao* listaPista) {
    while (listaPista != nullptr) {
        std::cout << "Passageiros do Voo-> " << listaPista->nomeVoo << std::endl;
        Passageiro* passageiroAtual = listaPista->proximoPassageiro;
        while (passageiroAtual != nullptr) {
            std::cout << "Numero de Bilhete: " << passageiroAtual->numeroDoBilhete << std::endl;
            std::cout << "Nome: " << passageiroAtual->primeiroNome << " " << passageiroAtual->segundoNome << std::endl;
            std::cout << "Nacionalidade: " << passageiroAtual->nacionalidade << std::endl;
            if (passageiroAtual->next != nullptr) {
                std::cout << std::endl;
            }
            passageiroAtual = passageiroAtual->next;
        }

        std::cout << std::endl;
        listaPista = listaPista->proximoAviao;
        std::cout << std::endl;
    }
}

void pesquisarpassageiro(Aviao* listaPista){
    std::string primNome;
    std::cout << "Digite o primeiro nome do passageiro" << std::endl;
    std::cin >> primNome;
    while (listaPista != nullptr) {

        Passageiro* passageiroAtual = listaPista->proximoPassageiro;
        while (passageiroAtual != nullptr ) {
            if (primNome == passageiroAtual->primeiroNome){
                std::cout << "Passageiro do Voo-> " << listaPista->nomeVoo << std::endl;
                std::cout << "Numero de Bilhete: " << passageiroAtual->numeroDoBilhete << std::endl;
                std::cout << "Nome: " << passageiroAtual->primeiroNome << " " << passageiroAtual->segundoNome << std::endl;
                std::cout << "Nacionalidade: " << passageiroAtual->nacionalidade << std::endl;
                std::cout << std::endl;
            }
            passageiroAtual = passageiroAtual->next;
        }
        listaPista = listaPista->proximoAviao;
        std::cout << std::endl;
    }
}