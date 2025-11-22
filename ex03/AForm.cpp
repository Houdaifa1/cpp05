#include "AForm.hpp"
#include "Bureaucrat.hpp"



AForm::AForm() :
    name("default"), grade_to_sign(1), grade_to_exec(1)
{}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_exec) :
    name(name), grade_to_sign(grade_to_sign), grade_to_exec(grade_to_exec)
{
    if (grade_to_sign > 150 || grade_to_exec > 150)
        throw AForm::GradeTooLowException();
    if (grade_to_sign < 1 || grade_to_exec < 1)
        throw AForm::GradeTooHighException();
    is_signed = false;
}

AForm::AForm(const AForm &other)
    : name(other.name),
      is_signed(other.is_signed),
      grade_to_sign(other.grade_to_sign),
      grade_to_exec(other.grade_to_exec)
{}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        this->is_signed = other.is_signed;
    return *this;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

const char *AForm::GradeExecLow::what() const throw()
{
    return "Grade is too low to exec!";
}

const char *AForm::FormNotSigned::what() const throw()
{
    return "Form Not Signed!";
}

std::string AForm::get_name() const {return name;}

bool AForm::get_signed_info() const {return is_signed;}

int AForm::get_grade_to_sign() const {return grade_to_sign;}

int AForm::get_grade_to_exec() const{return grade_to_exec;}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= grade_to_sign)
        is_signed = true;
    else
        throw AForm::GradeTooLowException();
}

void AForm::check_before_exec(Bureaucrat const  &executor) const
{
    if (!get_signed_info())
    {
        throw FormNotSigned();
    }
    if (executor.getGrade() > get_grade_to_exec())
    {
        throw GradeExecLow();
    }
}

std::ostream &operator<<(std::ostream &out, AForm &AForm)
{
    out << AForm.get_name() << ", grade to sign " << AForm.get_grade_to_sign()
        << " grade to execute " << AForm.get_grade_to_exec();
    if (AForm.get_signed_info())
        out << " , signed.";
    else
        out << " , still not signed";
    return out;
}

AForm::~AForm()
{}