#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(), _isGuardGate(false)  {
    std::cout << "ScavTrap: default constructor called\n";
    this->_hitPoint = 100;
    this->_energyPoint = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name), _isGuardGate(false) {
    std::cout << "ScavTrap: name constructor called\n";
    this->_hitPoint = 100;
    this->_energyPoint = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other), _isGuardGate(other._isGuardGate) {
    std::cout << "ScavTrap: copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap: copy assignment called\n"; 
    if (this == &other)
        return (*this);
    ClapTrap::operator=(other);
    this->_isGuardGate = other._isGuardGate;
    return (*this);
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap: Deconstructor called\n";
}

void ScavTrap::attack(const std::string& target) {
    if (_hitPoint == 0)
        std::cout << "ScavTrap: " << _name << " is already dead and can not attack!!\n";
    else if (_energyPoint > 0) {
        std::cout << "ScavTrap: " << _name << " attack " << target << " with " << _attackDamage << " damage!!\n";
        _energyPoint -= 1;
    }
    else
        std::cout << "ScavTrap: " << _name << " not enough energy point!!\n";
}

void ScavTrap::guardGate(void) {
    if (_isGuardGate == false) {
        std::cout << "ScavTrap: " << _name << " is now in guard gate mode!!\n";
        _isGuardGate = true;
    }
    else {
        std::cout << "ScavTrap: " << _name << "'s guard gate mode is off!!\n";
        _isGuardGate = true;
    }
}

