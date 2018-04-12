#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Hash.h"



using namespace std;

//---------- Construtor ---------- //
Hash::Hash(int size)
{
    this->size = size;
    this->array = new Data[size];
    this->itens = 0;
}

//---------- Destrutor ---------- //
Hash::~Hash()
{
    delete [] this->array;
}

//---------- Inserindo ---------- //
void Hash::insert(Data data)
{
    int pos = this->function(data);

    if(this->array[pos].getQuestionID() == -1)
    {
        this->array[pos] = data;
    }
    else
    {
        this->trataColisaoSondagemLinear(data,pos);
    }
    this->itens++;
}

//---------- Função hash ---------- //
int Hash::function(Data data)
{
    return data.getUserID() % this->size;
}

//---------- Tratamento linear de inserção ---------- //
void Hash::trataColisaoSondagemLinear(Data data,int pos)
{
    int i;
    for(i=pos; i<this->size; i++)
    {
        if(this->array[i].getQuestionID() == -1)
        {
            this->array[i] = data;
            break;
        }
    }
    if(i==this->size)
    {
        int j;
        for(j=0; j<pos; j++)
        {
            if(this->array[j].getQuestionID() == -1)
            {
                this->array[j] = data;
                break;
            }
        }
        if(j==pos)
        {
            cout<<"Crowded array!!"<<endl;
        }
    }
}

//---------- Imprimir as posições preenchidas ---------- //
void Hash::imprime()
{
    for(int i=0; i<this->size; i++)
    {
        if(this->array[i].getQuestionID() != -1)
        {
            cout<<"Question ID: "<<this->array[i].getQuestionID()<<endl;
            cout<<"User ID: "<<this->array[i].getUserID()<<endl;
            cout<<"Date: "<<this->array[i].getDate()<<endl;
            cout<<"Score: "<<this->array[i].getScore()<<endl;
            cout<<"Title: "<<this->array[i].getTitle()<<endl;
            cout<<"Indice: "<<i<<endl;
            cout<<"Indice Funcao de busca: "<<this->searchIndex(this->array[i])<<endl;
            cout<<endl<<endl;
        }
    }
}

//---------- Busca o index de um dado ---------- //
int Hash::searchIndex(Data data)
{
    int pos = function(data);
    if(this->array[pos].getQuestionID() == data.getQuestionID())
    {
        return pos;
    }
    else
    {
        return buscaTrataColisao(data,pos);
    }
}

//---------- Função para tratar colisão de busca ---------- //
int Hash::buscaTrataColisao(Data data, int pos)
{
    int i;
    for(i=pos; i<this->size; i++)
    {
        if(this->array[i].getQuestionID() == data.getQuestionID())
        {
            return i;
        }
    }
    int j;
    for(j=0; j<pos; j++)
    {
        if(this->array[j].getQuestionID() == data.getQuestionID())
        {
            return j;
        }
    }
    if(j==pos)
    {
        cout<<"Value not found!"<<endl;
        exit(1);
    }
}

//---------- Função para remover ---------- //
void Hash::remover(Data data)
{
    int pos = this->function(data);
    if(this->array[pos].getQuestionID() == data.getQuestionID())
    {
        this->array[pos].setQuestionID(-1); //Remove o dado colocando o valor -1
    }
    else
    {
        int newPos = buscaTrataColisao(data,pos);
        Data a();
        this->array[newPos].setQuestionID(-1); //Remove o dado colocando o valor -1
    }
    this->itens--;
}

int Hash::getItens()
{
    return this->itens;
}
