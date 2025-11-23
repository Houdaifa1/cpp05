#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat alice("Alice", 42);
        Form formA("FormA", 50, 30);

        std::cout << alice << std::endl;
        std::cout << formA << std::endl;

        alice.signForm(formA);
        std::cout << formA << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try
    {
        Form badForm("InvalidForm", 0, 10);
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat lowBob("LowBob", 120);
        Form highForm("HighForm", 50, 30);

        std::cout << lowBob << std::endl;
        std::cout << highForm << std::endl;

        lowBob.signForm(highForm);
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
