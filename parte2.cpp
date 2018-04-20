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
#include "HashAnswer.h"
#include "HashTag.h"
#include "HashString.h"
#include "HashTagBusca.h"
#include "HashBuscaAnswer.h"


using namespace std;

void Parte2 ()
{
    cout<<"FREQUÊNCIA DE TAGS"<<endl;
    cout<<"Digite o valor de Tag para ler: "<<endl;
    int tam;
    cin>>tam;
    HashBuscaAnswer * hash = new HashBuscaAnswer(1387272);
    HashAnswer * hashLeitura = new HashAnswer(tam*9);
    Answer * anser = readFile3();
    Data * aux = readFile();
    Data * data = vetorRandomData(tam,aux);

    for(int i=0; i<987272; i++)
        hash->insere(anser[i]);

    for(int i=0; i<tam; i++)
    {
        int questId = data[i].getQuestionID();
        list<int> listaQuestion = hash->busca(questId);
        for (list<int>::iterator i = listaQuestion.begin(); i != listaQuestion.end(); ++i)
        {
            Answer ans;
            ans.setQuestionID(questId);
            ans.setUserID(*i);
            hashLeitura->inserir(ans);
        }
    }

    hashLeitura->frequenciaDeTodosUsuarios();

    delete hashLeitura;
    delete [] data;
    delete [] anser;
    delete hash;
    cout<<"PARTE FREQUÊNCIA DE USUÁRIOS"<<endl;
    cout<<"Digite o numero de Answer a ler: "<<endl;
    cin>>tam;
    Tags * arrayDeTags = leituraParte2();
    HashTagBusca * hashBusca = new HashTagBusca(2985079);
    HashTag * frequencia = new HashTag(tam*9);
    for(int i=0; i<1885079-1; i++)
        hashBusca->insere(arrayDeTags[i]);
    Data * data2 = vetorRandomData(tam,aux);
    int questId = data2[0].getQuestionID();

    for(int i=0; i<tam; i++)
    {   questId = data2[i].getQuestionID();
        list<string> lista = hashBusca->busca(questId);
        for (list<string>::iterator i = lista.begin(); i != lista.end(); ++i)
        {
            Tags tagAux(questId,*i);
            frequencia->inserir(tagAux);
        }
    }

    frequencia->frequenciaDeTodasTags();



    delete [] data2;
    delete [] aux;
    delete [] arrayDeTags;
    delete frequencia;
    delete hashBusca;
}























