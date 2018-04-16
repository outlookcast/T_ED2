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

int HashString::funcaoHash(string val)
{
    unsigned short base =  2;
    string final="";
    char p1[10];
    char p2[10];
    for(int i=0; i<val.size()-1; i++)
    {
        if(i==0)
        {
            itoab(val[i],p1, 8, base);
            itoab(val[i+1],p2, 8, base);
        }
        else
        {
            itoab(val[i+1],p2, 8, base);
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
char* HashString::itoab(int n, char *str, size_t str_size, unsigned short base){
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
