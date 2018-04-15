#include "fstream"
#include "answer.h"
using namespace std;

Answer* readFile3(); //lê o arquivo
Answer* randomReadAux(int tam, Answer *aux); //retorna um vetor aleatório
Answer* randomRead(int tam); // lê o arquivo e retorna vetor aleatório
