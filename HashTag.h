#define _OPEN_SYS_ITOA_EXT
#ifndef HASHTAG_H_INCLUDED
#define HASHTAG_H_INCLUDED
#include "Tags.h"
#include <stdlib.h>
#include "HashString.h"
#include "FrequenciaTag.h"
#include <vector>

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
    int numTagsNaoRepetidas;
    ~HashTag();
    void inserir(Tags tag);
    int frenquenciaTag(Tags tag);
    vector<FrequenciaTag> frequenciaDeTodasTags();
};

#endif // HASHTAG_H_INCLUDED
