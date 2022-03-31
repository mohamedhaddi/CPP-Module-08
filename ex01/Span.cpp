/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:59:31 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/31 18:44:03 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

Span::Span(void) : _N(0)
{
	std::cout << "Span default constructor called" << std::endl;
	return ;
}

Span::Span(unsigned int N) : _N(N)
{
	std::cout << "Span constructor called" << std::endl;
	return ;
}

Span::Span(Span const &src)
{
	std::cout << "Span copy constructor called" << std::endl;
	*this = src;
	return ;
}

Span::~Span(void)
{
	std::cout << "Span destructor called" << std::endl;
	this->_numbers.clear();
	return ;
}

Span & Span::operator=(Span const &rhs)
{
	std::cout << "Span assignement operator called" << std::endl;
	if (this != &rhs)
	{
		this->_numbers = rhs._numbers;
		this->_N = rhs._N;
	}
	return (*this);
}

void Span::addNumber(int n)
{
	if (this->_numbers.size() < this->_N)
		this->_numbers.push_back(n);
	else
		throw Span::MaximumCapacityReachedException();
}

int Span::shortestSpan(void) const
{
	if (this->_numbers.size() < 2)
		throw Span::NotEnoughNumbersException();

	int min = std::abs(this->_numbers[0] - this->_numbers[1]);

	for (unsigned int i = 0; i < this->_numbers.size() - 1; i++)
	{
		int diff = std::abs(this->_numbers[i] - this->_numbers[i + 1]);
		if (diff < min)
			min = diff;
	}

	return (min);
}

int Span::longestSpan(void) const
{
	if (this->_numbers.size() < 2)
		throw Span::NotEnoughNumbersException();

	int max = std::abs(this->_numbers[0] - this->_numbers[1]);

	for (unsigned int i = 0; i < this->_numbers.size() - 1; i++)
	{
		int diff = std::abs(this->_numbers[i] - this->_numbers[i + 1]);
		if (diff > max)
			max = diff;
	}

	return (max);
}

const char *Span::MaximumCapacityReachedException::what() const throw()
{
	return ("Maximum capacity reached");
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
	return ("Not enough numbers");
}
