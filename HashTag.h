#ifndef HASHTAG_H_INCLUDED
#define HASHTAG_H_INCLUDED
#include "Tags.h"

class HashTag
{
private:
    Tags * array;
    int tam;
    int qnt;
    int numColisoes;
    int funcaoHash(string Tag);

public:
    HashTag(int tam);
    ~HashTag();
};

#endif // HASHTAG_H_INCLUDED
