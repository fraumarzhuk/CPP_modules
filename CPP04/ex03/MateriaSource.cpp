#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() : _count(0)
{
    for (int i = 0; i < 4; i++)
        _to_learn[i] = nullptr;
    std::cout << "MateriaSource Constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other) : _count(other._count)
{
    for (int i = 0; i < 4; i++)
    {
        if (other._to_learn[i])
            _to_learn[i] = other._to_learn[i]->clone();
        else
            _to_learn[i] = nullptr;
    }
    std::cout << "MateriaSource Copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    std::cout << "MateriaSource Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_to_learn[i])
                delete _to_learn[i];
            if (other._to_learn[i])
                _to_learn[i] = other._to_learn[i]->clone();
            else
                _to_learn[i] = nullptr;
        }
        _count = other._count;
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (_to_learn[i])
            delete _to_learn[i];
    }
    std::cout << "MateriaSource Destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (_count < 4 && m)
        _to_learn[_count++] = m;
}

AMateria* MateriaSource::createMateria(const std::string &type)
{
    for (int i = 0; i < _count; i++)
    {
        if (_to_learn[i] && _to_learn[i]->getType() == type)
            return _to_learn[i]->clone();
    }
    return nullptr;
}