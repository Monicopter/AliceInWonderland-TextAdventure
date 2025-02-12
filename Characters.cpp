#include "Characters.hpp"

// Getters
std::string Character::getId() const { return id; }
std::string Character::getName() const { return name; }
std::string Character::getDescription() const { return description; }
std::string Character::getTalkRiverBank() const { return talk_riverBank; }
std::string Character::getTalkRabbitHole() const { return talk_rabbitHole; }
std::string Character::getTalkLandingHall() const { return talk_landingHall; }
std::string Character::getTalkDoorwayHall() const { return talk_doorwayHall; }
std::string Character::getTalkBeachBank() const { return talk_beachBank; }
std::string Character::getTalkWhiteRabbitHome() const { return talk_whiteRabbitHome; }
std::string Character::getTalkDenseWoods() const { return talk_denseWoods; }
std::string Character::getTalkMushroomPatch() const { return talk_mushroomPatch; }
std::string Character::getTalkDuchessHomeExt() const { return talk_duchessHomeExt; }
std::string Character::getTalkDuchessHomeInt() const { return talk_duchessHomeInt; }
std::string Character::getTalkMarchHareHome() const { return talk_marchHareHome; }
std::string Character::getTalkRoyalGardens() const { return talk_royalGardens; }
std::string Character::getTalkCroquetField() const { return talk_croquetField; }
std::string Character::getTalkRoyalBeach() const { return talk_royalBeach; }
std::string Character::getTalkThrone() const { return talk_throne; }

// Setters
void Character::setId(const std::string& id) { this->id = id; }
void Character::setName(const std::string& name) { this->name = name; }
void Character::setDescription(const std::string& description) { this->description = description; }
void Character::setTalkRiverBank(const std::string& talk_riverBank) { this->talk_riverBank = talk_riverBank; }
void Character::setTalkRabbitHole(const std::string& talk_rabbitHole) { this->talk_rabbitHole = talk_rabbitHole; }
void Character::setTalkLandingHall(const std::string& talk_landingHall) { this->talk_landingHall = talk_landingHall; }
void Character::setTalkDoorwayHall(const std::string& talk_doorwayHall) { this->talk_doorwayHall = talk_doorwayHall; }
void Character::setTalkBeachBank(const std::string& talk_beachBank) { this->talk_beachBank = talk_beachBank; }
void Character::setTalkWhiteRabbitHome(const std::string& talk_whiteRabbitHome) { this->talk_whiteRabbitHome = talk_whiteRabbitHome; }
void Character::setTalkDenseWoods(const std::string& talk_denseWoods) { this->talk_denseWoods = talk_denseWoods; }
void Character::setTalkMushroomPatch(const std::string& talk_mushroomPatch) { this->talk_mushroomPatch = talk_mushroomPatch; }
void Character::setTalkDuchessHomeExt(const std::string& talk_duchessHomeExt) { this->talk_duchessHomeExt = talk_duchessHomeExt; }
void Character::setTalkDuchessHomeInt(const std::string& talk_duchessHomeInt) { this->talk_duchessHomeInt = talk_duchessHomeInt; }
void Character::setTalkMarchHareHome(const std::string& talk_marchHareHome) { this->talk_marchHareHome = talk_marchHareHome; }
void Character::setTalkRoyalGardens(const std::string& talk_royalGardens) { this->talk_royalGardens = talk_royalGardens; }
void Character::setTalkCroquetField(const std::string& talk_croquetField) { this->talk_croquetField = talk_croquetField; }
void Character::setTalkRoyalBeach(const std::string& talk_royalBeach) { this->talk_royalBeach = talk_royalBeach; }
void Character::setTalkThrone(const std::string& talk_throne) { this->talk_throne = talk_throne; }