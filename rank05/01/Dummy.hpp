#ifndef DUMMY_HPP
# define DUMMY_HPP

# include "ATarget.hpp"

class Dummy : public ATarget
{
	Dummy();
	virtual ~Dummy();
	virtual Dummy *clone() const;
};

#endif