#include <iostream>

class Warlock
{
	private:
		std::string	_name;
		std::string	_title;

	public:
	//constructors
	    Warlock();
		Warlock(std::string name, std::string title);
		~Warlock();
		Warlock& operator= (const Warlock &rhs);

	//getters
	const	std::string	&getName() const;
	const	std::string	&getTitle() const;
	//setters
	void				setTitle(const std::string &newTitle);
	
	void				introduce() const;
};