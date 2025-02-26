#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

#include <algorithm>
#include <cctype>

#include <limits>

#include <filesystem>

#include "Game.hpp"

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

Game::Game()
{
    currentLocation = nullptr;
}

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

Game::~Game()
{
}

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

void Game::startGame()
{
    printTextFile("Intro.txt"); //BE SURE TO UNCOMMENT FOR FINAL BUILD
    loadGameData();

    if (!locations.empty())
    {
        currentLocation = &locations[0];  //can change the index number to spawn into a different location see locations.txt for numerical id
        std::cout << "Current Location: " << currentLocation->getName() << std::endl;
        std::cout << "Description: " << currentLocation->getDescription() << std::endl;
    }
    else
    {
        std::cerr << "No locations loaded." << std::endl;
    }

}

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

void Game::loadGameData()
{
    loadItems();
    loadCharacters();
    loadLocations();
}

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

void Game::loadItems()
{
    // See loadLocations for comments on how this function works - it follows the same format

    std::ifstream file("Items.txt");
    if (!file.is_open())
    {
        std::cerr << "Failed to open Items.txt" << std::endl;
        return;
    }

    std::string line;
    Item item;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        if (line[0] == '#')
        {

            if (!item.getId().empty())
            {
                items.push_back(item);

                item = Item();
            }
        }

        // follows the same format as the loadLocations function but with different keywords
        if (line.find("id: ") == 0)
        {
            item.setId(line.substr(4));
        }
        if (line.find("name: ") == 0)
        {
            item.setName(line.substr(6));
        }
        if (line.find("description: ") == 0)
        {
            item.setDescription(line.substr(13));
        }
        if (line.find("canTake: ") == 0)
        {
            item.setCanTake(line.substr(9) == "true");
        }
        if (line.find("isConsumable: ") == 0)
        {
            item.setIsConsumable(line.substr(14) == "true");
        }
        if (line.find("isUsable: ") == 0)
        {
            item.setIsUsable(line.substr(10) == "true");
        }
        if (line.find("isKey: ") == 0)
        {
            item.setIsKey(line.substr(8) == "true");
        }
        if (line.find("keyLocationId: ") == 0)
        {
            item.setKeyLocationId(line.substr(15));
        }
        if (line.find("consumeEffect: ") == 0)
        {
            item.setConsumeEffect(line.substr(15));
        }
        if (line.find("useEffect: ") == 0)
        {
            item.setUseEffect(line.substr(11));
        }
    }
    // Add the last item if it has a non-empty id
    if (!item.getId().empty())
    {
        items.push_back(item);
    }

    file.close();

}


/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

void Game::loadCharacters()
{
    // See loadLocations for comments on how this function works - it follows the same format

    std::ifstream file("Characters.txt");
    if (!file.is_open())
    {
        std::cerr << "Failed to open Characters.txt" << std::endl;
        return;
    }

    std::string line;
    Character character;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        if (line[0] == '#')
        {

            if (!character.getId().empty())
            {
                characters.push_back(character);

                character = Character();
            }
        }
    

        // follows the same format as the loadLocations function but with different keywords
        if (line.find("id: ") == 0)
        {
            character.setId(line.substr(4));
        }
        if (line.find("name: ") == 0)
        {
            character.setName(line.substr(6));
        }
        if (line.find("description: ") == 0)
        {
            character.setDescription(line.substr(13));
        }
        if (line.find("talk_riverBank: ") == 0)
        {
            character.setTalkRiverBank(line.substr(16));
        }
        if (line.find("talk_rabbitHole: ") == 0)
        {
            character.setTalkRabbitHole(line.substr(17));
        }
        if (line.find("talk_landingHall: ") == 0)
        {
            character.setTalkLandingHall(line.substr(18));
        }
        if (line.find("talk_doorwayHall: ") == 0)
        {
            character.setTalkDoorwayHall(line.substr(18));
        }
        if (line.find("talk_beachBank: ") == 0)
        {
            character.setTalkBeachBank(line.substr(16));
        }
        if (line.find("talk_whiteRabbitHome: ") == 0)
        {
            character.setTalkWhiteRabbitHome(line.substr(22));
        }
        if (line.find("talk_denseWoods: ") == 0)
        {
            character.setTalkDenseWoods(line.substr(17));
        }
        if (line.find("talk_mushroomPatch: ") == 0)
        {
            character.setTalkMushroomPatch(line.substr(20));
        }
        if (line.find("talk_duchessHomeExt: ") == 0)
        {
            character.setTalkDuchessHomeExt(line.substr(21));
        }
        if (line.find("talk_duchessHomeInt: ") == 0)
        {
            character.setTalkDuchessHomeInt(line.substr(21));
        }
        if (line.find("talk_marchHareHome: ") == 0)
        {
            character.setTalkMarchHareHome(line.substr(20));
        }
        if (line.find("talk_royalGardens: ") == 0)
        {
            character.setTalkRoyalGardens(line.substr(19));
        }
        if (line.find("talk_croquetField: ") == 0)
        {
            character.setTalkCroquetField(line.substr(19));
        }
        if (line.find("talk_royalBeach: ") == 0)
        {
            character.setTalkRoyalBeach(line.substr(17));
        }
        if (line.find("talk_throne: ") == 0)
        {
            character.setTalkThrone(line.substr(13));
        }
        
    }
    // Add the last item if it has a non-empty id
    if (!character.getId().empty())
    {
        characters.push_back(character);
    }

    file.close();

}

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

