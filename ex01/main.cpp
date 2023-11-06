#include <cstdlib>
#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    std::cout << sizeof(void);
    {
        std::cout << "<< Animal >>\n";
        Animal animal1 = Animal();
        Animal animal2 = Animal(animal1);
        animal2 = animal1;
    }
    {
        std::cout << "\n<< WrongAnimal >>\n";
        WrongAnimal animal1 = WrongAnimal();
        WrongAnimal animal2 = WrongAnimal(animal1);
        animal2 = animal1;
    }
    {
        std::cout << "\n<< Cat >>\n";
        Cat cat1 = Cat();
        Cat cat2 = Cat(cat1);
        cat2 = cat1;
    }
    {
        std::cout << "\n<< WrongCat >>\n";
        WrongCat cat1 = WrongCat();
        WrongCat cat2 = WrongCat(cat1);
        cat2 = cat1;
    }
    {
        std::cout << "\n<< Dog >>\n";
        Dog dog1 = Dog();
        Dog dog2 = Dog(dog1);
        dog2 = dog1;
    }

    {
        std::cout << "\n << Subject tests >>\n";
        const Animal* meta = new Animal();
        const Animal* cat = new Dog();
        const Animal* dog = new Cat();
        const WrongAnimal* wrong_meta = new WrongAnimal();
        const WrongAnimal* wrong_cat = new WrongCat();

        std::cout << "-- types --\n";
        std::cout << "meta: " << meta->getType() << '\n';
        std::cout << "cat: " << cat->getType() << '\n';
        std::cout << "dog: " << dog->getType() << '\n';
        std::cout << "wrong_meta: " << wrong_meta->getType() << '\n';
        std::cout << "wrong_cat: " << wrong_cat->getType() << '\n';
        std::cout << "-- makeSound --\n";
        std::cout << "meta: "; ;meta->makeSound();
        std::cout << "cat: "; cat->makeSound();
        std::cout << "dog: "; dog->makeSound();
        std::cout << "wrong_meta: "; wrong_meta->makeSound();
        std::cout << "wrong_cat: "; wrong_cat->makeSound();
        std::cout << "-- destructors --\n";
        delete meta;
        delete cat;
        delete dog;
        delete wrong_meta;
        delete wrong_cat;
    }
    return EXIT_SUCCESS;
}
