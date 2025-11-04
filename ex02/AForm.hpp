# ifndef AForm_HPP
# define AForm_HPP

# include <iostream>

class Bureaucrat;



class AForm
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
        AForm();
        virtual ~AForm();
        AForm(std::string name, int new_grade_to_sign, int new_grade_to_exec);
        AForm(AForm &other);
        AForm &operator=(AForm &other);

        virtual void execute (Bureaucrat const  &executor) = 0;

        std::string get_name() const;
        bool get_signed_info() const;
        int get_grade_to_sign() const;
        int get_grade_to_exec() const;

        void beSigned(Bureaucrat &bureaucrat);


};

std::ostream &operator<<(std::ostream &out, AForm &AForm);


# endif