void Game::loadLocations()
{
    std::ifstream file("Locations.txt");
    if (!file.is_open())
    {
        std::cerr << "Failed to open Locations.txt" << std::endl;
        return;
    }

    std::string line;
    Location location;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        // Check if the 'line' in the txt file starts with the '#' character
        if (line[0] == '#')
        {
            // Check if the current location object has a non-empty id
            if (!location.getId().empty())
            {
                // Add the current location object to the locations vector
                locations.push_back(location);
                // Reset the location object for the next set of data
                location = Location();
            }
        }

        // Check if the line starts with a specific keyword and set the appropriate value in the location object

        if (line.find("id: ") == 0)
        {                                   // If the line starts with "id: ", extract the rest of the line
            location.setId(removeAllWhitespace(line.substr(4))); // Set the id of the location object to the rest of the line starting at the 4th character index
        }
        if (line.find("name: ") == 0)
        { // Same as above just with different keywords
            location.setName(line.substr(6));
        }
        if (line.find("description: ") == 0)
        {
            location.setDescription(line.substr(13));
        }
        if (line.find("items: ") == 0)
        {
            //create a vector of items to store the items in the location cell
            std::vector<Item> locationItems;
            std::istringstream itemsStream(line.substr(7));
            std::string itemId;
            //goes through the 'items: ' line of locations.txt and extracts the item ids and stores them in the locationItems vector
            while (itemsStream >> itemId)
            {
                //for loop that compares objects within the Game class items vector to the extracted item id from the location's cell items variable
                for (Item& item : items)
                {
                    if (itemId == "NULL") {
                        break;
                    }
                    else if (item.getId() == itemId)
                    {
                        locationItems.push_back(item);
                        break;
                    }
                }
            }
            location.setItems(locationItems);
        }
        if (line.find("characters: ") == 0)
        {
            //create a vector of characters to store the characters in the location cell
            std::vector<Character> locationCharacters;
            std::istringstream charactersStream(line.substr(12));
            std::string characterId;
            //goes through the 'characters: ' line of locations.txt and extracts the character ids and stores them in the locationCharacters vector
            while (charactersStream >> characterId)
            {
                //for loop that compares objects within the Game class character vector to the extracted character id from the location's cell characters variable
                for (Character& character : characters)
                {
                    if (characterId == "NULL") {
                        break;
                    }
                    else if (character.getId() == characterId)
                    {
                        locationCharacters.push_back(character);
                        break;
                    }
                }
            }
            location.setCharacters(locationCharacters);
        }
        if (line.find("pathNorth: ") == 0)
        {
            location.setPathNorth(line.substr(11));
        }
        if (line.find("pathSouth: ") == 0)
        {
            location.setPathSouth(line.substr(11));
        }
        if (line.find("pathEast: ") == 0)
        {
            location.setPathEast(line.substr(10));
        }
        if (line.find("pathWest: ") == 0)
        {
            location.setPathWest(line.substr(10));
        }
        if (line.find("northDesc: ") == 0)
        {
            location.setNorthDesc(line.substr(11));
        }
        if (line.find("southDesc: ") == 0)
        {
            location.setSouthDesc(line.substr(11));
        }
        if (line.find("eastDesc: ") == 0)
        {
            location.setEastDesc(line.substr(10));
        }
        if (line.find("westDesc: ") == 0)
        {
            location.setWestDesc(line.substr(10));
        }
        // boolean checks for true. If txt file is true for locked then it will be true - 1.
        // If false in txt file then value is false - 0
        if (line.find("northIsLocked: ") == 0)
        {
            location.setNorthIsLocked(line.substr(15) == "true");
        }
        if (line.find("southIsLocked: ") == 0)
        {
            location.setSouthIsLocked(line.substr(15) == "true");
        }
        if (line.find("eastIsLocked: ") == 0)
        {
            location.setEastIsLocked(line.substr(14) == "true");
        }
        if (line.find("westIsLocked: ") == 0)
        {
            location.setWestIsLocked(line.substr(14) == "true");
        }
        if (line.find("firstVisit: ") == 0)
        {
            location.setFirstVisit(line.substr(12) == "true");
        }
        if (line.find("events: ") == 0)     //events has to use the removeAllWhitespace function otherwise it wont load the text file properly
        {
            location.setEvents(removeAllWhitespace(line.substr(8)));
        }
        if (line.find("northKey: ") == 0)
        {
            location.setNorthKey(line.substr(10));
        }
        if (line.find("southKey: ") == 0)
        {
            location.setSouthKey(line.substr(10));
        }
        if (line.find("eastKey: ") == 0)
        {
            location.setEastKey(line.substr(9));
        }
        if (line.find("westKey: ") == 0)
        {
            location.setWestKey(line.substr(9));
        }
        
    }
    // Add the last location object to the locations vector if it has a non-empty id
    if (!location.getId().empty())
    {
        locations.push_back(location);
    }

    file.close();
}

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

