#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Data.h"
#include "Hash.h"
#include <stdlib.h>
#include "quickSort1.h"
#include "leitura.h"
#include "HashInt.h"
#include "HashEncad.h"
#include "No.h"
#include "Tags.h"
#include "answer.h"
#include "leitura3.h"


using namespace std;

//Leitura do arquivo de endrada com os tamanhos a serem testados
vector<int> readFile2(char * fileName)
{
    vector<int> vetor;
    ifstream file(fileName);

    if(!file.is_open())
    {
        std::cout << "ERROR: Could not open file" << endl;
        exit(-1);
    }
    else
    {
        string num;
        getline(file,num); //Ignora o tamanho
        while(getline(file,num))
        {
            int auxInt = atoi(num.c_str());
            vetor.push_back(auxInt);
        }

        return vetor;
    }
}

int main ()
{
    /*
    Data *vetorCompleto = readFile(607357);         //Armazena todas as estradas do arquivo
    vector<int> vetorTam = readFile2("entrada.txt");
    ofstream saida;

    saida.open("saida.txt");      //grava os resultados
	cout<<"Inicio dos testes\n";
    for(int i = 0; i < vetorTam.size(); ++i)
    {
		//Número de trocas e comparações para inteiro
        int numComparacaoInt = 0;
        int numTrocasInt = 0;

		//Número de trocas e comparações para Data
        int numComparacaoData = 0;
        int numTrocasData = 0;

        int tam = vetorTam[i];    //Tamanho do vetor na i° interação

		//Variaveis para medir o tempo medio de excução
        double tempoInt = 0;
        double tempoData = 0;

        for(int j = 0; j < 5; ++j)
        {
            int *vetor = vetorRandomInt(tam, vetorCompleto);           //Gera um vetor de inteiros de tamanho tam
            clock_t t1 = clock();                                      //Tempo antes de chamar quick
            quicksort(vetor, tam, &numComparacaoInt, &numTrocasInt);
            clock_t t2 = clock();										//Tempo depois de chamar quick

            tempoInt += (t2 - t1) * 1000.0 / CLOCKS_PER_SEC;
            delete vetor;

        }

		//Calcula a media para trocas, comparações e tempo
        numTrocasInt = numTrocasInt / 5;
        numComparacaoInt = numComparacaoInt / 5;
        tempoInt = tempoInt / 5;


        for(int j = 0; j < 5; ++j)
        {
            Data *vetor = vetorRandomData(tam, vetorCompleto);		//Gera um vetor de Data de tamanho tam
            clock_t t1 = clock();//Tempo antes de chamar quick
            quicksort(vetor, tam, &numComparacaoData, &numTrocasData);
            clock_t t2 = clock();									//Tempo depois de chamar quick
            tempoData += (t2 - t1) * 1000.0 / CLOCKS_PER_SEC;

            delete []vetor;


        }

		//Calcula a media para trocas, comparações e tempo
        numTrocasData = numTrocasData / 5;
        numComparacaoData = numComparacaoData / 5;
        tempoData = tempoData / 5;

		//Grava os resultados em saida.txt
        saida<<"Tam = "<<tam<<" :\n"<<"  Int:\n"<<"    Numero de comparacoes medio: "<<numComparacaoInt<<"\n    Numero de trocas medio: "<<numTrocasInt<<"\n    Tempo medio: "<<tempoInt<<endl;
        saida<<"\n  Data: \n"<<"    Numero de comparacoes medio: "<<numComparacaoData<<"\n    Numero de trocas medio: "<<numTrocasData<<"\n    Tempo medio: "<<tempoData<<endl<<endl;


		}
	cout<<"Fim dos testes\n";
    saida.close();
	delete []vetorCompleto;

	Data * data2 = readFile();
	Data * data = vetorRandomData(100,data2);
	HashEncad * hash = new HashEncad(1475);

	for(int i=0;i<100;i++)
    {
        hash->inserir(data[i].getQuestionID());
    }
    hash->imprimir();
    cout<<"Numero de Colisoes: "<<hash->getNumColisoes()<<endl;
    delete [] data;
    delete [] data2;
    delete hash;
*/
    Tags *tag = leituraRandomParte2(500000);
    cout<< tag[500000-1].getQuestionID();
    return 0;
}























