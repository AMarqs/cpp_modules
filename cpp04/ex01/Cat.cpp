#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	_brain = new Brain();
	std::cout << "[Cat] Default constructor called" << std::endl;
}
Cat::Cat(const Cat& copy) : Animal(copy)
{
	_brain = new Brain(*copy._brain);
	std::cout << "[Cat] Copy constructor called" << std::endl;
}
Cat& Cat::operator=(const Cat& copy)
{
	if (this != &copy)
	{
		Animal::operator=(copy);
		delete _brain;
		_brain = new Brain(*copy._brain);
	}
	std::cout << "[Cat] Copy assignment operator called" << std::endl;
	return *this;
}
Cat::~Cat()
{
	delete _brain;
	std::cout << "[Cat] Destructor called" << std::endl;
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