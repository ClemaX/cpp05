#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	:	Form("ShrubberyCreationForm", 145, 137),
		target("")
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
	:	Form("ShrubberyCreationForm", 145, 137),
		target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src)
	:	Form(src.getName(), src.getSignGrade(), src.getExecGrade()),
		target(src.target)
{}

ShrubberyCreationForm&		ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs)
{
	if (this != &rhs)
	{
		Form::operator=(rhs);
		target = rhs.target;
	}
	return *this;
}

void	ShrubberyCreationForm::payload() const
{
	static const char* tree =
	"        W\n"
	"       WWW\n"
	"       WWW\n"
	"      WWWWW\n"
	"W     WWWWW     W\n"
	"WWW   WWWWW   WWW\n"
	" WWW  WWWWW  WWW\n"
	"  WWW  WWW  WWW\n"
	"   WWW WWW WWW\n"
	"     WWWWWWW\n"
	"  WWWW  |  WWWW\n"
	"        |\n"
	"        |\n";

	std::ofstream	targetFile;

	targetFile.open((target + "_shrubbery").c_str());

	targetFile << tree;

	targetFile.close();
}
