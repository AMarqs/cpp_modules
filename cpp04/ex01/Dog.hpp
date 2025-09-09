#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : virtual public Animal
{
	private:

		Brain* _brain;

	public:

		Dog();
		Dog(const Dog& copy);
		Dog& operator=(const Dog& copy);
		virtual ~Dog();

		virtual void	makeSound() const;

		const std::string	getBrain(int index) const;
		void	setBrain(int index, const std::string &idea);
};

#endif