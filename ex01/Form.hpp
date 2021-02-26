#pragma once

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
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
	std::string			name;
	Bureaucrat::grade_t	signGrade;
	bool				isSigned;

protected:
	void	setSignGrade(Bureaucrat::grade_t grade) throw(GradeException);

public:
	Form();
	~Form();

	Form(std::string const& name, Bureaucrat::grade_t minGrade);

	Form(Form const& src);

	Form&	operator=(Form const& rhs);

	inline std::string const&	getName() const { return name; };
	inline Bureaucrat::grade_t	getSignGrade() const { return signGrade; };
	inline bool					getIsSigned() const { return isSigned; };

	void	beSigned(Bureaucrat const& signee) throw (GradeTooLowException);
};

std::ostream&	operator<<(std::ostream& os, Form const& src);
