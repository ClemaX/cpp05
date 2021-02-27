#pragma once

#include <iostream>
#include <string>
#include <map>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	typedef Form* (form_factory(std::string const& target));

	static const size_t			formCount;
	static const char*			formNames[];
	static form_factory*	formFactories[];

public:
	Intern();
	~Intern();

	Intern(Intern const& src);

	Intern&	operator=(Intern const& rhs);

	Form*	makeForm(std::string const& formName, std::string const& target);
};

std::ostream&	operator<<(std::ostream& os, Intern const& src);

