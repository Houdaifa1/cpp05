# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        target = other.target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

const char *ShrubberyCreationForm::FaildToOpen::what() const throw()
{
    return "Failed to open file!";
}

void ShrubberyCreationForm::execute(Bureaucrat const  &executor) const
{

    check_before_exec(executor);
    std::string file_name = target +  "_shrubbery";

    std::ofstream tree(file_name.c_str());
    if (!tree.is_open())
    {
        throw FaildToOpen();
    }
    tree << "  /\\\n"
         << " /  \\\n"
         << "/____\\\n"
         << "  ||\n";
    tree.close();
}