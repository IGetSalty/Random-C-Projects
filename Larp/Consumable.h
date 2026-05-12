#include "Item.h";

class Consumable: public Item {
    public:
        int EffectAmount;
        int Uses;
        std::string ConsumableType;

        Consumable(std::string name, std::string description, float weight, int value, int effectamount, int uses, std::string consumabletype) :
        Item(name, description, weight, value), EffectAmount(effectamount), Uses(uses), ConsumableType(consumabletype) {};

};
