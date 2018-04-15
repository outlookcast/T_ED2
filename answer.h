#ifndef ANSWER_H
#define ANSWER_H
#include <iostream>
#include <vector>
using namespace std;

class Answer
{
    public:
        Answer();
        ~Answer();

        //sets
        void setAnswerID(int answerID);
        void setUserID(int userID);
        void setDate(string date);
        void setQuestionID(int questionID);
        void setScore(int score);

        //gets
        int getAnswerID();
        int getUserID();
        string getDate();
        int getQuestionID();
        int getScore();
        vector<Answer> getLista();

        void inserirNaLista(Answer answer);
        void imprime();

    private:
        int answerID;
        int userID;
        string date;
        int questionID;
        int score;
        vector<Answer> lista;
};

#endif // ANSWER_H
