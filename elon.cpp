//elon.cpp


#include "elon.h"

//DEFAULT CONSTRUCTOR
elon::elon()
{
    isAwake = false;
    timesSeen = 0;
}


/*--------------MEMBER FUNCTIONS------------*/


//Controls Elon's movements. If he is awake, he moves randomly. If not, he does nothing
void elon::HeBeenSpotted(){
    if (timesSeen == 0){
        isAwake = true;
        timesSeen += 1;
        cout << "Elon is Awake! Don't let him find you!" << endl;
    }
    else if (timesSeen == 1){
        timesSeen += 1;
        cout << "He's found you! If he finds you again or you get into" << endl;
        cout << "the wrong car you loose!" << endl;
    }
    else if (timesSeen == 2){
        cout << "Elon has caught you." << endl;
        cout << "GAME OVER" << endl;
    }
}

//Checks to see if Elon is awake
bool elon::awakeOrNah(){
    return isAwake;
}

//Returns the amount of times you have seen or been seen by Elon
int elon::howManySpottings(){
    return timesSeen;
}


/*--------------END OF MEMBER FUNCTIONS------------*/
