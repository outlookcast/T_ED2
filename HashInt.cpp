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
    this->qnt = 0;
}

HashInt::~HashInt()
{
    delete [] array;
}

int HashInt::funcaoHash(int val)
{
    return val % this->tam;
}

int HashInt::funcaoHash2(int val)
{
    return val*val % this->tam;
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
            this->qnt++;
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
                this->qnt++;
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
        this->qnt++;
    }
    else
    {
        this->trataColisaoSondagemDuploHash(val,posicao);
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


void HashInt::trataColisaoSondagemQuadratica(int val, int posicao)
{
    if(this->qnt == this->tam)
    {
        cout<<"Array lotado!"<<endl;
    }
    else
    {
        int i = 1;
        while(true)
        {
            int aux = this->funcaoHash(val);
            int pos = aux + i + i*i;
            if(pos > this->tam)
            {
                //Se o tamanho da posição for maior q o tamanho do vetor então diminuimos até encontrar a posição relacionada
                while(true)
                {
                    pos = pos - this->tam;
                    if(pos < this->tam)
                        break;
                }
            }
            if(this->array[pos] == -1)
            {
                this->array[pos] = val;
                this->qnt++;
                break;
            }
            i++;
        }
    }
}

void HashInt::trataColisaoSondagemDuploHash(int val, int posicao)
{
    if(this->qnt == this->tam)
    {
        cout<<"Array lotado!"<<endl;
    }
    else
    {
        int i = 1;
        while(true)
        {
            int f1 = this->funcaoHash(val);
            int f2 = this->funcaoHash2(val);
            //Calcula o novo hash
            int pos = (f1 + i*f2) % this->tam;
            if(pos > this->tam)
            {
                //Se o tamanho da posição for maior q o tamanho do vetor então diminuimos até encontrar a posição relacionada
                while(true)
                {
                    pos = pos - this->tam;
                    if(pos < this->tam)
                        break;
                }
            }
            if(this->array[pos] == -1)
            {
                this->array[pos] = val;
                this->qnt++;
                break;
            }
            i++;
        }
    }
}


