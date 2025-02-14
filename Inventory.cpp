#include "Inventory.hpp"
#include <iostream>

//takes an item object and adds it to the inventory map using the item Class's ID as the key
void Inventory::addItem(const Item& item) {
    items.push_back(item);
    itemCounts[item.getId()] += 1; // Increment the count for the item ID
}

void Inventory::decrementItem(const Item& item) {
    
    itemCounts[item.getId()] -= 1;
}

//loops through the items map and prints the item ID and count that currently exist in the inventory
void Inventory::printInventory() const {
    std::cout << "Inventory:" << std::endl;
    std::map<std::string, int> itemCount;
    for (const auto& item : items) {
        //Checks if the item already has been printed to terminal once, if so it skips printing it again to avoid duplication
        if (itemCount[item.getId()] >= 1) {
            break;
        } 
        itemCount[item.getId()] += 1;
        std::cout << " - " << item.getName() << ": " << itemCounts.at(item.getId()) << std::endl;
    }
}

std::vector<Item>& Inventory::getItems() {
    return items;
}