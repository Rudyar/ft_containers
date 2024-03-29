/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:02:18 by arudy             #+#    #+#             */
/*   Updated: 2022/09/22 12:00:39 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// https://m.cplusplus.com/reference/iterator/iterator/
	// https://m.cplusplus.com/reference/iterator/iterator_traits/
	// page 516 iso c++ 98

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <cstddef> // ptrdiff_t

namespace ft
{
	// Define iterators categories
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	// Define Iterator struct
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
		struct iterator
		{
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;
		};

	// Default struct for iterator_traits
	template <class Iterator>
		struct iterator_traits
		{
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
		};

	// Spe struct for iterator_traits for pointer
	template <class T>
		struct iterator_traits<T*>
		{
			typedef T							value_type;
			typedef ptrdiff_t					difference_type;
			typedef T*							pointer;
			typedef T&							reference;
			typedef random_access_iterator_tag	iterator_category;
		};

	// Spe struct for iterator_traits for const pointer
	template <class T>
		struct iterator_traits<const T*>
		{
			typedef T							value_type;
			typedef ptrdiff_t					difference_type;
			typedef const T*					pointer;
			typedef const T&					reference;
			typedef random_access_iterator_tag	iterator_category;
		};
}

#endif
