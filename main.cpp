#include <iostream>
#include <aeroporto.h>
#include <utils.h>
using namespace std;

int main(){

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

    return 0;
}