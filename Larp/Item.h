#include <iostream>;

class Item {
    private:
        std::string Name;
        std::string Description;
        float Weight;
        int Value;
        //enum Rarity;
    
    
    public:
        Item(std::string name, std::string description, float weight, int value) : 
        Name(name), Description(description), Weight(weight), Value(value) {};

};