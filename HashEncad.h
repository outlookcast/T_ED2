#ifndef HASHENCAD_H_INCLUDED
#define HASHENCAD_H_INCLUDED
#include "No.h"
class HashEncad
{
private:
    No * vetor; /// Vetor de No's
    int tam; /// Tamanho do vetor da Hash
    int qnt; /// Quantidade de itens na Hash
    int numColisoes; /// Numero de colisoes gerados na Hash
    int funcaoHash(int val); /// Fun��o 1 de Hashing
    void trataColisaoSondagemEncadeada(int val,int posicao); ///Trata colisao com inser�ao na lista
public:
    void remover(int val);
    HashEncad(int tam);
    ~HashEncad();
    void inserir(int val);
    void imprimir();
    int getNumColisoes();
    int getQnt();
};

#endif // HASHENCAD_H_INCLUDED
