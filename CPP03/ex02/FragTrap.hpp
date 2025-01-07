#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
public:
	FragTrap(std::string name="default");
	FragTrap(const FragTrap &original);
	FragTrap &operator= (const FragTrap &original);
	~FragTrap();
	void highFivesGuys(void);
};

#endif