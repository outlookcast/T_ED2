#include <iostream>
#include <stdlib.h>
#include "quickSort2.h"
using namespace std;

void quicksort2(int *vetor, int tam, int *comparacoes, int *numCopias)
{
	int maior = 0;

	for(int i = 1; i < tam; ++i)
	{
		if(vetor[i] > vetor[maior])
			maior = i;
	}

	swap2(&vetor[maior], &vetor[tam-1]);
	quicksort2(vetor, 0, tam-2, comparacoes, numCopias);
}

void quicksort2(int *vetor, int inicio, int fim, int *comparacoes, int *numCopias)
{

	if(inicio == fim)
		return;

	int ind1 = 	inicio + rand() % (fim - inicio);
	int ind2 = inicio + rand() % (fim - inicio);
	int ind3 = inicio + rand() % (fim - inicio);

	int num1 = vetor[ind1];
	int num2 = vetor[ind2];
	int num3 = vetor[ind3];

	int pivo = mediana(num1, num2, num3);

	int indPivo;
	if(pivo == vetor[ind1])
		indPivo = ind1;
	else if(pivo == vetor[ind2])
		indPivo = ind2;
	else
		indPivo = ind3;

	swap2(&vetor[inicio], &vetor[indPivo]);

	int inferior = inicio + 1;
	int superior = fim;

    while(inferior <= superior)
    {

        while(vetor[inferior] < pivo)
        {
            inferior += 1;
            *comparacoes += 1;

        }
        *comparacoes += 1;

        while(vetor[superior] > pivo)
        {
            superior -= 1;
            *comparacoes += 1;
        }
        *comparacoes += 1;

        if(inferior < superior)
        {
            swap2(&vetor[inferior++], &vetor[superior--]);
            *numCopias += 1;
        }
        else
            inferior += 1;
    }
    swap2(&vetor[inicio], &vetor[superior]);
    *numCopias += 1;

    if(inicio <  superior - 1)
        quicksort2(vetor, inicio, superior-1, comparacoes, numCopias);

    if(superior+1 < fim)
        quicksort2(vetor, superior+1, fim, comparacoes, numCopias);

}

void swap2(int *valor1, int *valor2)
{

	int temp = *valor1;
	*valor1 = *valor2;
	*valor2 = temp;

}

int mediana(int num1, int num2, int num3)
{
	int temp;

	if(num1 <= num2)
	{
		if(num2  > num3)
		{

			num2 = num3;
			num3 = temp;

			if(num1 > num2)
			{
				temp = num2;
  			    num2 = num1;
			    num1= temp;

			}
		}
	}else
	{

		temp = num2;
  	    num2 = num1;
	    num1= temp;

		if(num2  > num3)
		{

			temp = num2;
			num2 = num3;
			num3 = temp;

			if(num1 > num2)
		    {

				temp = num1;
				num1 = num2;
				num2 = temp;

			}
		}
	}

	return num2;
}
