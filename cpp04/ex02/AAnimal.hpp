#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal
{
	protected:

		std::string	_type;
	
	public:

		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal& copy);
		AAnimal& operator=(const AAnimal& copy);
		virtual ~AAnimal();

		const std::string&	getType() const;
		virtual void	makeSound() const = 0;
};

#endif