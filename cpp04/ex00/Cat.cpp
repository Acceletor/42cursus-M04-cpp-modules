#include "Cat.hpp"

Cat::Cat(): Animal("Cat") {
    std::cout << _type << " default constructor called\n";
}

// Cat::Cat(const std::string& type): Animal(type) {
//     std::cout << "Cat constructor called\n";
// }

Cat::Cat(const Cat& other): Animal(other) {
    std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat copy assignment constructor called\n";
    if (this != &other) {
        Animal::operator=(other);
    }
    return (*this);
}

Cat::~Cat() {
    std::cout << "Cat deconstructor called\n";
}

void Cat::makeSound() const{
    std::cout << "meow meow meow~\n";
}