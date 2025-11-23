#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat alice("Alice", 42);
        std::cout << alice << std::endl;


        alice.incrementGrade();
        std::cout << alice << std::endl;

        alice.decrementGrade();
        std::cout << alice << std::endl;

        Bureaucrat bob("Bob", 0);
    }
    catch (std::exception  &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }


    try
    {
        Bureaucrat charlie("Charlie", 151);
    }
    catch (std::exception  &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }


    try
    {
        Bureaucrat max("Max", 1);

        std::cout << max << std::endl;
        max.incrementGrade();
    }
    catch (std::exception  &e)
    {
            std::cerr << "Caught exception on increment: " << e.what() << std::endl;
    }
    
    return 0;
}