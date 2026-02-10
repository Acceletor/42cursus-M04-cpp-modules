#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();
    
        delete meta;
        delete i;
        delete j;
    }
    std::cout << "\n------------------------\n";
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();
        const Animal* j = new Dog();
        std::cout << meta->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        std::cout << j->getType() << " " << std::endl;
        meta->makeSound();
        i->makeSound();
        j->makeSound();

        delete i;
        delete j;
        delete meta;
       
    }
    
    return 0;
}