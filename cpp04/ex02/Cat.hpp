#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : virtual public AAnimal
{
	private:

		Brain* _brain;

	public:

		Cat();
		Cat(const Cat& copy);
		Cat& operator=(const Cat& copy);
		virtual ~Cat();

		virtual void	makeSound() const;

		const std::string	getBrain(int index) const;
		void	setBrain(int index, const std::string &idea);
};

#endif