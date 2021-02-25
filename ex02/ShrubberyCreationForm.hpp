#pragma once

#include <iostream>
#include <string>

class ShrubberyCreationForm
{
private:

public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();

	ShrubberyCreationForm(ShrubberyCreationForm const& src);

	ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& rhs);
};

std::ostream&	operator<<(std::ostream& os, ShrubberyCreationForm const& src);

