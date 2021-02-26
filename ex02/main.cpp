#include "ShrubberyCreationForm.hpp"

int main()
{
	using std::cout;
	using std::endl;

	cout << "Creating ShrubberyCreationForm" << endl;

	ShrubberyCreationForm	formA("formA");

	cout << endl << "Creating Bureaucrat with valid grade" << endl;

	Bureaucrat  hermes("Hermes", formA.getExecGrade());
	cout << hermes << endl;

	cout << endl << "Sign and execute Form" << endl;

	hermes.signForm(formA);
	hermes.executeForm(formA);

	cout << endl << "Creating Bureaucrat with invalid grade for exec" << endl;

	Bureaucrat  bermes("Bermes", formA.getExecGrade() + 1);
	cout << bermes << endl;

	cout << endl << "Attempt to sign and execute Form" << endl;

	bermes.signForm(formA);
	bermes.executeForm(formA);

	return 0;
}
