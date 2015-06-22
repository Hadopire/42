#ifndef SHRUBERRY_HPP
#define SHRUBERRY_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class   ShrubberyCreationForm : public Form {
    
    private:
        std::string _target;
        ShrubberyCreationForm( void );

    public:
        ShrubberyCreationForm( std::string const & target );
        ShrubberyCreationForm( ShrubberyCreationForm const & src );
        virtual ~ShrubberyCreationForm( void );

        ShrubberyCreationForm & operator=( ShrubberyCreationForm const & );

        virtual void    execute( Bureaucrat const & executor ) const;

        std::string getTarget( void ) const;
};

#endif
