#pragma once

#include <map>
#include "Items.hpp"

class Inventory {
private:
    std::map<std::string, int> items; // Map to store item IDs and their counts

public:
    void addItem(const Item& item);
    void printInventory() const;
};