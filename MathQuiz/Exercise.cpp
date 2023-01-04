//345540496 Kevin Chami
#include "Exercise.h"

Exercise::Exercise(int min, int max){

    if(min > max){ // if the values are incorrect, initializate them by default 
        this->minValue = 0;
        this->maxValue = 10;
    }
    else{
        this->maxValue = max;
        this->minValue = min;
    }
    
    this->leftOperand = rand() % (maxValue - minValue + 1) + minValue; // random numbers for the exercise 
    this->rightOperand = rand() % (maxValue - minValue + 1) + minValue;
    this->op = rand() % 2 + 1;
}

int Exercise::eval(){
    
    int result;
    
    if(op == 2){ // sub
        result = leftOperand - rightOperand;
    } 
    else{ // op == 1 --> sum 
        result = leftOperand + rightOperand;
    }
    return result;
}

string Exercise::toString(){
    
    string siman; // print the exercise 
    if(op == 1){
        siman = " + ";
    }
    else{
        siman = " - ";
    }
    
    return to_string(leftOperand) + siman  + to_string(rightOperand) + " = "; 
    
    
}


