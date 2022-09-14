/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:00:54 by arudy             #+#    #+#             */
/*   Updated: 2022/09/14 15:05:18 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

namespace ft
{
	template<typename T>
	void	_swap(T& x, T&y)
	{
		T tmp = x;

		x = y;
		y = tmp;
	}
} // namespace ft


#endif
