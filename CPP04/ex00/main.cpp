#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"


int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << meta->getType() << " " << std::endl;
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound();
j->makeSound();
meta->makeSound();

const WrongAnimal *wrongy = new WrongAnimal();
const WrongAnimal *wrong_cat = new WrongCat();
const WrongAnimal *fox = new WrongCat("fox");
std::cout << wrongy->getType() << " " << std::endl;
std::cout << wrong_cat->getType() << " " << std::endl;
std::cout << fox->getType() << " " << std::endl;
wrongy->makeSound();
wrong_cat->makeSound();
fox->makeSound();

delete meta;
delete j;
delete i;
delete wrongy;
delete wrong_cat;
delete fox;

return 0;
}