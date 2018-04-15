#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
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

void PT1_Cenario_4()
{

    Data * vetorDeDados = readFile();


    ///Testando para N=1.000 -> Hash Linear
    Data * vetor1000 =  vetorRandomData(1000, vetorDeDados);
    HashInt * hashLinear1000 = new HashInt(1000,1);
    for(int i=0;i<1000;i++)
    {
        hashLinear1000->inserir(vetor1000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=1.000): "<<hashLinear1000->getNumColisoes()<<endl;
    delete [] vetor1000;
    delete hashLinear1000;

    ///Testando para N=5.000 -> Hash Linear
    Data * vetor5000 = vetorRandomData(5000, vetorDeDados);
    HashInt * hashLinear5000 = new HashInt(5000,1);
    for(int i=0;i<5000;i++)
    {
        hashLinear5000->inserir(vetor5000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=5.000): "<<hashLinear5000->getNumColisoes()<<endl;
    delete [] vetor5000;
    delete hashLinear5000;

    ///Testando para N=10.000 -> Hash Linear
    Data * vetor10000 = vetorRandomData(10000, vetorDeDados);
    HashInt * hashLinear10000 = new HashInt(10000,1);
    for(int i=0;i<10000;i++)
    {
        hashLinear10000->inserir(vetor10000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=10.000): "<<hashLinear10000->getNumColisoes()<<endl;
    delete [] vetor10000;
    delete hashLinear10000;

    ///Testando para N=50.000 -> Hash Linear
    Data * vetor50000 = vetorRandomData(50000, vetorDeDados);
    HashInt * hashLinear50000 = new HashInt(50000,1);
    for(int i=0;i<50000;i++)
    {
        hashLinear50000->inserir(vetor50000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=50.000): "<<hashLinear50000->getNumColisoes()<<endl;
    delete [] vetor50000;
    delete hashLinear50000;

    ///Testando para N=100.000 -> Hash Linear
    Data * vetor100000 = vetorRandomData(100000, vetorDeDados);
    HashInt * hashLinear100000 = new HashInt(100000,1);
    for(int i=0;i<100000;i++)
    {
        hashLinear100000->inserir(vetor100000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=100.000): "<<hashLinear100000->getNumColisoes()<<endl;
    delete [] vetor100000;
    delete hashLinear100000;

    ///Testando para N=500.000 -> Hash Linear
    Data * vetor500000 = vetorRandomData(500000, vetorDeDados);
    HashInt * hashLinear500000 = new HashInt(500000,1);
    for(int i=0;i<500000;i++)
    {
        hashLinear500000->inserir(vetor500000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=500.000): "<<hashLinear500000->getNumColisoes()<<endl;
    delete hashLinear500000;
    delete [] vetor500000;


    delete [] vetorDeDados;

}
