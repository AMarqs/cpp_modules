#ifndef ICE_HPP
#define ICE_HPP

#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"	

class Ice : public AMateria
{
	public:
		
		Ice();
		Ice(const Ice& copy);
		Ice& operator=(const Ice& copy);
		~Ice();

		std::string const & getType() const;  // ESTA CREO QUE NO LE HACE FALTA
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target); // ESTA NO SE SI HACE FALTA DEJARLA
};

#endif