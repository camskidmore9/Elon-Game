#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

//Creates the class of player
class player{

    private:

      //A copy of the boards that are stored for the user to access
      vector<vector <char>> iBoard;
      vector<vector <char>> vBoard;

  public:

      //DEFAULT CONSTRUCTOR
      player();

      //Stores the location of the player
      vector <int> location;

      //Also stores the coordinates of the player
      int uX;
      int uY;


      //Gets the direction the the player wants to move and changes their location in the vector
      void getDirection();

      //Updates the location of the player
      void updateLocation(int&, int&, int, int);

      //Returns the location vector
      vector <int> returnLocation();

      //Configures the invisible board for the player
      void setIboard(vector<vector <char>>);

      //Configures the visible board for the player
      void setVboard(vector<vector <char>>);

};

#endif // TEST_H
