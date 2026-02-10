#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

    // ClapTrap defaultClap;
    // ClapTrap tom("Tom");
    // ClapTrap copy_tom(tom);
    // tom = copy_tom;
    // ClapTrap ben("Ben");
    
    // std::cout << "--------------Test(Take damage) -----------\n";
    // tom.printStatus();
    // tom.takeDamage(5);
    // tom.printStatus();

    // ben.printStatus();
    // ben.takeDamage(10);
    // ben.printStatus();
    
    // std::cout << "--------------Test(attack)-----------\n";
    // tom.printStatus();
    // tom.attack("a monster");
    // tom.printStatus();
    
    // ben.printStatus();
    // ben.attack("a sea monster");
    // ben.printStatus();

    // std::cout << "--------------Test(repair)-----------\n";
    // tom.printStatus();
    // tom.beRepaired(3);
    // tom.printStatus();
    
    // ben.printStatus();
    // ben.beRepaired(3);
    // ben.printStatus();

    // std::cout << "--------------Copy one-----------\n";
    // copy_tom.printStatus();
    // defaultClap.printStatus();

    // ---------------------------------

    // ScavTrap d;
    // ScavTrap bob("Bob");
    // bob.printStatus();
    // ScavTrap bob1(bob);
    // bob1.printStatus();
    // ScavTrap tim("Tim");

    // std::cout << "--------------Test(guardgate)-----------\n";
    // bob.guardGate();
    // bob.guardGate();

    // std::cout << "--------------Test(attack)-----------\n";
    // bob.attack("a bear");
    // bob.printStatus();

    // std::cout << "--------------Test(copy assignment)-----------\n";
    // ScavTrap copyBob("bob5");
    // copyBob.printStatus();
    // copyBob = bob;
    // copyBob.printStatus();

    // std::cout << "--------------Test(take damage)-----------\n";
    // bob.printStatus();
    // tim.printStatus();
    // bob.takeDamage(20);
    // tim.takeDamage(100);
    // bob.printStatus();
    // tim.printStatus();
    // bob.takeDamage(20);
    // tim.takeDamage(100);

    // std::cout << "--------------Test(repair)-----------\n";
    // bob.printStatus();
    // tim.printStatus();
    // bob.beRepaired(10);
    // tim.beRepaired(10);
    // bob.printStatus();
    // tim.printStatus();

    // std::cout << "--------------deconstructor-----------\n";

    //------------------------------------------------

    FragTrap d;
    FragTrap bob("Bob");
    bob.printStatus();
    FragTrap bob1(bob);
    bob1.printStatus();
    FragTrap tim("Tim");

    std::cout << "--------------Test(highfive)-----------\n";
    bob.highFivesGuys();

    std::cout << "--------------Test(attack)-----------\n";
    bob.attack("a bear");
    bob.printStatus();

    std::cout << "--------------Test(copy assignment)-----------\n";
    FragTrap copyBob("bob5");
    copyBob.printStatus();
    copyBob = bob;
    copyBob.printStatus();

    std::cout << "--------------Test(take damage)-----------\n";
    bob.printStatus();
    tim.printStatus();
    bob.takeDamage(20);
    tim.takeDamage(100);
    bob.printStatus();
    tim.printStatus();
    bob.takeDamage(20);
    tim.takeDamage(100);

    std::cout << "--------------Test(highfive)-----------\n";
    tim.highFivesGuys();

    std::cout << "--------------Test(repair)-----------\n";
    bob.printStatus();
    tim.printStatus();
    bob.beRepaired(10);
    tim.beRepaired(10);
    bob.printStatus();
    tim.printStatus();

    std::cout << "--------------deconstructor-----------\n";

    return (0);
}