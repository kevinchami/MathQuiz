//345540496 Kevin Chami
#include "MathQuiz.h"

MathQuiz:: MathQuiz(int size, int min, int max){
    
    srand(time(NULL));
    
    if(size<=0){ // if the size is 0 or negative, will create 10 exercise by default 
        size=10;
    }

   generator = new ExGenerator(size, min, max); // create a new array of pointers which each pointer is an exercice 
   userAnswer = 0; // initialization
   correctAnswers = 0; // initialization

}



void MathQuiz:: startQuiz(){
    
    string textString; // the string where the text of the file will be saved 
    textString += "Results for the quiz:\n\n";
    
    cout<<"Welcome to the math quiz"<<endl;
    cout<<"You will get "<< generator->getNumOfEx() << " exercises" <<endl;
    
    while(generator->endOfEx() == false){ // while there are more exercises to show 
        
        Exercise* exerc = this->generator->next(); // the current exercise is saved in an object of Exercise type 
        
        if(exerc == NULL) // check that the exercise is not NULL
            break;
        
        
        cout<<exerc->toString(); // print to the user the current exercise
        // save the current exercise and answer into the string that will be in the file
        textString += exerc->toString(); 
        textString += to_string(exerc->eval()) + " ";

        cin>>userAnswer; // save the answer of the user 
        
        //check the user answer 
        if(userAnswer == exerc->eval()){
            cout<<"correct!"<<endl;
            this->correctAnswers++; 
        }else{
            cout<<"wrong!"<<endl;
        }
         textString+= "your answer " + to_string(userAnswer) + "\n"; // save this string for the file 
    }
    
     textString += "\nYou got " + to_string(this->correctAnswers) +
    " correct answers out of " + to_string(generator->getNumOfEx()) + " exercises."; // save this string for the file 
    
    cout<<"\nThe quiz has ended. You got " + to_string(this->correctAnswers) +
    " correct answers out of " + to_string(generator->getNumOfEx())<<endl;
    

    cout<<"\nDo you want to save the results? (press y or n)\n\n";
    char c;
    cin>>c; // receive the input of the user 
    string filePath;
    string fileName;
    if(c == 'y'){
        cout<<"Please enter the file path:";
        cin>>filePath; // save the file path where the user wants to create the file
        char last_char = filePath.back();  // if the last letter is not '\', i add it at the end of the fileName
        if (last_char != '\\'){
            filePath += "\\";
        }
        int randomNumber = 100 + rand() % 900; // 3 digits random number 
        fileName += filePath + "results" + to_string(randomNumber) + ".txt";
        saveFile(textString,fileName); // call the function to build the file 
        cout<<"Your results were saved in " + fileName + "\n Goodbye!"<<endl;
    }
    else{ 
        cout<<"Goodbye!"<<endl;
        return;
    }
}


void MathQuiz:: saveFile(string s, string filePath){
   std::ofstream file(filePath); // create the file using the filePath 
    file.write(s.c_str(), s.length()); // write into the file using the appropiate string and length 
    file.close(); // close the file 
}

MathQuiz::~MathQuiz()  //destructor 
{
    delete generator;
}




