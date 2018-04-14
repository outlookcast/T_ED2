#include <iostream>
#include <string>
#include "Tags.h"

using namespace std;

Tags::Tags()
{
    this->questionID = -1;
    this->tag = "-1";
}

Tags::Tags(int questionID,string tag)
{
    this->questionID = questionID;
    this->tag = tag;
}

Tags::~Tags(){}

int Tags::getQuestionID()
{
    return this->questionID;
}

string Tags::getTag()
{
    return this->tag;
}


void Tags::setQuestionID(int questionID)
{
    this->questionID = questionID;
}

void Tags::setTag(string tag)
{
    this->tag = tag;
}
