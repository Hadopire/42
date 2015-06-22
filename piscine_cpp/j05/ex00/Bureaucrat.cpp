#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name, int grade ) :
    _name(name)
{
    if (grade < 1) {
        
        this->_grade = 1;
        throw Bureaucrat::GradeTooHighException();
    }
    else if (grade > 150) {
        
        this->_grade = 150;
        throw Bureaucrat::GradeTooLowException();
    }
    else
        this->_grade = grade;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) :
    _name(src.getName()), _grade(src.getGrade())
{
}

Bureaucrat::~Bureaucrat( void ) {

}

Bureaucrat &    Bureaucrat::operator=(Bureaucrat const & rhs ) {

    this->_name = rhs.getName();
    this->_grade = rhs.getGrade();
    return *this;
}

std::ostream &  operator<<( std::ostream & out, Bureaucrat const & rhs ) {
    
    out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return out;
}

std::string Bureaucrat::getName( void ) const { return this->_name; }
int         Bureaucrat::getGrade( void ) const { return this->_grade; }
void        Bureaucrat::decGrade( void ) {

    if (this->_grade + 1 > 150)
        throw GradeTooLowException();
    else
        ++this->_grade;
}
void        Bureaucrat::incGrade( void ) {

    if (this->_grade - 1 < 1)
        throw GradeTooHighException();
    else
        --this->_grade;
}
