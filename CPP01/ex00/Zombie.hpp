#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
	private:
		std::string _name;
		std::string getName();
	public:
		void setName(std::string name);
		Zombie();
		Zombie(std::string name);
		//Zombie *newZombie(std::string name);
		~Zombie(void);
		void announce(void);
		void randomChump(std::string name);
};

#endif