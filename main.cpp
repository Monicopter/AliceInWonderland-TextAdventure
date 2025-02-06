#include <iostream>
#include "Game.hpp"
#include "Locations.hpp"
#include "Actions.hpp"




int main()
{
    Game game;

    game.startGame();




    std::string userInput;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, userInput);
        
        // Pass input to game class for processing
        game.userInput(userInput);
        
        // Check for quit condition
        if (userInput == "quit") {
            break;
        }
    }

    

    return 0;
}