
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

#include "Game.hpp"

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
    set currentLocation = &Locations[0];

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
        } else if (line.find("id: ") == 0) {
            location.id = line.substr(4);
        } else if (line.find("name: ") == 0) {
            location.name = line.substr(6);
        } else if (line.find("description: ") == 0) {
            location.description = line.substr(13);
        } else if (line.find("items: ") == 0) {
            location.items = line.substr(7);
        } else if (line.find("characters: ") == 0) {
            location.characters = line.substr(12);
        } else if (line.find("pathNorth: ") == 0) {
            location.pathNorth = line.substr(11);
        } else if (line.find("pathSouth: ") == 0) {
            location.pathSouth = line.substr(11);
        } else if (line.find("pathEast: ") == 0) {
            location.pathEast = line.substr(10);
        } else if (line.find("pathWest: ") == 0) {
            location.pathWest = line.substr(10);
        } else if (line.find("northDesc: ") == 0) {
            location.eastDesc = line.substr(11);
        } else if (line.find("southDesc: ") == 0) {
            location.eastDesc = line.substr(11);
        } else if (line.find("eastDesc: ") == 0) {
            location.eastDesc = line.substr(10);
        } else if (line.find("westDesc: ") == 0) {
            location.eastDesc = line.substr(10);
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
