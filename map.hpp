/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:09:44 by arudy             #+#    #+#             */
/*   Updated: 2022/08/31 12:31:54 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// page 490 ISO 1998

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

			class value_compare : std::binary_function<value_type, value_type, bool>
			{
				friend class map;
				protected :
					Compare comp;
					value_compare(Compare c) : comp(c) {}
				public :
					bool operator()(const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
			};
		private :
			// red_black_tree	_tree;
		public :
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) // use of explicit to not implicity convert type during construction
			{
				static_cast<void>(comp);
				static_cast<void>(alloc);
			}

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				static_cast<void>(comp);
				static_cast<void>(alloc);
				static_cast<void>(first);
				static_cast<void>(last);
			}

			map(const map& x)
			{
				static_cast<void>(x);
				// Deep copy ?
			}

			~map()
			{
				// destroy tree
			}

			map &operator=(const map &rhs)
			{
				// _tree = rhs._tree;
				return *this;
			}

			// ==================== Iterators

			// iterator begin()
			// {
				// return _tree.begin();
			// }

			// const_iterator begin() const
			// {
				// return _tree.begin();
			// }

			// iterator end()
			// {
				// return _tree.end();
			// }

			// const_iterator end() const
			// {
				// return _tree.end();
			// }

			// iterator rbegin()
			// {
				// return _tree.rbegin();
			// }

			// const_iterator rbegin() const
			// {
				// return _tree.rbegin();
			// }

			// iterator rend()
			// {
				// return _tree.rend();
			// }

			// const_iterator rend() const
			// {
				// return _tree.rend();
			// }

			// ==================== Capacity

			// bool empty() const
			// {
			// 	return tree size = 0 ?
			// }

			// size_type size() const
			// {
				// return _tree.size();
			// }

			// size_type max_size() const
			// {
				// return _tree.max_size() ??
			// }

	};

} // namespace ft


#endif
