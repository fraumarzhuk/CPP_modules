#include <iostream>
#include "Serializer.hpp"
#include <stdlib.h>


int main() {
	Data *data = new Data();
	data->value = 500765765;
	std::cout << "Initial value: " << data->value << std::endl;
	uintptr_t convert = Serializer::serialize(data);
	std::cout << "Serialized value: " << convert << std::endl;
	data = Serializer::deserialize(convert);
	std::cout << "Deserialized value: " << data->value << std::endl;

	delete data;
	return 0;
}
