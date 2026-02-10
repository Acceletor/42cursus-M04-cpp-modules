#include "FragTrap.hpp"

FragTrap::FragTrap() {
    std::cout << "FragTrap: default constructor called\n";
    _hitPoint = 100;
    _energyPoint = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
    std::cout << "FragTrap: name constructor called\n";
    _hitPoint = 100;
    _energyPoint = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other) {
    std::cout << "FragTrap Copy constructor called.\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap: copy assignment called\n"; 
    if (this == &other)
        return (*this);
    ClapTrap::operator=(other);
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap: Deconstructor called\n";
}

void FragTrap::attack(const std::string& target) {
    if (_hitPoint == 0)
        std::cout << "FragTrap: " << _name << " is already dead and can not attack." << std::endl;
    else if (_energyPoint > 0) {
        std::cout << "FragTrap: " << _name << " attack " << target << " with " << _attackDamage << " damage!!\n";
        _energyPoint -= 1;
    }
    else
        std::cout << "FragTrap: " << _name << " not enough energy point!!\n";
}

void FragTrap::highFivesGuys(void) {
    if (_hitPoint > 0) {
        std::cout << "FragTrap " << _name << " want to see a high five!\n";
    } else {
        std::cout << "FragTrap " << _name << "is alread dead, no high five!\n";
    }
}

