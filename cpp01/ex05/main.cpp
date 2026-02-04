#include "Harl.hpp"

int main() {

    Harl h;

    std::cout << "---------- DEBUG --------" << std::endl;
    h.complain("DEBUG");
    std::cout << "---------- INFO ----------" << std::endl;
    h.complain("INFO");
    std::cout << "---------- WARNING -------" << std::endl;
    h.complain("WARNING");
    std::cout << "---------- ERROR ---------" << std::endl;
    h.complain("ERROR");
    std::cout << "------Invalid Level ------" << std::endl;
    h.complain("invalid");

    return (0);
}
