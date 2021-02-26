#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	:	Form("RobotomyRequestForm", 72, 45),
		target("")
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
	:	Form("RobotomyRequestForm", 72, 45),
		target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src)
	:	Form(src.getName(), src.getSignGrade(), src.getExecGrade()),
		target(src.target)
{}

RobotomyRequestForm&		RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs)
{
	if (this != &rhs)
	{
		Form::operator=(rhs);
		target = rhs.target;
	}
	return *this;
}

void	RobotomyRequestForm::payload() const
{
	static bool	success = false;

	success = !success;

	std::cout << "Rizzzzzzz... Bzzzz! Bzzzzzzz!" << std::endl
		<< target << (success
			? " was robotomized successfully!"
			: " could not be robotomized!") << std::endl;
}
