#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
	protected:

		std::string _ideas[100];

	public:

		Brain();
		~Brain();
		Brain(const Brain& copy);
		Brain& operator=(const Brain& copy);
		
		const std::string	getIdea(int index) const;
		void	setIdea(int index, const std::string& idea);
};

#endif