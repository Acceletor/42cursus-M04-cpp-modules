#include "Zombie.hpp"

int main() {

    Zombie *z;

    z = newZombie("Foo1");
    randomChump("Foo2");
    z->announce();
    delete z;
    return (0);
}
