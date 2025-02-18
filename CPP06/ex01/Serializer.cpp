#include "Serializer.hpp"

Serializer::Serializer()
{
std::cout << "Serializer Constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
	std::cout << " Serializer Copy constructor called" << std::endl;
	*this = other;
}

Serializer &Serializer::operator = (const Serializer &other)
{
	std::cout << "Serializer Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		//assign;
	}
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << " Serializer Destructor called" << std::endl;
}
uintptr_t Serializer::serialize(Data *ptr)
{
	data.serialized = dynamic_cast<uintptr_t>(ptr.value);
	return data.serialized;
}

Data *Serializer::deserialize(uintptr_t raw)
{
	data.deserialized = reinterpret_cast<uintptr_t>(raw);
	return data;
}
// fsctream?


//TODO:
//1. How does the data come?
//2. How is the data saved?
