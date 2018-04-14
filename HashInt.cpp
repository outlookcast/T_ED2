#include <iostream>
#include "HashInt.h"

using namespace std;

HashInt::HashInt(int tam)
{
    this->tam = tam;
    this->array = new int [tam];
    for(int i=0; i<tam; i++)
    {
        this->array[i] = -1;
    }
}

HashInt::~HashInt()
{
    delete [] array;
}

int HashInt::funcaoHash(int val)
{
    return val % this->tam;
}

int HashInt::buscaTrataColisao(int val,int posicao)
{
    int i;
    for(i=posicao; i<this->tam; i++)
    {
        if(this->array[i] == val)
        {
            return i;
        }
    }
    if(i==tam) //Chegou no final e nao encontrou posição livre, portanto volta ao início
    {
        int j;
        for(j=0; j<posicao; j++)
        {
            if(this->array[j] == val)
            {
                return j;
            }
        }
        if(j==posicao)
        {
            cout<<"Valor não encontrado!"<<endl;
            exit(1);
        }
    }
}

void HashInt::trataColisaoSondagemLinear(int val,int posicao)
{
    int i;
    for(i=posicao; i<this->tam; i++)
    {
        if(this->array[i] == -1)
        {
            this->array[i] = val;
            cout<<"Inserido na posição: "<<i<<endl;
            break;
        }
    }
    if(i==tam) //Chegou no final e nao encontrou posição livre, portanto volta ao início
    {
        int j;
        for(j=0; j<posicao; j++)
        {
            if(this->array[j] == -1)
            {
                this->array[j] = val;
                cout<<"Inserido na posição: "<<j<<endl;
                break;
            }
        }
        if(j==posicao)
        {
            cout<<"Array lotado!!"<<endl;
        }
    }
}

int HashInt::busca(int val)
{
    int posicao = this->funcaoHash(val);
    if(this->array[posicao] == val)
    {
        return posicao;
    }
    else
    {
        return buscaTrataColisao(val,posicao);
    }

}

void HashInt::inserir(int val)
{
    int posicao = this->funcaoHash(val);

    if(this->array[posicao] == -1)
    {
        this->array[posicao] = val;
        cout<<"Inserido na posição: "<<posicao<<endl;
    }
    else
    {
        this->trataColisaoSondagemLinear(val,posicao);
    }
}

void HashInt::remover(int val)
{
    int posicao = this->funcaoHash(val);
    if(this->array[posicao] == val)
    {
        this->array[posicao] = -1; // removendo
    }
    else
    {
        int novaPosicao = buscaTrataColisao(val,posicao);
        cout<<"novaPosicao"<<novaPosicao;
        this->array[novaPosicao] = -1; //removendo
    }
}

void HashInt::imprimir()
{
    for(int i=0; i<this->tam; i++)
        cout<<this->array[i]<<" ";
    cout<<endl;
}
