#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
    Zombie *horde = new Zombie[N];

    for (int i = 0; i < N; i++) {
        std::ostringstream oss;
        oss << name << i+1;
        horde[i] = Zombie(oss.str());
    }
    return (horde);
}
