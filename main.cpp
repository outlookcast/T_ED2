#include <iostream>
#include <fstream>
#include "PT1_Cenario1.h"
#include "PT1_Cenario2.h"
#include "PT1_Cenario3.h"
#include "parte2.h"
#include "vector"

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
    cout<<"TRABALHO ESTRUTURA DE DADOS 2: "<<endl<<endl;
   	int chave;
   	cout<< "Parte do trabalho: "<< endl;
   	cout <<"1- Análise dos Algoritmos  : "<<endl;
   	cout <<"2- Implementação das Tags Frequentes e dos Usuários Ativos : "<<endl;
   	cin >>chave;
   	if (chave == 1)
	{
	    cout<<"Cenário parte 1: "<<endl;
		chave = 0;
	   	cout <<"1- Análise dos Algoritmos: "<<endl;
	   	cout <<"2- Impacto de variações do Quicksort: "<<endl;
	   	cout <<"3- Quicksort X InsertionSort X Mergesort X Heapsort X RadxSort: "<<endl;
	   	cout <<"4- Tratamento de Colisões: Endereçamento X Encadeamento: "<<endl;
	   	cin >>chave;
	   	switch (chave)
	   	{
	   		case 1:
	   				PT1_Cenario_1();
	   				break;
	   		case 2:
	   				PT1_Cenario_2();
	   				break;
	   		case 3:
	   				PT1_Cenario_3();
	   				break;
	   		case 4:
	   				PT1_Cenario_4();
	   				break;
	   		default:
	   				cout<<"Cenários devem ser entre 1 e 4"<<endl;
	   	}
	}
	else if (chave == 2)
	{
		Parte2();
	}
	else
		cout<<"Entrada deve ser 1 ou 2"<<endl;
    return 0;
}























