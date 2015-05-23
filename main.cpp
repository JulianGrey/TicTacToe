#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>


void placeMarker(std::string &cell, bool playerOne, bool &movePending);

void displayBoard(std::string boardArray[3][3]);

void displayAvailablePositions(std::string boardArray[3][3]);

int main() {
    const int dimension = 3;
    std::string input;
    bool quit = false;
    bool playing = false;
    bool movePending = false;
    bool playerOneTurn = true;

    while(!quit) {
        playing = true;
        std::string boardArray[dimension][dimension] = {
            {" ", " ", " "},
            {" ", " ", " "},
            {" ", " ", " "}
        };

        std::cout << typeid(input).name() << '\n';
        std::cout << typeid(boardArray).name() << '\n';
        std::cout << typeid(boardArray[0][0]).name() << '\n';

        displayBoard(boardArray);

        while(playing) {
            if(playerOneTurn) {
                std::cout << "Player one turn\n";
            }
            else {
                std::cout << "Player two turn\n";
            }

            movePending = true;
            while(movePending) {
                std::cout << "Choose where to put your marker\n";
                displayAvailablePositions(boardArray);
                std::cout << "Selection: ";
                getline(std::cin, input);
                if(input == "TL") {
                    placeMarker(boardArray[0][0], playerOneTurn, movePending);
                }
                else if(input == "TC") {
                    placeMarker(boardArray[0][1], playerOneTurn, movePending);
                }
                else if(input == "TR") {
                    placeMarker(boardArray[0][2], playerOneTurn, movePending);
                }
                else if(input == "CL") {
                    placeMarker(boardArray[1][0], playerOneTurn, movePending);
                }
                else if(input == "C") {
                    placeMarker(boardArray[1][1], playerOneTurn, movePending);
                }
                else if(input == "CR") {
                    placeMarker(boardArray[1][2], playerOneTurn, movePending);
                }
                else if(input == "BL") {
                    placeMarker(boardArray[2][0], playerOneTurn, movePending);
                }
                else if(input == "BC") {
                    placeMarker(boardArray[2][1], playerOneTurn, movePending);
                }
                else if(input == "BR") {
                    placeMarker(boardArray[2][2], playerOneTurn, movePending);
                }
                else {
                    std::cout << "Invalid option\n";
                }
            }
            displayBoard(boardArray);
            if(playerOneTurn) {
                playerOneTurn = false;
            }
            else {
                playerOneTurn = true;
            }
        }
        // quit = true;
    }

    return 0;
}

void placeMarker(std::string &cell, bool playerOne, bool &movePending) {
    if(cell == " ") {
        movePending = false;
        if(playerOne) {
            cell = "x";
        }
        else {
            cell = "o";
        }
    }
    else {
        std::cout << "Position already filled, choose another position\n";
    }
}

void displayAvailablePositions(std::string boardArray[3][3]) {
    if(boardArray[0][0] == " ") {
        std::cout << "Top Left (TL)\n";
    }
    if(boardArray[0][1] == " ") {
        std::cout << "Top Centre (TC)\n";
    }
    if(boardArray[0][2] == " ") {
        std::cout << "Top Right (TR)\n";
    }
    if(boardArray[1][0] == " ") {
        std::cout << "Centre Left (CL)\n";
    }
    if(boardArray[1][1] == " ") {
        std::cout << "Centre (C)\n";
    }
    if(boardArray[1][2] == " ") {
        std::cout << "Centre Right (CR)\n";
    }
    if(boardArray[2][0] == " ") {
        std::cout << "Bottom Left (BL)\n";
    }
    if(boardArray[2][1] == " ") {
        std::cout << "Bottom Centre (BC)\n";
    }
    if(boardArray[2][2] == " ") {
        std::cout << "Bottom Right (BR)\n";
    }
}

void displayBoard(std::string boardArray[3][3]) {
    std::cout << '\n';
    std::cout << boardArray[0][0] << "|" << boardArray[0][1] << "|" << boardArray[0][2] << '\n';
    std::cout << "-+-+-\n";
    std::cout << boardArray[1][0] << "|" << boardArray[1][1] << "|" << boardArray[1][2] << '\n';
    std::cout << "-+-+-\n";
    std::cout << boardArray[2][0] << "|" << boardArray[2][1] << "|" << boardArray[2][2] << '\n';
    std::cout << '\n';
}