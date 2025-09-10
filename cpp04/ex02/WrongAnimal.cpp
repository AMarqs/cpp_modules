#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Default WrongAnimal") { std::cout << "[WrongAnimal] Default constructor called" << std::endl; }
WrongAnimal::WrongAnimal(std::string type) : _type(type) { std::cout << "[WrongAnimal] Constructor called" << std::endl; }
WrongAnimal::WrongAnimal(const WrongAnimal& copy) : _type(copy._type) { std::cout << "[WrongAnimal] Copy constructor called" << std::endl; }
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
	std::cout << "[WrongAnimal] Copy assignment operator called" << std::endl;
	if (this != &copy)
		_type = copy._type;
	return *this;
}
WrongAnimal::~WrongAnimal() { std::cout << "[WrongAnimal] Destructor called" << std::endl; }

const std::string&	WrongAnimal::getType() const
{
	return _type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal Default sound" << std::endl;
}