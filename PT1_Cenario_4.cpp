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
#include "HashCoalescido.h"

using namespace std;

void PT1_Cenario_4()
{

    Data * vetorDeDados = readFile();
    Data * vetor1000 =  vetorRandomData(1000, vetorDeDados); ///Tamanho da Hash = 10.909
    Data * vetor5000 = vetorRandomData(5000, vetorDeDados); ///Tamanho da Hash = 50.227
    Data * vetor10000 = vetorRandomData(10000, vetorDeDados); ///Tamanho da Hash = 102.643
    Data * vetor50000 = vetorRandomData(50000, vetorDeDados); ///Tamanho da Hash = 508.727
    Data * vetor100000 = vetorRandomData(100000, vetorDeDados); ///Tamanho da Hash = 1.002.553
    Data * vetor500000 = vetorRandomData(500000, vetorDeDados); ///Tamanho da Hash = 5.028.733

    int H1k = 10909;
    int H5k = 50227;
    int H10k = 102643;
    int H50k = 508727;
    int H100k = 1002553;
    int H500k = 5028733;



    ///  ---------------------------------------- INICIO DOS TESTES PARA TRATAMENTO LINEAR ---------------------------------------- ///
    cout<<"///  -------- INICIO DOS TESTES PARA TRATAMENTO LINEAR -------- ///"<<endl;

    ///Testando para N=1.000 -> Hash Linear
    HashInt * hashLinear1000 = new HashInt(H1k,1);
    for(int i=0;i<1000;i++)
    {
        hashLinear1000->inserir(vetor1000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=1.000): "<<hashLinear1000->getNumColisoes()<<endl;
    delete hashLinear1000;

    ///Testando para N=5.000 -> Hash Linear
    HashInt * hashLinear5000 = new HashInt(H5k,1);
    for(int i=0;i<5000;i++)
    {
        hashLinear5000->inserir(vetor5000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=5.000): "<<hashLinear5000->getNumColisoes()<<endl;
    delete hashLinear5000;

    ///Testando para N=10.000 -> Hash Linear
    HashInt * hashLinear10000 = new HashInt(H10k,1);
    for(int i=0;i<10000;i++)
    {
        hashLinear10000->inserir(vetor10000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=10.000): "<<hashLinear10000->getNumColisoes()<<endl;
    delete hashLinear10000;

    ///Testando para N=50.000 -> Hash Linear
    HashInt * hashLinear50000 = new HashInt(H50k,1);
    for(int i=0;i<50000;i++)
    {
        hashLinear50000->inserir(vetor50000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=50.000): "<<hashLinear50000->getNumColisoes()<<endl;
    delete hashLinear50000;

    ///Testando para N=100.000 -> Hash Linear
    HashInt * hashLinear100000 = new HashInt(H100k,1);
    for(int i=0;i<100000;i++)
    {
        hashLinear100000->inserir(vetor100000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=100.000): "<<hashLinear100000->getNumColisoes()<<endl;
    delete hashLinear100000;

    ///Testando para N=500.000 -> Hash Linear
    HashInt * hashLinear500000 = new HashInt(H500k,1);
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
    HashEncad * hashHashEncad1000 = new HashEncad(H1k);
    for(int i=0;i<1000;i++)
    {
        hashHashEncad1000->inserir(vetor1000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=1.000): "<<hashHashEncad1000->getNumColisoes()<<endl;
    delete hashHashEncad1000;


    ///Testando para N=5.000 -> ENCADEAMENTO SEPARADO
    HashEncad * hashHashEncad5000 = new HashEncad(H5k);
    for(int i=0;i<5000;i++)
    {
        hashHashEncad5000->inserir(vetor5000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=5.000): "<<hashHashEncad5000->getNumColisoes()<<endl;
    delete hashHashEncad5000;


    ///Testando para N=10.000 -> ENCADEAMENTO SEPARADO
    HashEncad * hashHashEncad10000 = new HashEncad(H10k);
    for(int i=0;i<10000;i++)
    {
        hashHashEncad10000->inserir(vetor10000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=10.000): "<<hashHashEncad10000->getNumColisoes()<<endl;
    delete hashHashEncad10000;


    ///Testando para N=50.000 -> ENCADEAMENTO SEPARADO
    HashEncad * hashHashEncad50000 = new HashEncad(H50k);
    for(int i=0;i<50000;i++)
    {
        hashHashEncad50000->inserir(vetor50000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=50.000): "<<hashHashEncad50000->getNumColisoes()<<endl;
    delete hashHashEncad50000;


    ///Testando para N=100.000 -> ENCADEAMENTO SEPARADO
    HashEncad * hashHashEncad100000 = new HashEncad(H100k);
    for(int i=0;i<100000;i++)
    {
        hashHashEncad100000->inserir(vetor100000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento linear N=100.000): "<<hashHashEncad100000->getNumColisoes()<<endl;
    delete hashHashEncad100000;


    ///Testando para N=500.000 -> ENCADEAMENTO SEPARADO
    HashEncad * hashHashEncad500000 = new HashEncad(H500k);
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


    ///  ---------------------------------------- INICIO DOS TESTES PARA TRATAMENTO QUADR햀ICO ---------------------------------------- ///
    cout<<"///  -------- INICIO DOS TESTES PARA TRATAMENTO QUADR햀ICO -------- ///"<<endl;

    ///Testando para N=1.000 -> Hash Quadratico
    HashInt * hashQuadratico1000 = new HashInt(1100,2);
    for(int i=0;i<1000;i++)
    {
        hashQuadratico1000->inserir(vetor1000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento Quadratico N=1.000): "<<hashQuadratico1000->getNumColisoes()<<endl;
    delete hashQuadratico1000;


    ///  ---------------------------------------- INICIO DOS TESTES PARA TRATAMENTO QUADR햀ICO ---------------------------------------- ///
    cout<<"///  -------- INICIO DOS TESTES PARA TRATAMENTO QUADR햀ICO -------- ///"<<endl;

    cout<<endl;
    cout<<endl;
    cout<<endl;


/*
    ///  ---------------------------------------- INICIO DOS TESTES PARA TRATAMENTO COALESCIDO ---------------------------------------- ///
    cout<<"///  -------- INICIO DOS TESTES PARA TRATAMENTO COALESCIDO -------- ///"<<endl;


    ///Testando para N=1.000 -> Hash Coalescidos
    HashCoalescido * hashCoalescido1000 = new HashCoalescido(H1k);
    for(int i=0;i<1000;i++)
    {
        hashCoalescido1000->adicionaElemento(vetor1000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento Quadratica N=1.000): "<<hashCoalescido1000->getNumColisoes()<<endl;
    delete hashCoalescido1000;


    ///Testando para N=5.000 -> Hash Coalescidos
    HashCoalescido * hashCoalescido5000 = new HashCoalescido(H5k);
    for(int i=0;i<5000;i++)
    {
        hashCoalescido5000->adicionaElemento(vetor5000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento Quadratica N=5.000): "<<hashCoalescido5000->getNumColisoes()<<endl;
    delete hashCoalescido5000;


    ///Testando para N=10.000 -> Hash Coalescidos
    HashCoalescido * hashCoalescido10000 = new HashCoalescido(H10k);
    for(int i=0;i<10000;i++)
    {
        hashCoalescido10000->adicionaElemento(vetor10000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento Quadratica N=10.000): "<<hashCoalescido10000->getNumColisoes()<<endl;
    delete hashCoalescido10000;


    ///Testando para N=50.000 -> Hash Coalescidos
    HashCoalescido * hashCoalescido50000 = new HashCoalescido(H50k);
    for(int i=0;i<50000;i++)
    {
        hashCoalescido50000->adicionaElemento(vetor50000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento Quadratica N=50.000): "<<hashCoalescido50000->getNumColisoes()<<endl;
    delete hashCoalescido50000;


    ///Testando para N=100.000 -> Hash Coalescidos
    HashCoalescido * hashCoalescido100000 = new HashCoalescido(H100k);
    for(int i=0;i<100000;i++)
    {
        hashCoalescido100000->adicionaElemento(vetor100000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento Quadratica N=100.000): "<<hashCoalescido100000->getNumColisoes()<<endl;
    delete hashCoalescido100000;


    ///Testando para N=500.000 -> Hash Coalescidos
    HashCoalescido * hashCoalescido500000 = new HashCoalescido(H500k);
    for(int i=0;i<500000;i++)
    {
        hashCoalescido500000->adicionaElemento(vetor500000[i].getQuestionID());
    }
    cout<<"Numero de colisoes (Tratamento Quadratica N=500.000): "<<hashCoalescido500000->getNumColisoes()<<endl;
    delete hashCoalescido500000;

    ///  ---------------------------------------- FIM DOS TESTES PARA TRATAMENTO COALESCIDO ---------------------------------------- ///
    cout<<"///  -------- FIM DOS TESTES PARA TRATAMENTO TRATAMENTO COALESCIDO -------- ///"<<endl;
*/

    delete [] vetor1000;
    delete [] vetor5000;
    delete [] vetor10000;
    delete [] vetor50000;
    delete [] vetor100000;
    delete [] vetor500000;

    delete [] vetorDeDados;

}
