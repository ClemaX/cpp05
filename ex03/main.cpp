#include "Intern.hpp"

int main()
{
	using std::cout;
	using std::endl;


	cout << "Creating max level Bureaucrat" << endl;

	Bureaucrat hermes("Hermes", Bureaucrat::maxGrade);
	cout << hermes << endl;

	cout << endl << "Hiring some random Intern" << endl;

	Intern intern;

	cout << endl << "Ordering intern to create ShrubberyCreationForm" << endl;

	Form* tmp = intern.makeForm("shrubbery creation", "a");

	cout << endl << "Attempt to sign and execute form" << endl;

	hermes.signForm(*tmp);
	hermes.executeForm(*tmp);

	delete tmp;
	tmp = NULL;

	cout << endl << "Ordering intern to create RobotomyRequestForm" << endl;

	tmp = intern.makeForm("robotomy request", "Bender");

	cout << endl << "Attempt to sign and execute form" << endl;

	hermes.signForm(*tmp);
	hermes.executeForm(*tmp);

	delete tmp;
	tmp = NULL;

	cout << endl << "Ordering intern to create PresidentialPardonForm" << endl;

	tmp = intern.makeForm("presidential pardon", "Terrorist");

	cout << endl << "Attempt to sign and execute form" << endl;

	hermes.signForm(*tmp);
	hermes.executeForm(*tmp);

	delete tmp;
	tmp = NULL;

	return 0;
}
