#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("default"), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
    std::cout << "ClapTrap Default constructor called.\n";
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
    std::cout << "ClapTrap Name constructor called.\n";
}

ClapTrap::ClapTrap(const ClapTrap& other): _name(other._name), _hitPoint(other._hitPoint),
    _energyPoint(other._energyPoint), _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap Copy constructor called.\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this == &other)
        return (*this);
    std::cout << "ClapTrap Copy assignment constructor called.\n";
    this->_name = other._name;
    this->_hitPoint = other._hitPoint;
    this->_energyPoint = other._energyPoint;
    this->_attackDamage = other._attackDamage;
    return (*this);
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap Deconstructor called\n";
}

void ClapTrap::attack(const std::string& target) {
    if (_hitPoint == 0) 
        std::cout << "ClapTrap " << _name << "is already dead and can not attack!!\n";
    else if (_energyPoint > 0) {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
        _energyPoint -= 1;
    }
    else
        std::cout << "ClapTrap " << _name << "is has no energy points for attack!!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoint == 0 && amount != 0) {
        std::cout << "ClapTrap " << _name << "is already dead and can not take anymore damage!!\n";
    }
    else {
        std::cout << "ClapTrap " << _name << " took " << amount << " points of damage!\n";
        if (amount > _hitPoint)
            _hitPoint = 0;
        else
            _hitPoint -= amount;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoint == 0) 
        std::cout << _name << " is already dead too late to repair!!\n";
    else if (_energyPoint > 0) 
    {
        std::cout << "ClapTrap " << _name << " got " << amount << " point of repaired point!!\n";
        _hitPoint += amount;
        _energyPoint -= 1;
    }
    else
        std::cout << "Not enough energy point to repair!!\n";
}

int ClapTrap::getHitPoint() const {
    return (_hitPoint);
}

int ClapTrap::getEnergyPoint() const {
    return (_energyPoint);
}

void ClapTrap::printStatus() const {
    std::cout << "name: " << _name
              << " | energy: " << getEnergyPoint()
              << " | Health: " << getHitPoint()
              << " | attack damage: " << _attackDamage
              << std::endl; 
}
 


