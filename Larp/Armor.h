#include "Item.h";

class Armor: public Item {
    public:
        int Defense;
        int Durability;
        std::string ArmorSlot;
        float MagicResistance;

        Armor(std::string name, std::string description, float weight, int value, int defense, int durability, std::string armorslot, float magicresistance) :
        Item(name,description,weight,value), Defense(defense), Durability(durability), ArmorSlot(armorslot), MagicResistance(magicresistance) {};
};