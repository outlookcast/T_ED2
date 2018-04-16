#include <iostream>
#include <vector>
#include "Data.h"
#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

using namespace std;

class Hash
{
private:
    int size;
    Data * array;
    int itens;
    int function(Data data);
    void trataColisaoSondagemLinear(Data data,int pos);
    int buscaTrataColisao(Data data,int pos);
public:
    Hash(int size);
    ~Hash();
    void insert(Data data);
    void imprime();
    int searchIndex(Data data);
    void remover(Data data);
    int getItens();
    bool busca(Data data);
};
#endif // HASH_H_INCLUDED
