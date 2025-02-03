
void Game::startGame()
{
    std::cout << "Welcome to the Alice in Wonderland Text Adventure Game!" << std::endl;
    std::cout << "In this game, you will play as Alice; a curious and adventurous young girl." << std::endl;
    loadGameData();

    if (!locations.empty()) {
        currentLocation = &locations[0];
        std::cout << "Current Location: " << currentLocation->getName() << std::endl;
        std::cout << "Description: " << currentLocation->getDescription() << std::endl;
        std::cout << "Items: " << currentLocation->getItems() << std::endl;
        std::cout << "Characters: " << currentLocation->getCharacters() << std::endl;
        std::cout << "Paths: " << std::endl;
        std::cout << "North: " << currentLocation->getPathNorth() << std::endl;
        std::cout << "South: " << currentLocation->getPathSouth() << std::endl;
        std::cout << "East: " << currentLocation->getPathEast() << std::endl;
        std::cout << "West: " << currentLocation->getPathWest() << std::endl;
        std::cout << "North Description: " << currentLocation->getNorthDesc() << std::endl;
        std::cout << "South Description: " << currentLocation->getSouthDesc() << std::endl;
        std::cout << "East Description: " << currentLocation->getEastDesc() << std::endl;
        std::cout << "West Description: " << currentLocation->getWestDesc() << std::endl;
        std::cout << "North is Locked: " << currentLocation->getNorthIsLocked() << std::endl;
        std::cout << "South is Locked: " << currentLocation->getSouthIsLocked() << std::endl;
        std::cout << "East is Locked: " << currentLocation->getEastIsLocked() << std::endl;
        std::cout << "West is Locked: " << currentLocation->getWestIsLocked() << std::endl;
        std::cout << "North Key: " << currentLocation->getNorthKey() << std::endl;
        std::cout << "South Key: " << currentLocation->getSouthKey() << std::endl;
        std::cout << "East Key: " << currentLocation->getEastKey() << std::endl;
        std::cout << "West Key: " << currentLocation->getWestKey() << std::endl;




    } else {
        std::cerr << "No locations loaded." << std::endl;
    }
