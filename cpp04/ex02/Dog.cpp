#include <iostream>
#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
	std::cout << "[Dog] Default constructor called" << std::endl;
	_brain = new Brain();
}
Dog::Dog(const Dog& copy) : AAnimal(copy)
{
	std::cout << "[Dog] Copy constructor called" << std::endl;
	_brain = new Brain(*copy._brain);
}
Dog& Dog::operator=(const Dog& copy)
{
	std::cout << "[Dog] Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		AAnimal::operator=(copy);
		Brain* aux = new Brain(*copy._brain);
		delete _brain;
		_brain = aux;
	}
	return *this;
}
Dog::~Dog()
{
	std::cout << "[Dog] Destructor called" << std::endl;
	delete _brain;
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