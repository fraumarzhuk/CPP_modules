#include "Base.hpp"
#include "Aclass.hpp"
#include "Bclass.hpp"
#include "Cclass.hpp"



Base::~Base() {
	std::cout << "Base Destructor called" << std::endl;
}
Base *generate(void) {

	std::srand(std::time(NULL));
	static int seed = 0;
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
		std::cout << LIME300 << "Its an A class" << RESET << std::endl;
	else if (dynamic_cast<Bclass*>(p) != NULL)
		std::cout << LIME300 << "Its an B class" << RESET << std::endl;
	else if (dynamic_cast<Cclass*>(p) != NULL)
		std::cout << LIME300 << "Its an C class" << RESET << std::endl;
}

void identify(Base &p)
{
	std::string type = "unknown";
	try {
		Aclass a = dynamic_cast<Aclass&>(p);
		type = "A";
	} catch (std::exception &e) {
		try {
			Bclass a = dynamic_cast<Bclass&>(p);
			type = "B";
		} catch (std::exception &e) {
			try {
				Cclass a = dynamic_cast<Cclass&>(p);
				type = "C";
			} catch (std::exception &e) {
				type = "error casting this";
			}
		}
	}
	
	std::cout << "Result: " << CYAN400 << type  << RESET << " class" << std::endl;
}
