#include "HashTag.h"
#include <iostream>
#include <stdlib.h>
#include <cstdlib>

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
    return value;
}
