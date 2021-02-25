#include "Bureaucrat.hpp"

int main()
{
	std::cout << "Creating Bureaucrat with valid grade" << std::endl;
	Bureaucrat  hermes("Hermes", 42);
	std::cout << hermes << std::endl;

	std::cout << std::endl
		<< "Attempting to create Bureaucrat with low grade" << std::endl;
	try { Bureaucrat  invalMin("Hermes", Bureaucrat::minGrade + 1); }
	catch(const std::exception& e) { std::cerr << e.what() << std::endl; }

	std::cout << std::endl
		<< "Attempting to create Bureaucrat with high grade" << std::endl;
	try { Bureaucrat  invalMin("Hermes", Bureaucrat::maxGrade - 1); }
	catch(const std::exception& e) { std::cerr << e.what() << std::endl; }

	return 0;
}
