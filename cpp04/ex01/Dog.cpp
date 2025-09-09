#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	_brain = new Brain();
	std::cout << "[Dog] Default constructor called" << std::endl;
}
Dog::Dog(const Dog& copy) : Animal(copy)
{
	_brain = new Brain(*copy._brain);
	std::cout << "[Dog] Copy constructor called" << std::endl;
}
Dog& Dog::operator=(const Dog& copy)
{
	if (this != &copy)
	{
		Animal::operator=(copy);
		Brain* aux = new Brain(*copy._brain);
		delete _brain;
		_brain = aux;
	}
	std::cout << "[Dog] Copy assignment operator called" << std::endl;
	return *this;
}
Dog::~Dog()
{
	delete _brain;
	std::cout << "[Dog] Destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Guau!" << std::endl;
}

const std::string	Dog::getBrain(int index) const
{
	if (index >= 0 && index < 100)
		return _brain->getIdea(index);
	std::cout << "Incorrect index" << std::endl;
	return std::string();
}

void	Dog::setBrain(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		_brain->setIdea(index, idea);
}