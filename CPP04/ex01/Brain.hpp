#ifndef BRAIN_HPP
#define BRAIN_HPP
#include "colors.hpp"
#include <iostream>

class Brain
{
protected:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain &other);
	Brain &operator= (const Brain &other);
	~Brain();

	void setIdea(int index, const std::string &idea);
	std::string getIdea(int index) const;
};

#endif
