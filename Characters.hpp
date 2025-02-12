#pragma once

#include <string>
#include <typeinfo>

class Character {

private:

    std::string id;
    std::string name;
    std::string description;
    std::string talk_riverBank;
    std::string talk_rabbitHole;
    std::string talk_landingHall;
    std::string talk_doorwayHall;
    std::string talk_beachBank;
    std::string talk_whiteRabbitHome;
    std::string talk_denseWoods;
    std::string talk_mushroomPatch;
    std::string talk_duchessHomeExt;
    std::string talk_duchessHomeInt;
    std::string talk_marchHareHome;
    std::string talk_royalGardens;
    std::string talk_croquetField;
    std::string talk_royalBeach;
    std::string talk_throne;

public:



    // Getters
    std::string getId() const;
    std::string getName() const;
    std::string getDescription() const;
    std::string getTalkRiverBank() const;
    std::string getTalkRabbitHole() const;
    std::string getTalkLandingHall() const;
    std::string getTalkDoorwayHall() const;
    std::string getTalkBeachBank() const;
    std::string getTalkWhiteRabbitHome() const;
    std::string getTalkDenseWoods() const;
    std::string getTalkMushroomPatch() const;
    std::string getTalkDuchessHomeExt() const;
    std::string getTalkDuchessHomeInt() const;
    std::string getTalkMarchHareHome() const;
    std::string getTalkRoyalGardens() const;
    std::string getTalkCroquetField() const;
    std::string getTalkRoyalBeach() const;
    std::string getTalkThrone() const;

    // Setters

    void setId(const std::string& id);
    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setTalkRiverBank(const std::string& talk_riverBank);
    void setTalkRabbitHole(const std::string& talk_rabbitHole);
    void setTalkLandingHall(const std::string& talk_landingHall);
    void setTalkDoorwayHall(const std::string& talk_doorwayHall);
    void setTalkBeachBank(const std::string& talk_beachBank);
    void setTalkWhiteRabbitHome(const std::string& talk_whiteRabbitHome);
    void setTalkDenseWoods(const std::string& talk_denseWoods);
    void setTalkMushroomPatch(const std::string& talk_mushroomPatch);
    void setTalkDuchessHomeExt(const std::string& talk_duchessHomeExt);
    void setTalkDuchessHomeInt(const std::string& talk_duchessHomeInt);
    void setTalkMarchHareHome(const std::string& talk_marchHareHome);
    void setTalkRoyalGardens(const std::string& talk_royalGardens);
    void setTalkCroquetField(const std::string& talk_croquetField);
    void setTalkRoyalBeach(const std::string& talk_royalBeach);
    void setTalkThrone(const std::string& talk_throne);


};