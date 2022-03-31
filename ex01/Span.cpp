/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:59:31 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/31 22:43:04 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

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
	if (this->_numbers.size() == this->_N)
		throw Span::MaximumCapacityReachedException();

	this->_numbers.push_back(n);
}

void Span::fill(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->_numbers.size() + distance(begin, end) > this->_N)
		throw Span::MaximumCapacityReachedException();

	this->_numbers.insert(this->_numbers.end(), begin, end);
}

int Span::shortestSpan(void) const
{
	if (this->_numbers.size() < 2)
		throw Span::NotEnoughNumbersException();

	std::vector<int> numbersCopy = this->_numbers;
	std::sort(numbersCopy.begin(), numbersCopy.end());

	std::vector<int>::iterator it = numbersCopy.begin();

	int minDiff = std::abs(*it - *(++it));

	while (it != numbersCopy.end() - 1)
	{
		int newDiff = std::abs(*it - *(++it));
		if (newDiff < minDiff)
			minDiff = newDiff;
	}

	return (minDiff);
}

int Span::longestSpan(void) const
{
	if (this->_numbers.size() < 2)
		throw Span::NotEnoughNumbersException();

	std::vector<int> numbersCopy = this->_numbers;
	std::sort(numbersCopy.begin(), numbersCopy.end());

	int maxDiff = *(numbersCopy.end() - 1) - *numbersCopy.begin();

	return (maxDiff);
}

const char *Span::MaximumCapacityReachedException::what() const throw()
{
	return ("Maximum capacity reached");
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
	return ("Not enough numbers");
}
