#define _OPEN_SYS_ITOA_EXT
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "HashString.h"
#include <errno.h>
#include <limits.h>
#include <stddef.h>

HashString::HashString(int tam)
{
    this->tam = tam;
    this->array = new string[this->tam];
    for(int i=0; i<tam; i++)
        this->array[i] = "-1";
    this->qnt = 0;
    this->numColisoes = 0;
}

HashString::~HashString()
{
    delete [] this->array;
}

HashString::funcaoHash(string val)
{
    string final="";
    char p1[10];
    char p2[10];
    for(int i=0; i<val.size()-1; i++)
    {
        if(i==0)
        {
            itoa(val[i],p1,2);
            itoa(val[i+1],p2,2);
        }
        else
        {
            itoa(val[i+1],p2,2);
        }
        for(int i=0; i<7; i++)
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
        for(i=0; final[i]!='\0'; i++)
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
void HashString::inserir(string val)
{
    int posicao = funcaoHash(val);
    if(this->array[posicao] == "-1")
    {
        this->array[posicao] = val;
    }
    else
    {
        this->trataColisaoSondagemLinear(val,posicao);
    }
}


void HashString::trataColisaoSondagemLinear(string val,int posicao)
{
    int i;
    for(i=posicao; i<this->tam; i++)
    {
        if(this->array[i] == "-1")
        {
            this->array[i] = val;
            this->qnt++;
            break;
        }
        else
        {
            this->numColisoes++;
        }
    }
    if(i==tam) //Chegou no final e nao encontrou posi��o livre, portanto volta ao in�cio
    {
        int j;
        for(j=0; j<posicao; j++)
        {
            if(this->array[j] == "-1")
            {
                this->array[j] = val;
                this->qnt++;
                break;
            }
            else
            {
                this->numColisoes++;
            }
        }
        if(j==posicao)
        {
            cout<<"Array lotado!!"<<endl;
        }
    }
}

bool HashString::busca(string val)
{
    int posicao = funcaoHash(val);
    if(this->array[posicao] == val)
    {
        return true;
    }
    else
    {
        int i;
        for(i=posicao; i<this->tam; i++)
        {
            if(this->array[i] == val)
            {
                return true;
            }
        }
        if(i==tam) //Chegou no final e nao encontrou posi��o livre, portanto volta ao in�cio
        {
            int j;
            for(j=0; j<posicao; j++)
            {
                if(this->array[j] == val)
                {
                    return true;
                }
            }
            if(j==posicao)
            {
                return false;
            }
        }
    }
}
