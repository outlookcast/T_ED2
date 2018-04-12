#include <iostream>
#include "quickSort1.h"
#include "Data.h"

void quicksort(int *vetor, int inicio, int fim, int *comparacoes, int *numCopias)
{

    if(inicio == fim)
        return;

    int meio = (inicio + fim)/2;     // seleciona o pivo.
    swap(vetor[inicio], vetor[meio]);

    int pivo = vetor[inicio];

    int inferior = inicio + 1;
    int superior = fim;

    while(inferior <= superior)
    {

        while(vetor[inferior] < pivo)
        {
            inferior += 1;
            *comparacoes += 1;

        }
        *comparacoes += 1;

        while(vetor[superior] > pivo)
        {
            superior -= 1;
            *comparacoes += 1;
        }
        *comparacoes += 1;

        if(inferior < superior)
        {
            swap(vetor[inferior++], vetor[superior--]);
            *numCopias += 1;
        }
        else
            inferior += 1;
    }
    swap(vetor[inicio], vetor[superior]);
    *numCopias += 1;

    if(inicio <  superior - 1)
        quicksort(vetor, inicio, superior, comparacoes, numCopias);

    if(superior+1 < fim)
        quicksort(vetor, superior+1, fim, comparacoes, numCopias);


}

void quicksort(int *vetor, int n, int *comparacoes, int *numCopias)
{

    int maior = 0;

    // Acha o maior elemento
    for(int i = 1; i < n; ++i)
    {

        if(vetor[i] > vetor[maior])
        {
            maior = i;
            *comparacoes += 1;
        }
        *comparacoes += 1;
    }


    swap(vetor[maior], vetor[n-1]);//coloca o maior elemento no final do vetor.
    *numCopias +=1;
    quicksort(vetor, 0, n-2, comparacoes, numCopias);
}

void swap(int *valor1, int *valor2)
{

    int temp = *valor1;
    *valor1 = *valor2;
    *valor2 = temp;

}

void quicksort(Data *vetor, int inicio, int fim, int *comparacoes, int *numCopias)
{
    cout<<"Inicio quick\n";
    if(inicio == fim)
        return;

    int meio = (inicio + fim)/2;     // seleciona o pivo.
    swap(vetor[inicio], vetor[meio]);
    *numCopias += 1;
    int pivo = vetor[inicio].questionID;

    int inferior = inicio + 1;
    int superior = fim;

    while(inferior <= superior)
    {

        while(vetor[inferior].questionID < pivo)
        {
            inferior += 1;
            *comparacoes += 1;

        }
        *comparacoes += 1;

        while(vetor[superior].questionID > pivo)
        {
            superior -= 1;
            *comparacoes += 1;
        }
        *comparacoes += 1;

        if(inferior < superior)
        {
            swap(vetor[inferior++], vetor[superior--]);
            *numCopias += 1;
        }
        else
            inferior += 1;
    }
    swap(vetor[inicio], vetor[superior]);
    *numCopias += 1;

    if(inicio <  superior - 1)
        quicksort(vetor, inicio, superior, comparacoes, numCopias);

    if(superior+1 < fim)
        quicksort(vetor, superior+1, fim, comparacoes, numCopias);
}
void quicksort(Data *vetor, int n,  int *comparacoes, int *numCopias)
{
    int maior = 0;

    // Acha o maior elemento
    for(int i = 1; i < n; ++i)
    {

        if(vetor[i].questionID > vetor[maior].questionID)
        {
            maior = i;
            *comparacoes += 1;
        }
        *comparacoes += 1;
    }


    swap(vetor[maior], vetor[n-1]);//coloca o maior elemento no final do vetor.
    *numTrocas += 1;
    quicksort(vetor, 0, n-2, comparacoes, numCopias);
}
void swap(Data *valor1, Data *valor2)
{
    //Variaveis temporarias
    int questionID = valor1->questionID;
    int userID = valor1->userID;
    string date = valor1->date;
    int score = valor1->score;
    string title = valor1->title;

    //Copia de valor2 para valor1
    valor1->questionID = valor2->questionID;
    valor1->userID = valor2->userID;
    valor1->date = valor2->date;
    valor1->score = valor2->score;
    valor1->title = valor2->title;

    //copia de temp para valor1
    valor2->questionID = questionID;
    valor2->userID = userID;
    valor2->date = date;
    valor2->score = score;
    valor2->title = title;

}

