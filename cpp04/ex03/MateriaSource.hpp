#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>
#include "AMateria.hpp"

class MateriaSource
{
	public:

		MateriaSource();
		MateriaSource(std::string const & type);
		MateriaSource(const MateriaSource& copy);
		MateriaSource& operator=(const MateriaSource& copy);
		~MateriaSource();

};

#endif