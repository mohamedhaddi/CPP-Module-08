/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:13:39 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/31 21:26:10 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> cringeNumbers;

	cringeNumbers.push_back(42);
	cringeNumbers.push_back(1337);
	cringeNumbers.push_back(420);
	cringeNumbers.push_back(69);

	std::vector<int>::iterator it = easyfind(cringeNumbers, 420);

	if (it != cringeNumbers.end())
		std::cout 	<< "Found 420 at index "
					<< std::distance(cringeNumbers.begin(), it)
					<< std::endl;
	else
		std::cout 	<< "420 not found" << std::endl;

	it = easyfind(cringeNumbers, 666);

	if (it != cringeNumbers.end())
		std::cout 	<< "Found 666 at index "
					<< std::distance(cringeNumbers.begin(), it)
					<< std::endl;
	else
		std::cout	<< "666 not found" << std::endl;

	return (0);
}

