#include <iostream>

class Warlock
{
	private:
		std::string	_name;
		std::string	_title;

	public:
	//constructors
		Warlock(std::string name, std::string title);
		~Warlock();
	//getters
	const	std::string	&getName() const;
	const	std::string	&getTitle() const;
	//setters
	void				setTitle(const std::string &newTitle);
	
	void				introduce() const;
};