#ifndef HASH_CPP_INCLUDED
#define HASH_CPP_INCLUDED
#include "HashCoalescido.h"
#include <stdlib.h>

HashCoalescido::HashCoalescido(int tam)
{

    this->tam = tam;
    hash = new Modulo[tam];      //Aloca memória

    for(int i=0; i < tam; ++i) //todas as posições vão ter -1.
    {
		hash[i].chave = -1;
		hash[i].prox = -1;
	}

    quantColisao = 0;
    this->numColisoes = 0;

}

int HashCoalescido::getNumColisoes()
{
    return this->numColisoes;
}

HashCoalescido::~HashCoalescido()
{
    delete []hash;
}
int HashCoalescido::resolveColisao() // Tratamento de colisao
{
    int posicaoBase = tam - 1;
    do
    {
        this->numColisoes++;
        posicaoBase = posicaoBase -1;

        if(posicaoBase <= 0)   // se o endereço chegar no inicio da tabela.
        {
			cout<<"Tabela cheia\n";
            return -1;
        }

    }while(hash[posicaoBase].chave != -1);

    return posicaoBase;

}

int HashCoalescido::calculaPosicao(int chave)  //faz a operação chave % tam.
{

    return  (chave % tam);


}

void HashCoalescido::adicionaElemento(int num)
{

    int endereco = calculaPosicao(num);  // Esdereço base.
	int posicao = endereco;

    if(hash[posicao].chave != -1)             // Verifica se a posição é vazia.
	{

		while(hash[posicao].prox != -1)     //Encontra um prox vazio.
		{
			posicao = hash[posicao].prox;
		}

        endereco = resolveColisao();  //Tratamento de colisão. Colocar num na posição endereco.
		hash[posicao].prox = endereco;//Link da posição vazia com o primeiro com prox vazio.
		posicao = endereco;
	}

    hash[posicao].chave = num;

}

int HashCoalescido::retornaElemento(int num)
{

    int posicaoBase = calculaPosicao(num);// Esdereço base.

	if(hash[posicaoBase].chave == num)
		return hash[posicaoBase].chave;

    posicaoBase = hash[posicaoBase].prox;

	if(posicaoBase == -1)
	{
		cout<<"Erro, elemento não encontrado\n";
		exit(-1);
	}
	while(hash[posicaoBase].chave != num)
	{
		posicaoBase = hash[posicaoBase].prox;
		if(posicaoBase == calculaPosicao(num))
		{
			cout<<"Erro, elemento nãoencontrado\n";
			exit(-1);
		}
	}

    return hash[posicaoBase].chave;


}

int HashCoalescido::removeElemento(int num)
{

    int posicaoBase = calculaPosicao(num);// Esdereço base.

	if(hash[posicaoBase].chave == num)
	{
		int temp;
		if(hash[posicaoBase].prox != -1)
		{

			temp =  hash[posicaoBase].chave;
			int prox = hash[posicaoBase].prox;
			hash[posicaoBase].chave = hash[prox].chave;
			hash[posicaoBase].prox = hash[prox].prox;

			hash[prox].chave = -1;
			hash[prox].prox = -1;

		}

		temp =  hash[posicaoBase].chave;
		hash[posicaoBase].chave = -1;
		return temp;

	}

    posicaoBase = hash[posicaoBase].prox;
	if(posicaoBase == -1)
	{
		cout<<"Erro, elemento não encontrado\n";
		exit(-1);
	}
	int posicaoAnterior = -1;
	while(hash[posicaoBase].chave != num)
	{
		posicaoAnterior = posicaoBase;
		posicaoBase = hash[posicaoBase].prox;
		if(posicaoBase == calculaPosicao(num))
		{
			cout<<"Erro, elemento não encontrado\n";
			exit(-1);
		}
	}

	hash[posicaoAnterior].prox = hash[posicaoBase].prox;
	int temp = hash[posicaoBase].chave;
	hash[posicaoBase].chave = -1;
	hash[posicaoBase].prox = -1;

    return temp;

}


#endif // HASH_CPP_INCLUDED
