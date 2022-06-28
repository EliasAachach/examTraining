#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>

class ASpell:
{
	protected:
	std::string	name;
	std::string	effects;

	public:

	/*		Constructors	*/
	ASpell();
	ASpell(std::string name, std::string effects);
	ASpell(const ASpell	&src);
	~ASpell();
	
	/*		Overload	*/
	ASpell	&operator=(const ASpell &rhs);
	
	/*		Accessors	*/
	std::string	getName();
	std::string	getEffects();

	/*		Methods		*/

};

#endif