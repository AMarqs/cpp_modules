#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : virtual public Animal
{
	private:

		Brain* _brain;

	public:

		Cat();
		virtual ~Cat();
		Cat(const Cat& copy);
		Cat& operator=(const Cat& copy);

		virtual void	makeSound() const;

		const std::string	getBrain(int index) const;
		void	setBrain(int index, const std::string &idea);
};

#endif