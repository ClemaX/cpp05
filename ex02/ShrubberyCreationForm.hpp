#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Form.hpp"

class ShrubberyCreationForm	:	virtual public Form
{
private:
	std::string	target;

	virtual void	payload(void) const;

public:
	ShrubberyCreationForm();
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm(std::string const& target);
	ShrubberyCreationForm(ShrubberyCreationForm const& src);

	ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& rhs);
};
