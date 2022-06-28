#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include "ASpell.hpp"

class ATarget
{
	protected:
		std::string	_type;

	public:
	//constructors
	ATarget();
	ATarget(const ATarget &src);
	ATarget(std::string type);
	virtual	~ATarget();

	//overloads
	ATarget	&operator=(const ATarget &rhs);

	//accessors
	const std::string	&getType() const;

	//methods
	virtual ATarget	*clone() const = 0;
	void			getHitBySpell(const ASpell &spell) const;

};

#endif