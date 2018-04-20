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
#include "HashEncad.h"
#include "Tags.h"

unsigned long lrand() ///Em alguns compiladores a função rand() é limitada em 32767, então usamos essa função para retornar um valor randomizado maior.
{
    unsigned long r = 0;
    for (int i = 0; i < 5; ++i)
    {
        r = (r << 15) | (rand() & 0x7FFF);
    }
    return r & 0xFFFFFFFFFFFFFFFFULL;
}

using namespace std;

Tags * leituraParte2()
{
    Tags * dados = new Tags[1885079];
    ifstream ip("Tags.csv");
    if(!ip.is_open())
    {
        std::cout << "Não foi possível abrir o arquivo." << endl;
    }
    else
    {
        cout<<"Lendo o arquivo Tags.csv..."<<endl;
        string trash; ///String para armazenar string que nao usaremos
        string QuestionID;
        string Tag;
        getline(ip,trash); /// Ignora primeira linha do arquivo
        int cont = 1;
        int contadorDeLinhas = 0;
        while(contadorDeLinhas<1885079-1)
        {
            if(cont == 1)
            {
                getline(ip,QuestionID,',');
                cont++;
            }
            else if(cont == 2)
            {
                getline(ip,Tag,'\n');
                cont = 1;
                dados[contadorDeLinhas].setQuestionID(atoi(QuestionID.c_str()));
                dados[contadorDeLinhas].setTag(Tag);
                contadorDeLinhas++;
            }
        }
        ip.close();
        cout<<"Fim da leitura"<<endl;
        return dados;
    }
}

Tags * leituraRandomParte2Aux(int num, Tags * tags)
{
    srand(time(NULL));
    Tags *randomArray = new Tags[num];
    int j;
    int *vet = new int[1885079];
    for (int i=0; i<1885079; i++)
        vet[i]=0;
    for (int i=0; i<num;)
    {
        j = lrand() % 1885078;
        while(vet[j]==-1)
        {
            j = lrand() % 1885078;
        }
        vet[j] == -1;
        randomArray[i].setQuestionID(tags[j].getQuestionID());
        randomArray[i].setTag(tags[j].getTag());
        i++;
    }
    delete [] vet;
    return randomArray;
}

Tags * leituraRandomParte2(int num)
{
    Tags *tags = leituraParte2();
    Tags *tagsRandom = leituraRandomParte2Aux(num, tags);
    delete []tags;
    return tagsRandom;
}



























