#include "HashTag.h"
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "HashInt.h"
#include "HashString.h"

using namespace std;

HashTag::HashTag(int tam)
{
    this->tam = tam;
    this->array = new Tags[this->tam];
    this->qnt = 0;
    this->numColisoes = 0;
}

HashTag::~HashTag()
{
    delete [] this->array;
}

int HashTag::funcaoHash(string tag)
{
    string final="";
    char p1[10];
    char p2[10];
    for(int i=0;i<tag.size()-1;i++)
    {
        if(i==0)
        {
            itoa(tag[i],p1,2);
            itoa(tag[i+1],p2,2);
        }
        else
        {
            itoa(tag[i+1],p2,2);
        }
        for(int i=0;i<7;i++)
        {
            if(p1[i] == p2[i])
            {
                final += '0';
            }
            else
            {
                final += '1';
            }
        }
        final += '\0';
        int i;
        for(i=0;final[i]!='\0';i++)
        {
            p1[i] = final[i];
        }
        p1[i] += '\0';
        final = "";
    }

    char* endptr;
    long value = strtol(p1,&endptr,2);
    return value % this->tam;
}


void HashTag::inserir(Tags tag)
{
    int posicao = this->funcaoHash(tag.getTag());
    if(this->array[posicao].getQuestionID() == -1)
    {
        this->array[posicao].setQuestionID(tag.getQuestionID());
        this->array[posicao].setTag(tag.getTag());
    }
    else
    {
        this->numColisoes++;
        this->array[posicao].inserirNaLista(tag);
    }
}


int HashTag::frenquenciaTag(Tags tag)
{
    int posicao = this->funcaoHash(tag.getTag());
    string tagAux = tag.getTag();
    int frequencia = 1;
    list<Tags> lst = this->array[posicao].getLista();
    for (list<Tags>::iterator i = lst.begin(); i != lst.end(); ++i)
    {
        if(i->getTag() == tagAux )
        {
            frequencia++;
        }
    }
    return frequencia;
}


void HashTag::frequenciaDeTodasTags()
{
    HashString * hash = new HashString(this->tam);
    int numTagsNaoRepetidas = 0;
    for(int i=0; i<this->tam; i++)
    {
        if(this->array[i].getQuestionID() != -1 && this->array[i].getTag() != "-1")
        {
            if(hash->busca(this->array[i].getTag()) == false)
            {
                hash->inserir(this->array[i].getTag());
                cout<<"Frequencia da Tag "<<this->array[i].getTag()<<": "<<this->frenquenciaTag(this->array[i])<<endl;
                numTagsNaoRepetidas++;
            }
        }
    }
    cout<<"Numero de tags sem repeticao: "<<numTagsNaoRepetidas<<endl;
    delete hash;
}

