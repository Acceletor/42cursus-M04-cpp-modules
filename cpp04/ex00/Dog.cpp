#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
    std::cout << _type << " default constructor called\n";
}

Dog::Dog(const Dog& other): Animal(other) {
    std::cout << _type << " copy constructor called\n";
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << _type << " copy assignment constructor called\n";
    if (this != &other) {
        Animal::operator=(other);
    }
    return (*this);
}

Dog::~Dog() {
    std::cout << "Dog deconstructor called\n";
}

void Dog::makeSound() const {
    std::cout << "woof woof woof~\n";
}