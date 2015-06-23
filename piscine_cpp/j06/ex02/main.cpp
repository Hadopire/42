#include <iostream>
#include <exception>
#include <stdlib.h>
#include <time.h>

class   Base { public: virtual ~Base( void ){} };
class   A : public Base {};
class   B : public Base {};
class   C : public Base {};

Base *  generate( void ) {

    int i = rand()%3;
    Base *base;

    if (i == 0) {

        std::cout << "Base base = new A" << std::endl;
        base = new A;
    }
    else if (i == 2) {

        std::cout << "Base base = new B" << std::endl;
        base = new B;
    }
    else {

        std::cout << "Base base = new C" << std::endl;
        base = new C;
    }
    return base;
}

void    identify_from_pointer(Base * p) {

    try {
        A &a = dynamic_cast<A&>(*p);
        static_cast<void>(a);
        std::cout << "A" << std::endl;
    }
    catch (std::exception & e ){
        
        static_cast<void>(e);
    }
    try {
        B &b = dynamic_cast<B&>(*p);
        static_cast<void>(b);
        std::cout << "B" << std::endl;
    }
    catch ( std::exception & e ) {

        static_cast<void>(e);
    }
    try {
        C &c = dynamic_cast<C&>(*p);
        static_cast<void>(c);
        std::cout << "C" << std::endl;
    }
    catch( std::exception & e) {
        static_cast<void>(e);
    }
}

void    identify_from_reference(Base & p) {

    try {
        A &a = dynamic_cast<A&>(p);
        static_cast<void>(a);
        std::cout << "A" << std::endl;
    }
    catch (std::exception & e ){
        
        static_cast<void>(e);
    }
    try {
        B &b = dynamic_cast<B&>(p);
        static_cast<void>(b);
        std::cout << "B" << std::endl;
    }
    catch ( std::exception & e ) {

        static_cast<void>(e);
    }
    try {
        C &c = dynamic_cast<C&>(p);
        static_cast<void>(c);
        std::cout << "C" << std::endl;
    }
    catch( std::exception & e) {
        static_cast<void>(e);
    }
}


int main() {

    srand(time(NULL));
    Base *base = generate();
    identify_from_pointer(base);
    identify_from_reference(*base);
    delete base;
    return (0);
}
