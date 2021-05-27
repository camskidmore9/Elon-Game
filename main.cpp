/*
 * THIS ASSIGNMENT IS A COLLABORATION BETWEEN CAMERON SKIDMORE AND LYDIA WACHTMAN
 *
 *
 *
 */

#include <iostream>
#include <ctime>
#include<bits/stdc++.h>

#include "board.h"
#include "player.h"
#include "elon.h"
using namespace std;



int main()
{
    gameBoard setup;
    setup.StoryAndRules();


    bool play = true;
    while(play){
        string doPlay;
        locale loc;
        cout << "Would you like to play? (y/n)" << endl;
        cin >> doPlay;
        transform(doPlay.begin(), doPlay.end(), doPlay.begin(), ::tolower);
        if((doPlay == "y") || (doPlay == "yes")){
            bool wePlayin = true;
            gameBoard currentGame;
            currentGame.printBoard();
            cout << endl;
            while(wePlayin){

                currentGame.User.getDirection();

                currentGame.updatePlayer();

                currentGame.printBoard();
                cout << endl;
                currentGame.vroomvroomQuestion();
                cout << endl << endl << endl;

                wePlayin = currentGame.Gamestatus();
            }
        }
        else{
            cout << "Well you should but that's just my opionion. Have a good day" << endl;
            play = false;
        }
    }
    return(0);
}











//Nice
