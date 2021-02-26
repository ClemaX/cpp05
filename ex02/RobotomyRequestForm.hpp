#pragma once

#include <iostream>
#include <string>

#include "Form.hpp"

class RobotomyRequestForm	:	virtual public Form
{
private:
	std::string	target;

	virtual void	payload(void) const;

public:
	RobotomyRequestForm();
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm(std::string const& target);
	RobotomyRequestForm(RobotomyRequestForm const& src);

	RobotomyRequestForm&	operator=(RobotomyRequestForm const& rhs);
};
