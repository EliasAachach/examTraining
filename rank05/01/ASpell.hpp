#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
		std::string	_name;
		std::string	_effects;

	public:
	//constructors
	ASpell();
	ASpell(const ASpell &src);
	ASpell(std::string name, std::string effects);
	virtual	~ASpell();

	//overloads
	ASpell	&operator=(const ASpell &rhs);

	//accessors
	const std::string	&getName() const;
	const std::string	&getEffects() const;

	//methods
	virtual ASpell	*clone() const = 0;
	void			launch(const ATarget &target);

};

#endif