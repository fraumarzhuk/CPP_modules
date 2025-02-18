#include "Base.hpp"
#include "Aclass.hpp"
#include "Bclass.hpp"
#include "Cclass.hpp"

Base::~Base() {
	std::cout << "Base Destructor called" << std::endl;
}

Base *generate(void) {
	static int seed = 0;

	std::srand(std::time(0));
	int rand = std::rand() % 3 + seed++;

	if (rand == 0)
		return (new Aclass);
	else if (rand == 1)
		return (new Bclass);
	else
		return (new Cclass);
}

void identify(Base *p)
{
	if (dynamic_cast<Aclass*>(p) != NULL)
		std::cout << "Its an A class" << std::endl;
	else if (dynamic_cast<Bclass*>(p) != NULL)
		std::cout << "Its an B class" << std::endl;
	else if (dynamic_cast<Cclass*>(p) != NULL)
		std::cout << "Its an C class" << std::endl;
}

void identify(Base &p)
{
	std::string type = "unknown";
    if (dynamic_cast<Aclass*>(&p))
        type = "A";
    else if (dynamic_cast<Bclass*>(&p))
        type = "B";
    else if (dynamic_cast<Cclass*>(&p))
		type = "C";
        
	std::cout << "It is " << type << " class" << std::endl;
}
