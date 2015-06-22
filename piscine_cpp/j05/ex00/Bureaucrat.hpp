#include <string>
#include <iostream>

class Bureaucrat {

    private:
        std::string _name;
        int         _grade;
        Bureaucrat( void );

    public:
        class GradeTooHighException : public std::exception {
            
            public:
                GradeTooHighException( void ) throw() {}
                virtual ~GradeTooHighException( void ) throw() {}

                virtual const char* what( void )  const throw() { 
                    return "Invalid grade, too high.";
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                GradeTooLowException( void ) throw() {}
                virtual ~GradeTooLowException( void ) throw() {}

                virtual const char* what( void ) const throw() {
                    return "Invalid grade, too low.";
                }
        };

        Bureaucrat( std::string name, int grade );
        Bureaucrat( Bureaucrat const & src );
        ~Bureaucrat( void );

        Bureaucrat &    operator=( Bureaucrat const & rhs );

        std::string getName( void ) const;
        int         getGrade( void ) const;
        void        incGrade( void );
        void        decGrade( void );
};

std::ostream &    operator<<( std::ostream & out, Bureaucrat const & rhs );
