#pragma once

#include <iostream>
#include <string>

class Form;

class Bureaucrat
{
public:
	typedef unsigned int	grade_t;

	class GradeException		:	public std::exception {};

	class GradeTooLowException	:	public GradeException
	{
	public:
		char const*	what() const throw();
	};

	class GradeTooHighException	:	public GradeException
	{
	public:
		char const*	what() const throw();
	};

private:
	std::string const	name;
	grade_t				grade;

	Bureaucrat();

	void	setGrade(grade_t newGrade) throw(GradeException);

public:
	static grade_t const	minGrade = 150;
	static grade_t const	maxGrade = 1;
	static grade_t const	step = 1;

	~Bureaucrat();

	Bureaucrat(std::string const& name);
	Bureaucrat(std::string const& name, grade_t grade) throw(GradeException);

	Bureaucrat(Bureaucrat const& src);

	Bureaucrat&	operator=(Bureaucrat const& rhs);

	inline std::string const&	getName() const { return name; };
	inline grade_t				getGrade() const { return grade; };

	void	upgrade() throw(GradeException);
	void	downgrade() throw(GradeException);

	void	signForm(Form& form) const;
	void	executeForm(Form& form) const;
};

std::ostream&	operator<<(std::ostream& os, Bureaucrat const& src);
