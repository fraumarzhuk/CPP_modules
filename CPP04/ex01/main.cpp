#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    Cat originalCat;
    Cat copyCat(originalCat);
    Cat assignedCat;
    assignedCat = originalCat;

    std::cout << "Original Cat Brain Address: " << originalCat.getBrain() << std::endl;
    std::cout << "Copy Cat Brain Address: " << copyCat.getBrain() << std::endl;
    std::cout << "Assigned Cat Brain Address: " << assignedCat.getBrain() << std::endl;
    originalCat.getBrain()->setIdea(0, "Original Cat Idea");
    std::cout << "Original Cat Brain Idea: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Cat Brain Idea: " << copyCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Assigned Cat Brain Idea: " << assignedCat.getBrain()->getIdea(0) << std::endl;

    Animal *animals_array[10];
    for(int i = 0; i < 5; i++)
    {
        animals_array[i] = new Dog();
    }
    for(int i = 5; i < 10; i++)
    {
        animals_array[i] = new Cat();
    }
    for (int i = 0; i < 10; i++)
    {
        delete animals_array[i];
    }

    return 0;
}