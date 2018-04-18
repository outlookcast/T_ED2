#define _OPEN_SYS_ITOA_EXT
#ifndef HASHSTRING_H_INCLUDED
#define HASHSTRING_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

class HashString
{
private:
    string * array;
    int tam;
    int numColisoes;
    int qnt;
    int funcaoHash(string val);

public:
    HashString(int tam);
    ~HashString();
    bool busca(string val);
    void inserir(string val);
    void trataColisaoSondagemLinear(string val,int posicao);

};

#endif // HASHSTRING_H_INCLUDED
