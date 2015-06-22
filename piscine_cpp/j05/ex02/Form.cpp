#include "Form.hpp"
#include <stdexcept>
#include "Bureaucrat.hpp"

Form::Form( std::string name, int signGrade, int executeGrade ) :
    _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (signGrade > 150)
        throw GradeTooLowException("grade required to sign the form is too low");
    else if (signGrade < 1)
        throw GradeTooHighException("grade required to sign the form is too high");
    if (executeGrade > 150)
        throw GradeTooLowException("grade required to execute the form is too low");
    else if (executeGrade < 1)
        throw GradeTooHighException("grade required to execute the form is too high");
}

Form::Form( Form const & src ) :
    _name(src.getName()), _signed(src.getSigned()), _signGrade(src.getSignGrade()),
    _executeGrade(src.getExecuteGrade())
{
}

Form::~Form( void ) {

}

Form &    Form::operator=(Form const & rhs ) {

    this->_signed = rhs.getSigned();
    return *this;
}

void            Form::beSigned( Bureaucrat const & b) {

    if (this->_signed == true) {
        std::cout << "form already signed" << std::endl;
        return;
    }
    if (b.getGrade() > this->_signGrade)
        throw GradeTooLowException("bureaucrat grade too low to sign the form");
    else
        this->_signed = true;
}

std::ostream &  operator<<( std::ostream & out, Form const & rhs ) {

    out << "The form " << rhs.getName() << " require grade " << rhs.getSignGrade()
        << " to be signed and grade " << rhs.getExecuteGrade()
        << "to be executed. ";
    if (rhs.getSigned())
        out << "The form is already signed.";
    else
        out << "The form is not signed yet.";
    return out;
}

void        Form::execute( Bureaucrat const & executor) const {
    (void) executor;
}

std::string Form::getName( void ) const { return this->_name; }
int         Form::getSignGrade( void ) const { return this->_signGrade; }
int         Form::getExecuteGrade( void ) const { return this->_executeGrade; }
bool        Form::getSigned( void ) const { return this->_signed; }

Form::GradeTooHighException::GradeTooHighException( void ) throw() : _msg("") {}
Form::GradeTooHighException::GradeTooHighException( std::string const &msg) throw() : _msg(msg) {}
const char* Form::GradeTooHighException::what( void ) const throw() {
    return ("GradeTooHighException: " + this->_msg).c_str();
}
Form::GradeTooLowException::GradeTooLowException( void ) throw() : _msg("") {}
Form::GradeTooLowException::GradeTooLowException( std::string const &msg) throw() : _msg(msg) {}
const char* Form::GradeTooLowException::what( void ) const throw() {
    return ("GradeTooLowException: " + this->_msg).c_str();
}
