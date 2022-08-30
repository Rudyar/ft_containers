/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:09:44 by arudy             #+#    #+#             */
/*   Updated: 2022/08/30 18:21:26 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// page 490m ISO 1998

#ifndef MAP_HPP
#define MAP_HPP
#include <memory>
#include <iostream>
#include <functional>
#include "utils/pair.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
	class map
	{
		public :
			typedef Key									key_type;
			typedef T									mapped_type;
			typedef pair<const Key, T>					value_type;
			typedef Compare								key_compare;
			typedef Allocator 							allocator_type;
			typedef typename Allocator::reference		reference;
			typedef typename Allocator::const_reference	const_reference;
			typedef typename Allocator::pointer			pointer;
			typedef typename Allocator::const_pointer	const_pointer;
			// typedef red_black_tree					iterator;
			// typedef red_black_tree					const_iterator;
			// typedef red_black_tree					size_type;
			// typedef red_black_tree					difference_type;
			// typedef red_black_tree					reverse_iterator;
			// typedef red_black_tree					const_reverse_iterator;

	};

} // namespace ft


#endif
