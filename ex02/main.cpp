#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
    try
    {
        Bureaucrat alice("Alice", 42);
        AForm AFormA("AFormA", 50, 30);

        std::cout << alice << std::endl;
        std::cout << AFormA << std::endl;

        alice.signAForm(AFormA);
        std::cout << AFormA << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try
    {
        AForm badAForm("InvalidAForm", 0, 10);
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat lowBob("LowBob", 120);
        AForm highAForm("HighAForm", 50, 30);

        std::cout << lowBob << std::endl;
        std::cout << highAForm << std::endl;

        lowBob.signAForm(highAForm);
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
