#include "Item.h";

class Weapon: public Item {
    public:
        int Damage;
        int Durability;
        float CriticalChance;
        std::string WeaponType;
        bool TwoHanded;

        Weapon(std::string name, std::string description, float weight, int value, int damage, int durability, float criticalchance,
        std::string weapontype, bool twohanded) : //enum?
        Item(name,description,weight,value), Damage(damage),Durability(durability),CriticalChance(criticalchance), 
        WeaponType(weapontype),TwoHanded(twohanded)   {};
};