#include "Locations.hpp"

// Getters
std::string Locations::getId() const { return id; }
std::string Locations::getName() const { return name; }
std::string Locations::getDescription() const { return description; }
std::string Locations::getItems() const { return items; }
std::string Locations::getCharacters() const { return characters; }
std::string Locations::getPathNorth() const { return pathNorth; }
std::string Locations::getPathSouth() const { return pathSouth; }
std::string Locations::getPathEast() const { return pathEast; }
std::string Locations::getPathWest() const { return pathWest; }
std::string Locations::getNorthDesc() const { return northDesc; }
std::string Locations::getSouthDesc() const { return southDesc; }
std::string Locations::getEastDesc() const { return eastDesc; }
std::string Locations::getWestDesc() const { return westDesc; }

// Setters
void Locations::setId(const std::string& id) { this->id = id; }
void Locations::setName(const std::string& name) { this->name = name; }
void Locations::setDescription(const std::string& description) { this->description = description; }
void Locations::setItems(const std::string& items) { this->items = items; }
void Locations::setCharacters(const std::string& characters) { this->characters = characters; }
void Locations::setPathNorth(const std::string& pathNorth) { this->pathNorth = pathNorth; }
void Locations::setPathSouth(const std::string& pathSouth) { this->pathSouth = pathSouth; }
void Locations::setPathEast(const std::string& pathEast) { this->pathEast = pathEast; }
void Locations::setPathWest(const std::string& pathWest) { this->pathWest = pathWest; }
void Locations::setNorthDesc(const std::string& northDesc) { this->northDesc = northDesc; }
void Locations::setSouthDesc(const std::string& southDesc) { this->southDesc = southDesc; }
void Locations::setEastDesc(const std::string& eastDesc) { this->eastDesc = eastDesc; }
void Locations::setWestDesc(const std::string& westDesc) { this->westDesc = westDesc; }