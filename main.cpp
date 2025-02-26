/* 
 Title: Assignment4
 Description: Alice In Wonderland - Text Adventure Game
 Date: 26 February, 2025
 Author: Lucas Monico
 Athabasca ID: 3572445
 Version: 1.0
*/

/*
 DOCUMENTATION
 
 Program Purpose:
    This is a text adventure game inspired by games like Colossal Cave Adventure. It takes place in the Alice in Wonderland setting, specifically
    the original novel written by Lewis Carroll. 

 Compile (assuming Cygwin is running): g++ -o alicegame.exe Game.cpp Items.cpp Locations.cpp Inventory.cpp Characters.cpp main.cpp
 Execution (assuming Cygwin is running): ./alicegame.exe
 
 Notes: in Cygwin, main must return type int
 
 Classes: 
    Game - Primary class that creates a vector object instance of the sub classes for the game and populates those classes by loading in the relevant text files. It also handles most functionality for the game with its contained methods.

    Item - Class that handles the item's class and all the variables, getters, and setters needed

    Inventory - Class that handles the player's inventory - works in tandem with the Item class by containing a vector object of the Item class

    Location - Class that handles the location's class and all the variables, getters, and setters needed

    Character - Class that handles the character's class and all the variables, getters, and setters needed

    Action - Technically not a formal 'class' but an enum class used to designate the player's action/control commands

    Direction - Technically not a formal 'class' but an enum class used to designate directional movement

 Variables:

    main:

        std::string userCommand                //string that holds the player string input for commands

 	Game:
        
        Location* currentLocation               //Pointer to the player's current location
        std::vector<Character> characters       //all ingame characters vector
        std::vector<Item> items                 //all ingame items vector
        std::vector<Location> locations         //all in game location cells
        Inventory inventory                     //player inventory class object
        std::string playerEffect                //player effect string to store the current player status effect
        std::map<std::string, std::string> itemInputMap    // Map to convert user input string to an item ID - used by take, use, and consume commands
        std::string line                        //used for the ifstream flow for the loadItems, loadCharacters, and loadLocations methods
        std::string inputString                 //used to assign the input string to a temporary variable for several methods like userInput()
        std::map<std::string, Action> actionMap //used to translate the userInput into the proper action enum to dirvert the player's intended command to the appropriate method
        auto it = actionMap.find(commands[0])   //temporary variable that holds the first word of the player's command to divert to the appropriate action command
        std::string inspectObject               //temp var that holds every word after the initial command word then injects this string to the inspectCommand() method
        std::string characterName               //temp var that holds every word after the initial command word then injects this string to the talkCommand() method
        std::string itemName                    //temp var that holds every word after the initial command word then injects this string to the useCommand(), takeCommand(), or consumeCommand() method


    Characters:

        std::string id                      //Holds the id string for the Character class object
        std::string name                    //Holds the name string for the Character class object
        std::string description             //Holds the description string for the Character class object
        std::string talk_riverBank          //Holds the talk_riverBank string for the Character class object - used with the talkCommand() method from the Game class
        std::string talk_rabbitHole         //Holds the talk_rabbitHole string for the Character class object - used with the talkCommand() method from the Game class
        std::string talk_landingHall        //Holds the talk_landingHall string for the Character class object - used with the talkCommand() method from the Game class
        std::string talk_doorwayHall        //Holds the talk_doorwayHall string for the Character class object - used with the talkCommand() method from the Game class 
        std::string talk_beachBank          //Holds the talk_beachBank string for the Character class object - used with the talkCommand() method from the Game class
        std::string talk_whiteRabbitHome    //Holds the talk_whiteRabbitHome string for the Character class object - used with the talkCommand() method from the Game class
        std::string talk_denseWoods         //Holds the talk_denseWoods string for the Character class object - used with the talkCommand() method from the Game class
        std::string talk_mushroomPatch      //Holds the talk_mushroomPatch string for the Character class object - used with the talkCommand() method from the Game class
        std::string talk_duchessHomeExt     //Holds the talk_duchessHomeExt string for the Character class object - used with the talkCommand() method from the Game class
        std::string talk_duchessHomeInt     //Holds the talk_duchessHomeInt string for the Character class object - used with the talkCommand() method from the Game class
        std::string talk_marchHareHome      //Holds the talk_marchHareHome string for the Character class object - used with the talkCommand() method from the Game class
        std::string talk_royalGardens       //Holds the talk_royalGardens string for the Character class object - used with the talkCommand() method from the Game class
        std::string talk_croquetField       //Holds the talk_croquetField string for the Character class object - used with the talkCommand() method from the Game class 
        std::string talk_royalBeach         //Holds the talk_royalBeach string for the Character class object - used with the talkCommand() method from the Game class
        std::string talk_throne             //Holds the talk_throne string for the Character class object - used with the talkCommand() method from the Game class

    Items:

        std::string id                      //Holds the id string for the Item class object
        std::string name                    //Holds the name string for the Item class object
        std::string description             //Holds the description string for the Item class object
        bool canTake                        //Holds the canTake boolean for the Item class object
        bool isConsumable                   //Holds the isConsumable boolean for the Item class object
        bool isUsable;                      //Holds the isUseable boolean for the Item class object
        bool isKey                          //Holds the isKey boolean for the Item class object
        std::string keyLocationId           //Holds the keyLocationId for the Item class object - meaning the location Id that the key object unlocks
        std::string consumeEffect           //Holds the consumeEffect string for the Item class object - used in tandem with the playerEffect variable from the Game class
        std::string useEffect               //Holds the useEffect string for the Item class object - used in tandem with the useCommand() method from the Game class
        int takeEffect                      //Holds the takeEffect int for the Item class object

    Inventory:

        std::map<std::string, int> itemCounts  //a map object used to hold the id string and count int for item objects within the player's inventory
        std::vector<Item> items                //a vector object of the Item class to contain the individual items within the player's inventory

    Locations:
        
        std::string id                      //Holds the id string for the Location class object
        std::string name                    //Holds the name string for the Location class object
        std::string description             //Holds the description string for the Location class object
        std::vector<Item> items             //Holds a vector object of the Item class - used to store all the items contained within a specific location
        std::vector<Character> characters   //Holds a vector object of the Character class - used to store all the characters contained within a specific location
        std::string pathNorth               //Holds the pathNorth string for the Location class object - uses a Location object id to designate the location in this direction
        std::string pathSouth               //Holds the pathSouth string for the Location class object - uses a Location object id to designate the location in this direction
        std::string pathEast                //Holds the pathEast string for the Location class object - uses a Location object id to designate the location in this direction
        std::string pathWest                //Holds the pathWest string for the Location class object - uses a Location object id to designate the location in this direction
        std::string northDesc               //Holds the northDesc string for the Location class object - Description for the north location path
        std::string southDesc               //Holds the southDesc string for the Location class object - Description for the south location path
        std::string eastDesc                //Holds the eastDesc string for the Location class object - Description for the east location path
        std::string westDesc                //Holds the westDesc string for the Location class object - Description for the west location path
        bool northIsLocked                  //Holds the northIsLocked boolean for the Location class object 
        bool southIsLocked                  //Holds the southIsLocked boolean for the Location class object
        bool eastIsLocked                   //Holds the eastIsLocked boolean for the Location class object
        bool westIsLocked                   //Holds the westIsLocked boolean for the Location class object
        bool firstVisit                     //Holds the firstVisit boolean for the Location class object - certain script events depend on whether it's the player's first visit to a location
        std::string events                  //Holds the events string for the Location class object - used to designate a txt file name to load specific events if the player enters a location
        std::string northKey                //Holds the northKey string for the Location class object - designates a Item class object ID 
        std::string southKey                //Holds the southKey string for the Location class object - designates a Item class object ID 
        std::string eastKey                 //Holds the eastKey string for the Location class object - designates a Item class object ID 
        std::string westKey                 //Holds the westKey string for the Location class object - designates a Item class object ID 

/*
   
 Discussion:
	This game is mostly fleshed out up to the Duchess' house but obviously takes many liberties as
    far as the dialogue is concerned. I understand this is a public domain works but I didn't want to just copy and paste the dialogue.
    I ran out of time to flesh this out more; the original plan was to do the entire novel but that's just not realistic with my current time constraints.
    I'm also not even sure where to begin with a test plan for a project this size. I understand I could do a run through with each method for the classes like the getters and setters.
    But I feel this would take up an exorbant amount of space in the current format we use for these assignment submissions.
*/

#include <iostream>
#include "Game.hpp"
#include "Locations.hpp"
#include "Actions.hpp"
#include "Inventory.hpp"
#include "Items.hpp"

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