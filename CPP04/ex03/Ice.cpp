#include "Ice.hpp"

Ice::Ice(std::string const & type): AMateria(type)
{
std::cout << "Constructor called" << std::endl;
}

// Ice::Ice(const Ice &other): AMateria()
// {
// 	std::cout << "Copy constructor called" << std::endl;
// 	*this = other;
// }

Ice &Ice::operator =(const AMateria &other) // keep Ice?
{
	std::cout << "Cure copy assignment operator called" << std::endl;
	if (this != &other)
	{
		//assign;
	}
	return (*this);
}



Ice::~Ice()
{
	std::cout << "Destructor called" << std::endl;
}
Ice *Ice::clone() const
{
	Ice *ice_clone = new Ice("ice");
	return (ice_clone);
	//allocated on heap, delete later

}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}