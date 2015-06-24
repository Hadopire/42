#include <iostream>
#include <string>

template<typename T>
void    print(T a) {

    std::cout << a << std::endl;
}

template<typename T>
void    iter(T * array, size_t size, void f(T)) {
    
    for (size_t i = 0; i < size; i++) {
        
        f(array[i]);
    }
}

int main() {

    int a[] = { 1, 2, 3 ,4, 5 };
    float b[] = {3.14, 2.5, 8.5, 3.2};
    std::string c[2];

    c[0] = "premier element";
    c[1] = "deuxieme element";

    std::cout << "sur un tableau d'int" << std::endl;
    ::iter<int>(a, 5, print);
    std::cout << "sur un tableau de float" << std::endl;
    ::iter<float>(b, 4, print);
    std::cout << "sur un tabeau de string" << std::endl;
    ::iter<std::string>(c, 2, print);
    return (0);
}
