#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(Bureaucrat &target): AForm("ShrubberyForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

Bureaucrat &ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()), _target(other.getTarget())
{
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream shrub_file("example.txt");
    std::ofstream shrub_file((_target.getName() + "_shrubbery").c_str());
    if (!shrub_file)
    {
        std::cerr << "Error creating file" << std::endl;
        return ;
    }

    shrub_file << "                  %%%,%%%%%%%\n";
    shrub_file << "                   ,'%% \\-*%%%%%%%\n";
    shrub_file << "             ;%%%%%*%   _%%%%\"\n";
    shrub_file << "              ,%%%       \\(_.*%%%%.\n";
    shrub_file << "              % *%%, ,%%%%*(    '\n";
    shrub_file << "            %^     ,*%%% )\\|,%%*%,_\n";
    shrub_file << "                 *%    \\/ #).-\"*%%*\n";
    shrub_file << "                     _.) ,/ *%,\n";
    shrub_file << "             _________/)#(_____________\n";

    shrub_file.close();
}