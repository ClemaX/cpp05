#pragma once

#include <iostream>
#include <string>

class Bureaucrat
{
private:
	typedef unsigned int	grade_t;

	std::string const	name;
	grade_t				grade;

	Bureaucrat();

public:
	static  grade_t const	minGrade = 150;
	static  grade_t const	maxGrade = 1;
	static	grade_t const	step = 1;

	class GradeException	:	public std::exception {};

	class GradeTooLowException	:	public GradeException
	{
		char const*	what() const throw();
	};

	class GradeTooHighException	:	public GradeException
	{
		char const*	what() const throw();
	};

	~Bureaucrat();

	Bureaucrat(std::string const& name);
	Bureaucrat(std::string const& name, grade_t grade) throw(GradeException);

	Bureaucrat(Bureaucrat const& src);

	Bureaucrat&	operator=(Bureaucrat const& rhs);

	inline std::string const&	getName() const { return name; };
	inline grade_t				getGrade() const { return grade; };

	void	setGrade(grade_t newGrade) throw(GradeException);

	void	upgrade() throw(GradeException);
	void	downgrade() throw(GradeException);
};

std::ostream&	operator<<(std::ostream& os, Bureaucrat const& src);
