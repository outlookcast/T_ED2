#include "PT1_Cenario2.h"

void PT1_Cenario_2()
{
	Data *data = readFile();
	ofstream saida;

    saida.open("saida.txt");      //grava os resultados
	int vetor[] = {100, 200, 300, 350, 300, 250};

	int comparacaoQuick1 = 0;
    int trocaQuick1 = 0;
	double tempoQuick1 = 0;

	int comparacaoQuick2 = 0;
	int trocaQuick2 = 0;
	double tempoQuick2 = 0;

	int comparacaoQuick3 = 0;
	int trocaQuick3 = 0;
	double tempoQuick3 = 0;

	for(int i = 0; i < 6; ++i)
	{

	    comparacaoQuick1 = 0;
        trocaQuick1 = 0;
	    tempoQuick1 = 0;

	    comparacaoQuick2 = 0;
	    trocaQuick2 = 0;
	    tempoQuick2 = 0;

	    comparacaoQuick3 = 0;
	    trocaQuick3 = 0;
	    tempoQuick3 = 0;

		int *vetorAux = new int[vetor[i]];
		clock_t t1;
		clock_t t2;

		for(int j=0; j < 5; ++j)
		{
			int * vetorRand = vetorRandomInt(vetor[i], data);

			for(int k = 0; k < vetor[i]; ++k)
				vetorAux[k] = vetorRand [k];

			t1 = clock();
			quicksort(vetorAux, vetor[i], &comparacaoQuick1, &trocaQuick1);
			t2 = clock();

			tempoQuick1 += (t2 - t1) * 1000.0 / CLOCKS_PER_SEC;

			for(int k = 0; k < vetor[i]; ++k)
				vetorAux[k] = vetorRand [k];

			t1 = clock();
			quicksort2(vetorAux, vetor[i], &comparacaoQuick2, &trocaQuick2);
			t2 = clock();

			tempoQuick2 += (t2 - t1) * 1000.0 / CLOCKS_PER_SEC;

			for(int k = 0; k < vetor[i]; ++k)
				vetorAux[k] = vetorRand [k];

			t1 = clock();
			quicksort3(vetorAux, vetor[i], &comparacaoQuick3, &trocaQuick3);
			t2 = clock();

			tempoQuick3 += (t2 - t1) * 1000.0 / CLOCKS_PER_SEC;

			delete []vetorRand;

		}


		comparacaoQuick1 /= 5;
		trocaQuick1 /= 5;
		tempoQuick1 /= 5;

		comparacaoQuick2 /= 5;
		trocaQuick2 /= 5;
		tempoQuick2 /= 5;

		comparacaoQuick3 /= 5;
		trocaQuick3 /= 5;
		tempoQuick3 /= 5;



	

		saida<<"\nTam = "<<vetor[i]<<"\n\n    QuickSorteRec:\n     Numero de comparacoes Medio: "<<comparacaoQuick1<<"\n     Numero de trocas Medio:"<<trocaQuick1<<"\n     Tempo Medio: "<<tempoQuick1<<endl;
		saida<<"\n\n    QuickSorteMediana:\n     Numero de comparacoes Medio: "<<comparacaoQuick2<<"\n     Numero de trocas Medio:"<<trocaQuick2<<"\n     Tempo Medio: "<<tempoQuick2<<endl;
		saida<<"\n\n    QuickSorteInser:\n     Numero de comparacoes Medio: "<<comparacaoQuick3<<"\n     Numero de trocas Medio:"<<trocaQuick3<<"\n     Tempo Medio: "<<tempoQuick3<<endl;
		delete []vetorAux;
	}

	saida.close();
	delete []data;

}
