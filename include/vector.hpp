/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:31:14 by arudy             #+#    #+#             */
/*   Updated: 2022/09/20 12:05:10 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <exception>
#include <iostream>
#include "iterators/VectorIterator.hpp"
#include "iterators/reverse_iterator.hpp"
#include "utils/algorithm.hpp"
#include "utils/enable_if.hpp"
#include "utils/is_integral.hpp"

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

			explicit vector(size_type n, const T& value = T(), const allocator_type& alloc = allocator_type())
			{
				_size = n;
				_capacity = n;
				_alloc = alloc;
				_vec = _alloc.allocate(n);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(_vec + i, value);
			}

			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) // Check if is_integral, if yes, it's not an Iterator
			{
				_size = 0;
				_capacity = 0;
				_alloc = alloc;
				_vec = _alloc.allocate(0);
				assign(first, last);
			}

			vector(const vector& x)
			{
				_alloc = x._alloc;
				_size = x._size;
				_capacity = x._capacity;
				_vec = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(_vec + i, *(x._vec + i));
			}

			~vector()
			{
				clear();
				_alloc.deallocate(_vec, _capacity);
			}

			vector& operator=(const vector& rhs)
			{
				if (*this == rhs)
					return *this;
				assign(rhs.begin(), rhs.end());
				return *this;
			}

			template <class InputIterator>
			void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) // Check if is_integral, if yes, it's not an Iterator
			{
				clear();
				for (; first != last; first++)
					push_back(*first);
			}

			void assign(size_type n, const T& val)
			{
				clear();
				for (size_t i = 0; i < n; i++)
					push_back(val);
			}

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
				return const_reverse_iterator(end());
			}
			reverse_iterator rend()
			{
				return reverse_iterator(begin());
			}
			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(begin());
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
						_alloc.construct(_vec + _size, c);
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
					throw(std::length_error("vector : reserve"));
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
				if (_capacity == 0)
					reserve(1);
				if (_size == _capacity)
					reserve(_size * 2);
				T	*end = &_vec[_size];
				_size++;
				_alloc.construct(end, x);
			}

			void pop_back()
			{
				if (!empty())
				{
					_size--;
					_alloc.destroy(&_vec[_size]);
				}
			}

			iterator insert(iterator position, const T& x)
			{
				size_type	diff = position - begin();
				if (_size + 1 > _capacity)
					reserve(_size + 1);
				for (size_type i = _size; i > diff; i--)
				{
					_alloc.construct(&_vec[i], _vec[i - 1]);
					_alloc.destroy(&_vec[i - 1]);
				}
				_alloc.construct(&_vec[diff], x);
				_size++;
				return begin() + diff;
			}

			void insert(iterator position, size_type n, const T& x)
			{
				size_type	diff = position - begin();
				if (_size + n > _capacity)
					reserve(_size + n);
				for (size_type i = _size; i > diff; i--)
				{
					_alloc.construct(&_vec[i + n - 1], _vec[i - 1]);
					_alloc.destroy(&_vec[i - 1]);
				}
				for (size_type i = 0; i < n; i++)
					_alloc.construct(&_vec[diff + i], x);
				_size += n;
			}

			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				difference_type	dist = 0;
				for (InputIterator tmp = last; tmp != first; tmp--)
					dist++;
				difference_type	diff = position - begin();
				if (_size + dist > _capacity)
					reserve(_size + dist);
				for (difference_type i = _size; i > diff; i--)
				{
					_alloc.construct(&_vec[i + dist - 1], _vec[i - 1]);
					_alloc.destroy(&_vec[i - 1]);
				}
				for (difference_type i = 0; i < dist; i++)
				{
					_alloc.construct(&_vec[diff + i], *first);
					first++;
				}
				_size += dist;
			}

			iterator erase(iterator position)
			{
				iterator it = position;
				iterator ite = end();
				iterator ret = it;
				if (position + 1 == ite)
					pop_back();
				else
				{
					for (; it + 1 != ite; it++)
					{
						_alloc.destroy(it.base());
						_alloc.construct(it.base(), *(it + 1));
					}
					_size--;
				}
				return ret;
			}

			iterator erase(iterator first, iterator last)
			{
				iterator it = first;
				iterator ret;
				for (; first != last; ++first)
					ret = erase(it);
				return ret;
			}

			void swap(vector& x) // use ft::_swap??
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
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_vec + i);
				_size = 0;
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
		return !(x == y);
	}

	template <class T, class Allocator>
	bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <class T, class Allocator>
	bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		return y < x;
	}

	template <class T, class Allocator>
	bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		return !(x < y);
	}

	template <class T, class Allocator>
	bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		return !(y < x);
	}

	// specialized algorithms:
	template <class T, class Allocator>
	void swap(vector<T,Allocator>& x, vector<T,Allocator>& y)
	{
		x.swap(y);
	}
}

#endif
