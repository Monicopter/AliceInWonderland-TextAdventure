#pragma once

#include <iostream>
//#include <fstream>
// #include <string>
#include <vector>


#include "Locations.hpp"
#include "Actions.hpp"
#include "Items.hpp"
// #include "Characters.hpp"
#include "Inventory.hpp"


class Game
{
private:

    Location* currentLocation;              //Pointer to the player's current location

    std::vector<Location> locations;        //all in game location cells
    std::vector<Item> items;                //all ingame items vector
    Inventory inventory;                    //player inventory class object
    //std::vector<Character> characters;    //Game characters (incl. player char Alice)
    //item map to convert a user input string for the item name into the item's ID
    std::map<std::string, std::string> itemInputMap = {     // Map to convert user input string to an item ID - used by take, use, and consume commands
        {"tonic", "TONIC"},
        {"cake", "CAKE"},
        {"small cake", "CAKE"},
        {"key", "TINY_GOLD_KEY"},
        {"tiny key", "TINY_GOLD_KEY"},
        {"gold key", "TINY_GOLD_KEY"},
        {"white gloves", "WHITE_GLOVES"},
        {"gloves", "WHITE_GLOVES"},
        {"glove", "WHITE_GLOVES"},
        {"fan", "FAN"},
        {"hand fan", "FAN"},
        {"stick", "STICK"},
        {"blue mushroom", "SHRINK_MUSHROOM"},
        {"b mushroom", "SHRINK_MUSHROOM"},
        {"green mushroom", "ENLARGE_MUSHROOM"},
        {"g mushroom", "ENLARGE_MUSHROOM"},
        {"tea", "TEA"},
        {"tart", "TART"},
        {"ugly baby", "UGLY_BABY"},
        {"baby", "UGLY_BABY"},
        {"box", "SMALL_BOX"},
        {"small box", "SMALL_BOX"},
        {"paint", "RED_PAINT"},
        {"red paint", "RED_PAINT"},
        {"bucket of paint", "RED_PAINT"},
        {"bucket of red paint", "RED_PAINT"},
        {"flamingo", "FLAMINGO"}
        };
    std::string playerEffect = "NORMAL";   //player effect string to store the current player effect from consumables


public:

    Game();
    ~Game();

    void startGame();                       //public method to start the game
    void loadGameData();                    //calls loading functions for all txt file assets

    void loadItems();                       //Loads items from txt file
    //void loadCharacters();                //Loads characters from txt file
    //void loadInventory();                 //Loads inventory from txt file
    void loadLocations();                   //loads locations from txt file
    //void loadActions();                   //Loads actions from txt file

    void move(Direction direction);         //moves player to a new location
    void userInput(const std::string &input);                //handles player input
    void playerDirectionalInput(const std::string &input);   //handles player directional input
    void printHelp() const;                 //prints help menu
    void takeCommand(const std::string &input);              //handles player take command
    void useCommand(const std::string &input);              //handles player use command
    void consumeCommand(const std::string &input);          //handles player consume command
    //void useCommand(const std::string &input);              //handles player use command

    //void update();                        //updates game state such as moving locations, picking item up, etc.
    //void display();                       //displays current game state like location, items, etc.
    void printTextFile(const std::string& filename) const;   //prints text file to console - for longer exposition/events
    void handleUnlockEffect(const std::string& locationId);
    std::string removeAllWhitespace(const std::string& input); //removes all whitespace from a string
    void printAllItemIds() const;           //prints all item IDs to console
    Item findItemById(const std::string& itemId);

};