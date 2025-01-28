#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {

    {
        ShrubberyCreationForm Shrubby("Schrubby");
        Bureaucrat MegaRights("Signable", 130);
        Bureaucrat NoRights("Nonsignabe", 146);
        try
        {
            Shrubby.beSigned(NoRights);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            Shrubby.beSigned(MegaRights);
            MegaRights.executeForm(Shrubby);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
	std::cout << std::endl;

    {
        PresidentialPardonForm President("President Form");
        Bureaucrat MegaRights("I can sign", 4);
        Bureaucrat NoRights("I cant sign", 26);
        try
        {
            President.beSigned(NoRights);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            President.beSigned(MegaRights);
            MegaRights.executeForm(President);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
	std::cout << std::endl;

    {
        RobotomyRequestForm RobotForm("Robotomy Form");
        Bureaucrat MegaRights("I can sign", 44);
        Bureaucrat NoRights("I cant sign", 73);
        try
        {
            RobotForm.beSigned(NoRights);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            RobotForm.beSigned(MegaRights);
            MegaRights.executeForm(RobotForm);
            MegaRights.executeForm(RobotForm);
            MegaRights.executeForm(RobotForm);
            MegaRights.executeForm(RobotForm);

        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}