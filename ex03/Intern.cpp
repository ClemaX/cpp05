#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(Intern const& src)
{
	(void)src;
}

Intern&		Intern::operator=(Intern const& src)
{
	(void)src;

	return *this;
}

Form*	Intern::makeForm(std::string const& form, std::string const& target)
{
	if (form == "presidential pardon")
		return new PresidentialPardonForm(target);
	if (form == "robotomy request")
		return new RobotomyRequestForm(target);
	if (form == "shrubbery creation")
		return new ShrubberyCreationForm(target);
	return NULL;
}

std::ostream&	operator<<(std::ostream& os, Intern const& src)
{
	(void)src;

	os << "Just some random intern...";
	return os;
}
