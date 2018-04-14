#include <iostream>
#include "stdlib.h"
#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
using namespace std;

class FilaCont
{

private:

	int tam;
	int *fila;
	int inicio;
	int fim;

public:

	FilaCont();
	~FilaCont();
	void realocaFila(int tam);
	void enqueue(int num);
	int dequeue();
	bool filaVazia()
	{
		if(fim == -1 && inicio == -1)
			return true;

		return false;
	}

};

#endif
