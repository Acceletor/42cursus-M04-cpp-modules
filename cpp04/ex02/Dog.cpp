#include "Dog.hpp"

Dog::Dog(): Animal("Dog"), _brain(new Brain())  {
    std::cout << "🐶 Dog default constructor called\n";
}

Dog::Dog(const Dog& other): Animal(other), _brain(new Brain(*other._brain)) {
    std::cout << "🐶 Dog copy constructor called\n";
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "🐶 Dog copy assignment constructor called\n";
    if (this != &other) {
        Animal::operator=(other);
        Brain* newBrain = new Brain(*other._brain);
        delete _brain;
        _brain = newBrain;
    }
    return (*this);
}

Dog::~Dog() {
    delete _brain;
    std::cout << "🐶 Dog deconstructor called\n";
}

void Dog::makeSound() const {
    std::cout << "🐶 woof woof woof~\n";
}

Brain* Dog::getBrain() const {
    return (_brain);
}