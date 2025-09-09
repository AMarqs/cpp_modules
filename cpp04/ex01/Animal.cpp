#include <iostream>
#include "Animal.hpp"

Animal::Animal() : _type("Default Animal") { std::cout << "[Animal] Default constructor called" << std::endl; }
Animal::Animal(std::string type) : _type(type) { std::cout << "[Animal] Constructor called" << std::endl; }
Animal::Animal(const Animal& copy) : _type(copy._type) { std::cout << "[Animal] Copy constructor called" << std::endl; }
Animal& Animal::operator=(const Animal& copy)
{
	std::cout << "[Animal] Copy assignment operator called" << std::endl;
	if (this != &copy)
		_type = copy._type;
	return *this;
}
Animal::~Animal() { std::cout << "[Animal] Destructor called" << std::endl; }

const std::string&	Animal::getType() const
{
	return _type;
}

void	Animal::makeSound() const
{
	std::cout << "Default sound" << std::endl;
}