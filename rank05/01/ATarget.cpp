#include "ATarget.hpp"

/**
 *		CONSTRUCTORS
*/

ATarget::ATarget()
{
}

ATarget::ATarget(const ATarget &src): _type(src._type)
{
}

ATarget::ATarget(std::string type): _type(type)
{
}

ATarget::~ATarget()
{
}

/**
 *		OPERATORS 
*/

ATarget	&ATarget::operator=(const ATarget &rhs)
{
	this->_type = rhs.getType();
	return (*this);
}

/**
 *		ACCESSORS
*/

const std::string	&ATarget::getType() const
{
	return (this->_type);
}

/**
 *		ACCESSORS
*/

void	ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << this->_type << " has been " << spell.getEffects() << "!" << std::endl;
}