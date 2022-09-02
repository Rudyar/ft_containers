/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:09:44 by arudy             #+#    #+#             */
/*   Updated: 2022/09/02 10:03:24 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// page 490 ISO 1998

#ifndef MAP_HPP
#define MAP_HPP
#include <memory>
#include <iostream>
#include <functional>
#include "utils/pair.hpp"
#include "utils/red_black_tree.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
	class map
	{
		public :
			typedef Key																		key_type;
			typedef T																		mapped_type;
			typedef pair<const Key, T>														value_type;
			typedef Compare																	key_compare;
			typedef Allocator 																allocator_type;
			typedef size_t																	size_type;
			typedef typename Allocator::reference											reference;
			typedef typename Allocator::const_reference										const_reference;
			typedef typename Allocator::pointer												pointer;
			typedef typename Allocator::const_pointer										const_pointer;
			typedef typename ft::red_black_tree<value_type, key_compare, allocator_type>	tree_type;
			//////////////////////////////////////////////
			typedef typename tree_type::iterator											iterator;
			typedef typename tree_type::const_iterator										const_iterator;
			// typedef tree_type...					const_itera	tor;
			// typedef tree_type...					size_type;
			// typedef tree_type...					difference_type;
			// typedef tree_type...					reverse_iterator;
			// typedef tree_type...					const_reverse_iterator;

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
			tree_type	_tree;

		public :
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
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
			// 	return _tree.begin();
			// }

			// const_iterator begin() const
			// {
				// return _tree.begin();
			// }

			// iterator end() // Try to iter in a loop with end (see jbonniva Discord msg)
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

			bool empty() const
			{
				return _tree.empty();
			}

			size_type size() const
			{
				_tree.test();
				return _tree.size();
			}

			size_type max_size() const
			{
				return _tree.max_size();
			}

			// ==================== Elements access

			// mapped_type& operator[](const key_type& x)
			// {
					// An alternative way to insert elements in a map is by using member function map::operator[]. From ref insert
			// }

			// ==================== Modifiers

			// pair<iterator, bool> insert(const value_type& x)
			// {
			// }

			iterator insert(iterator position, const value_type& x)
			{
				_tree.insert(x);
				return position;
			}

			// template<class InputIterator>
			// void insert(InputIterator first, InputIterator last)
			// {
			// }

			// void erase(iterator position)
			// {
			// }

			// size_type erase(const key_type& x)
			// {
			// }

			// void erase(iterator forst, iterator last)
			// {
			// }

			// void swap(map& x)
			// {
			// }

			// void clear()
			// {
			// }

			// ==================== Observers

			// key_compare key_comp() const
			// {
				// return key_compare();
			// }

			// value_compare value_comp() const
			// {
				// return value_compare();
			// }

			// ==================== Operations

			// iterator find(const key_type& k)
			// {
			// }

			// const_iterator find(const key_type& k) const
			// {
			// }

			// size_type count(const key_type& k) const
			// {
			// }

			// iterator lower_bound(const key_type& k)
			// {
			// }

			// const_iterator lower_bound(const key_type& k) const
			// {
			// }

			// iterator upper_bound(const key_type& k)
			// {
			// }

			// const_iterator upper_bound(const key_type& k) const
			// {
			// }

			// pair<iterator, iterator> equal_range(const key_type& k)
			// {
			// }

			// pair<const_iterator, const_iterator> equal_range(const key_type& k) const
			// {
			// }

			allocator_type get_allocator() const
			{
				return allocator_type();
			}
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return true; // ???
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return rhs < lhs;
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	// template<class Key, class T, class Compare, class Alloc>
	// void swap(map<Key, T, Compare, Alloc>& lhs, map<Key, T, Compare, Alloc>& rhs)
	// {
	// 	return lhs.swap(rhs);
	// }

} // namespace ft

#endif
