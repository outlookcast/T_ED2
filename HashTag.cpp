#define _OPEN_SYS_ITOA_EXT
#include "HashTag.h"
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "HashInt.h"
#include <errno.h>
#include <limits.h>
#include <stddef.h>

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
    unsigned short base =  2;
    for(int i=0;i<tag.size()-1;i++)
    {
        if(i==0)
        {
            itoaa(tag[i],p1, 8, base);
            itoaa(tag[i+1],p2, 8, base);
        }
        else
        {
              itoaa(tag[i+1],p2, 8, base);
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

char* HashTag::itoaa(int n, char *str, size_t str_size, unsigned short base){
	static const char symbols[36]={
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B',
		'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
		'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
	};
	unsigned abs_n;
	unsigned quot, rem;
	char rev_str[CHAR_BIT*sizeof(int)];
	int rev_str_len=0;

	if(base<2 || base>sizeof symbols){  // Base inválida?
		errno=EINVAL;
		return NULL;
	}

	if(str_size<2){  // String de saída pequena demais?
		errno=ERANGE;
		return NULL;
	}

	if(n<0){  // Trata número negativo (ver nota).
		abs_n=(unsigned)-n;
		*str++='-';
		str_size--;
	}
	else
		abs_n=n;

	do {
		quot=abs_n/base;
		rem=abs_n-quot*base;
		rev_str[rev_str_len++]=symbols[rem];  // Seleciona o algarismo correspondente ao resto.
		if(rev_str_len>str_size-1){  // String de saída pequena demais?
			errno=ERANGE;
			return NULL;
		}
		abs_n=quot;
	} while(quot>0);

	do
		*str++=rev_str[--rev_str_len];  // Copia dígitos da string reversa para a ordem natural na saída.
	while(rev_str_len>0);

	*str='\0';  // Coloca o byte nulo terminador da string de saída.

	return str;
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
