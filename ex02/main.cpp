#include <cstdlib>
#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
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
        std::cout << "\n<< Brain >>\n";
        Brain brain1 = Brain();
        Brain brain2 = Brain(brain1); // Copy constructor uses copy assignment
    }

    {
        std::cout << "\n << Subject tests >>\n";
        const Animal* cat = new Dog();
        const Animal* dog = new Cat();
        const WrongAnimal* wrong_meta = new WrongAnimal();
        const WrongAnimal* wrong_cat = new WrongCat();

        std::cout << "-- types --\n";
        std::cout << "cat: " << cat->getType() << '\n';
        std::cout << "dog: " << dog->getType() << '\n';
        std::cout << "wrong_meta: " << wrong_meta->getType() << '\n';
        std::cout << "wrong_cat: " << wrong_cat->getType() << '\n';
        std::cout << "-- makeSound --\n";
        std::cout << "cat: "; cat->makeSound();
        std::cout << "dog: "; dog->makeSound();
        std::cout << "wrong_meta: "; wrong_meta->makeSound();
        std::cout << "wrong_cat: "; wrong_cat->makeSound();
        std::cout << "-- destructors --\n";
        delete cat;
        delete dog;
        delete wrong_meta;
        delete wrong_cat;
    }
    {
        Animal* animals[6];
    
        for (int i = 0; i < 3; i++)
        {
            animals[i] = new Cat();
        }
        for (int i = 3; i < 6; i++)
        {
            animals[i] = new Dog();
        }
        
        Cat& cat1 = dynamic_cast<Cat&>(*animals[0]);
        Cat& cat2 = dynamic_cast<Cat&>(*animals[1]);
        cat1.brain().firstIdea("Food");
        cat2.brain().firstIdea("Play");

        std::cout << cat1.brain().firstIdea() << '\n';
        std::cout << cat2.brain().firstIdea() << '\n';
        std::cout << &cat1.brain() << '\n';
        std::cout << &cat2.brain() << '\n';
        cat1 = cat2;
        std::cout << cat1.brain().firstIdea() << '\n';
        std::cout << cat2.brain().firstIdea() << '\n';
        std::cout << &cat1.brain() << '\n';
        std::cout << &cat2.brain() << '\n';

        for (int i = 0; i < 6; i++)
        {
            delete animals[i];
        }
    }
    return EXIT_SUCCESS;
}
