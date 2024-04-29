#include <iostream>
#include "aeroporto.h"

using namespace std;

void aeroportoMenu(){
    cout << "(e)mergencias (o)pcoes (g)ravar" << endl;
    cout << "---------------" << endl;
    cout << "Em aproximacao" << endl;
    cout << "---------------" << endl;

    cout << "Voo: " << endl;
    cout << "Modelo: " << endl;
    cout << "Origem: " << endl;
    cout << "Destino: " <<endl;
    cout << "Passageiros: " <<endl;

    ///////////////////////////////////////////////////////////

    cout << "---------------" << endl;
    cout << "Na pista" << endl;
    cout << "---------------" << endl;

    cout << "Voo: " << endl;
    cout << "Modelo: " << endl;
    cout << "Origem: " << endl;
    cout << "Destino: " <<endl;
    cout << "Passageiros: " <<endl;

    ///////////////////////////////////////////////////////////

    cout << "---------------" << endl;
    cout << "A descolar" <<endl;
    cout << "---------------" << endl;

    cout << "Voo: " << endl;
    cout << "Modelo: " << endl;
    cout << "Origem: " << endl;
    cout << "Destino: " <<endl;
    cout << "Passageiros: " <<endl;

    ///////////////////////////////////////////////////////////

    char escolha;
    bool sair = false;

    do{
        cout << "Digite a sua escolha (e)mergencias (o)pcoes (g)ravar (s)air" << endl;
        cin >> escolha;

        //Convertendo a escolha para minusculas
        escolha = tolower(escolha);

    switch(escolha) {
        case 'e':
            cout <<" ainda n tem nada " << endl;
            break;
        case 'o':
            cout << "ainda n tem nada " << endl;
            break;
        case 'g':
            cout << "ainda n tem nada " << endl;
            break;
        case 's':
            cout << "Escolheu a opcao Sair. Adeus!" << endl;
            sair = true;
            return;
        default:
            cout << "Opção inválida!" << endl;
            break;
        }
    }while (!sair);
};