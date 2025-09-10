#include <iostream>
#include "Brain.hpp"

Brain::Brain() { std::cout << "[Brain] Default constructor called" << std::endl; }
Brain::Brain(const Brain& copy)
{
	std::cout << "[Brain] Copy constructor called" << std::endl;
	*this = copy;
}
Brain& Brain::operator=(const Brain& copy)
{
	std::cout << "[Brain] Copy assignment operator called" << std::endl;
	if (this != &copy)
		for (int i = 0; i < 100; i++)
			_ideas[i] = copy._ideas[i];
	return *this;
}
Brain::~Brain() { std::cout << "[Brain] Destructor called" << std::endl; }

const std::string	Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return _ideas[index];
	std::cout << "Incorrect index" << std::endl;
	return std::string();
}

void	Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
		_ideas[index] = idea;
}