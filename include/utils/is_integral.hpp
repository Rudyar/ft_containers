/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:44:17 by arudy             #+#    #+#             */
/*   Updated: 2022/09/22 10:32:22 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://cplusplus.com/reference/type_traits/is_integral/?kw=is_integral
// https://cplusplus.com/reference/type_traits/integral_constant/		is_integral dep of integral_constant
// https://dev.to/sandordargo/what-are-type-traits-in-c-18j5

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace ft
{
	template <class T, T v>
	struct integral_constant
	{
		static const T					value = v;
		typedef T						value_type;
		typedef integral_constant<T, v>	type;
		operator T() { return v; }
	};

	// true and false type implementation
	typedef integral_constant<bool, true>	true_type;
	typedef integral_constant<bool, false>	false_type;

	// Default type = false
	template <class T>
	struct is_integral : public false_type {};

	template <>
	struct is_integral<bool> : public true_type {};

	template <>
	struct is_integral<char> : public true_type {};

	template <>
	struct is_integral<wchar_t> : public true_type {};

	template <>
	struct is_integral<signed char> : public true_type {};

	template <>
	struct is_integral<short int> : public true_type {};

	template <>
	struct is_integral<int> : public true_type {};

	template <>
	struct is_integral<long int> : public true_type {};

	template <>
	struct is_integral<unsigned char> : public true_type {};

	template <>
	struct is_integral<unsigned short int> : public true_type {};

	template <>
	struct is_integral<unsigned int> : public true_type {};

	template <>
	struct is_integral<unsigned long int> : public true_type {};

	// template <>
	// struct is_integral<long long int> : public true_type {}; C++98 doesnt support long long with -pedantic

	// template <>
	// struct is_integral<unsigned long long int> : public true_type {}; C++98 doesnt support long long with -pedantic
}

#endif
