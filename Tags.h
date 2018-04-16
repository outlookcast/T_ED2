#include <iostream>
#include <list>
#ifndef TAGS_H_INCLUDED
#define TAGS_H_INCLUDED

using namespace std;

class Tags
{
private:
    int questionID;
    string tag;
    list<Tags> lista;

public:
    Tags();
    Tags(int questionID,string tag);
    ~Tags();
    int getQuestionID();
    string getTag();
    void setQuestionID(int questionID);
    void setTag(string tag);
    void inserirNaLista(Tags tag);
    void imprime();
    list<Tags> getLista();

};

#endif // TAGS_H_INCLUDED
