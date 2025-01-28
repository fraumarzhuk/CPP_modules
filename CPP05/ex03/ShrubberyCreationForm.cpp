#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

const std::string &ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

// ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()), _target(other.getTarget())
// {
// 	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
// }

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}
void ShrubberyCreationForm::action() const
{
    std::ofstream shrub_file((_target + "_shrubbery").c_str());
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