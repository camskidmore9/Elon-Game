#include "board.h"
#include <windows.h>



//DEFAULT CONSTRUCTOR
gameBoard::gameBoard(){
    //Invisible Board. Holds the locations of the items
    Elon = {0,0};
    yugo = {0,0};
    pinto = {0,0};
    tesla = {0,0};
    user = {0,0};

    invBoard = {{'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}};

    //Visible to the user. Shows the area around the user
    visBoard = {{'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}};

    //Sets the boards stored in the user as the starting two boards
    User.setIboard(invBoard);
    User.setVboard(visBoard);


    /*----------This section generates starting locations for all entities and saves them to the invisible board-------------*/
    //Elon
    cCol = genLoc(cRow);
    invBoard[cRow][cCol] = 'E';
    ElonX = cRow;
    ElonY = cCol;
    Elon.at(0) = cRow;
    Elon.at(1) = cCol;

    //Yugo
    cCol = genLoc(cRow);
    invBoard[cRow][cCol] = 'Y';
    yugoX = cRow;
    yugoY = cCol;
    yugo.at(0) = cRow;
    yugo.at(1) = cCol;

    //Pinto
    cCol = genLoc(cRow);
    invBoard[cRow][cCol] = 'P';
    pintoX = cRow;
    pintoY = cCol;
    pinto.at(0) = cRow;
    pinto.at(1) = cCol;

    //Roadster
    cCol = genLoc(cRow);
    invBoard[cRow][cCol] = 'T';
    teslaX = cRow;
    teslaY = cCol;
    tesla.at(0) = cRow;
    tesla.at(1) = cCol;

    //User. Also stores the location in the visible board
    cCol = genLoc(cRow);
    invBoard[cRow][cCol] = '@';
    visBoard[cRow][cCol] = '@';
    userX = cRow;
    userY = cCol;
    user.at(0) = cRow;
    user.at(1) = cCol;
    User.location = {userX, userY};

    User.uX = userX;
    User.uY = userY;

    status = true;
    wrongCar = 0;
    isCar = false;


/*----------End of generating functions-------------*/
}


/*--------------MEMBER FUNCTIONS------------*/


//Function to generate the location for entities
int gameBoard::genLoc(int &compRow){
    srand (time(NULL));
    int compCol;
    compCol = rand() % 15;
    compRow = rand() % 15;
    while((invBoard[compRow][compCol] == 'E') || (invBoard[compRow][compCol] == 'T') || (invBoard[compRow][compCol] == 'P') || (invBoard[compRow][compCol] == 'Y') || (invBoard[compRow][compCol] == '@')){
        compCol = rand() % 15;
        compRow = rand() % 15;
    }
    return compCol;
}

//PRINTS THE CURRENT BOARD
void gameBoard::printBoard(){
    //system ("CLS");
    checkArea();
    for (int i = 0; i < 15; i++){
        for(int k = 0; k < 15; k++){
            cout << visBoard[i][k] << " \n"[k == 14];
        }
    }
}

//PRINTS THE CURRENT INV BOARD
void gameBoard::printInvBoard(){
    checkArea();
    for (int i = 0; i < 15; i++){
        for(int k = 0; k < 15; k++){
            cout << invBoard[i][k] << " \n"[k == 14];
        }
    }
}

//RETURNS THE PLAYERS LOCATION TO MAIN
vector <int> gameBoard::getUserLocation(){
    return(user);
}

//Checks the area around the user and updates the visible area
void gameBoard::checkArea(){
    visReset();
    int front = userX + 1;
    int back = userX - 1;
    int left = userY - 1;
    int right = userY + 1;

    if(front > 14){
        //Checks space to the left
        spaceCheck(userX, left);

        //Checks space behind and left
        spaceCheck(back, left);

        //Checks space behind
        spaceCheck(back, userY);

        //Checks space behind and right
        spaceCheck(back, right);

        //Checks space to right
        spaceCheck(userX, right);
    }
    else if(back < 0){
        //Checks space in front
        spaceCheck(front, userY);

        //Checks space front and to the left
        spaceCheck(front, left);

        //Checks space to the left
        spaceCheck(userX, left);

        //Checks space to right
        spaceCheck(userX, right);

        //Checks space front and to the right
        spaceCheck(front, right);
    }
    else{
        //Checks space in front
        spaceCheck(front, userY);

        //Checks space front and to the left
        spaceCheck(front, left);

        //Checks space to the left
        spaceCheck(userX, left);

        //Checks space behind and left
        spaceCheck(back, left);

        //Checks space behind
        spaceCheck(back, userY);

        //Checks space behind and right
        spaceCheck(back, right);

        //Checks space to right
        spaceCheck(userX, right);

        //Checks space front and to the right
        spaceCheck(front, right);
    }
}

//Resets the visible board
void gameBoard::visReset(){
    for (int i = 0; i < 15; i++){
        for(int k = 0; k < 15; k++){
            if((visBoard[i][k] == 'E') || (visBoard[i][k] == 'C') || (visBoard[i][k] == ' ') || (visBoard[i][k] == '~')){
                visBoard[i][k] = 'X';
            }
        }
    }
}

//Checks a single space. Called in areaCheck a bunch of times
void gameBoard::spaceCheck(int X, int Y){

    if(invBoard[X][Y] == 'X'){
        visBoard[X][Y] = ' ';
    }
    else if((invBoard[X][Y] == 'T') || (invBoard[X][Y] == 'P') || (invBoard[X][Y] == 'Y')){
        visBoard[X][Y] = 'C';
        isCar = true;
        if(invBoard[X][Y] == 'T'){
            whatCar = 'T';
        }
        else if(invBoard[X][Y] == 'P'){
            whatCar = 'P';
        }
        else if(invBoard[X][Y] == 'Y'){
            whatCar = 'Y';
        }
        else{
            whatCar = ' ';
        }

    }
    else if(invBoard[X][Y] == 'E'){
        visBoard[X][Y] = 'E';
        MuskMan.HeBeenSpotted();
    }
    else{
        visBoard[X][Y] = '~';
    }
}

//Updates the location of the player
void gameBoard::updatePlayer(){

    //Resets the users old position to X
    invBoard[userX][userY] = 'X';
    visBoard[userX][userY] = 'X';

    vector <int> newLoc;
    newLoc = User.returnLocation();

    user.at(0) = newLoc.at(0);
    userX = newLoc.at(0);

    user.at(1) = newLoc.at(1);
    userY = newLoc.at(1);

    //Updates the users location in the boards
    invBoard[userX][userY] = '@';
    visBoard[userX][userY] = '@';

    User.setIboard(invBoard);
    User.setVboard(visBoard);

    User.uX = userX;
    User.uY = userY;

    updateElon();
}

//Updates the information for Elon
void gameBoard::updateElon(){
    if(MuskMan.awakeOrNah()){
        //Resets the Elon's old position to X
        invBoard[ElonX][ElonY] = 'X';
        visBoard[ElonX][ElonY] = 'X';

        //makes new random location for elon
        ElonY = genLoc(ElonX);

        Elon.at(0) = ElonX;
        Elon.at(1) = ElonY;

        //updates elon location on boards
        invBoard[ElonX][ElonY] = 'E';
    }

}

//Checks the status of the game to stop the loop in main
bool gameBoard::Gamestatus(){
    if(MuskMan.howManySpottings() == 3){
        status = false;
    }
    return status;
}

//Checks if the user wants to get in the car
void gameBoard::vroomvroomQuestion(){
    string vroom;
    if(isCar == true){
        cout << "Enter the car? (y/n)" << endl;
        cin >> vroom;
        if((vroom == "y") || (vroom == "yes") || (vroom == "Y")){
            if(whatCar == 'T'){
                cout << "You have found the Roadster!" << endl;
                cout << "CONGRATS YOU WON!!!!" << endl;
                status = false;
            }
            else if(whatCar == 'P' || whatCar == 'Y'){
                wrongCar += 1;
                if(wrongCar == 1){
                    cout << "Oops that not the Roadster";
                    if(whatCar == 'P'){
                        cout << ", that's the Pinto\n"
                            "If you enter the wrong car again you will loose." << endl <<
                            "Choose wisely." << endl;
                    }
                    else if(whatCar == 'Y'){
                        cout << ", that's the Yugo\n"
                                "If you enter the wrong car again you will loose."
                                "Choose wisely." << endl;
                    }
                }
                else if(wrongCar == 2){
                    cout << "You have entered the wrong car.\n";
                    cout << "Again.\n";
                    cout << "You are now the Starman.\n";
                    cout << "Prepare for liftoff.\n";

                    timer(1);
                    cout << "5\n";
                    timer(1);
                    cout << "4\n";
                    timer(1);
                    cout << "3\n";
                    timer(1);
                    cout << "2\n";
                    timer(1);
                    cout << "1\n";
                    timer(1);


                    cout <<"  ______    ______   __       __  ________         ______   __     __  ________  _______  " << endl;
                    cout <<" /      \\  /      \\ |  \\     /  \\|        \\       /      \\ |  \\   |  \\|        \\|       \\ " << endl;
                    cout <<"|  $$$$$$\\|  $$$$$$\\| $$\\   /  $$| $$$$$$$$      |  $$$$$$\\| $$   | $$| $$$$$$$$| $$$$$$$\\" << endl;
                    cout <<"| $$ __\\$$| $$__| $$| $$$\\ /  $$$| $$__          | $$  | $$| $$   | $$| $$__    | $$__| $$" << endl;
                    cout <<"| $$|    \\| $$    $$| $$$$\\  $$$$| $$  \\         | $$  | $$ \\$$\\ /  $$| $$  \\   | $$    $$" << endl;
                    cout <<"| $$ \\$$$$| $$$$$$$$| $$\\$$ $$ $$| $$$$$         | $$  | $$  \\$$\\  $$ | $$$$$   | $$$$$$$\\" << endl;
                    cout <<"| $$__| $$| $$  | $$| $$ \\$$$| $$| $$_____       | $$__/ $$   \\$$ $$  | $$_____ | $$  | $$" << endl;
                    cout <<" \\$$    $$| $$  | $$| $$  \\$ | $$| $$     \\       \\$$    $$    \\$$$   | $$     \\| $$  | $$" << endl;
                    cout <<"  \\$$$$$$  \\$$   \\$$ \\$$      \\$$ \\$$$$$$$$        \\$$$$$$      \\$     \\$$$$$$$$ \\$$   \\$$" << endl;






                    status = false;
                }
            }
        }
    }
    isCar = false;
    whatCar = ' ';
}

//Prints the story and rules
void gameBoard::StoryAndRules(){
    cout << "Welcome to:" << endl;

    cout << " /$$$$$$$$                  /$$          " << endl;
    cout << "|__  $$__/                 | $$          " << endl;
    cout << "  | $$  /$$$$$$   /$$$$$$$| $$  /$$$$$$ " << endl;
    cout << "  | $$ /$$__  $$ /$$_____/| $$ |____  $$" << endl;
    cout << "  | $$| $$$$$$$$|  $$$$$$ | $$  /$$$$$$$" << endl;
    cout << "  | $$| $$_____/ \\____  $$| $$ /$$__  $$" << endl;
    cout << "  | $$|  $$$$$$$ /$$$$$$$/| $$|  $$$$$$$" << endl;
    cout << "  |__/ \\_______/|_______/ |__/ \\_______/" << endl << endl;

    cout << "------------------------------------------" << endl << endl;

    cout << "A game by Cameron Skidmore and Lydia Wachtman" << endl << endl;

    cout << "The Story:" << endl;
    cout << endl;
    cout << "You find your way to SpaceX the night before the Roadster is"
            "\n atop the rocket which is to send it into space. The building\n"
            " is dark and the roadster is hidden somewhere in large open dark\n"
            " room (15x15). In addition to the roadster, two other cars ae being"
            "\n stored in the facility as well. One is a Ford Pinto and the other"
            "is a Yugo" << endl;
    cout << endl;
    cout << "Elon Musk is also sleeping somewhere in the room and you must "
            "\navoid waking him while finding the roadster. Once awoken he will"
            "\n randomly move through the room looking for you." << endl;
    cout << endl;
    cout << endl;
    cout << "How it Works:" << endl;
    cout << endl;
    cout << "1. You are the @, the three cars are C, Elon is an E, "
            "darknes is X\n"
            "2. You move using WASD\n"
            "3. If there are two cars in your view, you must isolate it to one"
            "   before answering the question"
            "4. If you walk past sleeping Elon he wakes up\n"
            "5. If you get into the wrong car twice, you will loose and\n"
            "   become the 'Starman'\n"
            "6. Elon can find you once before you become the 'Starman'\n"
            "   Once you become the 'Starman', if Elon finds you agian\n"
            "   or you get into a car that isn't the roadster, you are\n"
            "   blasted into space with the roadster and you\n"
            "   loose the game.\n"
            "7. The only way to win is to get into the Roadster" << endl;
    cout << endl;
    cout << "There is also a hidden easter egg ;)" << endl;
    cout << endl;
    cout << endl;
}

//A timer for int seconds
void gameBoard::timer(int sec){
    Sleep(sec*1000);
}

/*--------------END MEMBER FUNCTIONS------------*/










//Nice
