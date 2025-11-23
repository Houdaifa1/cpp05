# include "Intern.hpp"
# include <vector>

Intern::Intern(){}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)(other);
    return *this;
}

Intern::~Intern(){}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
    const char* form_names[3] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };

    AForm *forms[3] = {
        new PresidentialPardonForm(target),
        new RobotomyRequestForm(target),
        new ShrubberyCreationForm(target)};

    int i = 0;
    while(i < 3)
    {
        if (form_name == form_names[i])
        {
            std::cout << "Intern creates " << form_name << " Form\n";
            for(int d = 0; d < 3; d++)
            {
                if (d != i)
                    delete forms[d];
            }
            return forms[i];
        }
        i++;
    }
    for(int d = 0; d < 3; d++) {delete forms[d];}
    std::cout << "Like bureaucrats said, I'm stupid\n";
    return NULL;
}