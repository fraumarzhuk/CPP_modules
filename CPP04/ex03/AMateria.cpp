#include "AMateria.hpp"


AMateria::AMateria(std::string const & type): _type(type)
{
std::cout << "AMateria constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria  destructor called" << std::endl;
}

std::string const &AMateria::getType() const{
	return (this->_type);
}

AMateria &AMateria::operator=(const AMateria &other) {
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}
// void AMateria::use(ICharacter& target)
// {
// 	std::cout << "virtual function with " << target << std::endl;
// }