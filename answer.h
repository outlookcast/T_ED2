#ifndef ANSWER_H
#define ANSWER_H
#include <iostream>
using namespace std;

class Answer
{
    public:
        Answer();
        virtual ~Answer();

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

    private:
        int answerID;
        int userID;
        string date;
        int questionID;
        int score;
};

#endif // ANSWER_H
