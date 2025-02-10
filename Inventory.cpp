#include "Inventory.hpp"
//#include "Game.hpp"
#include <iostream>

//takes an item object and adds it to the inventory map using the item Class's ID as the key
void Inventory::addItem(const Item& item) {
    items[item.getId()]++;
}

//loops through the items map and prints the item ID and count that currently exist in the inventory
void Inventory::printInventory() const {
    std::cout << "Inventory:" << std::endl;
    for (const auto& [key, val] : items) {
        std::cout << " - " << key << ": " << val << std::endl;
    }
}