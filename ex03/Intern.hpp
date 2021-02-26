#pragma once

#include <iostream>
#include <string>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	~Intern();

	Intern(Intern const& src);

	Intern&	operator=(Intern const& rhs);

	Form*	makeForm(std::string const& form, std::string const& target);
};

std::ostream&	operator<<(std::ostream& os, Intern const& src);