// Direction is an enum declared in Actions.hpp
void Game::move(Direction direction)
{
    if (currentLocation == nullptr)
    {
        std::cerr << "Current location is null." << std::endl;
        return;
    }

    /*
    nextLocationId is a string that will be used to store the id of the next location
    since getPathDirection returns the id of the queried direction's location
    */
    std::string nextLocationId;

    switch (direction)
    {
    case Direction::NORTH:
        if (currentLocation->getNorthIsLocked() == true)
        {
            std::cerr << "The North pathway is locked." << std::endl;
            return;
        } 
        else
        { 
        nextLocationId = currentLocation->getPathNorth();
        break;
        }
    case Direction::SOUTH:
        if (currentLocation->getSouthIsLocked() == true)
        {
            std::cerr << "The South pathway is locked." << std::endl;
            return;
        } 
        else
        { 
        nextLocationId = currentLocation->getPathSouth();
        break;
        }
    case Direction::EAST:
        if (currentLocation->getEastIsLocked() == true)
        {
            std::cerr << "The East pathway is locked." << std::endl;
            return;
        } 
        else
        { 
        nextLocationId = currentLocation->getPathEast();
        break;
        }
    case Direction::WEST:
        if (currentLocation->getWestIsLocked() == true)
        {
            std::cerr << "The West pathway is locked." << std::endl;
            return;
        } 
        else
        { 
        nextLocationId = currentLocation->getPathWest();
        break;
        }
    default:
        std::cerr << "Invalid direction." << std::endl;
        return;
    }
    
    // iterates over each object in the locations vector uses & to reference each object to avoid copying the object for efficiency
    for (auto &location : locations)
    {

        // compares the id of the current location to the id of the next location from the switch statement
        if (location.getId() == nextLocationId)
        {
            // Changes old current location to false - so it doesn't trigger first visit events/scripts upon future visits to a location
            currentLocation->setFirstVisit(false);
            currentLocation = &location; // sets the current location to the location element in the locations vector - if it matches location.getId()

           

            // if the current location has not been visited before and has events, print the events
            if (currentLocation->getFirstVisit() == true && currentLocation->getEvents() != "NULL") {   
                
                printTextFile(currentLocation->getEvents());
                
                std::cout << "Moved to: " << currentLocation->getName() << std::endl;
                std::cout << "Description: " << currentLocation->getDescription() << std::endl;
                return;
            } else {
                
                std::cout << "Moved to: " << currentLocation->getName() << std::endl;
                std::cout << "Description: " << currentLocation->getDescription() << std::endl;
                return;
            }
        }
    }
    std::cerr << "Cannot move in that direction." << std::endl;
}

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

