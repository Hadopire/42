/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 15:10:01 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/16 16:46:16 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>

void	ponyOnTheStack() {

	std::cout << "Lets create a pony on the stack" << std::endl;
	Pony pony = Pony("blue", "Stack");
	std::cout << "Lets change the value of pony" << std::endl;
	pony = Pony("red", "new Stack");
	std::cout << "We can see that pony died and a new was created" << std::endl;
}

void	ponyOnTheHeap() {
	
	std::cout << "Lets create a pony on the heap" << std::endl;
	Pony *pony = new Pony("blue", "Heap");
	std::cout << "Lets change the value of pony" << std::endl;
	Pony *copy = pony;
	pony = 0;
	std::cout << "We can se that pony did not die" << std::endl;
	delete copy;
}

int		main()
{
	ponyOnTheHeap();
	ponyOnTheStack();
	std::cout << "Back in the main, we have " << Pony::getNbPony() << " ponies left" << std::endl;
	return (0);
}
