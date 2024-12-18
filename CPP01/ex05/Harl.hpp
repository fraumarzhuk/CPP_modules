#include "colors.hpp"
#include <iostream>

#define NUM_LEVELS 4
class Harl{

private:
	void _debug(void);
	void _info(void);
	void _warning(void);
	void _error(void);
	void	(Harl::*level_funct_p[NUM_LEVELS])(void);
public:
	Harl();
	~Harl();
	void complain(std::string level);
};