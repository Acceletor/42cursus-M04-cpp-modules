#include "ClapTrap.hpp"

int main() {

    ClapTrap defaultClap;
    ClapTrap tom("Tom");
    ClapTrap copy_tom(tom);
    tom = copy_tom;
    ClapTrap ben("Ben");
    
    std::cout << "--------------Test(Take damage) -----------\n";
    tom.printStatus();
    tom.takeDamage(5);
    tom.printStatus();

    ben.printStatus();
    ben.takeDamage(10);
    ben.printStatus();
    
    std::cout << "--------------Test(attack)-----------\n";
    tom.printStatus();
    tom.attack("a monster");
    tom.printStatus();
    
    ben.printStatus();
    ben.attack("a sea monster");
    ben.printStatus();

    std::cout << "--------------Test(repair)-----------\n";
    tom.printStatus();
    tom.beRepaired(3);
    tom.printStatus();
    
    ben.printStatus();
    ben.beRepaired(3);
    ben.printStatus();

    std::cout << "--------------Copy one-----------\n";
    copy_tom.printStatus();
    defaultClap.printStatus();
    
    return (0);
}