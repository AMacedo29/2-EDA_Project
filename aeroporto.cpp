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
        std::cout << "Digite a sua escolha (e)mergencias (o)pcoes (g)ravar (s)eguinte (c)arregar (l)arvore" << std::endl;
        std::cin >> escolha;
        //Converte a escolha para minusculas
        escolha = tolower(escolha);

    switch(escolha) {
        case 'l':{
            Aviao* aviao = new Aviao();
            std::cout << "Arvore com chegada de estrangeiros" << std::endl;
            Passageiro* raiz = nullptr;
            Passageiro* listaNacionalidades = nullptr;
            inserirPassageirosNaArvoreDeNacionalidades(aviao);
            imprimeArvore(raiz, 0);
            break;
            }
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
        //Passageiro* node = construirArvoreBinariaDosPassageiros(listaPista);
        //Converte a escolha para minusculas
        escolha = tolower(escolha);
        switch(escolha){
            case 'a':
                mostrarpassageiros(listaPista);
                break;
            case's':
                //imprimirArvoreInOrder(node);
                mostrarpassageirosordenados(listaPista);
                break;
            case 'd':
                pesquisarpassageiro(listaPista,ListaAprox);
                break;
            case 'f':
                editarnacionalidade(ListaAprox);
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


/**
 * Adiciona 10 avioes à lista de chegada(ListaAprox).
 *
 * @param ListaAprox Referencia para a ListaAprox.
 */
void addListaAprox(Aviao*& ListaAprox){
    srand(time(nullptr));
    if (ListaAprox == nullptr) {
        for (int i = 0; i < 10; ++i) {
            ListaAprox = inserirAviaoAprox(&ListaAprox, ListaAprox);
        }
    }
}


/**
 * Imprime os aviões em aproximação.
 *
 * @param ListaAprox Ponteiro para o início da lista de aviões em aproximação.
 * Se a lista estiver vazia, nenhum avião será impresso.
 * Cada avião é impresso com seu nome de voo, modelo, origem, destino e os nomes dos seus passageiros.
 */
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

/**
 * Imprime os aviões em pista.
 *
 * @param listaPista Ponteiro para o início da lista de aviões na pista.
 * Se a lista estiver vazia, nenhum avião será impresso.
 * Cada avião é impresso com seu nome de voo, modelo, origem, destino e os nomes dos seus passageiros.
 */
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

/**
 * Imprime os aviões na lista de partida.
 *
 * @param listaPartida Ponteiro para o início da lista de aviões de partida.
 * Se a lista estiver vazia, nenhum avião será impresso.
 * Cada avião é impresso com seu nome de voo, modelo, origem, destino e os nomes dos seus passageiros.
 */
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

/**
 *
 * @param listaPista - Ponteiro para lista de Pista
 * Explicação: Nesta função ele recebe a lista e mostra todas as nacionalidades que estam nos aviões de partida
 * É uma função de auxilio para inserir a nacionalidade na função editarnacionalidade();
 * Nota: Ela duplica nacionalidade se houver a mesma nacionalidade em outro aviões!
 * Quando é apenas um funciona bem
 */
void mostrarlistadenacionalidades(Aviao* listaPista){
    std::string primnacionalidade;
    bool primeiraNacionalidade = true;
    std::cout << "Nacionalidades:" << std::endl;
    while (listaPista != nullptr){
        Passageiro* passageiroAtual = listaPista->proximoPassageiro;
        while (passageiroAtual != nullptr){
            if (primeiraNacionalidade) {
                primnacionalidade = passageiroAtual->nacionalidade;
                std::cout << primnacionalidade << std::endl;
                primeiraNacionalidade = false;
            } else {
                if (passageiroAtual->nacionalidade != primnacionalidade) {
                    Passageiro* passageiroAnterior = listaPista->proximoPassageiro;
                    bool encontrou = false;
                    while (passageiroAnterior != passageiroAtual) {
                        if (passageiroAnterior->nacionalidade == passageiroAtual->nacionalidade) {
                            encontrou = true;
                            break;
                        }
                        passageiroAnterior = passageiroAnterior->next;
                    }
                    if (!encontrou) {
                        std::cout << passageiroAtual->nacionalidade << std::endl;
                    }
                }
            }
            passageiroAtual = passageiroAtual->next;
        }
        listaPista = listaPista->proximoAviao;
    }
}
/**
 *
 * @param listaPista - Ponteiro para lista de Pista
 * Explicação: Nesta função é pedida para inserir a nacionalidade e depois mostra todos os passageiros com essa nacionalidade
 * Nota: Não mostra por ordem alfabética
 */
void mostrarpassageirosordenados(Aviao* listaPista) {
    std::string nacionalidade;
    mostrarlistadenacionalidades(listaPista);
    std::cout << "Insira uma nacionalidade" << std::endl;
    std::cin >> nacionalidade;

    while (listaPista != nullptr) {
        std::cout << "Passageiros: ";
        Passageiro* passageiroAtual = listaPista->proximoPassageiro;
        while (passageiroAtual != nullptr) {
            if(passageiroAtual->nacionalidade == nacionalidade){
                std::cout << "Numero de Bilhete: " << passageiroAtual->numeroDoBilhete << std::endl;
                std::cout << "Nome: " << passageiroAtual->primeiroNome << " " << passageiroAtual->segundoNome << std::endl;
                std::cout << "Nacionalidade: " << passageiroAtual->nacionalidade << std::endl;
                std::cout << std::endl;
            }

            passageiroAtual = passageiroAtual->next;
        }
        listaPista = listaPista->proximoAviao;
    }
}


/**
 *
 * @param listaPista - Ponteiro para lista de Pista
 * Explicação: Mostra todos os passageiros dos aviões que se encontram na pista
 */
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
/**
 *
 * @param listaPista - Ponteiro para lista de Pista
 * @param listaAprox - Ponteiro para lista de Aproximação(chegada)
 * Explicação: É pedido ao utilizador para inserir apenas o primeiro nome do passageeiros
 * e mostra todos os passageiros com esse nome, quer nos aviões que estam na zona de chegada ou na zona
 * de partida. Se não encontrar é enviado uma mensagem Passageiro nao encontrado
 */
void pesquisarpassageiro(Aviao* listaPista, Aviao* listaAprox) {
    std::string primNome;
    std::cout << "Digite o primeiro nome do passageiro: ";
    std::cin >> primNome;
    bool encontradopartida = false;

    while (listaPista != nullptr) {
        Passageiro* passageiroAtual = listaPista->proximoPassageiro;
        while (passageiroAtual != nullptr) {
            if (passageiroAtual->primeiroNome == primNome) {
                std::cout << "___Passageiro da zona de partida___" << std::endl;
                std::cout << "Voo: " << listaPista->nomeVoo << std::endl;
                std::cout << "Numero de Bilhete: " << passageiroAtual->numeroDoBilhete << std::endl;
                std::cout << "Nome: " << passageiroAtual->primeiroNome << " " << passageiroAtual->segundoNome << std::endl;
                std::cout << "Nacionalidade: " << passageiroAtual->nacionalidade << std::endl;
                std::cout << std::endl;
                encontradopartida = true;
            }
            passageiroAtual = passageiroAtual->next;
        }
        listaPista = listaPista->proximoAviao;
    }
    if (!encontradopartida) {
        std::cout << "O passageiro da zona de partida, nao foi encontrado." << std::endl;
    }
    bool encontradochegada = false;
    while (listaAprox != nullptr){
        Passageiro* passageirochegadas = listaAprox->proximoPassageiro;
        while (passageirochegadas != nullptr){
            if(passageirochegadas->primeiroNome == primNome){
                std::cout << "___Passageiro da zona de chegada___" << std::endl;
                std::cout << "Voo: " << listaAprox->nomeVoo << std::endl;
                std::cout << "Numero de Bilhete: " << passageirochegadas->numeroDoBilhete << std::endl;
                std::cout << "Nome: " << passageirochegadas->primeiroNome << " " << passageirochegadas->segundoNome << std::endl;
                std::cout << "Nacionalidade: " << passageirochegadas->nacionalidade << std::endl;
                std::cout << std::endl;
                encontradochegada = true;
            }
            passageirochegadas = passageirochegadas->next;
        }
        listaAprox = listaAprox -> proximoAviao;
    }
    if (!encontradochegada) {
        std::cout << "O passageiro da zona de chegada, nao foi encontrado." << std::endl;
    }

}
/**
 *
 * @param listaAprox - Ponteiro para lista de Aproximação(chegada)
 * @param numVoo - Recebe o nome do voo
 * Explicação: Nesta função ele mostra todos os passageiros de um expecífico voo
 * inserido pelo utilizador
 */
void mostrarPassageiroVoo(Aviao* listaAprox, std::string numVoo) {
    // Itera sobre a lista de aviões
    while (listaAprox != nullptr) {
        // Verifica se o número do voo corresponde ao número fornecido
        if (listaAprox->nomeVoo == numVoo) {
            std::cout << "Passageiros do Voo " << " (" << listaAprox->nomeVoo << "):" << std::endl;

            // Itera sobre a lista de passageiros do voo encontrado
            Passageiro* passageiroAtual = listaAprox->proximoPassageiro;
            while (passageiroAtual != nullptr) {
                std::cout << "Primeiro Nome: " << passageiroAtual->primeiroNome << std::endl;
                std::cout << "Segundo Nome: " << passageiroAtual->segundoNome << std::endl;
                std::cout << "Numero de Bilhete: " << passageiroAtual->numeroDoBilhete << std::endl;
                std::cout << "Nacionalidade: " << passageiroAtual->nacionalidade << std::endl;
                std::cout << std::endl;
                passageiroAtual = passageiroAtual->next;
            }
            return; // Saímos da função após encontrar e mostrar o voo
        }
        listaAprox = listaAprox->proximoAviao;
    }

    std::cout << "Voo com número " << numVoo << " não foi encontrado." << std::endl;
}
/**
 *
 * @param listaAprox - Ponteiro para lista de Aproximação(chegada)
 * @param numVoo - Recebe o nome do voo
 * @return - Vai retornar True ou False
 * Explicação: Recebe a lista e o nome do voo, e faz uma verificação se ela existe, se existir retorna
 * true, senão retorna false
 */
bool validarNumeroVoo(Aviao* listaAprox, std::string numVoo){
    while (listaAprox != nullptr){
        if(listaAprox->nomeVoo == numVoo){
            return true;
        }
        listaAprox = listaAprox -> proximoAviao;
    }
    return false;
}
/**
 *
 * @param listaAprox - Ponteiro para lista de Aproximação(chegada)
 * @param primNome - Recebe o primeiro nome do passageiro
 * @param nomeVoo - Recebe o nome do voo
 * @return - Vai retornar True ou False
 * Explicação: Recebe a lista, o primeiro nome e nome do voo, e faz uma verifcação se o primeiro nome consta
 * no avião, se houver retorna true, senão retorna false
 */
bool validarprimNome(Aviao* listaAprox, std::string& primNome, std::string& nomeVoo) {

    while (listaAprox != nullptr) {

        if (listaAprox->nomeVoo == nomeVoo) {
            Passageiro* passageiroAtual = listaAprox->proximoPassageiro;

            while (passageiroAtual != nullptr) {

                if (passageiroAtual->primeiroNome == primNome) {
                    return true;
                }
                passageiroAtual = passageiroAtual->next;
            }
            return false;
        }
        listaAprox = listaAprox->proximoAviao;
    }
    return false;
}
/**
 *
 * @param listaAprox - Ponteiro para lista de Aproximação(chegada)
 * @param segNome - Recebe o primeiro nome do passageiro
 * @param nomeVoo - Recebe o nome do voo
 * @return - Vai retornar True ou False
 * Explicação: Recebe a lista, o segundo nome e nome do voo, e faz uma verifcação se o segundo nome consta
 * no avião, se houver retorna true, senão retorna false
 */
bool validarsegNome(Aviao* listaAprox, std::string& segNome, std::string& nomeVoo) {

    while (listaAprox != nullptr) {

        if (listaAprox->nomeVoo == nomeVoo) {
            Passageiro* passageiroAtual = listaAprox->proximoPassageiro;

            while (passageiroAtual != nullptr) {

                if (passageiroAtual->segundoNome == segNome) {
                    return true;
                }
                passageiroAtual = passageiroAtual->next;
            }
            return false;
        }
        listaAprox = listaAprox->proximoAviao;
    }
    return false;
}
/**
 *
 * @param listaAprox - Ponteiro para lista de Aproximação(chegada)
 * Explicação: Recebe a lista, permite ao utilizador ir procurar pelo numero, o primeiro e segundo nome do passageiro,
 * faz verificações, depois pede para inserir uma nova nacionalidade e atualiza a nacionalidade do passageiro
 */
void editarnacionalidade(Aviao* listaAprox){
    std::string numerovoo;
    std::string primNome;
    std::string segNome;
    std::string novaNacionalidade;
    bool encontrado = false;

    do {
        std::cout << "Digite o numero de voo" << std::endl;
        std::cin >> numerovoo;
        if(validarNumeroVoo(listaAprox, numerovoo)){
            std::cout << "Voo foi encontrado" << std::endl;
        }
    } while (!validarNumeroVoo(listaAprox,numerovoo));
    //Mostra os dados de todos os passagiros do voo que foi inserido;
    mostrarPassageiroVoo(listaAprox, numerovoo);

    do {
        std::cout << "Digite o primeiro nome do passageiro"<< std::endl;
        std::cin >> primNome;
        if(validarprimNome(listaAprox, primNome, numerovoo)){
            std::cout << "O primeiro nome foi encontrado" << std::endl;
        }
    } while (!validarprimNome(listaAprox,primNome,numerovoo));

    do {
        std::cout << "Digite o segundo nome do passageiro"<< std::endl;
        std::cin >> segNome;
        if(validarprimNome(listaAprox, segNome, numerovoo)){
            std::cout << "O primeiro nome foi encontrado" << std::endl;
        }
    } while (!validarsegNome(listaAprox,segNome,numerovoo));

    while (listaAprox != nullptr){
        Passageiro* passageirochegada = listaAprox->proximoPassageiro;
        while (passageirochegada != nullptr){
            if(passageirochegada->primeiroNome == primNome && passageirochegada->segundoNome == segNome && listaAprox->nomeVoo == numerovoo){
                std::cout << "Insira a nova nacionalidade para " << passageirochegada->primeiroNome << " " << passageirochegada->segundoNome << ":" << std::endl;
                std::cin >> novaNacionalidade;
                passageirochegada->nacionalidade = novaNacionalidade;
                std::cout << "Nacionalidade de passageiro Atualizado com sucesso!" << std::endl;
                encontrado = true;
                break;
            }
            passageirochegada = passageirochegada->next;
        }
        listaAprox = listaAprox->proximoAviao;
    }
    if(!encontrado){
        std::cout << "Passageiro nao foi encontrado." << std::endl;
    }
}

//BST para Passageiro da Pista
/*

 Passageiro* criarNovoPassageiro(const std::string& numeroDoBilhete, const std::string& primeiroNome, const std::string& segundoNome, const std::string& nacionalidade) {
    Passageiro* novoPassageiro = new Passageiro();
    novoPassageiro->numeroDoBilhete = numeroDoBilhete;
    novoPassageiro->primeiroNome = primeiroNome;
    novoPassageiro->segundoNome = segundoNome;
    novoPassageiro->nacionalidade = nacionalidade;
    novoPassageiro->next = nullptr;
    novoPassageiro->esq = nullptr;
    novoPassageiro->dir = nullptr;
    return novoPassageiro;
}


Passageiro* inserirPassageiro(Passageiro* raiz, Passageiro* novoPassageiro) {
    if (raiz == nullptr) {
        return novoPassageiro;
    }

    if (novoPassageiro->primeiroNome < raiz->primeiroNome) {
        raiz->esq = inserirPassageiro(raiz->esq, novoPassageiro);
    } else {
        raiz->dir = inserirPassageiro(raiz->dir, novoPassageiro);
    }

    return raiz;
}

Passageiro* construirArvoreBinariaDosPassageiros(Aviao* listaPista) {
    Passageiro* raiz = nullptr;

    while (listaPista != nullptr) {
        Passageiro* passageiroAtual = listaPista->proximoPassageiro;
        while (passageiroAtual != nullptr) {
            Passageiro* proximo = passageiroAtual->next;
             // Desconecta o passageiro da lista
            raiz = inserirPassageiro(raiz, passageiroAtual);
            passageiroAtual = proximo;
        }
        listaPista = listaPista->proximoAviao;
    }

    return raiz;
}

void imprimirArvoreInOrder(Passageiro* raiz) {
    std::string nacionalidade;
    std::cout << "Insira a nacionalidade que deseja: "<< std::endl;
    std::cin >> nacionalidade;
    if (raiz != nullptr) {
        imprimirArvoreInOrder(raiz->esq);
        if(raiz->nacionalidade == nacionalidade){
            std::cout << "Nome: " << raiz->primeiroNome << " " << raiz->segundoNome << ", Nacionalidade: " << raiz->nacionalidade << std::endl;
        }
        imprimirArvoreInOrder(raiz->dir);
    }
}
*/