# include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 72, 45), target("")
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :  AForm(other), target(other.target){}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 72, 45), target(target){}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        target = other.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::execute(Bureaucrat const  &executor) const
{
    check_before_exec(executor);
    std::cout << target << "has has been pardoned by Zaphod Beeblebrox\n";
}