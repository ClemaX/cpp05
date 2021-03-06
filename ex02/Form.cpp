#include "Form.hpp"

Form::Form()
	:	name(""),
		signGrade(Bureaucrat::maxGrade),
		execGrade(Bureaucrat::maxGrade),
		isSigned(false)
{
}

Form::~Form()
{
}

Form::Form(std::string const& name, Bureaucrat::grade_t newSignGrade,
	Bureaucrat::grade_t newExecGrade)
	:	name(name),
		isSigned(false)
{
	setSignGrade(newSignGrade);
	setExecGrade(newExecGrade);
}

Form::Form(Form const& src)
	:	name(src.name),
		signGrade(src.signGrade),
		execGrade(src.execGrade),
		isSigned(src.isSigned)
{
}

Form&		Form::operator=(Form const& src)
{
	if (this != &src)
	{
		name = src.name;
		signGrade = src.signGrade;
		execGrade = src.execGrade;
		isSigned = src.isSigned;
	}
	return *this;
}

/**
 * @brief Set the minimum grade required to sign the form.
 *
 * Throws a `GradeException` if the grade is out of bounds.
 *
 * The minimum and maximum are defined respectively by
 * `Bureaucrat::minGrade` and `Bureaucrat::maxGrade`.
 *
 * @param newGrade The new minimum grade.
 */
void	Form::setSignGrade(Bureaucrat::grade_t newGrade) throw(GradeException)
{
	if (newGrade < Bureaucrat::maxGrade)
		throw GradeTooHighException();
	else if (newGrade > Bureaucrat::minGrade)
		throw GradeTooLowException();
	else
		signGrade = newGrade;
}

/**
 * @brief Set the minimum grade required to execute the form.
 *
 * Throws a `GradeException` if the grade is out of bounds.
 *
 * The minimum and maximum are defined respectively by
 * `Bureaucrat::minGrade` and `Bureaucrat::maxGrade`.
 *
 * @param newGrade The new minimum grade.
 */
void	Form::setExecGrade(Bureaucrat::grade_t newGrade) throw(GradeException)
{
	if (newGrade < Bureaucrat::maxGrade)
		throw GradeTooHighException();
	else if (newGrade > Bureaucrat::minGrade)
		throw GradeTooLowException();
	else
		execGrade = newGrade;
}

/**
 * @brief Sign the form if the signee's grade is high enough.
 *
 * Throws a GradeTooLowException if the signee's grade is too low.
 * @param signee The Bureaucrat signing the form.
 */
void	Form::beSigned(Bureaucrat const& signee) throw(GradeTooLowException)
{
	if (signee.getGrade() <= signGrade)
		isSigned = true;
	else
		throw GradeTooLowException();
}

/**
 * @brief Execute the form if the signee's grade is high enough.
 *
 * Throws a `FormNotSignedException` if the form hasn't been signed.
 * Throws a `GradeTooLowException` if the signee's grade is too low.
 * @param signee The Bureaucrat signing the form.
 */
void	Form::execute(Bureaucrat const& signee)
	throw(FormNotSignedException, GradeTooLowException)
{
	if (!isSigned)
		throw FormNotSignedException();
	else if (signee.getGrade() > execGrade)
		throw GradeTooLowException();
	else
		payload();
}

char const*	Form::GradeTooLowException::what() const throw()
{ return "Grade too low"; }

char const*	Form::GradeTooHighException::what() const throw()
{ return "Grade too high"; }

char const*	Form::FormNotSignedException::what() const throw()
{ return "Form has not been signed"; }

std::ostream&	operator<<(std::ostream& os, Form const& src)
{
	os << src.getName() << ": " << (src.getIsSigned() ? "signed" : "unsigned");
	return os;
}
