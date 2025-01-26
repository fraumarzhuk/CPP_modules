#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure Constructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
    std::cout << "Cure Copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
    std::cout << "Cure Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    return *this;
}

Cure::~Cure()
{
    std::cout << "Cure Destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << AMBER900 << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}