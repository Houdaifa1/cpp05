#include "Form.hpp"
#include "Bureaucrat.hpp"



Form::Form() :
    name("default"), grade_to_sign(1), grade_to_exec(1)
{}

Form::Form(std::string name, int grade_to_sign, int grade_to_exec) :
    name(name), grade_to_sign(grade_to_sign), grade_to_exec(grade_to_exec)
{
    if (grade_to_sign > 150 || grade_to_exec > 150)
        throw Form::GradeTooLowException();
    if (grade_to_sign < 1 || grade_to_exec < 1)
        throw Form::GradeTooHighException();
    is_signed = false;
}

Form::Form(const Form &other)
    : name(other.name),
      is_signed(other.is_signed),
      grade_to_sign(other.grade_to_sign),
      grade_to_exec(other.grade_to_exec)
{}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        this->is_signed = other.is_signed;
    return *this;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}


std::string Form::get_name() const {return name;}

bool Form::get_signed_info() const {return is_signed;}

int Form::get_grade_to_sign() const {return grade_to_sign;}

int Form::get_grade_to_exec() const{return grade_to_exec;}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= grade_to_sign)
        is_signed = true;
    else
        throw Form::GradeTooLowException();
}


std::ostream &operator<<(std::ostream &out, Form &form)
{
    out << form.get_name() << ", grade to sign " << form.get_grade_to_sign()
        << " grade to execute " << form.get_grade_to_exec();
    if (form.get_signed_info())
        out << " , signed.";
    else
        out << " , still not signed";
    return out;
}

Form::~Form()
{}