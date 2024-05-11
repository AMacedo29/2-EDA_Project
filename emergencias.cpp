#include "emergencias.h"
#include <iostream>


bool aeroportoFechado = false;

int diasRestantesAeroportoFechado = 0;

void fecharAeroportoPorXDias(int numeroDeDias) {
    if (numeroDeDias > 5) {
        std::cout << "Aeroporto pode ser fechado por no máximo 5 dias. Limitando para 5 dias." << std::endl;
        numeroDeDias = 5;
    }
    aeroportoFechado = true;
    diasRestantesAeroportoFechado = numeroDeDias;
}

void escolherDiasParaFecharAeroporto() {
    int numeroDeDias;
    std::cout << "Digite o número de dias que o aeroporto ficará fechado: ";
    std::cin >> numeroDeDias;
    fecharAeroportoPorXDias(numeroDeDias);
}

