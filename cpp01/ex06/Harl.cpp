#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::_debug(void) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n" << std::endl;
}

void Harl::_info(void) {
    std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!\n" << std::endl; 
}

void Harl::_warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years, whereas you started working here just last month.\n" << std::endl;
}

void Harl::_error(void) {
    std::cout << "This is unacceptable!\nI want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level) {
    size_t j = 4;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for(size_t i = 0; i < 4; i++) {
        if (level == levels[i]){
            j = i;
            break; 
        }
    }
    switch (j) {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            _debug();
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            _info();
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            _warning();
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            _error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

