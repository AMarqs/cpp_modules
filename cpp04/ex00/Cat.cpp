#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal("Cat") { std::cout << "[Cat] Default constructor called" << std::endl; }
Cat::Cat(const Cat& copy) : Animal(copy) { std::cout << "[Cat] Copy constructor called" << std::endl; }
Cat& Cat::operator=(const Cat& copy)
{
	if (this != &copy)
		Animal::operator=(copy);
	std::cout << "[Cat] Copy assignment operator called" << std::endl;
	return *this;
}
Cat::~Cat() { std::cout << "[Cat] Destructor called" << std::endl; }

void	Cat::makeSound() const
{
	std::cout << "Miau!" << std::endl;
}