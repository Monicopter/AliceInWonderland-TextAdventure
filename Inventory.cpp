#include "Inventory.hpp"
#include <iostream>

//takes an item object and adds it to the inventory map using the item Class's ID as the key
void Inventory::addItem(const Item& item) {
    items.push_back(item);
    itemCounts[item.getId()] += 1; // Increment the count for the item ID
}

//loops through the items map and prints the item ID and count that currently exist in the inventory
void Inventory::printInventory() const {
    std::cout << "Inventory:" << std::endl;
    for (const auto& item : items) {
        std::cout << " - " << item.getName() << ": " << itemCounts.at(item.getId()) << std::endl;
    }
}

std::vector<Item>& Inventory::getItems() {
    return items;
}