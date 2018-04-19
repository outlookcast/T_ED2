#ifndef HASHTAGBUSCA_H_INCLUDED
#define HASHTAGBUSCA_H_INCLUDED
#include "Tags.h"
#include <list>

class HashTagBusca
{
    private:
        Tags * array;
        int qnt;
        int tam;
        int funcaoHash(Tags tag);
        int funcaoHash(int val);
    public:
        HashTagBusca(int tam);
        ~HashTagBusca();
        void insere(Tags tag);
        list<string> busca(int questionID);

};

#endif // HASHTAGBUSCA_H_INCLUDED
