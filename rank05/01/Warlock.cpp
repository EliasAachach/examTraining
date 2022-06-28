#include "Warlock.hpp"

	/*	CONSTRUCTORS	*/

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->_name << ": My job here is done!" << std::endl;
}

	/*	ACCESSORS	*/
const std::string	&Warlock::getName() const
{
	return (this->_name);
}

const std::string	&Warlock::getTitle() const
{
	return (this->_title);
}

void	Warlock::setTitle(const std::string &newTitle)
{
	this->_title = newTitle;
}

void	Warlock::introduce() const
{
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}