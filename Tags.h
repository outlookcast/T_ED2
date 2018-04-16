#include <iostream>
#include <vector>
#ifndef TAGS_H_INCLUDED
#define TAGS_H_INCLUDED

using namespace std;

class Tags
{
private:
    int questionID;
    string tag;
    vector<Tags> lista;

public:
    Tags();
    Tags(int questionID,string tag);
    ~Tags();
    int getQuestionID();
    string getTag();
    void setQuestionID(int questionID);
    void setTag(string tag);

};

#endif // TAGS_H_INCLUDED
