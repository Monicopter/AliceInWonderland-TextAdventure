#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

#include "Game.hpp"

/*----------------------------------------------------------------------------*/

Game::Game()
{
    currentLocation = nullptr;
}

/*----------------------------------------------------------------------------*/

Game::~Game()
{
}

/*----------------------------------------------------------------------------*/

void Game::startGame()
{
    // std::cout << "Welcome to the Alice in Wonderland Text Adventure Game!" << std::endl;
    // std::cout << "In this game, you will play as Alice; a curious and imaginative young girl.\n" << std::endl;
    // std::cout << "You begin your adventure on the bank of a river, your older sister is sitting not far off, completely absorbed into her novel." << std::endl;
    // std::cout << "where you see a White Rabbit with a pocket watch.\n" << std::endl;

    // printTextFile("Intro.txt");
    loadGameData();

    if (!locations.empty())
    {
        currentLocation = &locations[0];
        std::cout << "Current Location: " << currentLocation->getName() << std::endl;
        std::cout << "Description: " << currentLocation->getDescription() << std::endl;
    }
    else
    {
        std::cerr << "No locations loaded." << std::endl;
    }
}

/*----------------------------------------------------------------------------*/

void Game::loadGameData()
{
    loadLocations();
    // loadActions();
    loadItems();
    // loadCharacters();
    // loadInventory();
}

/*----------------------------------------------------------------------------*/

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
            location.setId(line.substr(4)); // Set the id of the location object to the rest of the line starting at the 4th character index
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
            location.setItems(line.substr(7));
        }
        if (line.find("characters: ") == 0)
        {
            location.setCharacters(line.substr(12));
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

/*----------------------------------------------------------------------------*/

// void Game::loadActions()
// {

// }

/*----------------------------------------------------------------------------*/

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
    if (line.find("takeEffect: ") == 0)
    {
        item.setTakeEffect(std::stoi(line.substr(12)));
    }
}

/*----------------------------------------------------------------------------*/

// void Game::loadCharacters()
// {

// }

/*----------------------------------------------------------------------------*/

// void Game::loadInventory()
// {

// }

/*----------------------------------------------------------------------------*/

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
        nextLocationId = currentLocation->getPathNorth();
        break;
    case Direction::SOUTH:
        nextLocationId = currentLocation->getPathSouth();
        break;
    case Direction::EAST:
        nextLocationId = currentLocation->getPathEast();
        break;
    case Direction::WEST:
        nextLocationId = currentLocation->getPathWest();
        break;
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
            currentLocation = &location; // sets the current location to the location element in the locations vector - if it matches location.getId()
            std::cout << "Moved to: " << currentLocation->getName() << std::endl;
            std::cout << "Description: " << currentLocation->getDescription() << std::endl;
            return;
        }
    }
    std::cerr << "Cannot move in that direction." << std::endl;
}

/*----------------------------------------------------------------------------*/

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

    // looping the first command (commands[0]) through the actionMap to find a matching keyword
    auto it = actionMap.find(commands[0]);
    // if the commands[0] is NOT equal to the end of the actionMap - that means it DID find a matching keyword
    if (it != actionMap.end())
    {
        // switch statement (it->second) pulls the value of the keyword from the actionMap which would be ACTION::HELP, ACTION::INSPECT, etc.
        switch (it->second)
        {
        case Action::HELP:
            printHelp();
            break;
        case Action::INSPECT:
            std::cout << "Inspect" << std::endl;
            std::cout << "Current Location: " << currentLocation->getName() << std::endl;
            break;
        case Action::TALK:
            std::cout << "Talk" << std::endl;
            break;
        case Action::TAKE:
            std::cout << "Take" << std::endl;
            break;
        case Action::USE:
            std::cout << "Use" << std::endl;
            break;
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
        case Action::INVENTORY:
            std::cout << "Inventory" << std::endl;
            break;
        case Action::CONSUME:
            std::cout << "Consume" << std::endl;
            break;
        case Action::QUIT:
            std::cout << "Exiting game, Goodbye..." << std::endl;
            exit(0);
        default:
            break;
        }
    }
    else
    {
        std::cerr << "Invalid action! Type 'help' for a list of commands!" << std::endl;
    }
}

/*----------------------------------------------------------------------------*/

void Game::playerDirectionalInput(const std::string &input)
{

    if (input == "north" || input == "n")
    {
        move(Direction::NORTH);
    }
    else if (input == "south" || input == "s")
    {
        move(Direction::SOUTH);
    }
    else if (input == "east" || input == "e")
    {
        move(Direction::EAST);
    }
    else if (input == "west" || input == "w")
    {
        move(Direction::WEST);
    }
    else
    {
        std::cerr << "Invalid direction. Use north, south, east, or west." << std::endl;
    }
}

/*----------------------------------------------------------------------------*/

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

/*----------------------------------------------------------------------------*/

// void Game::update()
// {
// }

/*----------------------------------------------------------------------------*/

// void Game::display()
// {
// }

/*----------------------------------------------------------------------------*/


void Game::printTextFile(const std::string& filename) const {

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
        std::cout << "Press Enter";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    file.close();
}
