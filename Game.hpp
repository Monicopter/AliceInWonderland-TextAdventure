#pragma once

#include <iostream>
//#include <fstream>
// #include <string>
#include <vector>
#include "Locations.hpp"
// #include "Items.hpp"
// #include "Characters.hpp"
// #include "Inventory.hpp"
#include "Actions.hpp"

class Location;
// class Item;
// class Character;
//class Inventory;
//class Action;

class Game
{
private:

    Location* currentLocation;  //Pointer to the player's current location
    //Inventory inventory;    //player's current inventory
    //Action action; //manages player input
    std::vector<Location> locations; //all in game location cells
    void loadLocationsFromFile();
    void move(Direction direction); //moves player to a new location - dependent on player direction input

    //std::vector<Item> items; //all ingame items
    //std::vector<Character> characters; //Game characters (incl. player char Alice)


    //void loadItemsFromFile();
   // void loadCharactersFromFile();


public:

    Game();
    ~Game();

    void startGame();      //public method to start the game
    //void update();  //updates game state such as moving locations, picking item up, etc.
    //void display(); //displays current game state like location, items, etc.
    void loadGameData(); //calls loading functions for all txt file assets
    //void loadCharacters(); //Loads characters from txt file
    void loadLocations(); //loads locations from txt file
    //void loadItems(); //Loads items from txt file
    //void loadActions(); //Loads actions from txt file
    //void handleAction(const std::string& action); //handles various ingame actions
    //const std::vector<Location>& getLocations() const; //for getting locations, etc.
    void playerInput(const std::string &input);     //handles player input

};