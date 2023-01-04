//345540496 Kevin Chami
#ifndef EXGENERATOR_H
#define EXGENERATOR_H
#include "Exercise.h"


class ExGenerator{
    
    private:
    Exercise ** exercises;
    int numOfEx;
    int current;
    
    public:
    ExGenerator(int size = 10, int min = 0, int max = 10);
    int getNumOfEx() const;
    int getCurrent() const;
    Exercise* next();
    bool endOfEx() const;
    ~ExGenerator(); // destructor 
};

#endif