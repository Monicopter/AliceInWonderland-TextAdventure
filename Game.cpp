#include <iostream>
#include <fstream>

#include <string>
#include <vector>

#include "Game.hpp"
#include "Locations.hpp"


Game::Game()
{
    currentLocation = nullptr;
}

Game::~Game()
{

}

void Game::startGame()
{
    std::cout << "Welcome to the Alice in Wonderland Text Adventure Game!" << std::endl;
    std::cout << "In this game, you will play as Alice; a curious and adventurous young girl." << std::endl;
    loadGameData();

    if (!locations.empty()) {
        currentLocation = &locations[0];
        std::cout << "Current Location: " << currentLocation->getName() << std::endl;
        std::cout << "Description: " << currentLocation->getDescription() << std::endl;
    } else {
        std::cerr << "No locations loaded." << std::endl;
    }

}

void Game::loadGameData()
{
    // loadCharacters();
    loadLocations();
    // loadItems();
}

// void Game::loadCharacters()
// {

// }

void Game::loadLocations()
{
    std::ifstream file("Locations.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open Locations.txt" << std::endl;
        return;
    }

    std::string line;
    Location location;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        if (line[0] == '#') {
            if (!location.getId().empty()) {
                locations.push_back(location);
                location = Location();
            }
        } 
        if (line.find("id: ") == 0) {
            location.setId(line.substr(4));
        } 
        if (line.find("name: ") == 0) {
            location.setName(line.substr(6));
        } 
        if (line.find("description: ") == 0) {
            location.setDescription(line.substr(13));
        } 
        if (line.find("items: ") == 0) {
            location.setItems(line.substr(7));
        } 
        if (line.find("characters: ") == 0) {
            location.setCharacters(line.substr(12));
        } 
        if (line.find("pathNorth: ") == 0) {
            location.setPathNorth(line.substr(11));
        } 
        if (line.find("pathSouth: ") == 0) {
            location.setPathSouth(line.substr(11));
        } 
        if (line.find("pathEast: ") == 0) {
            location.setPathEast(line.substr(10));
        } 
        if (line.find("pathWest: ") == 0) {
            location.setPathWest(line.substr(10));
        } 
        if (line.find("northDesc: ") == 0) {
            location.setNorthDesc(line.substr(11));
        } 
        if (line.find("southDesc: ") == 0) {
            location.setSouthDesc(line.substr(11));
        } 
        if (line.find("eastDesc: ") == 0) {
            location.setEastDesc(line.substr(10));
        } 
        if (line.find("westDesc: ") == 0) {
            location.setWestDesc(line.substr(10));
        } 
        if (line.find("northIsLocked: ") == 0) {
            location.setNorthIsLocked(line.substr(15) == "false");
        }
        if (line.find("southIsLocked: ") == 0) {
            location.setSouthIsLocked(line.substr(15) == "false");
        }
        if (line.find("eastIsLocked: ") == 0) {
            location.setEastIsLocked(line.substr(14) == "false");
        }
        if (line.find("westIsLocked: ") == 0) {
            location.setWestIsLocked(line.substr(14) == "false");
        }
        if (line.find("northKey: ") == 0) {
            location.setNorthKey(line.substr(10));
        }
        if (line.find("southKey: ") == 0) {
            location.setSouthKey(line.substr(10));
        }
        if (line.find("eastKey: ") == 0) {
            location.setEastKey(line.substr(9));
        }
        if (line.find("westKey: ") == 0) {
            location.setWestKey(line.substr(9));
        }
        
    }

    if (!location.getId().empty()) {
        locations.push_back(location);
    }

    file.close();
}


// void Game::loadItems()
// {

// }


// void Game::playerInput(const std::string &input)
// {
// }

// void Game::update()
// {
// }

// void Game::display()
// {
// }


// void Game::handleAction(const std::string &action)
// {
// }