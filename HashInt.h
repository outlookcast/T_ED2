#ifndef HASHINT_H_INCLUDED
#define HASHINT_H_INCLUDED

#include <iostream>
#include <stdlib.h>

class HashInt
{
private:
    int * array; /// Vetor de inteiros da Hash
    int tam; /// Tamanho do vetor da Hash
    int qnt; /// Quantidade de itens na Hash
    int numColisoes; /// Numero de colisoes gerados na Hash
    int funcaoHash(int val); /// Função 1 de Hashing
    int funcaoHash2(int val); /// Função 2 de Hashing
    int buscaTrataColisao(int val,int posicao); /// Retorna indice de um valor por busca linear (colisao)
    void trataColisaoSondagemLinear(int val,int posicao); /// Sondagem linear
    void trataColisaoSondagemQuadratica(int val, int posicao); /// Sondagem Quadrática
    void trataColisaoSondagemDuploHash(int val, int posicao); /// Sondagem por duplo hash

public:
    ~HashInt();
    HashInt(int tam);
    int busca(int val);
    void inserir(int val);
    void remover(int val);
    void imprimir();
    int getNumColisoes();
    int getQnt();
};

#endif // HASHINT_H_INCLUDED
