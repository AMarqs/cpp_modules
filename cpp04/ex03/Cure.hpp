#ifndef CURE_HPP
#define CURE_HPP

#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"	

class Cure : public AMateria
{
	public:
		
		Cure();
		Cure(const Cure& copy);
		Cure& operator=(const Cure& copy);
		~Cure();

		std::string const & getType() const;  // ESTA CREO QUE NO LE HACE FALTA
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target); // ESTA NO SE SI HACE FALTA DEJARLA
};

#endif