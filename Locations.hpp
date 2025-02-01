#include <string>
#include <typeinfo>

class Locations {

private:
    std::string id;
    std::string name;
    std::string description;
    std::string items;
    std::string characters;
    std::string pathNorth;
    std::string pathSouth;
    std::string pathEast;
    std::string pathWest;
    std::string northDesc;
    std::string southDesc;
    std::string eastDesc;
    std::string westDesc;

public:

    // Getters
    std::string getId() const;
    std::string getName() const;
    std::string getDescription() const;
    std::string getItems() const;
    std::string getCharacters() const;
    std::string getPathNorth() const;
    std::string getPathSouth() const;
    std::string getPathEast() const;
    std::string getPathWest() const;
    std::string getNorthDesc() const;
    std::string getSouthDesc() const;
    std::string getEastDesc() const;
    std::string getWestDesc() const;

    // Setters
    void setId(const std::string& id);
    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setItems(const std::string& items);
    void setCharacters(const std::string& characters);
    void setPathNorth(const std::string& pathNorth);
    void setPathSouth(const std::string& pathSouth);
    void setPathEast(const std::string& pathEast);
    void setPathWest(const std::string& pathWest);
    void setNorthDesc(const std::string& northDesc);
    void setSouthDesc(const std::string& southDesc);
    void setEastDesc(const std::string& eastDesc);
    void setWestDesc(const std::string& westDesc);


};