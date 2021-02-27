#include "Intern.hpp"

const size_t Intern::formCount = 3;

const char*	Intern::formNames[Intern::formCount] =
{
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

static Form*	genShrubberyCreation(std::string const& target)
{ return new ShrubberyCreationForm(target); }

static Form*	genRobotomyRequest(std::string const& target)
{ return new RobotomyRequestForm(target); }

static Form*	genPresidentialPardon(std::string const& target)
{ return new PresidentialPardonForm(target); }

Intern::form_factory* Intern::formFactories[Intern::formCount] =
{
	&genShrubberyCreation,
	&genRobotomyRequest,
	&genPresidentialPardon
};

static int		iscmp(std::string const& a, std::string const& b)
{
	if (a.length() != b.length())
		return (-1);
	std::string::const_iterator			it_a = a.begin();
	std::string::const_iterator			it_b = b.begin();
	const std::string::const_iterator	end_a = a.end();

	while (it_a != end_a && std::tolower(*it_a++) == std::tolower(*it_b++))
		;
	return (std::tolower(*it_b) - std::tolower(*it_a));
}


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

Form*	Intern::makeForm(std::string const& formName, std::string const& target)
{
	size_t i = 0;

	while (i != formCount && iscmp(formNames[i], formName))
		i++;

	return (i != formCount) ? formFactories[i](target) : NULL;
}

std::ostream&	operator<<(std::ostream& os, Intern const& src)
{
	(void)src;

	os << "Just some random intern...";
	return os;
}
