#include "Zombie.hpp"
#include <sstream>

Zombie *zombieHorde(int N, std::string name){
	Zombie *zombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++){
		std::ostringstream ss;
		ss << i << " " << name;
		zombieHorde[i].setName(ss.str());
	}
	return (zombieHorde);
}