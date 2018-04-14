#include <iostream>

using namespace std;

void swap(int *valor1, int *valor2);
void mediana(int *inicio, int *meio, int *fim); 
void quicksort(int *vetor, int inicio, int fim);
void insertion(int *vetor, int n);

int main(void)
{

	int vetor[10] = {1, 2, 3, 7, 6, 4, 8, 10, 5, 9};
	quicksort(vetor, 0, 9);

	for(int i = 0; i < 10; ++i)
	{

		cout<<vetor[i]<<" ";
	}

	cout<<endl;

}

void quicksort(int *vetor, int inicio, int fim)
{
	
	if(inicio == fim)
		return;

	if((fim - inicio) + 1 <=30)
		insertion(&vetor[inicio], (fim - inicio) + 1);

	int meio = (inicio + fim)/2;     // seleciona o pivo.

	mediana(&vetor[inicio], &vetor[meio], &vetor[fim]);

	swap(vetor[inicio+1], vetor[meio]);

	int pivo = vetor[inicio+1];

	int inferior = inicio + 2; 
	int superior = fim-1;

	while(inferior <= superior)
	{

		while(vetor[inferior] < pivo)
			inferior += 1;

		while(vetor[superior] > pivo)
			superior -= 1;
		
		if(inferior < superior)
			swap(vetor[inferior], vetor[superior]);
		else
			inferior += 1;
	}
	swap(vetor[inicio+1], vetor[superior]);
	
	quicksort(vetor, inicio, superior);
	quicksort(vetor, superior+1, fim);

}

void swap(int *valor1, int *valor2)
{

	int temp = *valor1;
	*valor1 = *valor2;
	*valor2 = temp;

}

void mediana(int *inicio, int *meio, int *fim)
{

	if(*inicio <= *meio)
	{
		if(*meio  > *fim)
		{

			swap(meio, fim);

			if(*inicio > *meio)
				swap(meio,  inicio);
		}
	}else
	{

		swap(inicio, meio);

		if(*meio  > *fim)
		{

			swap(meio, fim);

			if(*inicio > *meio)
				swap(meio,  inicio);
		}		
	}
}

void insertion(int *vetor, int n)
{

	for(int i = 1; i < n; ++i)
	{

		int temp = vetor[i];
		
		int j;
		for(j = i; j > 0 && temp < vetor[j-1]; j--)
			vetor[j] = vetor[j-1];

		vetor[j] = temp;

	}

}
