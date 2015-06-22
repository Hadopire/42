#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Form;

class Bureaucrat {

    private:
        std::string const   _name;
        int                 _grade;
        Bureaucrat( void );

    public:
        class GradeTooHighException : public std::exception {
            
            public:
                GradeTooHighException( void ) throw() {}
                virtual ~GradeTooHighException( void ) throw() {}

                virtual const char* what( void )  const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                GradeTooLowException( void ) throw() {}
                virtual ~GradeTooLowException( void ) throw() {}

                virtual const char* what( void ) const throw();
        };

        Bureaucrat( std::string name, int grade );
        Bureaucrat( Bureaucrat const & src );
        ~Bureaucrat( void );

        void            signForm(Form & );
    
        Bureaucrat &    operator=( Bureaucrat const & rhs );

        std::string getName( void ) const;
        int         getGrade( void ) const;
        void        incGrade( void );
        void        decGrade( void );
};

std::ostream &    operator<<( std::ostream & out, Bureaucrat const & rhs );

#endif
