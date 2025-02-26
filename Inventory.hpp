#pragma once

#include <vector>
#include <map>

#include "Items.hpp"

class Inventory {
private:
    std::map<std::string, int> itemCounts; // Map to store item IDs and their counts
    std::vector<Item> items; // Vector to store the items in the player's inventory

public:
    void addItem(const Item& item);
    void decrementItem(const Item& item);
    void printInventory() const;
    std::vector<Item>& getItems(); // Method to get the items vector for player's inventory
};