#include "ASpell.hpp"

/**
 *		CONSTRUCTORS
*/

ASpell::ASpell()
{
}

ASpell::ASpell(const ASpell &src): _name(src._name), _effects(src._effects)
{
}

ASpell::ASpell(std::string name , std::string effects): _name(name), _effects(effects)
{
}

ASpell::~ASpell()
{
}

/**
 *		OPERATORS 
*/

ASpell	&ASpell::operator=(const ASpell &rhs)
{
	this->_name = rhs.getName();
	this->_name = rhs.getEffects();
	return (*this);
}

/**
 *		ACCESSORS
*/

const std::string	&ASpell::getName() const
{
	return (this->_name);
}

const std::string	&ASpell::getEffects() const
{
	return (this->_effects);
}

/**
 *		METHODS
*/

void	ASpell::launch(const ATarget &target)
{
	target.getHitBySpell(*this);
}