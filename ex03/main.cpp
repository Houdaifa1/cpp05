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
    rrf = someRandomIntern.makeForm("qss request", "Bender");
   (void)rrf;
    delete (rrf);
    return 0;
}
