#include "Zombie.hpp"

int main() {
    Zombie *h;
    int N;

    N = 5;
    h = zombieHorde(N, "Bob");
    for (int i = 0; i < N; i++) {
        h[i].announce();
    }
    delete[] h;
    return (0);
}
