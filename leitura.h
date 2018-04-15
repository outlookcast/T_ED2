#include <fstream>
#include "Data.h"
#include "Tags.h"
#include "answer.h"

using namespace std;
Data* readFile();
Tags* leituraParte2();
Data* vetorRandomData(int tam, Data *aux);
int* vetorRandomInt(int tam, Data *aux);
Tags * leituraRandomParte2(int num); // retorna N Tags random não repetidas
Answer* readFile3(); //lê o arquivo
Answer* randomReadAux(int tam, Answer *aux); //retorna um vetor aleatório
Answer* randomRead(int tam); // lê o arquivo e retorna vetor aleatório não repetidos
