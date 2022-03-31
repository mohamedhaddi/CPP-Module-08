/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:13:39 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/31 22:46:03 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <iterator>
#include <vector>

int main() {

	Span sp = Span(5);

	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		/*
		std::vector<int>::iterator it = sp._numbers.begin();
		std::cout << "sp: ";
		while (it != sp._numbers.end()) {
			std::cout << *it << " ";
			it++;
		}
		std::cout << std::endl;
		*/

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		
		std::vector<int> v;
		for (int i = 0; i < 10; i++)
			v.push_back(i);

		std::vector<int>::iterator it1 = v.begin();
		std::vector<int>::iterator it2 = v.end();

		sp.fill(it1, it2);

		/*
		std::vector<int>::iterator it3 = sp._numbers.begin();
		std::cout << "sp: ";
		while (it3 != sp._numbers.end()) {
			std::cout << *it3 << " ";
			it3++;
		}
		std::cout << std::endl;
		*/
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;

}
