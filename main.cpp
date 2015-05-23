#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>


std::string placeMarker(bool playerOne, bool &movePending);

void displayBoard(std::string boardArray[3][3]);

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
                std::cout << "Choose where to put your marker: ";
                getline(std::cin, input);
                if(input == "TL") {
                    boardArray[0][0] = placeMarker(playerOneTurn, movePending);
                }
                else if(input == "TC") {
                    boardArray[0][1] = placeMarker(playerOneTurn, movePending);
                }
                else if(input == "TR") {
                    boardArray[0][2] = placeMarker(playerOneTurn, movePending);
                }
                else if(input == "CL") {
                    boardArray[1][0] = placeMarker(playerOneTurn, movePending);
                }
                else if(input == "CC") {
                    boardArray[1][1] = placeMarker(playerOneTurn, movePending);
                }
                else if(input == "CR") {
                    boardArray[1][2] = placeMarker(playerOneTurn, movePending);
                }
                else if(input == "BL") {
                    boardArray[2][0] = placeMarker(playerOneTurn, movePending);
                }
                else if(input == "BC") {
                    boardArray[2][1] = placeMarker(playerOneTurn, movePending);
                }
                else if(input == "BR") {
                    boardArray[2][2] = placeMarker(playerOneTurn, movePending);
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

std::string placeMarker(bool playerOne, bool &movePending) {
    movePending = false;
    if(playerOne) {
        return "x";
    }
    else {
        return "o";
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