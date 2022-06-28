#include <iostream>
#include <vector>
#include "ASpell.hpp"

class Warlock
{
	private:
		std::string	_name;
		std::string	_title;
		std::vector<ASpell *> _spellList;


	public:
	//constructors
	    Warlock();
		Warlock(std::string name, std::string title);
		~Warlock();
        Warlock(const Warlock &);
		Warlock& operator= (const Warlock &rhs);

	//getters
	const	std::string	&getName() const;
	const	std::string	&getTitle() const;
	//setters
	void				setTitle(const std::string &newTitle);
	//methods
	void				introduce() const;
	void				learnSpell(ASpell *toLearn);
	// void				forgetSpell(std::string toForget);
	// void				launchSpell(std::string name, ATarget &target);

};