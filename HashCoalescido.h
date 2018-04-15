#ifndef HASHCOALESCIDO_H_INCLUDED
#define HASHCOALESCIDO_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct
{

	int chave;
	int prox;

}Modulo;


class HashCoalescido
{

private:

    int numColisoes;
    int tam;   //tamanho da hash
    long long int quantColisao;
    Modulo *hash;
    int calculaPosicao(int chave);   //faz a operação chave % tam, e resolve a colisão por sondagem linear.
    int resolveColisao();

public:
    HashCoalescido(int tam);
    ~HashCoalescido();
    void adicionaElemento(int num);
    int retornaElemento(int num);
    int removeElemento(int num);
    int getNumColisoes();


};


#endif // HASHCOALESCIDO_H_INCLUDED
