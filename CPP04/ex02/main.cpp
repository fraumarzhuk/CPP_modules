#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();

	delete j;
	delete i;

    Cat originalCat;
    Cat copyCat(originalCat);
    Cat assignedCat;
    assignedCat = originalCat;

    std::cout << "Original Cat Brain Address: " << YELLOW200 << originalCat.getBrain() << RESET << std::endl;
    std::cout << "Copy Cat Brain Address: " <<  CYAN200 <<copyCat.getBrain() << RESET << std::endl;
    std::cout << "Assigned Cat Brain Address: " << PURPLE200 << assignedCat.getBrain() << RESET << std::endl;
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