#include <fstream>
#include "Data.h"
#include "Tags.h"
#include "answer.h"

using namespace std;
Data* readFile();
Tags* leituraParte2();
Data* vetorRandomData(int tam, Data *aux);
int* vetorRandomInt(int tam, Data *aux);
Tags * leituraRandomParte2(int num); // retorna N Tags random n�o repetidas
Answer* readFile3(); //l� o arquivo
Answer* randomReadAux(int tam, Answer *aux); //retorna um vetor aleat�rio
Answer* randomRead(int tam); // l� o arquivo e retorna vetor aleat�rio n�o repetidos
