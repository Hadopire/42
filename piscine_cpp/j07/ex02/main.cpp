#include "Array.class.hpp"
#include <string>
int main() {

	std::cout << "on essaye de creer un tableau vide et dacceder a une case" << std::endl;
	Array<int> a;
	try {
		std::cout << a[0];
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "on cree un tableau dint avec ses valeur initialisees par default et on affiche la premiere case pour etre sur" << std::endl;
	Array<int> b(10);
	std::cout << b[0] << std::endl;
	std::cout << "on fait un nouveau tableau dint en utilisant operator= avec le precedent" << std::endl;
	Array<int> c;
	c = b;
	std::cout << c[0] << std::endl;
	std::cout << "on modifie la premiere case de notre nouveau tableau et on verifie si ca change pas lancien" << std::endl;
	c[0] = 10;
	std::cout << "ancien: " << b[0] << std::endl;
	std::cout << "nouveau: " << c[0] << std::endl;

	std::cout << "ok un tableau de string maintenant" << std::endl;
	Array<std::string> str(2);
	str[0] = "premiere case";
	str[1] = "seconde case";
	for (unsigned int i = 0; i < str.size(); i++) {
		std::cout << str[i] << std::endl;
	}
	return (0);
}
