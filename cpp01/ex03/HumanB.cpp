#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(nullptr) {
    std::cout << "Human name " << _name << " is Created without a weapon"
        << std::endl;
}

HumanB::HumanB(std::string name, Weapon& weapon): _name(name), _weapon(&weapon) {
    std::cout << "Human name " << _name 
              << " is Created with a " << _weapon->getType()
              << std::endl;
}

HumanB::~HumanB() {
    std::cout << _name << " Died" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
    _weapon = &weapon;
}

void HumanB::attack() {
    std::cout << _name << " attacks with their "
        << _weapon->getType() << std::endl;
}
