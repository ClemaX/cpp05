#include "Form.hpp"

Form::Form()
	:	name(""),
		minGrade(Bureaucrat::maxGrade),
		isSigned(false)
{
}

Form::~Form()
{
}

Form::Form(std::string const& name, Bureaucrat::grade_t newMinGrade)
	:	name(name),
		isSigned(false)
{
	setMinGrade(newMinGrade);
}

Form::Form(Form const& src)
	:	name(src.name),
		minGrade(src.minGrade),
		isSigned(src.isSigned)
{
}

Form&		Form::operator=(Form const& src)
{
	if (this != &src)
	{
		name = src.name;
		minGrade = src.minGrade;
		isSigned = src.isSigned;
	}
	return *this;
}

/**
 * @brief Set the minimum grade required to sign the form.
 *
 * Throws a GradeException if the grade is out of bounds.
 * @param newGrade The new minimum grade.
 */
void	Form::setMinGrade(Bureaucrat::grade_t newGrade) throw(GradeException)
{
	if (newGrade < Bureaucrat::maxGrade)
		throw GradeTooHighException();
	else if (newGrade > Bureaucrat::minGrade)
		throw GradeTooLowException();
	else
		minGrade = newGrade;
}

/**
 * @brief Sign the form if the signee's grade is valid.
 *
 * Throws a GradeTooLowException if the signee's grade is too low.
 * @param signee The Bureaucrat signing the form.
 */
void	Form::beSigned(Bureaucrat const& signee) throw(GradeTooLowException)
{
	if (signee.getGrade() <= minGrade)
		isSigned = true;
	else
		throw GradeTooLowException();
}

char const*	Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

char const*	Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

std::ostream&	operator<<(std::ostream& os, Form const& src)
{
	os << src.getName() << ": " << (src.getIsSigned() ? "signed" : "unsigned");
	return os;
}
