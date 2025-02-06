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
//class Action;     //Not needed as the action class in Action.hpp/cpp is an enum. Apparently enum class do not work the same way as normal classes and do not need to be forward declared.

class Game
{
private:

    Location* currentLocation;              //Pointer to the player's current location
    //Inventory inventory;                  //player's current inventory
    //Action action;                        //manages player input
    std::vector<Location> locations;        //all in game location cells


    //std::vector<Item> items;              //all ingame items
    //std::vector<Character> characters;    //Game characters (incl. player char Alice)


    //void loadItemsFromFile();
   // void loadCharactersFromFile();


public:

    Game();
    ~Game();

    void startGame();                       //public method to start the game
    //void update();                        //updates game state such as moving locations, picking item up, etc.
    //void display();                       //displays current game state like location, items, etc.
    void loadGameData();                    //calls loading functions for all txt file assets
    //void loadCharacters();                //Loads characters from txt file
    void loadLocations();                   //loads locations from txt file
    void move(Direction direction);         //moves player to a new location
    void userInput(const std::string &input);               //handles player input
    void playerDirectionalInput(const std::string &input);   //handles player directional input
    //void loadItems();                     //Loads items from txt file
    //void loadActions();                   //Loads actions from txt file
    //void loadInventory();                 //Loads inventory from txt file

};