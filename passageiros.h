#ifndef INC_2_EDA_PROJECT_PASSAGEIROS_H
#define INC_2_EDA_PROJECT_PASSAGEIROS_H
#include <iostream>
#include <string>




struct Passageiro{
    std::string numeroDoBilhete; //TK1000000
    std::string primeiroNome;
    std::string segundoNome;
    std::string nacionalidade;
    Passageiro* next; // Ponteiro para o próximo passageiro da lista
    Passageiro* esq;  // Ponteiro para o filho da esquerdo na árvore
    Passageiro* dir;  // Ponteiro para o filho da direito na árvore
};

//void novoPassageiro();

int contarPassageiros();

void adicionarPassageiro(Passageiro*& proximoPassageiro);

Passageiro* listaNacionalidades(Passageiro*& passageiro);

void inserirPassageiroNaArvore(Passageiro*& no, Passageiro* passageiro);

void inserirPassageiroNaListaNacionalidades(Passageiro*& listaNacionalidades, Passageiro* passageiro);

void imprimeArvore(Passageiro* no, int nivel);

Passageiro* removerCopia(Passageiro* raiz, Passageiro* no, Passageiro* ant);

Passageiro* removerCopia(Passageiro* raiz, int num);



#endif //INC_2_EDA_PROJECT_PASSAGEIROS_H
