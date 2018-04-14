#include <iostream>
#include "radixSort.h"
#include "FilaCont.h"
using namespace std;

void radixSort(int *vetor, int tam)
{

	FilaCont vetorFila[10];

	for(int i = 0; i < 10; ++i)
	{
		vetorFila[i].realocaFila(tam);
	}

	int fator;
	int i;

	for(fator = 1, i = 0; i < 10; fator *= 10, ++i)   // Executa o for 10 vezes, o maior número de casas para um inteiro
	{

		for(int j = 0; j < tam; ++j)
		{
			vetorFila[(vetor[j] / fator) % 10].enqueue(vetor[j]);    //coloca na vetor[j] na posição coreta, ou seja, na fila corespondente ao digito que esta sendo considerado.
		}
		
		int t = 0;
		for(int j = 0; j < 10; ++j)           //Pega em sequencia os elementos das filas e coloca no vetor.
		{

			while(!vetorFila[j].filaVazia())
			{
				vetor[t] = vetorFila[j].dequeue();
				t += 1;
			}
		}

	}
}
