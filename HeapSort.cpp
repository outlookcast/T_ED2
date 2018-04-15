#include <iostream>
using namespace std;
#include "heapSort.h"

void montaHeap(int *vetor, int tam, int *numComparacoes, int *numTrocas)
{

	if(tam == 1)
		return;

    for(int i = (tam / 2)-1; i >= 0; --i)
    {
        if((2*i+1) < tam)                //Filho a direita
		{
          if(vetor[2*i + 1] > vetor[i]) //Verifica propriedade de Heap
          {
			   //Troca elemento			
               int aux = vetor[2*i + 1];
               vetor[2*i + 1] = vetor[i];
               vetor[i] = aux;

               montaHeap(&vetor[2*i + 1], tam-(2*i + 1)); 

			   if(vetor[2*i + 1] > vetor[i]) //Verifica propriedade de Heap
         	   {
			   //Troca elemento			
               		int aux = vetor[2*i + 1];
               		vetor[2*i + 1] = vetor[i];
               		vetor[i] = aux;
					*numTrocas +=3;

               }
			   *numComparacoes +=1;	
			   *numTrocas +=3;	
		  }
		  *numComparacoes +1;
		}

        if((2*i+2) < tam)             //Filho a esquerda
        {    
			if(vetor[2*i + 2] > vetor[i])//Verifica propriedade de Heap
            {
				 //Troca elemento
                 int aux = vetor[2*i + 2];
                 vetor[2*i + 2] = vetor[i];
                 vetor[i] = aux;

                 montaHeap(&vetor[2*i + 2], tam-(2*i + 2));

			     if(vetor[2*i + 1] > vetor[i]) //Verifica propriedade de Heap
         	     {
			        //Troca elemento			
                    int aux = vetor[2*i + 1];
                    vetor[2*i + 1] = vetor[i];
                    vetor[i] = aux;
					*numTrocas +=3;
                 }
				 *numComparacoes +1;
				 *numTrocas +=3;	
            }
			*numComparacoes +1;
		}
    
		*numComparacoes+=3;	
	}

}

void heapSort(int *vetor, int tam, int *numComparacoes, int *numTrocas)
{

    while(tam > 0)///Um vetor maior que um elemento.
    {

        montaHeap(vetor, tam, numComparacoes, numTrocas); /// Cria a Heap.

        /// Troca a ultima posição com a primeira.
        int aux = vetor[0];
        vetor[0] = vetor[tam-1];
        vetor[tam - 1] = aux;
        tam -= 1;
		*numComparacoes += 1;
		*numTrocas +=3;
    }

}
