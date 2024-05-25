#include "emergencias.h"
#include <iostream>
#include "aviao.h"
#include "aeroporto.h"
#include "simulacao.h"
#include "utils.h"


void menuOpcoes(){
    char escolha;
    bool sair = false;
    do {
        std::cout << "Digite a sua escolha (f)echar_aeroporto (p)ouso_de_mergencia (i)nverter_prioridade (n)Passageiros (b)sair" << std::endl;
        std::cin >> escolha;
        //Converte a escolha para minusculas
        escolha = tolower(escolha);
        switch(escolha){
            case 'f':
                fecharAeroporto();
                break;
            case'p':
                std::cout <<" Escolheu Pouso de emergencia" << std::endl;
                break;
            case 'i':
                inverterPrioridade(ListaAprox);
                inverterPrioridade(listaPista);
                inverterPrioridade(listaPartida);
                imprimirListaAprox(ListaAprox);
                imprimirListaPista(listaPista);
                imprimirListaPartida(listaPartida);
                break;
            case 'n':
                menuNacionalidades();
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


bool aeroportoFechado = false;

int diasRestantesAeroportoFechado;


/**
 * Isto é para não entrar letras no numeroDeDias senão fica num loop infinito
 *
 * @param str É a string que vai ser verificada
 * @return false / true dependendo da verificação (se contem apenas digitos)
 */
bool digito(const std::string& str){
    for (char digito : str) {
        if (!isdigit(digito)){
            return false;
        }
    }
    return true;
}

/**
 * Serve para fechar o aeroporto por X dias
 */
void fecharAeroporto(){
    std::string input;
    int numeroDeDias;
    std::cout << "Digite o numero de dias que o aeroporto ficara fechado: ";
    std::cin >> input;
    if (digito(input)) {
        int numeroDeDias = std::stoi(input); // Isto é para transformar de str para itn
        if (numeroDeDias >= 1 && numeroDeDias <= 5) {
            std::cout << "O aeroporto ficara fechado por " << numeroDeDias << " dias." << std::endl;
            diasRestantesAeroportoFechado = numeroDeDias;
            aeroportoFechado = true;
            return;
        }
    }
    // Se o input não for entre 1 e 5 vem para aqui e fica defenico com 5
    std::cout << "Entrada invalida ou fora do intervalo. O aeroporto sera fechado por 5 dias." << std::endl;
    numeroDeDias = 5;
    diasRestantesAeroportoFechado = numeroDeDias;
    aeroportoFechado = true;
}


/**
 * Inverte a ordem das listas ligadas
 *
 * @param head Referência para o ponteiro que aponta para o primeiro nó (cabeça) da lista ligada.
 */
void inverterLista(Aviao*& head){
    Aviao* anterior = nullptr;
    Aviao* atual = head;
    Aviao* proximo = nullptr;
    while (atual != nullptr) {
        proximo = atual->proximoAviao;
        atual->proximoAviao = anterior;
        anterior = atual;
        atual = proximo;
    }
    head = anterior;
}

/**
 * Inverte a ordem das listas ligadas
 *
 * @param listaPista Referência para o ponteiro que aponta para o primeiro nó (cabeça) da lista ligada.
 */
void inverterPrioridade(Aviao*& listaPista){
    inverterLista(listaPista);
}
//moverAviaoEmergencia(&ListaAprox,&listaPista,"Aeroporto EDA Emergencia");

void pousoDeEmergencia(){
    std::cout << "Emergencia! " << std::endl;
    ListaAprox = inserirAviaoAproxEmergencia(&ListaAprox, ListaAprox);
    imprimirListaAprox(ListaAprox);
    imprimirListaPista(listaPista);
    imprimirListaPartida(listaPartida);

    if (countAvioes(listaPista) < 7){
        // Move o avião de emergencia para a pista se tiver espaço
        moverAviaoEmergencia(&ListaAprox, &listaPista, "Aeroporto EDA Emergencia");
    } else { // se não tiver espaço suficiente na listaPista
        std::string VooPista;
        std::string ModeloPista;
        std::cout << "Digite o Voo a ser movido da Pista para Partida: " << std::endl;
        std::cin >> VooPista;
        std::cout << "Digite o Modelo a ser movido da Pista para Partida: " << std::endl;
        std::cin >> ModeloPista;
        moverAviao(&listaPista, &listaPartida, VooPista, ModeloPista);
        moverAviaoEmergencia(&ListaAprox, &listaPista, "Aeroporto EDA Emergencia");
    }
    if (countAvioes(listaPartida) >=5){
        std::string nomeVoo;
        std::string modeloAviao;
        std::cout << "Digite o Voo a ser movido da Partida: " << std::endl;
        std::cin >> nomeVoo;
        std::cout << "Digite o Modelo a ser movido da Partida" << std::endl;
        std::cin >> modeloAviao;
        removerAviao(&listaPartida,nomeVoo,modeloAviao);
    }
    // Atualizar origem e destino do avião de emergência na listaPista
    Aviao* atual = listaPista;
    while(atual){
        if (atual -> destino == "Aeroporto EDA Emergencia") {
            atual -> destino = getRandomDestino();
            atual -> origem = "Aeroporto EDA";
            break;
        }
        atual = atual->proximoAviao;
    }
    imprimirListaAprox(ListaAprox);
    imprimirListaPista(listaPista);
    imprimirListaPartida(listaPartida);
}