#include "Items.hpp"

// Getters
std::string Item::getId() const { return id; }
std::string Item::getName() const { return name; }
std::string Item::getDescription() const { return description; }
bool Item::getCanTake() const { return canTake; }
bool Item::getIsConsumable() const { return isConsumable; }
bool Item::getIsUsable() const { return isUsable; }
bool Item::getIsKey() const { return isKey; }
std::string Item::getKeyLocationId() const { return keyLocationId; }
std::string Item::getConsumeEffect() const { return consumeEffect; }
std::string Item::getUseEffect() const { return useEffect; }
int Item::getTakeEffect() const { return takeEffect; }

// Setters
void Item::setId(const std::string& id) { this->id = id; }
void Item::setName(const std::string& name) { this->name = name; }
void Item::setDescription(const std::string& description) { this->description = description; }
void Item::setCanTake(bool canTake) { this->canTake = canTake; }
void Item::setIsConsumable(bool isConsumable) { this->isConsumable = isConsumable; }
void Item::setIsUsable(bool isUsable) { this->isUsable = isUsable; }
void Item::setIsKey(bool isKey) { this->isKey = isKey; }
void Item::setKeyLocationId(const std::string& keyLocationId) { this->keyLocationId = keyLocationId; }
void Item::setConsumeEffect(const std::string& consumeEffect) { this->consumeEffect = consumeEffect; }
void Item::setUseEffect(const std::string& useEffect) { this->useEffect = useEffect; }
void Item::setTakeEffect(int takeEffect) { this->takeEffect = takeEffect; }

