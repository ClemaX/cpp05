#pragma once

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	class FormException			:	public std::exception {};

	class GradeException		:	public FormException {};

	class FormNotSignedException	:	public FormException
	{
	public:
		char const* what() const throw();
	};

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
	Bureaucrat::grade_t	execGrade;
	bool				isSigned;

	void	setSignGrade(Bureaucrat::grade_t grade) throw(GradeException);
	void	setExecGrade(Bureaucrat::grade_t grade) throw(GradeException);

	virtual void	payload() const = 0;

public:
	Form();
	virtual ~Form();

	Form(std::string const& name, Bureaucrat::grade_t newSignGrade,
		Bureaucrat::grade_t newExecGrade);

	Form(Form const& src);

	Form&	operator=(Form const& rhs);

	inline std::string const&	getName() const { return name; };
	inline Bureaucrat::grade_t	getSignGrade() const { return signGrade; };
	inline Bureaucrat::grade_t	getExecGrade() const { return execGrade; };
	inline bool					getIsSigned() const { return isSigned; };

	void	beSigned(Bureaucrat const& signee) throw(GradeTooLowException);
	void	execute(Bureaucrat const& signee)
		throw(GradeTooLowException, FormNotSignedException);
};

std::ostream&	operator<<(std::ostream& os, Form const& src);
