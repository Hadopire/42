#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form {

    protected:
        std::string const   _name;
        bool                _signed;
        int const           _signGrade;
        int const           _executeGrade;
        Form( void );

    public:
        class GradeTooHighException : public std::exception {
            
            private:
                std::string const   _msg;
            public:
                GradeTooHighException( void ) throw();
                GradeTooHighException( std::string const & msg ) throw();
                virtual ~GradeTooHighException( void ) throw() {}

                virtual const char* what( void )  const throw();
        };

        class GradeTooLowException : public std::exception {
            private:
                std::string const   _msg;
            public:
                GradeTooLowException( void ) throw();
                GradeTooLowException( std::string const & msg ) throw();
                virtual ~GradeTooLowException( void ) throw() {}

                virtual const char* what( void ) const throw();
        };

        Form( std::string name, int signGrade, int executeGrade );
        Form( Form const & src );
        virtual ~Form( void );
        
        void            beSigned( Bureaucrat const & );
        virtual void    execute( Bureaucrat const & ) const;

        Form &      operator=( Form const & rhs );

        std::string getName( void ) const;
        bool        getSigned( void ) const;
        int         getSignGrade( void ) const;
        int         getExecuteGrade( void ) const;
};

std::ostream &    operator<<( std::ostream & out, Form const & rhs );

#endif
