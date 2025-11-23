#include "Bureaucrat.hpp"
#include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "Intern.hpp"

int main()
{
    try
    {
        Bureaucrat alice("Alice", 137);
        ShrubberyCreationForm tree("");
        alice.signAForm(tree);
        alice.executeForm(tree);

      
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("shrubbery creation", "tessssst");
    Bureaucrat alice("Alice", 1);
    alice.signAForm(*rrf);
    alice.executeForm(*rrf);
    delete (rrf);
    return 0;
}
