#include "Form.hpp"

int main()
{
	using std::cout;
	using std::endl;

	cout << "Creating Bureaucrat with valid grade" << endl;

	Bureaucrat  hermes("Hermes", 42);
	cout << hermes << endl;

	cout << endl << "Creating Form with higher grade" << endl;

	Form	formA("formA", hermes.getGrade() - Bureaucrat::step);

	cout << endl << "Attempt to sign" << endl;

	hermes.signForm(formA);

	return 0;
}
