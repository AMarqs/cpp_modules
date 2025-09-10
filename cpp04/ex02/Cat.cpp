#include <iostream>
#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
	std::cout << "[Cat] Default constructor called" << std::endl;
	_brain = new Brain();
}
Cat::Cat(const Cat& copy) : AAnimal(copy)
{
	std::cout << "[Cat] Copy constructor called" << std::endl;
	_brain = new Brain(*copy._brain);
}
Cat& Cat::operator=(const Cat& copy)
{
	std::cout << "[Cat] Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		AAnimal::operator=(copy);
		delete _brain;
		_brain = new Brain(*copy._brain);
	}
	return *this;
}
Cat::~Cat()
{
	std::cout << "[Cat] Destructor called" << std::endl;
	delete _brain;
}

void	Cat::makeSound() const
{
	std::cout << "Miau!" << std::endl;
}

const std::string	Cat::getBrain(int index) const
{
	if (index >= 0 && index < 100)
		return _brain->getIdea(index);
	std::cout << "Incorrect index" << std::endl;
	return std::string();
}

void	Cat::setBrain(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		_brain->setIdea(index, idea);
}