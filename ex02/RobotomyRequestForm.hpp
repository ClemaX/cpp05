#pragma once

#include <iostream>
#include <string>

class RobotomyRequestForm
{
private:

public:
	RobotomyRequestForm();
	~RobotomyRequestForm();

	RobotomyRequestForm(RobotomyRequestForm const& src);

	RobotomyRequestForm&	operator=(RobotomyRequestForm const& rhs);
};

std::ostream&	operator<<(std::ostream& os, RobotomyRequestForm const& src);

