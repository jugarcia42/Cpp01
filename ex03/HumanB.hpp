#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon;
	public:
		// Constructors
		HumanB(std::string name);
		~HumanB();

		// Member functions
		void attack();
		void setWeapon(Weapon &weapon);
};

#endif