#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	private:
		std::string _type;
	public:
		// Constructors
		Weapon();
		Weapon(std::string type);
		~Weapon();
		
		// Member functions
		void setType(std::string type);
		const std::string &getType() const;
};

#endif