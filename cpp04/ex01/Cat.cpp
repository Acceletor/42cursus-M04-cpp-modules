#include "Cat.hpp"

Cat::Cat(): Animal("Cat"), _brain(new Brain()) {
    std::cout << "🐈 Cat default constructor called\n";
}

Cat::Cat(const Cat& other): Animal(other), _brain(new Brain(*other._brain)) {
    std::cout << "🐈 Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "🐈 Cat copy assignment constructor called\n";
    if (this != &other) {
        Animal::operator=(other);
        Brain* newBrain = new Brain(*other._brain);
        delete _brain;
        _brain = newBrain;
    }
    return (*this);
}

Cat::~Cat() {
    delete _brain;
    std::cout << "🐈 Cat deconstructor called\n";
}

void Cat::makeSound() const{
    std::cout << "🐈 meow meow meow~\n";
}

Brain* Cat::getBrain() const{
    return (this->_brain);
}