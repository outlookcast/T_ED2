#include "HashEncad.h"
#include <iostream>

using namespace std;

HashEncad::HashEncad(int tam)
{
    this->tam = tam;
    this->vetor = new No[this->tam];
    this->qnt = 0;
    this->numColisoes = 0;
}

HashEncad::~HashEncad()
{
    delete [] vetor;
}

int HashEncad::funcaoHash(int val)
{
    return val % this->tam;
}

void HashEncad::inserir(int val)
{

    int pos = this->funcaoHash(val);
    if(this->vetor[pos].getVal() == -1)
    {
        this->vetor[pos].setVal(val);
    }
    else
    {
        this->numColisoes++;
        this->trataColisaoSondagemEncadeada(val,pos);
    }
    this->qnt++;
}

void HashEncad::trataColisaoSondagemEncadeada(int val,int posicao)
{
    this->vetor[posicao].insereNaLista(val);
}


void HashEncad::imprimir()
{
    for(int i=0;i<tam;i++)
    {
        No aux = this->vetor[i];
        if(aux.getVal() != -1)
        {
            cout<<aux.getVal()<<" -> ";
            aux.imprime();
            cout<<endl;
        }
    }
}

int HashEncad::getNumColisoes()
{
    return this->numColisoes;
}


int HashEncad::getQnt()
{
    return this->qnt;
}

void HashEncad::remover(int val)
{
    int pos = this->funcaoHash(val);
    if(this->vetor[pos].getVal() != val)
    {
        this->vetor[pos].removeValorDaLista(val);
    }
    else
    {
        if(this->vetor[pos].getLista().size() > 0)
        {
            int primeiro = this->vetor[pos].getLista().front();
            this->vetor[pos].setVal(primeiro);
            this->vetor[pos].removeValorDaLista(primeiro);
        }
        else
        {
            this->vetor[pos].setVal(-1);
        }
    }
}
