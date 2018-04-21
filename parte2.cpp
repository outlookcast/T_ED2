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
#include "quickSort1.h"

using namespace std;

void Parte2 ()
{
    cout<<"FREQUÊNCIA DE USUARIOS"<<endl;
    ofstream saidaT;
    saidaT.open("saidaUsers.txt");
    cout<<"Digite a quantidade de itens do QuestionsID que deseja ler: "<<endl;
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

    vector<FrequenciaTag> vetor = hashLeitura->frequenciaDeTodosUsuarios();

    FrequenciaTag * array = new FrequenciaTag[vetor.size()];
    FrequenciaTag * array2 = new FrequenciaTag[vetor.size()];
    int k = vetor.size() -1;
    for(int i=0;i<vetor.size();i++)
    {
        array[i].frequencia = vetor[i].frequencia;
        array[i].tag = vetor[i].tag;
    }
    quicksort(array,vetor.size());
    for(int i=0;i<vetor.size();i++)
    {
        array2[i].frequencia = array[k].frequencia;
        array2[i].tag = array[k].tag;
        k--;
    }

    for(int i=0;i<vetor.size();i++)
        saidaT<<array2[i].tag<<" "<<array2[i].frequencia<<endl;


    delete [] array;
    delete [] array2;
    delete hashLeitura;
    delete [] data;
    delete [] anser;
    delete hash;


    cout<<"PARTE FREQUÊNCIA DE TAGS"<<endl;
    ofstream saida;
    saida.open("saidaTags.txt");
    Tags * arrayDeTags = leituraParte2();
    HashTagBusca * hashBusca = new HashTagBusca(2985079);
    HashTag * frequencia = new HashTag(tam*9);
    for(int i=0; i<1885079-1; i++)
        hashBusca->insere(arrayDeTags[i]);
    Data * data2 = vetorRandomData(tam,aux);
    int questId = data2[0].getQuestionID();

    for(int i=0; i<tam; i++)
    {
        questId = data2[i].getQuestionID();
        list<string> lista = hashBusca->busca(questId);
        for (list<string>::iterator i = lista.begin(); i != lista.end(); ++i)
        {
            Tags tagAux(questId,*i);
            frequencia->inserir(tagAux);
        }
    }
    vector<FrequenciaTag> aux2 = frequencia->frequenciaDeTodasTags();
    FrequenciaTag * auxTag = new FrequenciaTag[aux2.size()];
    FrequenciaTag * auxTag2 = new FrequenciaTag[aux2.size()];
    int j = aux2.size()-1;
    ///Copiando do vector para o array
    for(int i=0; i<aux2.size(); i++)
    {
        auxTag[i].frequencia = aux2[i].frequencia;
        auxTag[i].tag = aux2[i].tag;
    }
    quicksort(auxTag, aux2.size());
    saida<<"Frequência de TAGS: ";
    saida<<endl;
    saida<<endl;
    for(int i=0;i<aux2.size();i++)
    {
        auxTag2[i].frequencia = auxTag[j].frequencia;
        auxTag2[i].tag = auxTag[j].tag;
        j--;
    }
    for(int i=0;i<aux2.size();i++)
        saida<<auxTag2[i].tag<<" "<<auxTag2[i].frequencia<<endl;
    saida.close();
    delete [] auxTag2;
    delete [] data2;
    delete [] auxTag;
    delete [] arrayDeTags;
    delete frequencia;
    delete hashBusca;
}























