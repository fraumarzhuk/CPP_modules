#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
protected:
	static const int _hp = 100;
	static const int _ep = 100;
	static const int _atk = 30;
public:
	FragTrap(std::string name="default");
	FragTrap(const FragTrap &original);
	FragTrap &operator= (const FragTrap &original);
	~FragTrap();
	void highFivesGuys(void);
};

#endif