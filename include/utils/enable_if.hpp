/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:07:14 by arudy             #+#    #+#             */
/*   Updated: 2022/08/23 09:20:32 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://en.cppreference.com/w/cpp/types/enable_if
// SFINAE https://www.developpez.com/actu/94611/SFINAE-Interlude-moins-Cplusplus-avance-exemple-d-implementation/
// https://eli.thegreenplace.net/2014/sfinae-and-enable_if/

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

namespace ft
{
	template <bool B, class T = void>
	struct enable_if {};

	template <class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
} // namespace ft

#endif
