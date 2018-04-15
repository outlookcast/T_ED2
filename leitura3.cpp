#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <stdlib.h>
#include "leitura3.h"
#include "answer.h"
using namespace std;

Answer* readFile3()
{
    int tam = 987272;
    Answer *answer = new Answer[tam];
    ifstream ip("Answers.csv");
    if(!ip.is_open())
    {
        std::cout << "ERROR: Could not open file" << endl;
        return answer;
    }
    else
    {
        cout<<"Reading file..."<<endl;
        string answerID;
        string userID;
        string date;
        string questionID;
        string score;
        string restOfLine;
        string trash;
        int c=0;
        int cont = 1;
        getline(ip,trash);
        int posicao = 0;

        while(ip.good() && c < tam)
        {
            if(cont == 1)
            {
                getline(ip,answerID,',');
                cont++;
            }
            else if(cont == 2)
            {
                getline(ip,userID,',');
                cont++;
            }
            else if(cont == 3)
            {
                getline(ip,date,',');
                cont++;
            }
            else if(cont == 4)
            {
                getline(ip,questionID,',');
                cont++;
            }
            else if(cont == 5)
            {
                getline(ip,score,',');
                cont++;
            }
            else if (cont == 6)
            {
                getline(ip,restOfLine,'\n');
                trash = restOfLine;
                int j = 0;
             //   cout<<answerID<<" "<<userID<<" "<<date<<" "<<questionID<<" "<<score<<endl;
                answer[posicao].setAnswerID(atoi(answerID.c_str()));
                answer[posicao].setUserID(atoi(userID.c_str()));
                answer[posicao].setDate(date);
                answer[posicao].setQuestionID(atoi(questionID.c_str()));
                answer[posicao].setScore(atoi(score.c_str()));
                while(true)
                {
                  //  cout<<trash[j];
                    if (trash[j]=='"' && trash[j+1]=='\0')
                        break;
                    else if (trash[j]=='"' && trash[j+1] == '"')
                    {
                        j++;
                    }
                    else if (trash[j]=='\0')
                    {
                        getline(ip,trash);
                        j = -1;
                    }
                    j++;
                }
                cont = 1;
                c += 1;
                posicao += 1;
            }
        }
        ip.close();
        cout<<"Fim da leitura"<<endl;
        return answer;
    }
}

Answer *randomReadAux(int num, Answer *answer)
{
    Answer *randomArray = new Answer[num];
    int j;
    int *vet = new int[987272];
    for (int i=0;i<987272;i++)
        vet[i]=-1;
    for (int i=0; i<num;)
    {
        j = rand() % 987272;
        if (vet[j] == -1)
        {
            randomArray[i].setAnswerID(answer[j].getAnswerID());
            randomArray[i].setDate(answer[j].getDate());
            randomArray[i].setQuestionID(answer[j].getQuestionID());
            randomArray[i].setScore(answer[j].getScore());
            randomArray[i].setUserID(answer[j].getUserID());
            i++;
            vet[j] == 0;
        }
    }
    delete [] vet;
    return randomArray;
}

Answer* randomRead(int num) //Retorna Answers aleatórias em um vetor de tamanho num
{
    Answer *answer = readFile3();
    Answer *answerAleatorio = randomReadAux(num, answer);
    delete []answer;
    return answerAleatorio;
}





















































