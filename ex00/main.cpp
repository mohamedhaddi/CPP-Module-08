/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:13:39 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/31 17:49:28 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> coolNumbers;

	coolNumbers.push_back(42);
	coolNumbers.push_back(1337);
	coolNumbers.push_back(420);
	coolNumbers.push_back(69);

	std::vector<int>::iterator it = easyfind(coolNumbers, 420);

	if (it != coolNumbers.end())
		std::cout 	<< "Found 420 at index "
					<< std::distance(coolNumbers.begin(), it)
					<< std::endl;
	else
		std::cout 	<< "420 not found" << std::endl;

	it = easyfind(coolNumbers, 666);

	if (it != coolNumbers.end())
		std::cout 	<< "Found 666 at index "
					<< std::distance(coolNumbers.begin(), it)
					<< std::endl;
	else
		std::cout	<< "666 not found" << std::endl;

	return (0);
}

