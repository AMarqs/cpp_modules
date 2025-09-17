#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
	protected:

		std::string	_type;
	
	public:

		Animal();
		Animal(std::string type);
		virtual ~Animal();
		Animal(const Animal& copy);
		Animal& operator=(const Animal& copy);

		const std::string&	getType() const;
		virtual void	makeSound() const;
};

#endif