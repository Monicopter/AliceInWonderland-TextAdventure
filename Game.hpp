#pragma once

#include <iostream>
#include <vector>

#include "Locations.hpp"
#include "Actions.hpp"
#include "Items.hpp"
#include "Characters.hpp"
#include "Inventory.hpp"


class Game
{
private:

    Location* currentLocation;              //Pointer to the player's current location

    std::vector<Character> characters;       //all ingame characters vector
    std::vector<Item> items;                //all ingame items vector
    std::vector<Location> locations;        //all in game location cells
    Inventory inventory;                    //player inventory class object
    std::string playerEffect = "NORMAL";   //player effect string to store the current player effect from consumables

    //item map to convert a user input string for the item name into the item's ID
    std::map<std::string, std::string> itemInputMap = {     // Map to convert user input string to an item ID - used by take, use, and consume commands
        {"tonic", "SHRINK_TONIC"},
        {"potion", "ENLARGE_POTION"},
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
        {"shrink mushroom", "SHRINK_MUSHROOM"},
        {"shrinking mushroom", "SHRINK_MUSHROOM"},
        {"enlarge mushroom", "ENLARGE_MUSHROOM"},
        {"enlarging mushroom", "ENLARGE_MUSHROOM"},
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
        {"table", "GLASS_TABLE"},
        {"glass table", "GLASS_TABLE"},
        {"night stand", "NIGHT_STAND"},
        {"stand", "NIGHT_STAND"},
        {"night", "NIGHT_STAND"},
        {"looking glass", "LOOKING_GLASS"},
        {"looking", "LOOKING_GLASS"},
        {"mirror", "LOOKING_GLASS"},
        {"pebble", "PEBBLE"},
        {"flamingo", "FLAMINGO"}
        };

public:

    Game();
    ~Game();

    void startGame();                       //public method to start the game
    void loadGameData();                    //calls loading functions for all txt file assets
    void loadItems();                       //Loads items from txt file
    void loadCharacters();                  //Loads characters from txt file
    void loadLocations();                   //loads locations from txt file


    void move(Direction direction);                         //moves player to a new location
    void userInput(const std::string &input);               //handles player input
    void playerDirectionalInput(const std::string &input);  //handles player directional input
    void printHelp() const;                                 //prints help menu
    void takeCommand(const std::string &input);             //handles player take command
    void useCommand(const std::string &input);              //handles player use command
    void consumeCommand(const std::string &input);          //handles player consume command
    void talkCommand(const std::string &input);             //handles player talk command
    void inspectCommand(const std::string &input);          //handles player inspect command

    void display();                                         //displays current game state like location, items, etc.
    void printTextFile(const std::string &filename) const;  //prints text file to console - for longer exposition/events
    void handleUnlockEffect(const std::string &locationId);      //used to unlock direction pathways from USE command of key items
    std::string removeAllWhitespace(const std::string &input);   //removes all whitespace from a string
    void addInventoryItemById(const std::string &itemId);        //adds item to inventory from an input item ID
    void addCharacterToLocation(const std::string &characterId); //adds a character to the current location cell
    void addItemToLocation(const std::string &itemId);           //adds an item to the players current location
    void setPlayerLocation(const std::string &locationId);       //forcefully changes the player's current location
    void removeCharacterFromLocation(const std::string &characterId); //removes a character from the currentLocation using the character's ID
};