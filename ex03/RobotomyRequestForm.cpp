# include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime> 

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :  AForm(other), target(other.target) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}



void RobotomyRequestForm::execute(Bureaucrat const  &executor) const
{
    check_before_exec(executor);
    srand(time(NULL));
    std::cout << "brrrr... dzzzzz...brrrr... dzzzzz...\n";
    if (rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully!\n";
    else
        std::cout << "The robotomy failed!\n";
}