#include <fstream>
#include "Data.h"
#include "answer.h"

using namespace std;
Data* readFile();
Data* vetorRandomData(int tam, Data *aux);
int* vetorRandomInt(int tam, Data *aux);
Answer* readFile3(); //l� o arquivo
Answer* randomReadAux(int tam, Answer *aux); //retorna um vetor aleat�rio
Answer* randomRead(int tam); // l� o arquivo e retorna vetor aleat�rio n�o repetidos
void PT1_Cenario_4();
