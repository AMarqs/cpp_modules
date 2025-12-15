#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "Animal.hpp"

class Dog : virtual public Animal
{
	public:

		Dog();
		virtual ~Dog();
		Dog(const Dog& copy);
		Dog& operator=(const Dog& copy);

		void	makeSound() const;
};

#endif