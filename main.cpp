#include <iostream>
#include "Game.hpp"
#include "Locations.hpp"




int main()
{
    Game game;

    game.startGame();

    std::string input;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);
        if (input == "quit") {
            break;
        }
        game.playerInput(input);
    }

    return 0;
}