#include "Brain.hpp"

Brain::Brain() {
    std::cout << "🧠 Brain default constructor called\n";
}

Brain::Brain(const Brain& other) {
    std::cout << "🧠 Brain copy constructor called\n";
    *this = other;
    (void)other;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "🧠 Brain copy assignment called\n";
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            _ideas[i] = other._ideas[i];
        } 
    }
    return (*this);
}

Brain::~Brain() {
    std::cout << "🧠 Brain deconstructor called\n";
}

std::string Brain::getIdea(int index) const {
    if (index < 0 || index >= 100) {
        std::cout << "🧠 Not a valid index to get idea.\n";
        return "";
    }
    return _ideas[index];
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index < 0 || index >= 100) {
        std::cout << "🧠 Not a valid index to set idea.\n";
        return;
    }
    _ideas[index] = idea;
}