#include <iostream>
#include <cstdlib> // Para a função rand()
#include <fstream> // Para ler ficheiros
#include <string>

using namespace std;


/**
* calcula um numero inteiro aleatorio dentro do intervalo especificado
*
* @param minVal o valor minimo do intervalo
* @param maxVal o valor maximo do intervalo
* @return um numero inteiro aleatório dentro do intervalo [minVal, maxVal]
*/
int randomNumber(int minVal, int maxVal) {
    return minVal + (rand() % (maxVal + 1 - minVal));
}

/**
 *
 * @return um destino lido aleatoriamente do arquivo "destino.txt".
 */
string getRandomDestino() {
    ifstream myFile("files/destino.txt"); // Abre o arquivo "destino.txt"
    string linha; // Variável temporária para armazenar cada linha do arquivo
    int numeroDeLinhas = 0;

    // Conta o número de linhas
    while (getline(myFile, linha)) {
        ++numeroDeLinhas;
    }

    // Gera um número de linha aleatório
    int linhaAleatoria = randomNumber(0, numeroDeLinhas - 1);

    // Obtém a linha aleatória
    myFile.clear(); // Limpa a flag EOF (fim do ficheiro)
    myFile.seekg(0); // Volta ao início do arquivo
    for (int i = 0; i <= linhaAleatoria; ++i) {
        getline(myFile, linha);
    }

    return linha; // Retorna um destino aleatorio
}


/////////////////////////////////////////////////////////////////////////////////////////


/**
 *
 * @return um modelo lido aleatoriamente do arquivo "modelo.txt".
 */
string getRandomModelo() {
    ifstream myFile("files/modelo.txt"); // Abre o arquivo "modelo.txt"
    string linha; // Variável temporária para armazenar cada linha do arquivo
    int numeroDeLinhas = 0;

    // Conta o número de linhas
    while (getline(myFile, linha)) {
        ++numeroDeLinhas;
    }

    // Gera um número de linha aleatório
    int linhaAleatoria = randomNumber(0, numeroDeLinhas - 1);

    // Obtém a linha aleatória
    myFile.clear(); // Limpa a flag EOF (fim do ficheiro)
    myFile.seekg(0); // Volta ao início do arquivo
    for (int i = 0; i <= linhaAleatoria; ++i) {
        getline(myFile, linha);
    }

    return linha; // Retorna um modelo aleatorio
}


/////////////////////////////////////////////////////////////////////////////////////////


/**
 *
 * @return uma nacionalidade lido aleatoriamente do arquivo "nacionalidade.txt".
 */
string getRandomNacionalidade() {
    ifstream myFile("files/nacionalidade.txt"); // Abre o arquivo "nacionalidade.txt"
    string linha; // Variável temporária para armazenar cada linha do arquivo
    int numeroDeLinhas = 0;

    // Conta o número de linhas
    while (getline(myFile, linha)) {
        ++numeroDeLinhas;
    }

    // Gera um número de linha aleatório
    int linhaAleatoria = randomNumber(0, numeroDeLinhas - 1);

    // Obtém a linha aleatória
    myFile.clear(); // Limpa a flag EOF (fim do ficheiro)
    myFile.seekg(0); // Volta ao início do arquivo
    for (int i = 0; i <= linhaAleatoria; ++i) {
        getline(myFile, linha);
    }

    return linha; // Retorna uma nacionalidade aleatoria
}


/////////////////////////////////////////////////////////////////////////////////////////


/**
 *
 * @return uma origem lido aleatoriamente do arquivo "origem.txt".
 */
string getRandomOrigem() {
    ifstream myFile("files/origem.txt"); // Abre o arquivo "origem.txt"
    string linha; // Variável temporária para armazenar cada linha do arquivo
    int numeroDeLinhas = 0;

    // Conta o número de linhas
    while (getline(myFile, linha)) {
        ++numeroDeLinhas;
    }

    // Gera um número de linha aleatório
    int linhaAleatoria = randomNumber(0, numeroDeLinhas - 1);

    // Obtém a linha aleatória
    myFile.clear(); // Limpa a flag EOF (fim do ficheiro)
    myFile.seekg(0); // Volta ao início do arquivo
    for (int i = 0; i <= linhaAleatoria; ++i) {
        getline(myFile, linha);
    }

    return linha; // Retorna uma origem aleatoria
}


/////////////////////////////////////////////////////////////////////////////////////////


/**
 *
 * @return um primeiro nome lido aleatoriamente do arquivo "primeiro_nome.txt".
 */
string getRandomPrimeiroNome() {
    ifstream myFile("files/primeiro_nome.txt"); // Abre o arquivo "primeiro_nome.txt"
    string linha; // Variável temporária para armazenar cada linha do arquivo
    int numeroDeLinhas = 0;

    // Conta o número de linhas
    while (getline(myFile, linha)) {
        ++numeroDeLinhas;
    }

    // Gera um número de linha aleatório
    int linhaAleatoria = randomNumber(0, numeroDeLinhas - 1);

    // Obtém a linha aleatória
    myFile.clear(); // Limpa a flag EOF (fim do ficheiro)
    myFile.seekg(0); // Volta ao início do arquivo
    for (int i = 0; i <= linhaAleatoria; ++i) {
        getline(myFile, linha);
    }

    return linha; // Retorna um primeiro nome aleatorio
}


/////////////////////////////////////////////////////////////////////////////////////////


/**
 *
 * @return um segundo nome lido aleatoriamente do arquivo "segundo_nome.txt".
 */
string getRandomSegundoNome() {
    ifstream myFile("files/segundo_nome.txt"); // Abre o arquivo "segundo_nome.txt"
    string linha; // Variável temporária para armazenar cada linha do arquivo
    int numeroDeLinhas = 0;

    // Conta o número de linhas
    while (getline(myFile, linha)) {
        ++numeroDeLinhas;
    }

    // Gera um número de linha aleatório
    int linhaAleatoria = randomNumber(0, numeroDeLinhas - 1);

    // Obtém a linha aleatória
    myFile.clear(); // Limpa a flag EOF (fim do ficheiro)
    myFile.seekg(0); // Volta ao início do arquivo
    for (int i = 0; i <= linhaAleatoria; ++i) {
        getline(myFile, linha);
    }

    return linha; // Retorna um segundo nome aleatorio
}

/////////////////////////////////////////////////////////////////////////////////////////


/**
 *
 * @return um voo  lido aleatoriamente do arquivo "voo.txt".
 */
string getRandomVoo() {
    ifstream myFile("files/voo.txt"); // Abre o arquivo "voo.txt"
    string linha; // Variável temporária para armazenar cada linha do arquivo
    int numeroDeLinhas = 0;

    // Conta o número de linhas
    while (getline(myFile, linha)) {
        ++numeroDeLinhas;
    }

    // Gera um número de linha aleatório
    int linhaAleatoria = randomNumber(0, numeroDeLinhas - 1);

    // Obtém a linha aleatória
    myFile.clear(); // Limpa a flag EOF (fim do ficheiro)
    myFile.seekg(0); // Volta ao início do arquivo
    for (int i = 0; i <= linhaAleatoria; ++i) {
        getline(myFile, linha);
    }

    return linha; // Retorna um voo aleatorio
}