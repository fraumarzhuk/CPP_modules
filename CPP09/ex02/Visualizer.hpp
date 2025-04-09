#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP
#include <iostream>
#include "colors.hpp"
#include <vector>

class Visualizer
{
private:
	Visualizer();
	Visualizer(const Visualizer &other);
	Visualizer &operator= (const Visualizer &other);
	~Visualizer();
public:
	static void print_pairs(std::vector<std::pair<int, int> > main_arg);
};
#endif
