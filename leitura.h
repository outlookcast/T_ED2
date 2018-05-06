#include <fstream>
#include "Data.h"
#include "answer.h"

using namespace std;
Data* readFile();
Data* vetorRandomData(int tam, Data *aux);
int* vetorRandomInt(int tam, Data *aux);
Answer* readFile3(); //lê o arquivo
Answer* randomReadAux(int tam, Answer *aux); //retorna um vetor aleatório
Answer* randomRead(int tam); // lê o arquivo e retorna vetor aleatório não repetidos
void PT1_Cenario_4();
