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
#include "HashEncad.h"
#include "Tags.h"

using namespace std;

Tags * leituraParte2()
{
    Tags * dados = new Tags[1885079];
    ifstream ip("Tags.csv");
    if(!ip.is_open())
    {
        std::cout << "ERROR: Could not open file" << endl;
    }
    else
    {
        cout<<"Reading file..."<<endl;
        string trash; ///String para armazenar string que nao usaremos
        string QuestionID;
        string Tag;
        getline(ip,trash); /// Ignora primeira linha do arquivo
        int cont = 1;
        int contadorDeLinhas = 0;
        while(ip.good())
        {
            if(cont == 1)
            {
                getline(ip,QuestionID,',');
                contadorDeLinhas++;
                cont++;
            }
            else if(cont == 2)
            {
                getline(ip,Tag,'\n');
                cont = 1;
            }
            dados[contadorDeLinhas].setQuestionID(atoi(QuestionID.c_str()));
            dados[contadorDeLinhas].setTag(Tag);
        }
        ip.close();
        cout<<"Numero de linhas: "<<contadorDeLinhas<<endl;
        return dados;
    }
}
