#include <iostream>
#include <limits>
#include <vector>
#include <memory>

class Weapon {
    public: 
        std::string Name;
        std::string Kind;
        int Length; //in centimetre up to 1m
        float Danger; //a scale between 0 and 1. 1 most danger
    
        Weapon() : Name(""), Kind(""), Length(50), Danger(0.5) {} //default constructor

        Weapon(std::string name, std::string kind, int length, float danger) //constructor 
            : Name(name),Kind(kind),Length(length),Danger(danger) {} 

        ~Weapon() {  //destructor
            std::cout << "Deleting Weapons" << std::endl;
        }
        
};      

void printDetails(std::unique_ptr<Weapon>& a) {
    std::cout << a -> Name << " " << a -> Kind << " " << a -> Length << " " << a -> Danger << std::endl;
}

int main() {

    //Weapon sword("Excalibur","Sword",90,0.7); //Creates a stack object called sword
    //Weapon* sword = new Weapon("Excalibur","Sword",90,0.7);//Creates a pointer to a heap object (sword)
    //but MUST remember to manually delete (not good)
    std::unique_ptr<Weapon> sword = std::make_unique<Weapon>("Excalibur","Sword",90,0.7); //Makes a smart pointer
    printDetails(sword);
    std::cin.get();
}