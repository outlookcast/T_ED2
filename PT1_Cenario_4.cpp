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
    Data * vetor1000 =  vetorRandomData(1000, vetorDeDados);
    Data * vetor5000 = vetorRandomData(5000, vetorDeDados);
    Data * vetor10000 = vetorRandomData(10000, vetorDeDados);
    Data * vetor50000 = vetorRandomData(50000, vetorDeDados);
    Data * vetor100000 = vetorRandomData(100000, vetorDeDados);
    Data * vetor500000 = vetorRandomData(500000, vetorDeDados);

    /*

    ///  ---------------------------------------- INICIO DOS TESTES PARA TRATAMENTO LINEAR ---------------------------------------- ///
    cout<<"///  -------- INICIO DOS TESTES PARA TRATAMENTO LINEAR -------- ///"<<endl;

    ///Testando para N=1.000 -> Hash Linear
    HashInt * hashLinear1000 = new HashInt(1000,1);
    for(int i=0;i<1000;i++)
    {
        hashLinear1000->inserir(vetor1000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=1.000): "<<hashLinear1000->getNumColisoes()<<endl;
    delete hashLinear1000;

    ///Testando para N=5.000 -> Hash Linear
    HashInt * hashLinear5000 = new HashInt(5000,1);
    for(int i=0;i<5000;i++)
    {
        hashLinear5000->inserir(vetor5000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=5.000): "<<hashLinear5000->getNumColisoes()<<endl;
    delete hashLinear5000;

    ///Testando para N=10.000 -> Hash Linear
    HashInt * hashLinear10000 = new HashInt(10000,1);
    for(int i=0;i<10000;i++)
    {
        hashLinear10000->inserir(vetor10000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=10.000): "<<hashLinear10000->getNumColisoes()<<endl;
    delete hashLinear10000;

    ///Testando para N=50.000 -> Hash Linear
    HashInt * hashLinear50000 = new HashInt(50000,1);
    for(int i=0;i<50000;i++)
    {
        hashLinear50000->inserir(vetor50000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=50.000): "<<hashLinear50000->getNumColisoes()<<endl;
    delete hashLinear50000;

    ///Testando para N=100.000 -> Hash Linear
    HashInt * hashLinear100000 = new HashInt(100000,1);
    for(int i=0;i<100000;i++)
    {
        hashLinear100000->inserir(vetor100000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=100.000): "<<hashLinear100000->getNumColisoes()<<endl;
    delete hashLinear100000;

    ///Testando para N=500.000 -> Hash Linear
    HashInt * hashLinear500000 = new HashInt(500000,1);
    for(int i=0;i<500000;i++)
    {
        hashLinear500000->inserir(vetor500000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=500.000): "<<hashLinear500000->getNumColisoes()<<endl;
    delete hashLinear500000;

    ///  ---------------------------------------- FIM DOS TESTES PARA TRATAMENTO LINEAR ---------------------------------------- ///
    cout<<"///  -------- FIM DOS TESTES PARA TRATAMENTO LINEAR -------- ///"<<endl;

    cout<<endl;
    cout<<endl;
    cout<<endl;

    ///  ---------------------------------------- INICIO DOS TESTES PARA TRATAMENTO ENCADEAMENTO SEPARADO ---------------------------------------- ///
    cout<<"///  -------- INICIO DOS TESTES PARA TRATAMENTO ENCADEAMENTO SEPARADO -------- ///"<<endl;

    ///Testando para N=1.000 -> ENCADEAMENTO SEPARADO
    HashEncad * hashHashEncad1000 = new HashEncad(1000);
    for(int i=0;i<1000;i++)
    {
        hashHashEncad1000->inserir(vetor1000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=1.000): "<<hashHashEncad1000->getNumColisoes()<<endl;
    delete hashHashEncad1000;


    ///Testando para N=5.000 -> ENCADEAMENTO SEPARADO
    HashEncad * hashHashEncad5000 = new HashEncad(5000);
    for(int i=0;i<5000;i++)
    {
        hashHashEncad5000->inserir(vetor5000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=5.000): "<<hashHashEncad5000->getNumColisoes()<<endl;
    delete hashHashEncad5000;


    ///Testando para N=10.000 -> ENCADEAMENTO SEPARADO
    HashEncad * hashHashEncad10000 = new HashEncad(10000);
    for(int i=0;i<10000;i++)
    {
        hashHashEncad10000->inserir(vetor10000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=10.000): "<<hashHashEncad10000->getNumColisoes()<<endl;
    delete hashHashEncad10000;


    ///Testando para N=50.000 -> ENCADEAMENTO SEPARADO
    HashEncad * hashHashEncad50000 = new HashEncad(50000);
    for(int i=0;i<50000;i++)
    {
        hashHashEncad50000->inserir(vetor50000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=50.000): "<<hashHashEncad50000->getNumColisoes()<<endl;
    delete hashHashEncad50000;


    ///Testando para N=100.000 -> ENCADEAMENTO SEPARADO
    HashEncad * hashHashEncad100000 = new HashEncad(100000);
    for(int i=0;i<100000;i++)
    {
        hashHashEncad100000->inserir(vetor100000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=100.000): "<<hashHashEncad100000->getNumColisoes()<<endl;
    delete hashHashEncad100000;


    ///Testando para N=500.000 -> ENCADEAMENTO SEPARADO
    HashEncad * hashHashEncad500000 = new HashEncad(500000);
    for(int i=0;i<500000;i++)
    {
        hashHashEncad500000->inserir(vetor500000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=500.000): "<<hashHashEncad500000->getNumColisoes()<<endl;
    delete hashHashEncad500000;


    ///  ---------------------------------------- FIM DOS TESTES PARA TRATAMENTO ENCADEAMENTO SEPARADO ---------------------------------------- ///
    cout<<"///  -------- FIM DOS TESTES PARA TRATAMENTO ENCADEAMENTO SEPARADO -------- ///"<<endl;


    cout<<endl;
    cout<<endl;
    cout<<endl;

    */

    ///  ---------------------------------------- INICIO DOS TESTES PARA TRATAMENTO QUADR햀ICA ---------------------------------------- ///
    cout<<"///  -------- INICIO DOS TESTES PARA TRATAMENTO QUADR햀ICA -------- ///"<<endl;


    ///Testando para N=1.000 -> Hash Linear
    HashInt * hashQuadratica1000 = new HashInt(1000,2);
    for(int i=0;i<1000;i++)
    {
        hashQuadratica1000->inserir(vetor1000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento Quadratica N=1.000): "<<hashQuadratica1000->getNumColisoes()<<endl;
    delete hashQuadratica1000;


    ///  ---------------------------------------- FIM DOS TESTES PARA TRATAMENTO QUADR햀ICA ---------------------------------------- ///
    cout<<"///  -------- FIM DOS TESTES PARA TRATAMENTO TRATAMENTO QUADR햀ICA -------- ///"<<endl;


    delete [] vetor1000;
    delete [] vetor5000;
    delete [] vetor10000;
    delete [] vetor50000;
    delete [] vetor100000;
    delete [] vetor500000;

    delete [] vetorDeDados;

}
