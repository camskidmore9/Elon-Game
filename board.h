#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "player.h"
#include "elon.h"

using namespace std;





class gameBoard{
  private:

    //Vector of vectors for the two board. One invisible that holds the locations and one that is displayed to the board
    vector <vector<char>> invBoard;
    vector <vector<char>> visBoard;

    //Vectors for the location of the items. These might not be used
    vector <int> pinto;
    vector <int> tesla;
    vector <int> yugo;
    vector <int> user;
    vector <int> Elon;

    //This integar is the row of whatever item is being edited at the moment. Changes a lot
    int cRow;
    int cCol;

    //Integers that store the X & Y coordinates of all items
    int pintoX;
    int pintoY;
    int teslaX;
    int teslaY;
    int yugoX;
    int yugoY;
    int userX;
    int userY;
    int ElonX;
    int ElonY;

    bool isCar;
    bool status;
    char whatCar;
    int wrongCar;

  public:

      //DEFAULT CONSTRUCTOR
      gameBoard();

      //Creates the user
      player User;

      //Creates the Elon
      elon MuskMan;

      //Updates the location of Elon
      void updateElon(int, int);

      //Updates the location of the player
      void updatePlayer();

      //Prints the current visboard
      void printBoard(vector <char>);

      //Prints the current invisible board
      void printInvBoard();
      
      //Generates random location that isn't taken by one of the other items
      int genLoc( int&);

      //Prints the current board
      void printBoard();

      //Returns the players location to main
      vector <int> getUserLocation();

      //Checks the area around the user and shows them what is there
      void checkArea();

      //Resets the visible board
      void visReset();

      void spaceCheck(int, int);

      //updates elons place in the board if he's awake
      void updateElon();

      //rules and story output
      void StoryAndRules();

      //Outputs the status of the game. If true, game continues. If false, ends the gane
      bool Gamestatus();

      //Activates when the user encounters a car. Will wake Elon or allow them to win the game
      void vroomvroomQuestion();

      //Timer for int seconds
      void timer(int);
};

#endif // TEST_H
