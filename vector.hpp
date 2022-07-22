/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:31:14 by arudy             #+#    #+#             */
/*   Updated: 2022/07/22 14:33:06 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <exception>
#include <iostream>
#include "iterators/VectorIterator.hpp"
#include "iterators/reverse_iterator.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{

		public:
			// types:
			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference		const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			typedef Allocator								allocator_type;
			typedef size_t									size_type;
			typedef int										difference_type;
			typedef T										value_type;
			typedef ft::VectorIterator<pointer>				iterator;
			typedef ft::VectorIterator<const_pointer>		const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		private:
			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;
			value_type		*_vec;

		public:
			// Canonical
			explicit vector(const allocator_type& alloc = allocator_type())
			{
				_size = 0;
				_capacity = 0;
				_alloc = alloc;
				_vec = _alloc.allocate(0);
			}

			explicit vector(size_type n, const T& value = T(), const allocator_type& alloc = allocator_type()) : _alloc(alloc)
			{
				_size = n;
				_capacity = n;
				_vec = _alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_vec + i, value);
			}

			// template <class InputIterator>
			// vector(InputIterator first, InputIterator last, const Allocator& = Allocator());					Utilise is_integral

			vector(const vector& x) : _size(x._size)
			{
				_alloc = x._alloc;
				_capacity = _size;
				if (size())
					_vec = _alloc.allocate(_size);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(_vec + i, *(x._vec + i));
			}

			~vector()
			{
				clear();
				_alloc.deallocate(_vec, _capacity);
			}

			// vector& operator=(const vector& x) appeler assign d'apres la doc
			// {
			// 	if (*this == x)
			// 		return *this;
			// 	clear();
			// 	assign
			// }

			// template <class InputIterator>
			// void assign(InputIterator first, InputIterator last);
			// void assign(size_type n, const T& u);

			allocator_type get_allocator() const
			{
				return _alloc;
			}

			// iterators:
			iterator begin()
			{
				return iterator(_vec);
			}
			const_iterator begin() const
			{
				return const_iterator(_vec);
			}
			iterator end()
			{
				return iterator(_vec + size());
			}
			const_iterator end() const
			{
				return const_iterator(_vec + size());
			}
			reverse_iterator rbegin()
			{
				return reverse_iterator(end());
			}
			const_reverse_iterator rbegin() const
			{
				return reverse_iterator(end());
			}
			reverse_iterator rend()
			{
				return reverse_iterator(_vec);
			}
			const_reverse_iterator rend() const
			{
				return reverse_iterator(_vec);
			}

			// capacity:
			size_type size() const
			{
				return _size;
			}

			size_type max_size() const
			{
				return _alloc.max_size();
			}

			void resize(size_type n, T c = T())
			{
				if (n > max_size())
					throw(std::length_error("vector : resize"));
				if (n <= size())
				{
					for (; _size > n ; _size--)
						_alloc.destroy(&_vec[_size]);
				}
				else
				{
					reserve(n);
					for (; _size < n; _size++)
						_alloc.construct(_vec + _size, c);			// Peut etre mieux avec des iterators (insert) ??
				}
			}

			size_type capacity() const
			{
				return _capacity;
			}

			bool empty() const
			{
				if (_size != 0)
					return false;
				return true;
			}

			void reserve(size_type n)
			{
				if (n > max_size())
					throw(std::length_error("vector : max size"));
				if (n > capacity())
				{
					T	*tmp;
					size_type old_capacity = _capacity;
					_capacity = n;
					tmp = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
					{
						_alloc.construct(tmp + i, *(_vec + i));
						_alloc.destroy(&_vec[i]);
					}
					_alloc.deallocate(_vec, old_capacity);
					_vec = tmp;
				}
			}

			// element access:
			reference operator[](size_type n)
			{
				return *(_vec + n);
			}

			const_reference operator[](size_type n) const
			{
				return *(_vec + n);
			}

			const_reference at(size_type n) const
			{
				if (n < 0 || n >= size())
					throw(std::out_of_range("vector : at const"));
				return *(_vec + n);
			}

			reference at(size_type n)
			{
				if (n < 0 || n >= size())
					throw(std::out_of_range("vector : at"));
				return *(_vec + n);
			}

			reference front()
			{
				return *_vec;
			}

			const_reference front() const
			{
				return *_vec;
			}

			reference back()
			{
				return *(_vec + (_size - 1));
			}

			const_reference back() const
			{
				return *(_vec + (_size - 1));
			}

			// modifiers:
			void push_back(const T& x)
			{
				reserve(_size + 1);
				T	*end = &_vec[_size];
				_size++;
				_alloc.construct(end, x);
			}

			void pop_back()											// Comportement indef si _vec empty, je laisse segfault ??
			{
				_alloc.destroy(&_vec[_size]);
				_size--;
			}
			// iterator insert(iterator position, const T& x);
			// void insert(iterator position, size_type n, const T& x);
			// template <class InputIterator>
			// void insert(iterator position, InputIterator first, InputIterator last);
			// iterator erase(iterator position);
			// iterator erase(iterator first, iterator last);

			void swap(vector& x)
			{
				if (*this == x)
					return ;
				size_type		tmp_size = x._size;
				size_type		tmp_capacity = x._capacity;
				T				*tmp_vec = x._vec;

				x._size = _size;
				x._capacity = _capacity;
				x._vec = _vec;

				_size = tmp_size;
				_capacity = tmp_capacity;
				_vec = tmp_vec;
			}

			void clear()
			{
				for (; _size != 0; _size--)
					_alloc.destroy(&_vec[_size]);
			}

			void	printVec()
			{
				if (size() != 0)
				{
					std::cout << "-----------------" << std::endl;
					for (size_type i = 0; i < _size; i++)
					{
							std::cout << "Vec i : " << _vec[i] << std::endl;
					}
					std::cout << "-----------------" << std::endl;
				}
				else
				{
					std::cout << "-----------------" << std::endl;
					std::cout << "Vec's empty !" << std::endl;
					std::cout << "-----------------" << std::endl;
				}
			}
	};

	template <class T, class Allocator>
	bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		if (x.size() != y.size())
			return false;
		for (size_t i = 0; i < x.size(); i++)
		{
			if (x[i] != y[i])
				return false;
		}
		return true;
	}

	template <class T, class Allocator>
	bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		if (x == y)
			return true;
		return false;
	}

	template <class T, class Allocator>
	bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y); //	utiliser lexicographical_compare et utiliser < pour les autres comp

	template <class T, class Allocator>
	bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y);

	template <class T, class Allocator>
	bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

	template <class T, class Allocator>
	bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

	// specialized algorithms:
	template <class T, class Allocator>
	void swap(vector<T,Allocator>& x, vector<T,Allocator>& y)
	{
		x.swap(y);
	}
}

#endif
