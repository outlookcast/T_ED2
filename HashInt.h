#ifndef HASHINT_H_INCLUDED
#define HASHINT_H_INCLUDED

#include <iostream>
#include <stdlib.h>

class HashInt
{
private:
    int * array;
    int tam;
    int qnt;
    int funcaoHash(int val);
    int buscaTrataColisao(int val,int posicao);
    void trataColisaoSondagemLinear(int val,int posicao);
    void trataColisaoSondagemQuadratica(int val, int posicao);

public:
    ~HashInt();
    HashInt(int tam);
    int busca(int val);
    void inserir(int val);
    void remover(int val);
    void imprimir();
};

#endif // HASHINT_H_INCLUDED
