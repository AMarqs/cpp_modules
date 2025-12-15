#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "Animal.hpp"

class Cat : virtual public Animal
{
	public:

		Cat();
		virtual ~Cat();
		Cat(const Cat& copy);
		Cat& operator=(const Cat& copy);

		void	makeSound() const;
};

#endif