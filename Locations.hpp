#pragma once

#include <string>
#include <vector>
#include "Items.hpp"
#include "Characters.hpp"

class Game;

class Location {
private:
    std::string id;
    std::string name;
    std::string description;
    std::vector<Item> items;
    std::vector<Character> characters;
    std::string pathNorth;
    std::string pathSouth;
    std::string pathEast;
    std::string pathWest;
    std::string northDesc;
    std::string southDesc;
    std::string eastDesc;
    std::string westDesc;
    bool northIsLocked;
    bool southIsLocked;
    bool eastIsLocked;
    bool westIsLocked;

    bool firstVisit;
    std::string events;

    // Assign keys to an item class object after completing item class
    std::string northKey;
    std::string southKey;
    std::string eastKey;
    std::string westKey;


public:
    // Getters
    std::string getId() const;
    std::string getName() const;
    std::string getDescription() const;
    std::vector<Item>& getItems();      //removed const from getItems() to allow for item removal in takeCommand()
    std::vector<Character>& getCharacters();
    std::string getPathNorth() const;
    std::string getPathSouth() const;
    std::string getPathEast() const;
    std::string getPathWest() const;
    std::string getNorthDesc() const;
    std::string getSouthDesc() const;
    std::string getEastDesc() const;
    std::string getWestDesc() const;
    bool getNorthIsLocked() const;
    bool getSouthIsLocked() const;
    bool getEastIsLocked() const;
    bool getWestIsLocked() const;

    bool getFirstVisit() const;
    std::string getEvents() const;

    std::string getNorthKey() const;
    std::string getSouthKey() const;
    std::string getEastKey() const;
    std::string getWestKey() const;

    // Setters
    void setId(const std::string& id);
    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setItems(const std::vector<Item>& items);
    void setCharacters(const std::vector<Character>& characters);
    void setPathNorth(const std::string& pathNorth);
    void setPathSouth(const std::string& pathSouth);
    void setPathEast(const std::string& pathEast);
    void setPathWest(const std::string& pathWest);
    void setNorthDesc(const std::string& northDesc);
    void setSouthDesc(const std::string& southDesc);
    void setEastDesc(const std::string& eastDesc);
    void setWestDesc(const std::string& westDesc);
    void setNorthIsLocked(bool northIsLocked);
    void setSouthIsLocked(bool southIsLocked);
    void setEastIsLocked(bool eastIsLocked);
    void setWestIsLocked(bool westIsLocked);

    void setFirstVisit (bool firstVisit);
    void setEvents(const std::string& events);

    // Assign keys to an item class object after completing item class
    void setNorthKey(const std::string& northKey);
    void setSouthKey(const std::string& southKey);
    void setEastKey(const std::string& eastKey);
    void setWestKey(const std::string& westKey);

    friend class Game;  //makes Game class a friend so it can access private variables (like firstVisit and events)
     
};