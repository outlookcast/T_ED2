#include "PT1_Cenario3.h"

void PT1_Cenario_3()
{
	Data *data = readFile();
	ofstream saida;

    saida.open("saida.txt");      //grava os resultados
	int vetor[] = {100, 200, 300, 350, 300, 250};

	int comparacaoHeap = 0;
    int trocaHeap = 0;
	double tempoHeap = 0;

	int comparacaoMerge = 0;
	int trocaMerge = 0;
	double tempoMerge = 0;

	int comparacaoQuick = 0;
	int trocaQuick = 0;
	double tempoQuick = 0;	

	int comparacaoInsert = 0;
	int trocaInsert = 0;
	double tempoInsert = 0;
	
	int trocaRadix = 0;
	double tempoRadix = 0;
	
	for(int i = 0; i < 6; ++i)
	{
		comparacaoHeap = 0;
		trocaHeap = 0;
		tempoHeap = 0;

		comparacaoMerge = 0;
		trocaMerge = 0;
		tempoMerge = 0;

		comparacaoQuick = 0;
		trocaQuick = 0;
		tempoQuick = 0;	

		comparacaoInsert = 0;
		trocaInsert = 0;
		tempoInsert = 0;			

		trocaRadix = 0;
		tempoRadix = 0;

		int *vetorAux = new int[vetor[i]];
		clock_t t1;
		clock_t t2;

		for(int j=0; j < 5; ++j)
		{		
			int * vetorRand = vetorRandomInt(vetor[i], data);
			
			for(int k = 0; k < vetor[i]; ++k)
				vetorAux[k] = vetorRand [k];
			
			t1 = clock();
			heapSort(vetorAux, vetor[i], &comparacaoHeap, &trocaHeap);
			t2 = clock();
			
			tempoHeap += (t2 - t1) * 1000.0 / CLOCKS_PER_SEC;			

			for(int k = 0; k < vetor[i]; ++k)
				vetorAux[k] = vetorRand [k];
			
			t1 = clock();
			//quicksort3(vetorAux, vetor[i], &comparacaoQuick, &trocaQuick);
			t2 = clock();

			tempoQuick += (t2 - t1) * 1000.0 / CLOCKS_PER_SEC;

			for(int k = 0; k < vetor[i]; ++k)
				vetorAux[k] = vetorRand [k];
			
			t1 = clock();
			//insertion(vetorAux, vetor[i], &comparacaoInsert, &trocaInsert);
			t2 = clock();			

			tempoInsert += (t2 - t1) * 1000.0 / CLOCKS_PER_SEC;

			for(int k = 0; k < vetor[i]; ++k)
				vetorAux[k] = vetorRand [k];

			t1 = clock();
			merge(vetorAux, vetor[i], &trocaMerge, &comparacaoMerge);
			t2 = clock();

			tempoMerge += (t2 - t1) * 1000.0 / CLOCKS_PER_SEC;			

			for(int k = 0; k < vetor[i]; ++k)
				vetorAux[k] = vetorRand [k];
			
			t1 = clock();
			radixSort(vetorAux, vetor[i], &trocaRadix);	
			t2 = clock();

			tempoRadix += (t2 - t1) * 1000.0 / CLOCKS_PER_SEC;

			delete []vetorRand;	
			
		}

		comparacaoHeap /= 5;
		trocaHeap /= 5;
		tempoHeap /= 5;

		comparacaoMerge /= 5;
		trocaMerge /= 5;
		tempoMerge /= 5;

		comparacaoQuick /= 5;
		trocaQuick /= 5;
		tempoQuick /= 5;	

		comparacaoInsert /= 5;
		trocaInsert /= 5;
		tempoInsert /= 5;			

		trocaRadix /= 5;
		tempoRadix /= 5;
		
		saida<<"\nTam = "<<vetor[i]<<"\n\n    HeapSorte:\n     Numero de comparacoes Medio: "<<comparacaoHeap<<"\n     Numero de trocas Medio:"<<trocaHeap<<"\n     Tempo Medio"<<tempoHeap<<endl;
		saida<<"\n\n    MergeSorte:\n     Numero de comparacoes Medio: "<<comparacaoMerge<<"\n     Numero de trocas Medio:"<<trocaMerge<<"\n     Tempo Medio"<<tempoMerge<<endl;
		saida<<"\n\n    QuickSorte:\n     Numero de comparacoes Medio: "<<comparacaoQuick<<"\n     Numero de trocas Medio:"<<trocaQuick<<"\n     Tempo Medio"<<tempoQuick<<endl;
		saida<<"\n\n    InsertSorte:\n     Numero de comparacoes Medio: "<<comparacaoInsert<<"\n     Numero de trocas Medio:"<<trocaInsert<<"\n     Tempo Medio"<<tempoInsert<<endl;
		saida<<"\n\n    RadixSorte:\n     Numero de trocas Medio:"<<trocaRadix<<"\n     Tempo Medio"<<tempoRadix<<endl;

		delete []vetorAux;
	}

	saida.close();
	delete []data;

}
