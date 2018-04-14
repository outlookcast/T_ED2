#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <stdlib.h>
#include "leitura3.h"
#include "answer.h"

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
        bool fim = false;
        getline(ip,trash);
        int i;
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
        cout<<"total: "<<c<<endl;
        cout<<answer[987272-1].getQuestionID();
        return answer;
    }
}


























































