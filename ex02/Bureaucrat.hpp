# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>


class AForm;

class Bureaucrat
{
    private :

        const std::string   name;
        int                 grade;

    public :
    
        class GradeTooHighException : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };

        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(std::string name, int new_grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);

        std::string getName() const;
        int         getGrade() const;
        void incrementGrade();
        void decrementGrade();

        void signAForm(AForm &AForm);
        void executeForm(AForm const & form) const;
    
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);


# endif