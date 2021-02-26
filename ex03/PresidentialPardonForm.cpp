#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	:	Form("PresidentialPardonForm", 72, 45),
		target("")
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
	:	Form("PresidentialPardonForm", 72, 45),
		target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src)
	:	Form(src.getName(), src.getSignGrade(), src.getExecGrade()),
		target(src.target)
{}

PresidentialPardonForm&		PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs)
{
	if (this != &rhs)
	{
		Form::operator=(rhs);
		target = rhs.target;
	}
	return *this;
}

void	PresidentialPardonForm::payload() const
{
	std::cout << target <<  " has been pardoned by Zafod Beeblebrox!"
		<< std::endl;
}
