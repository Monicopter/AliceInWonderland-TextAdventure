#include <iostream>
#include "Game.hpp"
#include "Locations.hpp"
#include "Actions.hpp"




int main()
{
    Game game;

    game.startGame();

    game.userInput();

    return 0;
}