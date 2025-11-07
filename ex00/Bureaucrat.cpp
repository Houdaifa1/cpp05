# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :
        name("Default"), grade(150)
{
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int new_grade) :
        name(name)
{
    if (new_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (new_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    grade = new_grade;
    std::cout << "Parameterized constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    std::cout << "Copy constructor called" << std::endl;
    grade = other.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
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

std::ostream    &operator<<(std::ostream &out, const Bureaucrat &bureauobj)
{
    out << bureauobj.getName() << ", bureaucrat grade " << bureauobj.getGrade();
    return out;
} 

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
}
