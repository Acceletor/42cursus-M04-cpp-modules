#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat") {
    std::cout << "WrongCat default constructor called\n";
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other) {
    std::cout << "WrongCat copy constructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat copy assignment constructor called\n";
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return (*this);
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat deconstructor called\n";
}

void WrongCat::makeSound() const {
    std::cout << "WrongCat: nvka^*bf20#\n";
}