void Game::userInput(const std::string &input)
{
    std::string inputString = input;

    // for loop that iterates through user input and converts it to lower case
    for (int n = 0; n < inputString.length(); n++)
    {
        inputString[n] = tolower(inputString[n]);
    }

    // creating a string vector to store the individual command words from the user input
    std::istringstream stream(inputString);
    std::string command;
    std::vector<std::string> commands;

    // map of user commands
    std::map<std::string, Action> actionMap = {
        {"help", Action::HELP},
        {"inspect", Action::INSPECT},
        {"talk", Action::TALK},
        {"take", Action::TAKE},
        {"use", Action::USE},
        {"move", Action::MOVE},
        {"inventory", Action::INVENTORY},
        {"consume", Action::CONSUME},
        {"display", Action::DISPLAY},  //used for debugging
        {"quit", Action::QUIT}};

    // Extract words from userInput separated by whitespace
    while (stream >> command)
    {
        commands.push_back(command);
    }
    // Ensure there is at least one command
    if (commands.empty())
    {
        std::cerr << "No command entered." << std::endl;
        return;
    }
///////////////////////////////////////////////////////////////////////////////
    // looping the first command (commands[0]) through the actionMap to find a matching keyword
    auto it = actionMap.find(commands[0]);
    // if the commands[0] is NOT equal to the end of the actionMap - that means it DID find a matching keyword
    if (it != actionMap.end())
    {
        // switch statement (it->second) pulls the value of the keyword from the actionMap which would be ACTION::HELP, ACTION::INSPECT, etc.
        switch (it->second)
        {
///////////////////////////////////////////////////////////////////////////////            
        case Action::HELP:

            printHelp();
            break;
///////////////////////////////////////////////////////////////////////////////
        case Action::INSPECT:

            if (commands.size() > 1) {
                std::string inspectObject;
                // Starts at commands[1] to avoid the command keyword - then increments by 1 through to the end of the commands vector
                for (size_t i = 1; i < commands.size(); ++i) { 
                    if (i > 1) {
                        inspectObject += " ";        // Add a space between words
                    }
                    inspectObject += commands[i];    // Concatenates the current commands vector word to the inspectObject string
                }
                inspectCommand(inspectObject);          // Passes the inspectObject string to the inspectCommand function
                break;
            } else {
                std::cerr << "Inspect what? Specify what you wish to inspect. It can be a location, direction, item, or character." << std::endl;
            }
            break;

///////////////////////////////////////////////////////////////////////////////
        case Action::TALK:
            // If the user input has more than one word (commands.size() > 1) then it will take every word in the commands vector and pass it to the takeCommand function
            if (commands.size() > 1) {
                std::string characterName;
                // Starts at commands[1] to avoid the command keyword - then increments by 1 through to the end of the commands vector
                for (size_t i = 1; i < commands.size(); ++i) { 
                    if (i > 1) {
                        characterName += " ";        // Add a space between words
                    }
                    characterName += commands[i];    // Concatenates the current commands vector word to the itemName string
                }
                talkCommand(characterName);          // Passes the itemName string to the takeCommand function
                break;
            } else {
                std::cerr << "Talk to whom? Input the character name: 'talk <character name>'" << std::endl;
            }
            break;
///////////////////////////////////////////////////////////////////////////////
        case Action::TAKE:
            // If the user input has more than one word (commands.size() > 1) then it will take every word in the commands vector and pass it to the takeCommand function
            if (commands.size() > 1) {
                std::string itemName;
                // Starts at commands[1] to avoid the command keyword - then increments by 1 through to the end of the commands vector
                for (size_t i = 1; i < commands.size(); ++i) { 
                    if (i > 1) {
                        itemName += " ";        // Add a space between words
                    }
                    itemName += commands[i];    // Concatenates the current commands vector word to the itemName string
                }
                takeCommand(itemName);          // Passes the itemName string to the takeCommand function
                break;
            } else {
                std::cerr << "Take what? Input the item name: 'take <item name>'" << std::endl;
            }
            break;
///////////////////////////////////////////////////////////////////////////////
        case Action::USE:
            // Follows the same format as the takeCommand function but with different keywords
            if (commands.size() > 1) {
                std::string itemName;
                
                for (size_t i = 1; i < commands.size(); ++i) { 
                    if (i > 1) {
                        itemName += " ";        
                    }
                    itemName += commands[i];    
                }
                useCommand(itemName); 
                break;
            } else {
                std::cerr << "Use what? Input the item name: 'use <item name>' This item MUST be in your inventory." << std::endl;
            }
            break;
///////////////////////////////////////////////////////////////////////////////
        case Action::MOVE:
            if (commands.size() > 1)
            {
                playerDirectionalInput(commands[1]);
            }
            else
            {
                std::cerr << "Move where? Options are North, South, East, or West." << std::endl;
            }
            break;
///////////////////////////////////////////////////////////////////////////////
        case Action::INVENTORY:
            inventory.printInventory();
            break;
///////////////////////////////////////////////////////////////////////////////
        case Action::CONSUME:
            // If the user input has more than one word (commands.size() > 1) then it will take every word in the commands vector and pass it to the takeCommand function
            if (commands.size() > 1) {
                std::string itemName;
                // Starts at commands[1] to avoid the command keyword - then increments by 1 through to the end of the commands vector
                for (size_t i = 1; i < commands.size(); ++i) { 
                    if (i > 1) {
                        itemName += " ";        // Add a space between words
                    }
                    itemName += commands[i];    // Concatenates the current commands vector word to the itemName string
                }
                consumeCommand(itemName);          // Passes the itemName string to the takeCommand function
                break;
            } else {
                std::cerr << "Consume what? Input the item name: 'consume <item name>' This item MUST be in your inventory." << std::endl;
            }
            break;
///////////////////////////////////////////////////////////////////////////////
        //Used for debugging - not part of the game loop - might remove for final build
        case Action::DISPLAY:
            display();
            break;
///////////////////////////////////////////////////////////////////////////////
        case Action::QUIT:
            std::cout << "Exiting game, Goodbye..." << std::endl;
            exit(0);
///////////////////////////////////////////////////////////////////////////////
        default:
            break;
        }
    }
    else
    {
        std::cerr << "Invalid action! Type 'help' for a list of commands!" << std::endl;
    }
}

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

// function to handle player input for the "move" command - links with the move function
void Game::playerDirectionalInput(const std::string &input)
{

    if (input == "north" || input == "n")
    {   //conditional check if the player is enlarged within the white rabbit's home location - cannot leave until shrunk again.
        if (currentLocation->getId() == "wRHome" && playerEffect == "ENLARGE")
        {
            std::cout << "You're much too large to fit through the doorway, or the windows for that matter." << std::endl;
            return;
        }
        move(Direction::NORTH);
        return;
    }
    if (input == "south" || input == "s")
    {   //conditional for the doorway hall path south into the gardens - player needs to be shrunk to use this pathway
        if (currentLocation->getId() == "doorwayHall" && playerEffect != "SHRINK" && currentLocation->getSouthIsLocked() == false ) 
        {
            std::cout << "You need to be shrunk to fit through this doorway!" << std::endl;
            return;     
        } 
        move(Direction::SOUTH);
        return;
    }
    if (input == "east" || input == "e")
    {
        move(Direction::EAST);
        return;
    }
    if (input == "west" || input == "w")
    {
        move(Direction::WEST);
        return;
    }
    else
    {
        std::cerr << "Invalid direction. Use north, south, east, or west." << std::endl;
        return;
    }
}

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

// function to print the help menu from the user input "help"
void Game::printHelp() const
{

    std::cout << "Available commands:" << std::endl;
    std::cout << "HELP - Display this help message." << std::endl;     
    std::cout << "INSPECT <object> - Can be used for contextual descriptions; like directions, characters, objects, etc." << std::endl;     
    std::cout << "TALK <character> - Talk to a character." << std::endl;
    std::cout << "TAKE <item> - Take an item." << std::endl;
    std::cout << "USE <item> - Use an item." << std::endl;
    std::cout << "MOVE <direction> - Move in a direction (north, south, east, or west)." << std::endl;
    std::cout << "INVENTORY - Show your inventory." << std::endl;
    std::cout << "CONSUME <item> - Consume an item." << std::endl;
    std::cout << "QUIT - Quit the game." << std::endl;
}

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

