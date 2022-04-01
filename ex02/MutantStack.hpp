/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:06:42 by mhaddi            #+#    #+#             */
/*   Updated: 2022/04/01 21:21:26 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{

	public:

		MutantStack(void) {};
		MutantStack(MutantStack const &src) { *this = src; };
		~MutantStack(void) {};

		MutantStack &operator=(MutantStack const &rhs) {
			std::stack<T>::operator=(rhs);
			return *this;
		};

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin(void)
		{
			return this->c.begin();
		}

		iterator end(void)
		{
			return this->c.end();
		}

};

#endif
