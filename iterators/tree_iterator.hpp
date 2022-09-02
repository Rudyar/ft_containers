/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:12:41 by arudy             #+#    #+#             */
/*   Updated: 2022/09/02 19:54:04 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{

	template <typename N, typename T, typename Compare> // Keep N or T ??
	class tree_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public :
			typedef typename ft::iterator_traits<N>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<N>::value_type			value_type;
			typedef typename ft::iterator_traits<N>::difference_type	difference_type;
			typedef typename ft::iterator_traits<N>::pointer			pointer;
			typedef typename ft::iterator_traits<N>::reference			reference;
			typedef T*													node_ptr; // N or T ??

		protected :
			node_ptr _current;

		public :
			tree_iterator() : _current(NULL) {}
			tree_iterator(node_ptr node) : _current(node) {}
			tree_iterator(const tree_iterator &x) : _current(x._current) {}

			tree_iterator& operator=(const tree_iterator& rhs)
			{
				if (*this = rhs)
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
					node_ptr tmp = _current->parent;
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
				node_ptr tmp(*this);
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
					node_ptr tmp = _current->parent;
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
