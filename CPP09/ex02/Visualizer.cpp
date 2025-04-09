#include "Visualizer.hpp"

Visualizer::Visualizer()
{
std::cout << "Visualizer Constructor called" << std::endl;
}

Visualizer::Visualizer(const Visualizer &other)
{
	std::cout << " Visualizer Copy constructor called" << std::endl;
	*this = other;
}

Visualizer &Visualizer::operator = (const Visualizer &other)
{
	std::cout << "Visualizer Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		//assign;
	}
	return (*this);
}

Visualizer::~Visualizer()
{
	std::cout << " Visualizer Destructor called" << std::endl;
}

void Visualizer::print_pairs(std::vector<std::pair<int, int> > main_arg) {
	typename std::vector<std::pair<int, int> >::iterator a_it_b = main_arg.begin();
	typename std::vector<std::pair<int, int> >::iterator a_it_e = main_arg.end();
	
	//separate to pairs
	while (a_it_b < a_it_e) {
		std::cout << "[" << (*a_it_b).first << "," << (*a_it_b).second << "], ";
		a_it_b++;
	}
	std::cout << std::endl;

}