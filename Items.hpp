#pragma once

#include <string>
#include <typeinfo>

class Item {

private:

    std::string id;
    std::string name;
    std::string description;
    bool canTake;
    bool isConsumable;
    bool isUsable;
    bool isKey; // If the item is a key to unlock a location
    std::string keyLocationId; // The ID of the location this key unlocks
    std::string consumeEffect;
    std::string useEffect;
    int takeEffect;

public:

    // Getters
    std::string getId() const;
    std::string getName() const;
    std::string getDescription() const;
    bool getCanTake() const;
    bool getIsConsumable() const;
    bool getIsUsable() const;
    bool getIsKey() const;
    std::string getKeyLocationId() const;
    std::string getConsumeEffect() const;
    std::string getUseEffect() const;
    int getTakeEffect() const;

    // Setters
    void setId(const std::string& id);
    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setCanTake(bool canTake);
    void setIsConsumable(bool isConsumable);
    void setIsUsable(bool isUsable);
    void setIsKey(bool isKey);
    void setKeyLocationId(const std::string& keyLocationId);
    void setConsumeEffect(const std::string& consumeEffect);
    void setUseEffect(const std::string& useEffect);
    void setTakeEffect(int takeEffect);


};