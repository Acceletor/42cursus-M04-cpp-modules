#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

#define NB_ANIMALS 4

static void printIdea(const Brain* b, int idx, const std::string& name) {
    std::cout << name << ": idea[" << idx << "] = " << b->getIdea(idx) << std::endl;
}

static void arrayTest() {
    Animal* tab[NB_ANIMALS + 1];
    tab[NB_ANIMALS] = NULL;
    std::cout << "----Creating Cats\n";
    for (int i = 0; i < (NB_ANIMALS/2); i++) {
        tab[i] = new Cat;
    }
    std::cout << "----Creating Dogs\n";
    for (int i = NB_ANIMALS/2; i < NB_ANIMALS; i++) {
        tab[i] = new Dog;
    }
    std::cout << "----All of them make sound\n";
    for (int i = 0; i < NB_ANIMALS; i++) {
        tab[i]->makeSound();
    }
    std::cout << "----Deleting them all\n";
    for (int i = 0; i < NB_ANIMALS; i++) {
        delete tab[i];
    }
}

static void catCopyTest() {
    Cat original;
    original.getBrain()->setIdea(0, "I want fish");
    original.getBrain()->setIdea(1, "I want sleep");
    printIdea(original.getBrain(), 0, "original");
    printIdea(original.getBrain(), 1, "original");

    std::cout << "----copy Orignal cat\n";
    Cat copyCat(original);
    original.getBrain()->setIdea(0, "I change my mind");

    std::cout << "----After modifying original\n";
    printIdea(original.getBrain(), 0, "original");
    printIdea(copyCat.getBrain(), 0, "copy");

    std::cout << "----Test copy assignment -------\n";
    copyCat = original;
    printIdea(original.getBrain(), 0, "original");
    printIdea(copyCat.getBrain(), 0, "copy");
    std::cout << "----Deconstructor calling -------\n";
}

static void dogCopyTest() {
    Dog* original = new Dog();
    original->getBrain()->setIdea(0, "I want bone");
    original->getBrain()->setIdea(1, "I want sleep");
    printIdea(original->getBrain(), 0, "original");
    printIdea(original->getBrain(), 1, "original");

    std::cout << "----copy Orignal dog\n";
    Dog* copyDog = new Dog(*original);
    original->getBrain()->setIdea(0, "I change my mind");

    std::cout << "----After modifying original\n";
    printIdea(original->getBrain(), 0, "original");
    printIdea(copyDog->getBrain(), 0, "copy");

    std::cout << "----Test copy assignment -------\n";
    *copyDog = *original;
    printIdea(original->getBrain(), 0, "original");
    printIdea(copyDog->getBrain(), 0, "copy");

    std::cout << "----Deconstructor calling -------\n";
    delete original;
    delete copyDog;
}

// void	testInstanceCrash(void)
// {
// 	Animal *bear = new Animal();
// 	bear->makeSound();
// 	delete bear;
// }

int main()
{
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;//should not create a leak
        delete i;
    }

    {
        std::cout << " ------------------------------\n";
        std::cout << "|        Array test            |\n";
        std::cout << " ------------------------------\n";
        arrayTest();
        std::cout << std::endl;
    }
    {
        std::cout << " ------------------------------\n";
        std::cout << "|        Copy Cat test         |\n";
        std::cout << " ------------------------------\n";
        catCopyTest();
        std::cout << std::endl;
    }
    {
        std::cout << " ------------------------------\n";
        std::cout << "|        Copy Dog test         |\n";
        std::cout << " ------------------------------\n";
        dogCopyTest();
        std::cout << std::endl;
    }
    
    // testInstanceCrash();
    
    return 0;
}