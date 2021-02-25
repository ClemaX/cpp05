#pragma once

#include <iostream>
#include <string>

class PresidentialPardonForm
{
private:

public:
	PresidentialPardonForm();
	~PresidentialPardonForm();

	PresidentialPardonForm(PresidentialPardonForm const& src);

	PresidentialPardonForm&	operator=(PresidentialPardonForm const& rhs);
};

std::ostream&	operator<<(std::ostream& os, PresidentialPardonForm const& src);

