#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Default AAnimal") { std::cout << "[AAnimal] Default constructor called" << std::endl; }
AAnimal::AAnimal(std::string type) : _type(type) { std::cout << "[AAnimal] Constructor called" << std::endl; }
AAnimal::AAnimal(const AAnimal& copy) : _type(copy._type) { std::cout << "[AAnimal] Copy constructor called" << std::endl; }
AAnimal& AAnimal::operator=(const AAnimal& copy)
{
	std::cout << "[AAnimal] Copy assignment operator called" << std::endl;
	if (this != &copy)
		_type = copy._type;
	return *this;
}
AAnimal::~AAnimal() { std::cout << "[AAnimal] Destructor called" << std::endl; }

const std::string&	AAnimal::getType() const
{
	return _type;
}