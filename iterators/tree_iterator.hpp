/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:12:41 by arudy             #+#    #+#             */
/*   Updated: 2022/09/06 11:33:16 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "../utils/pair.hpp"

namespace ft
{

	template <typename T, typename N, class Compare> // Keep N or T ??
	class tree_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public :
			typedef typename ft::iterator_traits<N>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<N>::value_type			value_type;
			typedef typename ft::iterator_traits<N>::difference_type	difference_type;
			// typedef typename ft::iterator_traits<N>::pointer			pointer;
			typedef T*													pointer;
			typedef typename ft::iterator_traits<N>::reference			reference;
			typedef N													node_pointer;

		protected :
			node_pointer _current;

		public :
			tree_iterator() : _current(NULL)
			{
				std::cout << "Default it tree ctor \n";
			}

			tree_iterator(node_pointer node) : _current(node)
			{
				std::cout << "Node arg it tree ctor \n";
			}

			tree_iterator(const tree_iterator &x) : _current(x._current)
			{
				std::cout << "Copy it tree ctor \n";
			}

			tree_iterator& operator=(const tree_iterator& rhs)
			{
				if (this == &rhs)
					return *this;
				_current = rhs._current;
				return *this;
			}

			reference operator*() const
			{
				return _current->data;
			}

			pointer operator->() const
			{
				return &(_current->data);
			}

			tree_iterator& operator++() // ++n
			{
				if (_current && _current->right)
				{
					_current = _current->right;
					while (_current->left && _current->left != NULL)
						_current = _current->left;
				}
				else
				{
					node_pointer tmp = _current->parent;
					while (_current == tmp->right)
					{
						_current = tmp;
						tmp = tmp->parent;
					}
					if (_current->right != tmp) // Not sure about this, need to test increment when _current is full right, but i think it fix the most left++
						_current = tmp;
				}
				return *this;
			}

			tree_iterator operator++(int) // n++;
			{
				node_pointer tmp(*this);
				operator++();
				return tmp;
			}

			tree_iterator& operator--() // --n
			{
				if (_current && _current->left)
				{
					_current = _current->left;
					while (_current->right && _current->right != NULL)
						_current = _current->right;
				}
				else
				{
					node_pointer tmp = _current->parent;
					while (_current == tmp->left)
					{
						_current = tmp;
						tmp = tmp->parent;
					}
					_current = tmp;
				}
				return *this;
			}
	};

} // namespace ft


#endif
