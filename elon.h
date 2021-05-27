#ifndef ELON_H
#define ELON_H
#include <iostream>
using namespace std;

class elon{

    private:

        //A booleon for if Elon is awake or not
        bool isAwake;

        //The number of times the player has encountered Elon
        int timesSeen;

        //Elons coordinates
        int ElonX;
        int ElonY;

    public:

        //DEFAULT CONSTRUCTOR
        elon();

        //counts how many times elon has been spotted and wakes him up the first time
        //if not already awake
        void HeBeenSpotted();

        //returns if elon is awake
        bool awakeOrNah();

        //returns how many times elon has been seen
        int howManySpottings();



};

#endif // ELON_H
