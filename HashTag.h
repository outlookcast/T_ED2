#define _OPEN_SYS_ITOA_EXT
#ifndef HASHTAG_H_INCLUDED
#define HASHTAG_H_INCLUDED
#include "Tags.h"
#include <stdlib.h>
#include "HashString.h"
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
    void inserir(Tags tag);
    int frenquenciaTag(Tags tag);
    void frequenciaDeTodasTags();
};

#endif // HASHTAG_H_INCLUDED
