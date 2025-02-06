#pragma once

#include <iostream>
//#include <fstream>
// #include <string>
#include <vector>


#include "Locations.hpp"
#include "Actions.hpp"
#include "Items.hpp"
// #include "Characters.hpp"
// #include "Inventory.hpp"


class Game
{
private:

    Location* currentLocation;              //Pointer to the player's current location

    std::vector<Location> locations;        //all in game location cells
    std::vector<Item> items;                //all ingame items vector
    //std::vector<Character> characters;    //Game characters (incl. player char Alice)


public:

    Game();
    ~Game();

    void startGame();                       //public method to start the game
    void loadGameData();                    //calls loading functions for all txt file assets
    void loadLocations();                   //loads locations from txt file
    //void loadActions();                   //Loads actions from txt file
    void loadItems();                       //Loads items from txt file
    //void loadCharacters();                //Loads characters from txt file
    //void loadInventory();                 //Loads inventory from txt file
    void move(Direction direction);         //moves player to a new location
    void userInput(const std::string &input);                //handles player input
    void playerDirectionalInput(const std::string &input);   //handles player directional input
    void printHelp() const;                 //prints help menu
    //void update();                        //updates game state such as moving locations, picking item up, etc.
    //void display();                       //displays current game state like location, items, etc.
    void printTextFile(const std::string& filename) const;


};