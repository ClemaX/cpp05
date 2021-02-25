#include "Bureaucrat.hpp"

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

void	Bureaucrat::setGrade(grade_t newGrade) throw(GradeException)
{
	if (newGrade < maxGrade)
		throw GradeTooHighException();
	else if (newGrade > minGrade)
		throw GradeTooLowException();
	else
		grade = newGrade;
}

void	Bureaucrat::upgrade() throw(GradeException)
{
	setGrade(grade - step);
}

void	Bureaucrat::downgrade() throw(GradeException)
{
	setGrade(grade + step);
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
