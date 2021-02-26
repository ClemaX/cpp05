#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	using std::cout;
	using std::endl;

	cout << "Creating ShrubberyCreationForm" << endl;

	ShrubberyCreationForm	formA("a");

	cout << "Creating PresidentialPardonForm" << endl;

	RobotomyRequestForm		formB("b");

	cout << "Creating RobotomyRequestForm" << endl;

	PresidentialPardonForm	formC("c");

	cout << endl << "Creating Bureaucrat with valid grade" << endl;

	Bureaucrat  hermes("Hermes", formA.getExecGrade());
	cout << hermes << endl;

	cout << endl << "Sign and execute ShrubberyCreationForm" << endl;

	hermes.signForm(formA);
	hermes.executeForm(formA);

	cout << endl << "Creating Bureaucrat with invalid grade for exec" << endl;

	Bureaucrat  bermes("Bermes", formA.getExecGrade() + 1);
	cout << bermes << endl;

	cout << endl << "Attempt to sign and execute ShrubberyCreationForm" << endl;

	bermes.signForm(formA);
	bermes.executeForm(formA);

	cout << endl << "Creating Bureaucrat with valid grade for exec" << endl;

	Bureaucrat  cermes("Cermes", formB.getExecGrade());

	cout << endl << "Sign and execute RobotomyRequestForm twice" << endl;

	cermes.signForm(formB);
	cermes.executeForm(formB);

	cout << endl;

	cermes.executeForm(formB);

	cout << endl << "Creating Bureaucrat with valid grade for exec" << endl;

	Bureaucrat  dermes("Dermes", formC.getExecGrade());

	cout << endl << "Sign and execute PresidentialPardonForm" << endl;

	dermes.signForm(formC);
	dermes.executeForm(formC);

	return 0;
}
