#include <string>
#include "Weapon.hpp"

Weapon::Weapon() {}
Weapon::Weapon(std::string type) : _type(type) {}
Weapon::~Weapon() {}

const std::string&	Weapon::getType()
{
	return _type;
}

void	Weapon::setType(std::string new_type)
{
	_type = new_type;
}