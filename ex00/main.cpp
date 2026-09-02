#include "Zombie.hpp"

int main(void)
{
	Zombie *newZombie1;
	
	newZombie1 = newZombie("Pepe"); //heap
	newZombie1->announce();
	randomChump("Vinisiu"); //stack
	delete newZombie1;
	return (0);
}