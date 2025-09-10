#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") { std::cout << "[WrongCat] Default constructor called" << std::endl; }
WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy) { std::cout << "[WrongCat] Copy constructor called" << std::endl; }
WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	std::cout << "[WrongCat] Copy assignment operator called" << std::endl;
	if (this != &copy)
		WrongAnimal::operator=(copy);
	return *this;
}
WrongCat::~WrongCat() { std::cout << "[WrongCat] Destructor called" << std::endl; }

void	WrongCat::makeSound() const
{
	std::cout << "Wrong Miau!" << std::endl;
}