#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>
#include "colors.hpp"

struct Data{
	unsigned long value;
	uintptr_t deserialized;
	uintptr_t serialized;
};

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &other);
	Serializer &operator= (const Serializer &other);
	~Serializer();
	static Data data;
public:

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
#endif
