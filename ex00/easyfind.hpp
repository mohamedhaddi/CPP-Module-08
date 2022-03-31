/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:10:24 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/31 17:41:53 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template<typename T>
typename T::iterator easyfind(T & container, int value)
{
	typename T::iterator it = container.begin();
	typename T::iterator end = container.end();

	while (it != end)
	{
		if (*it == value)
			return (it);
		it++;
	}

	return (container.end());
}


#endif