void Game::takeCommand(const std::string &input)
{
    std::string inputString = input;
 
    //iterates through the itemInputMap to find a matching value for the user input keyword
    auto it = itemInputMap.find(inputString);

    if (it != itemInputMap.end())
    {
        inputString = it->second;
    } else {
        std::cerr << "Item not found." << std::endl;
    }

    //iterates through the current location's items vector to find a matching item ID to the user input 
    //then adds the item to the player's inventory
    
    // assigns a reference &locationItems from the current locations items vector
    auto &locationItems = currentLocation->getItems();
    /* itemCycle is an iterator that iterates through each item in the referenced vector for the current location's
    items - increments by 1 element until it reaches the end of the vector */
    for (auto itemCycle = locationItems.begin(); itemCycle != locationItems.end(); ++itemCycle)
    {   
        if (itemCycle->getId() == inputString && itemCycle->getCanTake() == true)
        {
            
            inventory.addItem(*itemCycle);                 // Adds the item to the player's inventory - after dereferencing itemCycle to add the item
            std::cout << "You have taken: " << itemCycle->getName() << std::endl; // prints out the name of the item taken
            locationItems.erase(itemCycle);                // Removes the item from the location's item vector
         
            return; 
        }
        else if (itemCycle->getId() == inputString && itemCycle->getCanTake() == false) //edge case where the item exists but the user cannot take it
        {
            std::cout << "You cannot take: " << itemCycle->getName() << std::endl;
            return; 
        }
    }
    std::cerr << "Item not found in the current location." << std::endl;
}

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

void Game::useCommand(const std::string &input)
{
    std::string inputString = input;

    // Iterates through the itemInputMap to find a matching value for the user input keyword
    auto it = itemInputMap.find(inputString);

    if (it != itemInputMap.end())
    {
        inputString = it->second;
    }
    else
    {
        std::cerr << "Item not found." << std::endl;
        return;
    }

    // Follows a similar format to the takeCommand function but compares with the inventory items vector instead of the current location's items vector
    auto &inventoryItems = inventory.getItems();
 
    for (auto itemCycle = inventoryItems.begin(); itemCycle != inventoryItems.end(); ++itemCycle)
    {   
        if (itemCycle->getId() == inputString && itemCycle->getIsUsable() == true)
        {   //Checks the item useEffect for items in player's inventory then diverts to the appropriate effect
            std::string effect = itemCycle->getUseEffect();

            if (effect == "SHRINK") //for the hand fan object and doorwayhall tears event
            {
                inventoryItems.erase(itemCycle); // Removes the item from the inventory
                playerEffect = "SHRINK";
                currentLocation->setFirstVisit(false); // sets doorway hall first visit for false so it doesn't repeat scripted beats for tears event
                printTextFile("tearsEvent.txt");
                setPlayerLocation("beachBank");
            }
            else if (effect == "ENLARGE")
            {
                inventoryItems.erase(itemCycle);
                playerEffect = "ENLARGE";
                std::cout << "You are now enlarged" << std::endl;
            }
            else if (effect == "UNLOCK")    //for the tiny gold key item
            {
                std::string usedItemName = itemCycle->getName();
                inventoryItems.erase(itemCycle); 
                std::cout << "You have used: " << usedItemName << std::endl;
                handleUnlockEffect(itemCycle->getKeyLocationId());
                
            }
            else if (effect == "WEAR")  //for the white gloves item object
            {
                if (playerEffect == "ENLARGE")
                {
                    std::cout << "You're much too large to wear these gloves!" << std::endl;
                    return;
                }
                if (playerEffect == "SHRINK")
                {
                    std::cout << "You're much too tiny to wear these gloves!" << std::endl;
                    return;
                }
                std::string usedItemName = itemCycle->getName();
                inventoryItems.erase(itemCycle); 
                std::cout << "You are now wearing the " << usedItemName << std::endl;
                return;
            }
            else if (effect == "THROW")
            {
                inventoryItems.erase(itemCycle);
                removeCharacterFromLocation("dog");
                currentLocation->setFirstVisit(false); 
                printTextFile("dogStickEvent.txt"); 
                setPlayerLocation("mushroomPatch");
            }
            else if (effect == "SPAWN_CAKE")
            {
                inventoryItems.erase(itemCycle); 
                addInventoryItemById("CAKE");
                std::cout << "There was a small cake inside the box! It has the words 'EAT ME' written neatly in currants on it." << std::endl;
            }
            else
            {   
                //For items with a text output use effect
                inventoryItems.erase(itemCycle); 
                std::cerr << "-" << effect << std::endl;
            }
            return; 
        }

        else if (itemCycle->getId() == inputString && itemCycle->getIsUsable() == false) 
        {
            std::cout << "You cannot use: " << itemCycle->getName() << std::endl;
            return; 
        }
    }
    std::cerr << "Item not found in the inventory." << std::endl;
}

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

