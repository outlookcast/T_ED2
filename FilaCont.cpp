#include "FilaCont.h"

FilaCont::FilaCont()
{

	tam = 0;
	fila = NULL;
}

FilaCont::~FilaCont()
{

	delete []fila;
}

void FilaCont::realocaFila(int tam)
{

	if(fila != NULL)
		delete []fila;
	
	fila = new int[tam];
	this->tam = tam;
	fim = -1;
	inicio = -1;
}

void FilaCont::enqueue(int num)
{

	if(fila != NULL)
	{

		if(fim == -1 && inicio == -1)  //fila fazia
		{
			fim = 0;
			inicio = 0;
			fila[0] = num;
		}
		else if(fim == tam-1)        //fila cheia
		{
			cout<<"Fila cheia\n";
			exit(-1);
		}
		else
		{
			fim += 1;
			fila[fim] = num;
		}
	}
	else
	{

		cout<<"Fila não alocada\n";
		exit(-1);
	}
}

int FilaCont::dequeue()
{

	if(fila != NULL)
	{

		if(fim == -1 && inicio == -1)  //fila vazia
		{
			cout<<"Fila fazia\n";
			exit(-1);
		}
		else if(fim == inicio)  //Só existe um elemento
		{
			
			int temp = fila[inicio];
			inicio = -1;
			fim = -1;
			return temp;
		}
		else					//exite mais de um elemento.
		{
			
			int temp = fila[inicio];
			inicio += 1;
			return temp;
		}
	}
	else
	{
		cout<<"Fila não alocada\n";
		exit(-1);		
	}
}
