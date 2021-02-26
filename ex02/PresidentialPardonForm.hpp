#pragma once

#include <iostream>
#include <string>

#include "Form.hpp"

class PresidentialPardonForm	:	virtual public Form
{
private:
	std::string	target;

	virtual void	payload(void) const;

public:
	PresidentialPardonForm();
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm(std::string const& target);
	PresidentialPardonForm(PresidentialPardonForm const& src);

	PresidentialPardonForm&	operator=(PresidentialPardonForm const& rhs);
};
