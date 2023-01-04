//345540496 Kevin Chami
#include "ExGenerator.h"

ExGenerator:: ExGenerator(int size, int min, int max){
    
    numOfEx = size;
    
    exercises = new Exercise*[numOfEx]; // create the array where will be exercises for the game 
    for (int i = 0; i < numOfEx; i++){ // initialize the exercises* array
        exercises[i] = new Exercise(min, max); // each pointer will be an exercise with min and max parameters 
    }
}

int ExGenerator::getNumOfEx() const {
    return numOfEx;
}

int ExGenerator::getCurrent() const{
    return current;
}

Exercise* ExGenerator:: next(){ // returns the exercise and increase the current one to the next one 
    
    int curValue = current;
    
    if(this->current == this->numOfEx){ // check that the next exercise actually exists 
        return NULL;
    }
    this->current++;
    return this->exercises[current-1];
}

bool ExGenerator::endOfEx() const{ // check if the exercises are over 
    if(current == this->numOfEx){
        return true;
    }
    return false;
}

ExGenerator:: ~ExGenerator(){ // delete first of all each index of the array, and then the whole array "exercises"
    for(int i = 0 ; i<numOfEx; i++){
        delete exercises[i];
    }
    delete[] exercises;
}