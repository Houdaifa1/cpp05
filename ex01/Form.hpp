# ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>

class Bureaucrat;



class Form
{
    private :

        const std::string   name;
        bool                is_signed;
        const int           grade_to_sign;
        const int           grade_to_exec;

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
        Form();
        ~Form();
        Form(std::string name, int new_grade_to_sign, int new_grade_to_exec);
        Form(const Form &other);
        Form &operator=(const Form &other);

        std::string get_name() const;
        bool get_signed_info() const;
        int get_grade_to_sign() const;
        int get_grade_to_exec() const;

        void beSigned(Bureaucrat &bureaucrat);


};

std::ostream &operator<<(std::ostream &out, Form &form);


# endif