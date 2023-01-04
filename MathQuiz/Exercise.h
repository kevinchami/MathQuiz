//345540496 Kevin Chami
#ifndef EXERCISE_H
#define EXERCISE_H

#include <iostream>
#include <random>
using namespace std;

class Exercise {
    
    public:
    int leftOperand;
    int rightOperand;
    int op;
    int maxValue;
    int minValue;
    
    public:
        Exercise(int min = 0, int max = 10);
        int eval();
        string toString();
};

#endif