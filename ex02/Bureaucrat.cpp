#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() :
        name("Default"), grade(150)
{}

Bureaucrat::Bureaucrat(std::string name, int new_grade) :
        name(name)
{
    if (new_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (new_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    grade = new_grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

std::string Bureaucrat::getName() const { return name; }

int Bureaucrat::getGrade() const {return grade; }

void Bureaucrat::incrementGrade()
{
    if (grade == 1)
        throw Bureaucrat::GradeTooHighException();
    grade -= 1;
}

void Bureaucrat::decrementGrade()
{
    if (grade == 150)
        throw Bureaucrat::GradeTooLowException();
    grade += 1;
}

void Bureaucrat::signAForm(AForm &AForm)
{
    try
    {
        AForm.beSigned(*this);
        std::cout << name << " signed " << AForm.get_name() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout   << name << " couldn’t sign " << AForm.get_name() 
                    << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try 
    {
        form.execute(*this);
    }
    catch(std::exception &e)
    {
        std::cout   << name << " couldn’t execute " << form.get_name() 
                    << " because " << e.what() << std::endl;
        return ;
    }
    std::cout << name << " executed " << form.get_name() << std::endl;
}

std::ostream    &operator<<(std::ostream &out, const Bureaucrat &bureauobj)
{
    out << bureauobj.getName() << ", bureaucrat grade " << bureauobj.getGrade();
    return out;
} 

Bureaucrat::~Bureaucrat()
{}
