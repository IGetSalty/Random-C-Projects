#include <iostream>;

class Item {
    public:
        std::string Name;
        std::string Description;
        float Weight;
        int Value;
        enum class Rarity {
            Common,
            Uncommon,
            Rare,
            Epic,
            Legendary
        };

        Item(std::string name, std::string description, float weight, int value) : 
        Name(name), Description(description), Weight(weight), Value(value) {};

};





