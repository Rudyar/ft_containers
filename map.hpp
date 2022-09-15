/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:09:44 by arudy             #+#    #+#             */
/*   Updated: 2022/09/15 12:28:06 by arudy            ###   ########.fr       */
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
#include "utils/lexicographical_compare.hpp"
#include "utils/enable_if.hpp"
#include "utils/is_integral.hpp"
#include "iterators/reverse_iterator.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
	class map
	{
		public :
			typedef Key														key_type;
			typedef T														mapped_type;
			typedef ft::pair<const key_type, mapped_type>					value_type;
			typedef Compare													key_compare;
			typedef Allocator 												allocator_type;
			typedef size_t													size_type;
			typedef ptrdiff_t												difference_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef typename ft::red_black_tree<value_type, key_type, key_compare>	tree_type;
			////////////////////////////////////////
			typedef typename tree_type::iterator							iterator;
			typedef typename tree_type::const_iterator						const_iterator;
			typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;

			class value_compare : std::binary_function<value_type, value_type, bool>
			{
				friend class map;
				protected :
					key_compare comp;
					value_compare(key_compare c) : comp(c) {}
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
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				static_cast<void>(comp);
				static_cast<void>(alloc);
				insert(first, last);
			}

			map(const map& x)
			{
				insert(x.begin(), x.end());
			}

			~map()
			{
			}

/////////////////////////////////////////////////////////////////

			void printTree()
			{
				_tree.print_red_black_tree();
			}

/////////////////////////////////////////////////////////////////

			map &operator=(const map &rhs)
			{
				if (*this != rhs)
				{
					clear();
					insert(rhs.begin(), rhs.end());
				}
				return *this;
			}

			// ==================== Iterators

			iterator begin()
			{
				return _tree.begin();
			}

			const_iterator begin() const
			{
				return _tree.begin();
			}

			iterator end()
			{
				return _tree.end();
			}

			const_iterator end() const
			{
				return _tree.end();
			}

			reverse_iterator rbegin()
			{
				return reverse_iterator(_tree.end());
			}

			const_reverse_iterator rbegin() const
			{
				return const_revser_iterator(_tree.end());
			}

			reverse_iterator rend()
			{
				return reverse_iterator(_tree.begin());
			}

			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(_tree.begin());
			}

			// ==================== Capacity

			bool empty() const
			{
				return _tree.empty();
			}

			size_type size() const
			{
				return _tree.size();
			}

			size_type max_size() const
			{
				return _tree.max_size();
			}

			// ==================== Elements access

			mapped_type& operator[](const key_type& k)
			{
				return (insert(ft::make_pair(k, mapped_type())).first)->second;
			}

			// ==================== Modifiers

			pair<iterator, bool> insert(const_reference x)
			{
				return _tree.insert(x);
			}

			iterator insert(iterator position, const value_type& x)
			{
				(void)position;
				return _tree.insert(x).first;
			}

			template<class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				for (; first != last ; first++)
					_tree.insert(*first);
			}

			void erase(iterator position)
			{
				erase(position->first);
			}

			size_type erase(const key_type& k)
			{
					// std::cout << "K : " << k << std::endl;
				return _tree.delete_node(ft::make_pair(k, mapped_type()));
			}

			void erase(iterator first, iterator last)
			{
				iterator tmp;

				if (first == begin() && last == end())
					clear();
				else
				{
					while (first != last)
					{
						tmp = first;
						first++;
						erase(tmp->first);
					}
				}
			}

			void swap(map& x)
			{
				_tree.swap_tree(x._tree);
			}

			void clear()
			{
				if (size())
					_tree.clear();
			}

			// ==================== Observers

			key_compare key_comp() const
			{
				return key_compare();
			}

			value_compare value_comp() const
			{

				return value_compare(_tree.comp());
			}

			// ==================== Operations

			iterator find(const key_type& k)
			{
				return _tree.find(ft::make_pair(k, mapped_type()));
			}

			const_iterator find(const key_type& k) const
			{
				return _tree.find(ft::make_pair(k, mapped_type()));
			}

			size_type count(const key_type& k) const // recheck
			{
				return _tree.count(ft::make_pair(k, mapped_type()));
			}

			iterator lower_bound(const key_type& k)
			{
				return _tree.lower_bound(ft::make_pair(k, mapped_type()));
			}

			const_iterator lower_bound(const key_type& k) const
			{
				return _tree.lower_bound(ft::make_pair(k, mapped_type()));
			}

			iterator upper_bound(const key_type& k)
			{
				return _tree.upper_bound(ft::make_pair(k, mapped_type()));
			}

			const_iterator upper_bound(const key_type& k) const
			{
				return _tree.upper_bound(ft::make_pair(k, mapped_type()));
			}

			pair<iterator, iterator> equal_range(const key_type& k)
			{
				return ft::make_pair(lower_bound(k), upper_bound(k));
			}

			pair<const_iterator, const_iterator> equal_range(const key_type& k) const
			{
				return ft::make_pair(lower_bound(k), upper_bound(k));
			}

			allocator_type get_allocator() const
			{
				return allocator_type();
			}

	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		typename map<Key, T, Compare, Alloc>::const_iterator it = lhs.begin();
		typename map<Key, T, Compare, Alloc>::const_iterator it2 = rhs.begin();

		if (lhs.size() != rhs.size())
			return false;
		while (it != lhs.end())
		{
			if (*it != *it2)
				return false;
			it++;
			it2++;
		}
		return true;
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return rhs < lhs;
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return !(lhs == rhs);
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

	template<class Key, class T, class Compare, class Alloc>
	void swap(map<Key, T, Compare, Alloc>& lhs, map<Key, T, Compare, Alloc>& rhs)
	{
		return lhs.swap(rhs);
	}

} // namespace ft

#endif
