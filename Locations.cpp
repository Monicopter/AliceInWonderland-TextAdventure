#include "Locations.hpp"
#include "Game.hpp"

// Getters
std::string Location::getId() const { return id; }
std::string Location::getName() const { return name; }
std::string Location::getDescription() const { return description; }
std::string Location::getItems() const { return items; }
std::string Location::getCharacters() const { return characters; }
std::string Location::getPathNorth() const { return pathNorth; }
std::string Location::getPathSouth() const { return pathSouth; }
std::string Location::getPathEast() const { return pathEast; }
std::string Location::getPathWest() const { return pathWest; }
std::string Location::getNorthDesc() const { return northDesc; }
std::string Location::getSouthDesc() const { return southDesc; }
std::string Location::getEastDesc() const { return eastDesc; }
std::string Location::getWestDesc() const { return westDesc; }
bool Location::getNorthIsLocked() const { return northIsLocked; }
bool Location::getSouthIsLocked() const { return southIsLocked; }
bool Location::getEastIsLocked() const { return eastIsLocked; }
bool Location::getWestIsLocked() const { return westIsLocked; }

// Assign keys to an item class object after completing item class
std::string Location::getNorthKey() const { return northKey; }
std::string Location::getSouthKey() const { return southKey; }
std::string Location::getEastKey() const { return eastKey; }
std::string Location::getWestKey() const { return westKey; }


//add an int counter or boolean for first visit to an area?

/*---------------------------------------------------------------------------*/

// Setters
void Location::setId(const std::string& id) { this->id = id; }
void Location::setName(const std::string& name) { this->name = name; }
void Location::setDescription(const std::string& description) { this->description = description; }
void Location::setItems(const std::string& items) { this->items = items; }
void Location::setCharacters(const std::string& characters) { this->characters = characters; }
void Location::setPathNorth(const std::string& pathNorth) { this->pathNorth = pathNorth; }
void Location::setPathSouth(const std::string& pathSouth) { this->pathSouth = pathSouth; }
void Location::setPathEast(const std::string& pathEast) { this->pathEast = pathEast; }
void Location::setPathWest(const std::string& pathWest) { this->pathWest = pathWest; }
void Location::setNorthDesc(const std::string& northDesc) { this->northDesc = northDesc; }
void Location::setSouthDesc(const std::string& southDesc) { this->southDesc = southDesc; }
void Location::setEastDesc(const std::string& eastDesc) { this->eastDesc = eastDesc; }
void Location::setWestDesc(const std::string& westDesc) { this->westDesc = westDesc; }
void Location::setNorthIsLocked(bool northIsLocked) { this->northIsLocked = northIsLocked; }
void Location::setSouthIsLocked(bool southIsLocked) { this->southIsLocked = southIsLocked; }
void Location::setEastIsLocked(bool eastIsLocked) { this->eastIsLocked = eastIsLocked; }
void Location::setWestIsLocked(bool westIsLocked) { this->westIsLocked = westIsLocked; }

// Assign keys to an item class object after completing item class
void Location::setNorthKey(const std::string& northKey) { this->northKey = northKey; }
void Location::setSouthKey(const std::string& southKey) { this->southKey = southKey; }
void Location::setEastKey(const std::string& eastKey) { this->eastKey = eastKey; }
void Location::setWestKey(const std::string& westKey) { this->westKey = westKey; }

//add an int counter or boolean for first visit to an area?