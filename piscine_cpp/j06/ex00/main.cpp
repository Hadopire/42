#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include <cmath>
#include <limits>

void    int_to_char(int i, std::stringstream & ssc) {

    if (isprint(i))
        ssc << "'" << static_cast<char>(i) << "'";
    else if (isascii(i))
        ssc << "Non displayable";
    else
        ssc << "Impossible";

}

void    set_precision(std::string entry, std::stringstream & ssd, std::stringstream & ssf) {

    int precision = entry.find(".") == std::string::npos ? 1 : entry.size() - entry.find(".") - 1;
    if (entry[entry.size() - 1] == 'f')
        precision--;
    if (precision == 0)
        precision++;
    ssf.precision(precision > 7 ? 7 : precision);
    ssd.precision(precision > 15 ? 15 : precision);
}

int main(int ac, char **av) {

    if (ac > 1) {

        std::string entry = av[1];
        std::stringstream ssc;
        std::stringstream ssf;
        std::stringstream ssi;
        std::stringstream ssd;

        ssf << std::fixed;
        ssd << std::fixed;
        if (entry[entry.size() - 1] == 'f' && entry.compare("inf") != 0 && entry.compare("-inf") != 0 && 
            entry.compare("+inf") != 0) { //si float

            std::cout << "Float type detected" << std::endl;
            set_precision(entry, ssd, ssf);
            float f = static_cast<float>(::atof(entry.c_str()));
            if (isinf(f) || isnan(f)) { // si inf ou nan alors int et char impossible
                ssc << "Impossible";
                ssi << "Impossible";
            }
            else { // sinon convertion vers int et char
                int i = static_cast<int>(f);
                if (static_cast<float>(i) == f) {
                    int_to_char(i, ssc);
                }
                else
                    ssc << "Impossible";
                if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
                    ssi << i;
                else
                    ssi << "Impossible";
            }
            ssf << f << "f";
            ssd << static_cast<double>(f);
        }
        else if (entry.find(".") == std::string::npos && entry.find("inf") == std::string::npos &&
            entry.find("nan") == std::string::npos && entry.find("NaN") == std::string::npos) { // si int

            std::cout << "Int type detected" << std::endl;
            ssf.precision(1);
            ssd.precision(1);
            int i = atoi(entry.c_str());
            int_to_char(i, ssc); //conversion to char
            ssf << static_cast<float>(i) << "f";
            ssd << static_cast<double>(i);
            ssi << i;
        }
        else /* sinon double */ {
            std::cout << "Double type detected" << std::endl;
            set_precision(entry, ssd, ssf);
            double d = ::atof(entry.c_str());
            if (isinf(d) || isnan(d)) {
                ssc << "Impossible";
                ssi << "Impossible";
            }
            else {
                int i = static_cast<int>(d);
                if (static_cast<double>(i) == d) {
                    int_to_char(i, ssc);
                }
                else
                    ssc << "Impossible";
                if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
                    ssi << i;
                else
                    ssi << "Impossible";
            }
            ssd << d;
            ssf << static_cast<float>(d) << "f";
        }

        std::cout << "char: " << ssc.str() << std::endl << "int: " << ssi.str() << std::endl << "float: " 
            << ssf.str() << std::endl << "double: " << ssd.str() << std::endl;
    }

    return (0);
}
