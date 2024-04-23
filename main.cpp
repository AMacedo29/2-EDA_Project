#include <iostream>
#include "aeroporto.h"
#include "utils.h"
#include "aviao.h"

using namespace std;

/*
Grupo 24: Tiago-2127121, João Silva-2187423, André-Macedo 2076023 ;
*/


int main(){
    srand(time(nullptr)); // Deve ser chamada apenas uma vez no início do programa por isso fica aqui

    Aviao* listaAvioes = nullptr; // A lista começa vazia

    for (int i = 0; i < 5; ++i) {
        Aviao* aviaoAleatorio = gerarAviaoAleatorio();
        adicionarAviao(listaAvioes, aviaoAleatorio);
    }

    imprimirAvioes(listaAvioes); // Imprime os aviões da lista ligada

/*
    for (int i = 0; i < 5; ++i) {
        std::string bilhete = gerarBilheteAleatorio();
        std::cout << "Numero de Bilhete: " << bilhete << std::endl;
    }

    aeroportoMenu();

    cout << " ----------------------- "<< endl; // Vamos apagar isto so está aqui para distinguir o menu do randoms
    cout << " ----------------------- "<< endl; // Vamos apagar isto so está aqui para distinguir o menu do randoms
    cout << " ----------------------- "<< endl; // Vamos apagar isto so está aqui para distinguir o menu do randoms

    string destino = getRandomDestino();
    cout << "Destino aleatorio: " << destino << endl;

    string modelo = getRandomModelo();
    cout << "Modelo aleatorio: " << modelo << endl;

    string nacionalidade = getRandomNacionalidade();
    cout << "Nacionalidade aleatoria: " << nacionalidade << endl;

    string origem = getRandomOrigem();
    cout << "Origem aleatoria: " << origem << endl;

    string primeiroNome = getRandomPrimeiroNome();
    cout << "Primeiro Nome aleatorio: " << primeiroNome << endl;

    string segundoNome = getRandomSegundoNome();
    cout << "Segundo nome aleatorio: " << segundoNome << endl;

    string voo = getRandomVoo();
    cout << "Voo aleatorio: " << voo << endl;

     */

    return 0;
}