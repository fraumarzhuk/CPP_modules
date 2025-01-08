#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
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