void Game::consumeCommand(const std::string &input)
{
    std::string inputString = input;

    // Iterate through the items in the player's inventory
    auto &inventoryItems = inventory.getItems();
    for (auto itemCycle = inventoryItems.begin(); itemCycle != inventoryItems.end(); ++itemCycle)
    {
        std::string itemName = itemCycle->getName();

        // Convert the item name to lowercase
        for (int n = 0; n < itemName.length(); n++)
        {
            itemName[n] = tolower(itemName[n]);
        }

        // Check if the input string is a substring of the item name and if the item is consumable
        if (itemName.find(inputString) != std::string::npos && itemCycle->getIsConsumable() == true)
        {
            
            std::string consumedItemName = itemCycle->getName(); // Store the name of the consumed item

            // Check if the consumed item is the SHRINK_TONIC for doorway hall scripted event
            if (inputString == "tonic") //event for consuming the tonic item within the doorway hall location
            {
                currentLocation->setSouthIsLocked(true);
                std::cout << "Great! You're now around 10 inches tall! Small enough to fit through that door. Unfortunately, the door is now closed and the key is on top of the table." << std::endl;
                std::cout << "Now that you're tiny you notice a small box near the feet of the table. What's inside?" << std::endl;
            }

            if (inputString == "cake")  //event for consuming the cake item within the doorway hall location
            {
                std::cout << "Curiouser and curiouser" << std::endl;
                std::cout << "You've now grown VERY large, you have to bend your neck to avoid hitting the ceiling beams." << std::endl;
                std::cout << "Alice is really having a rough go of it. She starts weaping. Is she going to be this large forever now?" << std::endl;
                std::cout << "You suddenly spot the frantic White Rabbit hopping down the hall towards you. Maybe you could ask for his help?" << std::endl;
                addCharacterToLocation("whiteRabbit");
            }

            if (inputString == "potion")    //event for consuming the potion item within the white rabbit's home location
            {
                printTextFile("potionEvent.txt");
                addItemToLocation("PEBBLE");
            }
            if (inputString == "pebble")    //event for consuming the potion item within the white rabbit's home location
            {
                currentLocation->setFirstVisit(false);
                printTextFile("transitionHomeToWoods.txt");
                setPlayerLocation("denseWoods");
            }
            if (inputString == "enlarging mushroom")
            {
                playerEffect = itemCycle->getConsumeEffect();   // Sets the player effect to the item's consume effect
                std::cout << "Effect: " << playerEffect << std::endl;
                std::cout << "You have consumed a small bit of the " << consumedItemName << std::endl;
                return;
            }
            if (inputString == "shrinking mushroom")
            {
                playerEffect = itemCycle->getConsumeEffect();   // Sets the player effect to the item's consume effect
                std::cout << "Effect: " << playerEffect << std::endl;
                std::cout << "You have consumed a small bit of the " << consumedItemName << std::endl;
                return;
            }

            playerEffect = itemCycle->getConsumeEffect();   // Sets the player effect to the item's consume effect
            std::cout << "Effect: " << playerEffect << std::endl;
            
            inventory.decrementItem(*itemCycle); // Decrement the item count
            inventoryItems.erase(itemCycle); // Removes the item from the inventory
            std::cout << "You have consumed: " << consumedItemName << std::endl;
            return;

        }
        else if (itemCycle->getId() == inputString && itemCycle->getIsConsumable() == false)
        {
            std::cout << "You cannot consume: " << itemCycle->getName() << std::endl;
            return;
        }
    }
    std::cerr << "Item not found in the inventory." << std::endl;
}

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

