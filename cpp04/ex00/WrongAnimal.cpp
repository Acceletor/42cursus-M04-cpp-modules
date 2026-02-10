#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("Default") {
    std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(const std::string& type): _type(type) {
    std::cout << "WrongAnimal type constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other): _type(other._type) {
    std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal copy assignment constructor called\n";
    if (this != &other) {
        _type = other._type;
    }
    return (*this);
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal deconstructor called\n";
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal make sound depending on there type\n";
}

std::string WrongAnimal::getType() const {
    return _type;
}

