#include "Animal.hpp"

Animal::Animal(): _type("Default") {
    std::cout << "Animal default constructor called\n";
}

Animal::Animal(const std::string& type): _type(type) {
    std::cout << "Animal type constructor called\n";
}

Animal::Animal(const Animal& other): _type(other._type) {
    std::cout << "Animal copy constructor called\n";
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal copy assignment constructor called\n";
    if (this == &other)
        return (*this);
    _type = other._type;
    return (*this);
}

Animal::~Animal() {
    std::cout << "Animal deconstructor called\n";
}

void Animal::makeSound() const {
    std::cout << "Animal make sound depending on there type\n";
}

std::string Animal::getType() const {
    return (_type);
}