void Game::talkCommand(const std::string &input) {
    std::string inputString = input;
    auto &locationCharacters = currentLocation->getCharacters();

    // Iterate through the characters in the current location
    //for (const Character& character : currentLocation->getCharacters()) {
    for (auto characterCycle = locationCharacters.begin(); characterCycle != locationCharacters.end(); ++characterCycle) {

     
        std::string characterName = characterCycle->getName();

        //converts character name to lower case to match player input
        for (int n = 0; n < characterName.length(); n++)
        {
            characterName[n] = tolower(characterName[n]);
        }
    

        // Checks if the player input is even sligtly a match to a character name present in currentLocation
        if (characterName.find(inputString) != std::string::npos) {
            // Pull the appropriate talk line for the current location
            std::string talkLine;
            std::string characterId;
            std::string characterName;
            
            //finds current location and assigns the correct contextual talk dialogue for currentLocation
            if (currentLocation->getId() == "riverBank") 
            {
                talkLine = characterCycle->getTalkRiverBank();
                characterName = characterCycle->getName();
            } 
            if (currentLocation->getId() == "rabbitHole") 
            {
                talkLine = characterCycle->getTalkRabbitHole();
                characterName = characterCycle->getName();
            } 
            if (currentLocation->getId() == "landingHall") 
            {
                talkLine = characterCycle->getTalkLandingHall();
                characterName = characterCycle->getName();
            } 
            if (currentLocation->getId() == "doorwayHall") 
            {
                talkLine = characterCycle->getTalkDoorwayHall();
                characterName = characterCycle->getName();
                characterId = characterCycle->getId();
                if (characterId == "whiteRabbit")   
                {
                    addItemToLocation("WHITE_GLOVES");
                    addItemToLocation("FAN");
                    locationCharacters.erase(characterCycle);
                }
            } 
            if (currentLocation->getId() == "beachBank") 
            {

                talkLine = characterCycle->getTalkBeachBank();
                characterName = characterCycle->getName();
                characterId = characterCycle->getId();
                if (characterId == "mouse")   
                {
                    locationCharacters.erase(characterCycle);
                }
            } 
            if (currentLocation->getId() == "whiteRabbitHome") 
            {
                talkLine = characterCycle->getTalkWhiteRabbitHome();
                characterName = characterCycle->getName();
            } 
            if (currentLocation->getId() == "denseWoods") 
            {
                talkLine = characterCycle->getTalkDenseWoods();
                characterName = characterCycle->getName();
            } 
            if (currentLocation->getId() == "mushroomPatch") 
            {
                talkLine = characterCycle->getTalkMushroomPatch();
                characterName = characterCycle->getName();
            } 
            if (currentLocation->getId() == "duchessHomeExt") 
            {
                talkLine = characterCycle->getTalkDuchessHomeExt();
                characterName = characterCycle->getName();
            } 
            if (currentLocation->getId() == "duchessHomeInt") 
            {
                talkLine = characterCycle->getTalkDuchessHomeInt();
                characterName = characterCycle->getName();
                characterId = characterCycle->getId();
                if (characterId == "duchess")   
                {
                    printTextFile("duchessBabyEvent.txt");
                    addInventoryItemById("UGLY_BABY");
                    locationCharacters.erase(characterCycle);
                }
            } 
            if (currentLocation->getId() == "marchHareHome") 
            {
                talkLine = characterCycle->getTalkMarchHareHome();
                characterName = characterCycle->getName();
            } 
            if (currentLocation->getId() == "royalGardens") 
            {
                talkLine = characterCycle->getTalkRoyalGardens();
                characterName = characterCycle->getName();
            } 
            if (currentLocation->getId() == "croquetField") 
            {
                talkLine = characterCycle->getTalkCroquetField();
                characterName = characterCycle->getName();
            } 
            if (currentLocation->getId() == "royalBeach") 
            {
                talkLine = characterCycle->getTalkRoyalBeach();
                characterName = characterCycle->getName();
            } 
            if (currentLocation->getId() == "throne") 
            {
                talkLine = characterCycle->getTalkThrone();
                characterName = characterCycle->getName();
            }

            //edge case if a character is present but doesn't have a talk line - the player should never see this message in final draft.
            if (talkLine == "NULL")
            {
                std::cout << characterName << " has nothing to say to you." << std::endl;
                return;
            }

            // Print the talk line
            std::cout << characterName << ": " << talkLine << std::endl;
            return;
        }
    }

    std::cerr << "Character not found in the current location." << std::endl;
}

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

void Game::inspectCommand(const std::string &input) 
{
    std::string inputString = input;

    // Check if the input refers to a direction
    if (inputString == "north" || inputString == "n" && currentLocation->getNorthDesc() != "NULL")
    {
        if (currentLocation->getNorthDesc() == "NULL") {
            std::cout << "There's nothing of interest in that direction." << std::endl;
            return;
        }
        std::cout << currentLocation->getNorthDesc() << std::endl;
        return;
    }
    else if (inputString == "south" || inputString == "s" && currentLocation->getSouthDesc() != "NULL")
    {
        if (currentLocation->getSouthDesc() == "NULL") {
            std::cout << "There's nothing of interest in that direction." << std::endl;
            return;
        }
        std::cout << currentLocation->getSouthDesc() << std::endl;
        return;
    }
    else if (inputString == "east" || inputString == "e" && currentLocation->getEastDesc() != "NULL")
    {
        if (currentLocation->getEastDesc() == "NULL") {
            std::cout << "There's nothing of interest in that direction." << std::endl;
            return;
        }
        std::cout << currentLocation->getEastDesc() << std::endl;
        return;
    }
    else if (inputString == "west" || inputString == "w" && currentLocation->getWestDesc() != "NULL")
    {
        if (currentLocation->getWestDesc() == "NULL") {
            std::cout << "There's nothing of interest in that direction." << std::endl;
            return;
        }
        std::cout << currentLocation->getWestDesc() << std::endl;
        return;
    } 


    // Check if the input refers to a character name
    for (const auto& character : currentLocation->getCharacters())
    {
        std::string characterName = character.getName();
        // Convert the character name to lowercase
        for (int n = 0; n < characterName.length(); n++)
        {
            characterName[n] = tolower(characterName[n]);
        }

        //if the inputString is not equal to the end position of the string (meaning it found a match)
        //Get the description
        if (characterName.find(inputString) != std::string::npos)
        {
            std::cout << character.getDescription() << std::endl;
            return;
        }
    }

    // Check if the input refers to an item within the location
    for (const auto& item : currentLocation->getItems())
    {
        std::string itemName = item.getName();
        // Convert the item name to lowercase
        for (int n = 0; n < itemName.length(); n++)
        {
            itemName[n] = tolower(itemName[n]);
        }
        //if the inputString is not equal to the end position of the string (meaning it found a match)
        //Get the description
        if (itemName.find(inputString) != std::string::npos)
        {
            std::cout << item.getDescription() << std::endl;
            return;
        }
    }

    // Check if the input refers to an item within player's inventory
    for (const auto& item : inventory.getItems())
    {
        std::string itemName = item.getName();
        // Convert the item name to lowercase
        for (int n = 0; n < itemName.length(); n++)
        {
            itemName[n] = tolower(itemName[n]);
        }
        //if the inputString is not equal to the end position of the string (meaning it found a match)
        //Get the description
        if (itemName.find(inputString) != std::string::npos)
        {
            std::cout << item.getDescription() << std::endl;
            return;
        }
    }

    // Check if the input refers to a location name

    std::string locationName = currentLocation->getName();
    // Convert the location name to lowercase
    for (int n = 0; n < locationName.length(); n++)
    {
        locationName[n] = tolower(locationName[n]);
    }
    //if the inputString is not equal to the end position of the string (meaning it found a match)
    //Get the description
    if (locationName.find(inputString) != std::string::npos) 
    {
        std::cout << currentLocation->getDescription() << std::endl;
        return;
    } 

    std::cerr << "Cannot inspect: " << inputString << std::endl;
}

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

