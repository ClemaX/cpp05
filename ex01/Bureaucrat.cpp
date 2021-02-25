#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat()
	:	name(""), grade(minGrade)
{
}

Bureaucrat::Bureaucrat(std::string const& name)
	:	name(name), grade(minGrade)
{
}

Bureaucrat::Bureaucrat(std::string const& name, grade_t newGrade)
	throw(GradeException)
	:	name(name)
{
	setGrade(newGrade);
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(Bureaucrat const& src)
	:	name(src.name), grade(src.grade)
{
}

Bureaucrat&		Bureaucrat::operator=(Bureaucrat const& src)
{
	if (this != &src)
		grade = src.grade;
	return *this;
}

/**
 * @brief Set the Bureaucrat's grade.
 *
 * Throws a GradeException if the new grade is out of bounds.
 * @param newGrade The grade to assign.
 */
void	Bureaucrat::setGrade(grade_t newGrade) throw(GradeException)
{
	if (newGrade < maxGrade)
		throw GradeTooHighException();
	else if (newGrade > minGrade)
		throw GradeTooLowException();
	else
		grade = newGrade;
}

/**
 * @brief Upgrade the Bureaucrat.
 */
void	Bureaucrat::upgrade() throw(GradeException)
{
	setGrade(grade - step);
}

/**
 * @brief Downgrade the Bureaucrat.
 */
void	Bureaucrat::downgrade() throw(GradeException)
{
	setGrade(grade + step);
}

/**
 * @brief Sign a Form.
 *
 * @param form
 */
void	Bureaucrat::signForm(Form& form)
{
	bool	success = true;

	try
	{
		form.beSigned(*this);
	}
	catch(const Form::GradeTooLowException& e)
	{
		success = false;
		std::cout << name << " cannot sign " << form.getName() << " because: "
			<< e.what() << std::endl;
	}

	if (success)
		std::cout << name << " signs " << form.getName() << std::endl;
}

char const*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

char const*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

std::ostream&	operator<<(std::ostream& os, Bureaucrat const& src)
{
	os << src.getName() << " (" << src.getGrade() << ')';
	return os;
}
