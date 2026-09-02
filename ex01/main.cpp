#include "Zombie.hpp"

int main(void)
{
	Zombie *horde;
	int N = 3;
	
	horde = zombieHorde(N, "Horde");
 	for (int i = 0; i < N; i++)
	{
       std::cout << "Zombie " << i << ": ";
	   horde[i].announce();
    }

	delete[] horde;
	return (0);
}