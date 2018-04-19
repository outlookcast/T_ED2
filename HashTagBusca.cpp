#include "HashTagBusca.h"
#include <iostream>
#include <stdlib.h>
#include "Tags.h"

using namespace std;

HashTagBusca::HashTagBusca(int tam)
{
    this->tam = tam;
    this->qnt = 0;
    this->array = new Tags[this->tam];
}

HashTagBusca::~HashTagBusca()
{
    delete [] this->array;
}

int HashTagBusca::funcaoHash(Tags tag)
{
    int pos = tag.getQuestionID();
    return pos % this->tam;
}

int HashTagBusca::funcaoHash(int val)
{
    return val % this->tam;
}

void HashTagBusca::insere(Tags tag)
{
    int posicao = this->funcaoHash(tag.getQuestionID());
    if(this->array[posicao].getQuestionID() == -1)
    {
        this->array[posicao].setQuestionID(tag.getQuestionID());
        this->array[posicao].setTag(tag.getTag());
    }
    else
    {
        this->array[posicao].inserirNaLista(tag);
    }
}

list<string> HashTagBusca::busca(int questionID)
{
    int posicao = funcaoHash(questionID);
    list<string> lista;
    if(this->array[posicao].getQuestionID() == questionID)
    {
        lista.push_back(this->array[posicao].getTag());
    }
    list<Tags> listaAuxiliar = this->array[posicao].getLista();

    for (list<Tags>::iterator i = listaAuxiliar.begin(); i != listaAuxiliar.end(); ++i)
    {
        if(i->getQuestionID() == questionID )
        {
            lista.push_back(i->getTag());
        }
    }
    return lista;
}
