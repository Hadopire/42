#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
struct Data
{
    std::string s1;
    int         n;
    std::string s2;
};

void *serialize( void ) {
    
    void *data = new Data;
    static_cast<Data*>(data)->s1.resize(8);
    static_cast<Data*>(data)->s2.resize(8);
    std::string alphanum("0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM");
    for (int i = 0; i < 8; i++) {
        
        char c = alphanum[ rand() % (alphanum.size() - 1) ];
        static_cast<Data*>(data)->s1[i] = c;
        c = alphanum[ rand() % (alphanum.size() - 1) ];
        static_cast<Data*>(data)->s2[i] = c;
    }
    static_cast<Data*>(data)->n = rand();
    return (data);
}

Data *deserialize( void * raw ) {
    
    Data *data = new Data;
    data->s1 = static_cast<Data*>(raw)->s1;
    data->s2 = static_cast<Data*>(raw)->s2;
    data->n = static_cast<Data*>(raw)->n;
    return (data);
}

int main() {
    
    srand(time(NULL));
    void *data = serialize();
    Data *ddata = deserialize(data);
    std::cout << ddata->s1 << std::endl;
    std::cout << ddata->n << std::endl;
    std::cout << ddata->s2 << std::endl;
    delete static_cast<Data*>(data);
    delete ddata;
    return (0);
}
