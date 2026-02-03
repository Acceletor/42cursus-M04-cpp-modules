#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string type) {
    setType(type);
    std::cout << getType() << " CREATED" << std::endl;
}

Weapon::~Weapon(){
    std::cout << getType() << " DESTROYED" << std::endl;
}

const std::string& Weapon::getType() const {
    return _type;
}

void Weapon::setType(std::string type) {
    _type = type;
}
