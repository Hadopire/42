#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void ) {

    // b essaye de signer f mais il est trop noob pour ca
    Bureaucrat b = Bureaucrat("Michel", 20);
    Form f = Form("Traite sur la peche aux moules", 19, 1);
   b.signForm(f);

   Form f2 = Form("Traite sur les poneys", 21, 1);
   std::cout << f2 << std::endl;
   std::cout << b << std::endl;
   b.signForm(f2);
    
    // tests de creation de form interdite
   try {

        Form test("lalala", 1, 1000);
    }
    catch (std::exception & e) {
        
        std::cout << e.what() << std::endl;
    }
    try {

        Form test("lalala", 1000, 1);
    }
    catch (std::exception & e) {
        
        std::cout << e.what() << std::endl;
    }
    return (0);
}
