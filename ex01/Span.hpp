/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:51:46 by mhaddi            #+#    #+#             */
/*   Updated: 2022/04/01 17:59:03 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span {

	public:

		Span(unsigned int N);
		Span(Span const &src);
		~Span(void);

		Span &operator=(Span const &rhs);

		void 	addNumber(int n);
		int 	shortestSpan(void) const;
		int		longestSpan(void) const;
		void 	fill(
					std::vector<int>::iterator begin,
					std::vector<int>::iterator end
				);

	private:
		
		std::vector<int> _numbers;
		unsigned int _N;

		Span(void);

		class MaximumCapacityReachedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class NotEnoughNumbersException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

};
	

#endif
