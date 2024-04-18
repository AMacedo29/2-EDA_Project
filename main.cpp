#include <iostream>
#include "aeroporto.h"
#include "utils.h"
using namespace std;

int main(){
    srand(time(nullptr)); // Deve ser chamada apenas uma vez no início do programa por isso fica aqui


    for (int i = 0; i < 5; ++i) {
        std::string bilhete = gerarBilheteAleatorio();
        std::cout << "Numero de Bilhete: " << bilhete << std::endl;
    }


    /*

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