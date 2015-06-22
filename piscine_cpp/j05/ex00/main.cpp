#include "Bureaucrat.hpp"

// Premier try en mettant un grade trop bas, deuxieme try en essayant d'incrementer le grade de michel alors qu'il est deja le boss de la vie

int main( void ) {

    try
    {
        Bureaucrat a("jean", 1000);
        std::cout << a << std::endl;
    }
    catch(std::exception & e) {
        std::cout << e.what() << std::endl;
    }


    try
    {
        Bureaucrat a("michel", 1);
        std::cout << a << std::endl;
        a.incGrade();
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