// Used for debugging - can be called with display command from in game
void Game::display()
{
        std::cout << "DISPLAY" << std::endl;
        std::cout << "Current Location: " << currentLocation->getName() << std::endl;
        std::cout << "Location Items: " << std::endl;            //DEBUGGING CODE - NOT NEEDED
        for (const Item& item : currentLocation->getItems())        //DEBUGGING CODE - NOT NEEDED
        {
            std::cout << " - " << item.getId() << ": " << item.getName() << std::endl;  //DEBUGGING CODE - NOT NEEDED
        }
        std::cout << "Location Characters: " << std::endl;  
        for (const Character& character: currentLocation->getCharacters())
        {
            std::cout << " - " << character.getName() << std::endl;     //DEBUGGING CODE - NOT NEEDED
        }
        std::cout << "Current Player Effect: " << playerEffect << std::endl;    //DEBUGGING CODE - NOT NEEDED
        bool firstVisit = currentLocation->getFirstVisit(); //DEBUGGING CODE
        std::cout << "First visit: " << (firstVisit ? "true" : "false") << std::endl; //DEBUGGING CODE
}

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

//Used to print text files to the terminal - used for long exposition or events
void Game::printTextFile(const std::string& filename) const 
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << filename << std::endl;
        return;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
        std::cout << "...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    file.close();
}

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

//used for key items that unlock a location cell
void Game::handleUnlockEffect(const std::string& locationId)
{
    for (auto& location : locations)
    {
        //for the first visit load a story txt file then transports player to beachBank location
        if (currentLocation->getId() == "doorwayHall" && currentLocation->getFirstVisit() == true)
        {
            addItemToLocation("SHRINK_TONIC");
            currentLocation->setSouthIsLocked(false);
            std::cout << "The door is now open but there's no way for me to fit through at my current size." << std::endl;
            std::cout << "Alice looks back at the glass table and notices a tonic bottle there now," << std::endl;
            std::cout << "That certainly wasn't there before, was it?" << std::endl;
            return;
        }
        //for second visit to doorwayhall area allows player to unlock door to royal gardens
        if (currentLocation->getId() == "doorwayHall" && currentLocation->getFirstVisit() == false)
        {
            currentLocation->setSouthIsLocked(false);
            std::cout << "You've unlocked the door to the Gardens!" << std::endl;
            return;
        }
    }
    std::cerr << "Location to unlock not found." << std::endl;
}

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

// function to remove all whitespace from a string - mostly just used for the events variable 
// in Locations class as it cannot load the text file properly without removing the invisible whitespace 
std::string Game::removeAllWhitespace(const std::string& input) 
{
    std::string result = input;
    result.erase(std::remove_if(result.begin(), result.end(), isspace), result.end());
    return result;
}

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

void Game::addInventoryItemById(const std::string& itemId)
{
    //loops through the items vector until it matches the id with the user input itemID then adds item to inventory
    for (auto& item : items)
    {
        if (item.getId() == itemId)
        {
             inventory.addItem(item);
             return;
        }
    }
    std::cout << "Item not found!" << std::endl;
}

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

void Game::addCharacterToLocation(const std::string& characterId)
{
    for (auto& character : characters)
    {
        if (character.getId() == characterId)
        {
            currentLocation->addCharacter(character);
            return;
        }
    }
    std::cout << "Character not found!" << std::endl;
}

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

void Game::addItemToLocation(const std::string& itemId)
{
    for (auto& item : items)
    {
        if (item.getId() == itemId)
        {
            currentLocation->addItem(item);
            return;
        }
    }
    std::cout << "Item not found!" << std::endl;
}

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

void Game::setPlayerLocation(const std::string& locationId)
{
    for (auto& location : locations)
    {
        if (location.getId() == locationId)
        {
            currentLocation = &location;        //Updates the players location to the current location iteration pointer - effectively changing the player's current location 
            return;
        }
    }
    std::cerr << "Location not found!" << std::endl;
}

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

void Game::removeCharacterFromLocation(const std::string& characterId)
{
    auto &locationCharacters = currentLocation->getCharacters();

    for (auto characterCycle = locationCharacters.begin(); characterCycle != locationCharacters.end(); ++characterCycle) 
    {
        std::string charId = characterCycle->getId();
        if (charId == characterId)   
        {
        locationCharacters.erase(characterCycle);
        return;
        }
    }
    std::cerr << "Character not found in the current location." << std::endl;
}