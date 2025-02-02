
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

#include "Game.hpp"
#include "Locations.hpp"


Game::Game()
{

}

Game::~Game()
{

}

void Game::startGame()
{
    std::cout << "Welcome to the Alice in Wonderland Text Adventure Game!" << std::endl;
    std::cout << "In this game, you will play as Alice; a curious and adventurous young girl." << std::endl;
    loadGameData();
    currentLocation = &locations[0];

}

void Game::loadGameData()
{
    loadCharacters();
    loadLocations();
    loadItems();
}

void Game::loadCharacters()
{

}

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
            if (!location.id.empty()) {
                locations.push_back(location);
                location = Location();
            }
        } 
        if (line.find("id: ") == 0) {
            location.id = line.substr(4);
        } 
        if (line.find("name: ") == 0) {
            location.name = line.substr(6);
        } 
        if (line.find("description: ") == 0) {
            location.description = line.substr(13);
        } 
        if (line.find("items: ") == 0) {
            location.items = line.substr(7);
        } 
        if (line.find("characters: ") == 0) {
            location.characters = line.substr(12);
        } 
        if (line.find("pathNorth: ") == 0) {
            location.pathNorth = line.substr(11);
        } 
        if (line.find("pathSouth: ") == 0) {
            location.pathSouth = line.substr(11);
        } 
        if (line.find("pathEast: ") == 0) {
            location.pathEast = line.substr(10);
        } 
        if (line.find("pathWest: ") == 0) {
            location.pathWest = line.substr(10);
        } 
        if (line.find("northDesc: ") == 0) {
            location.eastDesc = line.substr(11);
        } 
        if (line.find("southDesc: ") == 0) {
            location.eastDesc = line.substr(11);
        } 
        if (line.find("eastDesc: ") == 0) {
            location.eastDesc = line.substr(10);
        } 
        if (line.find("westDesc: ") == 0) {
            location.eastDesc = line.substr(10);
        } 
        if (line.find("northIsLocked: ") == 0) {
            location.northIsLocked = line.substr(15);
        }
        if (line.find("southIsLocked: ") == 0) {
            location.southIsLocked = line.substr(15);
        }
        if (line.find("eastIsLocked: ") == 0) {
            location.eastIsLocked = line.substr(14);
        }
        if (line.find("westIsLocked: ") == 0) {
            location.westIsLocked = line.substr(14);
        }
        if (line.find("northKey: ") == 0) {
            location.northUnlockReq = line.substr(10);
        }
        if (line.find("southKey: ") == 0) {
            location.southUnlockReq = line.substr(10);
        }
        if (line.find("eastKey: ") == 0) {
            location.eastUnlockReq = line.substr(9);
        }
        if (line.find("westKey: ") == 0) {
            location.westUnlockReq = line.substr(9);
        }
    }

    if (!location.id.empty()) {
        locations.push_back(location);
    }

    file.close();
}

void Game::loadItems()
{

}


void Game::playerInput(const std::string &input)
{
}

void Game::update()
{
}

void Game::display()
{
}


void Game::handleAction(const std::string &action)
{
}