#include <iostream>
#include "Game.hpp"
#include "Locations.hpp"
#include "Actions.hpp"




int main()
{
    Game game;

    game.startGame();

    std::string userCommand;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, userCommand);
        // Pass input to game class object userInput method
        game.userInput(userCommand);

    }

    return 0;
}