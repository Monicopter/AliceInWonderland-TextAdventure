


//Testing of Getters and Setters
currentLocation->setName("Test Name");
std::cout << "Current Location: " << currentLocation->getName() << std::endl;
currentLocation->setDescription("Test Description");
std::cout << "Description: " << currentLocation->getDescription() << std::endl;
currentLocation->setItems("Test Items");
std::cout << "Items: " << currentLocation->getItems() << std::endl;
currentLocation->setCharacters("Test Characters");
std::cout << "Characters: " << currentLocation->getCharacters() << std::endl;


std::cout << "Paths: " << std::endl;
currentLocation->setPathNorth("Test Path North");
std::cout << "North: " << currentLocation->getPathNorth() << std::endl;
currentLocation->setPathSouth("Test Path South");
std::cout << "South: " << currentLocation->getPathSouth() << std::endl;
currentLocation->setPathEast("Test Path East");
std::cout << "East: " << currentLocation->getPathEast() << std::endl;
currentLocation->setPathWest("Test Path West");
std::cout << "West: " << currentLocation->getPathWest() << std::endl;

currentLocation->setNorthDesc("Test North Description");
std::cout << "North Description: " << currentLocation->getNorthDesc() << std::endl;
currentLocation->setSouthDesc("Test South Description");
std::cout << "South Description: " << currentLocation->getSouthDesc() << std::endl;
currentLocation->setEastDesc("Test East Description");
std::cout << "East Description: " << currentLocation->getEastDesc() << std::endl;
currentLocation->setWestDesc("Test West Description");
std::cout << "West Description: " << currentLocation->getWestDesc() << std::endl;

currentLocation->setNorthIsLocked(true);
std::cout << "North is Locked: " << currentLocation->getNorthIsLocked() << std::endl;
currentLocation->setNorthIsLocked(false);
std::cout << "North is Locked: " << currentLocation->getNorthIsLocked() << std::endl;
currentLocation->setSouthIsLocked(true);
std::cout << "South is Locked: " << currentLocation->getSouthIsLocked() << std::endl;
currentLocation->setSouthIsLocked(false);
std::cout << "South is Locked: " << currentLocation->getSouthIsLocked() << std::endl;
currentLocation->setEastIsLocked(true);
std::cout << "East is Locked: " << currentLocation->getEastIsLocked() << std::endl;
currentLocation->setEastIsLocked(false);
std::cout << "East is Locked: " << currentLocation->getEastIsLocked() << std::endl;
currentLocation->setWestIsLocked(true);
std::cout << "West is Locked: " << currentLocation->getWestIsLocked() << std::endl;
currentLocation->setWestIsLocked(false);
std::cout << "West is Locked: " << currentLocation->getWestIsLocked() << std::endl;

currentLocation->setNorthKey("Test North Key");
std::cout << "North Key: " << currentLocation->getNorthKey() << std::endl;
currentLocation->setSouthKey("Test South Key");
std::cout << "South Key: " << currentLocation->getSouthKey() << std::endl;
currentLocation->setEastKey("Test East Key");
std::cout << "East Key: " << currentLocation->getEastKey() << std::endl;
currentLocation->setWestKey("Test West Key");
std::cout << "West Key: " << currentLocation->getWestKey() << std::endl;

