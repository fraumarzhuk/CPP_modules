#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
private:
public:
	FragTrap(std::string name="default");
	FragTrap(const FragTrap &original);
	FragTrap &operator= (const FragTrap &original);
	~FragTrap();
	void attack(std::string target);
	void highFivesGuys(void);
	void restore_default_values();
};

#endif