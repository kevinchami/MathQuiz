//345540496 Kevin Chami
#ifndef MATHQUIZ_H
#define MATHQUIZ_H
#include "ExGenerator.h"
#include <fstream>


class MathQuiz{
    
    ExGenerator * generator;
    int userAnswer;
    int correctAnswers;
    void saveFile(string s, string filePath);
    
    public: 
    MathQuiz(int size = 10, int min = 0, int max = 10);
    void startQuiz();
    ~MathQuiz(); // destructor for generate 
};


#endif 
