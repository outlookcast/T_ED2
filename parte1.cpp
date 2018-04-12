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
using namespace std;

vector<int> readFile2(char * fileName)
{
    vector<int> vetor;
    ifstream file(fileName);

    if(!file.is_open())
    {
        std::cout << "ERROR: Could not open file" << endl;
        exit(1128);
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
    Data *vetorCompleto = readFile(607357);
    vector<int> vetorTam = readFile2("entrada.txt");
    ofstream saida;

    saida.open("saida.txt");

    for(int i = 0; i < vetorTam.size(); ++i)
    {
        int numComparacaoInt = 0;
        int numTrocasInt = 0;

        int numComparacaoData = 0;
        int numTrocasData = 0;

        int tam = vetorTam[i];
        double tempoInt = 0;
        double tempoData = 0;
        for(int j = 0; j < 5; ++i)
        {
            int *vetor = vetorRandomInt(tam, vetorCompleto);
            clock_t t1 = clock();
            quicksort(vetor, tam, &numComparacaoInt, &numTrocasInt);
            clock_t t2 = clock();

            tempoInt += (t2 - t1) * 1000.0 / CLOCKS_PER_SEC;
            delete vetor;
        }

        numTrocasInt = numTrocasInt / 5;
        numComparacaoInt = numComparacaoInt / 5;
        tempoInt = tempoInt / 5;

        for(int j = 0; j < 5; ++i)
        {
            Data *vetor = vetorRandomData(tam, vetorCompleto);
            clock_t t1 = clock();
            quicksort(vetor, tam, &numComparacaoData, &numTrocasData);
            clock_t t2 = clock();

            tempoData += (t2 - t1) * 1000.0 / CLOCKS_PER_SEC;

            delete vetor;//
        }

        numTrocasData = numTrocasData / 5;
        numComparacaoData = numComparacaoData / 5;
        tempoData = tempoData / 5;

        saida<<"Tam = "<<tam<<" :\n"<<"  Int:\n"<<"Numero de comparacoes medio: "<<numComparacaoInt<<"\nNumero de trocas medio: "<<numTrocasInt<<"\nTempo medio: "<<tempoInt<<endl;
        saida<<"  Data: \n"<<"Numero de comparacoes medio: "<<numComparacaoData<<"\nNumero de trocas medio: "<<numTrocasData<<"\nTempo medio: "<<tempoData<<endl;
    }

    saida.close();
    return 0;
}
