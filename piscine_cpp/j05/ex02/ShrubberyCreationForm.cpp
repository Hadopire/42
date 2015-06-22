#include "ShrubberyCreationForm.hpp"
#include <sstream>
#include <fstream>
#include <stdexcept>
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string const & target ) :
    Form("Shrubbery creation form", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) :
    Form(src)
{

    this->_target = src.getTarget();
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs ){

    Form::operator=(*this);
    this->_target = rhs.getTarget();
    return *this;
}

void    ShrubberyCreationForm::execute( Bureaucrat const & executor ) const {

    if (!this->_signed) {
        std::cout << "form not signed yet" << std::endl;
        return;
    }
    else if (executor.getGrade() > this->_executeGrade)
        throw Form::GradeTooLowException("bureaucrast too noob to execute form");
    std::ofstream ofs((this->_target + "_shrubbery").c_str());
    ofs <<"          _-_" << std::endl;
    ofs <<"       /~~   ~~\\" << std::endl;
    ofs <<"    /~~         ~~\\" << std::endl;
    ofs <<"   {               }" << std::endl;
    ofs <<"    \\  _-     -_  /" << std::endl;
    ofs <<"      ~  \\ //  ~" << std::endl;
    ofs <<"    - -   | | _- _" << std::endl;
    ofs <<"     _ -  | |   -_" << std::endl;
    ofs <<"         / \\" << std::endl;
    ofs.close();
}

std::string ShrubberyCreationForm::getTarget( void ) const { return this->_target; }
