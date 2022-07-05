/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:31:14 by arudy             #+#    #+#             */
/*   Updated: 2022/07/05 18:11:20 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>
#include <exception>
#include <iostream>

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{

		public:
			// types:
			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference		const_reference;
			typedef typename Allocator::const_pointer		const_pointer;
			typedef Allocator								allocator_type;
			typedef size_t									size_type;
			typedef int										difference_type;
			typedef T										value_type;
			typedef typename Allocator::pointer				pointer;
			// typedef std::reverse_iterator<iterator>			reverse_iterator;
			// typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
			// typedef implementation defined					iterator;
			// typedef implementation defined					const_iterator;

		private:
			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;
			T				*_vec;

		public:
			// Canonical
			explicit vector(const Allocator& alloc = Allocator())
			{
				_size = 0;
				_capacity = 0;
				_alloc = alloc;
				_vec = _alloc.allocate(0);
			}

			explicit vector(size_type n, const T& value = T(), const Allocator& alloc = Allocator())
			{
				_size = n;
				_capacity = n;
				_alloc = alloc;
				_vec = alloc.allocate(n);
				for (size_t i = 0; i < n; i++)
					_alloc.construct(_vec, value);
			}

			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const Allocator& = Allocator());

			vector(const vector<T,Allocator>& x);

			~vector()
			{
				// _alloc.destroy(_vec, _size);
				// Appeler clear et deallocate
			}

			vector<T,Allocator>& operator=(const vector<T,Allocator>& x);
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last);
			void assign(size_type n, const T& u);
			allocator_type get_allocator() const;
			// iterators:
			// iterator begin();
			// const_iterator begin() const;
			// iterator end();
			// const_iterator end() const;
			// reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;
			// reverse_iterator rend();
			// const_reverse_iterator rend() const;

			// capacity:
			size_type size() const
			{
				return _size;
			}

			size_type max_size() const
			{
				return _alloc.max_size();
			}

			void resize(size_type size, T c = T()); // Appeler reserve !

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
					for (size_t i = 0; i < _size; i++)
					{
						_alloc.construct(tmp + i, *_vec + i);
						_alloc.destroy(&_vec[i]);
					}
					_alloc.deallocate(_vec, old_capacity);
					_vec = tmp;
				}
			}

			// element access:
			// reference operator[](size_type n);
			// const_reference operator[](size_type n) const;
			// const_reference at(size_type n) const;
			// reference at(size_type n);
			// reference front();
			// const_reference front() const;
			// reference back();
			// const_reference back() const;

			// modifiers:
			void push_back(const T& x)								// Surement d'autres choses à gérer
			{
				reserve(_size + 1);
				T	*end = &_vec[_size];
				_size++;
				_alloc.construct(end, x);
			}

			// void pop_back();
			// iterator insert(iterator position, const T& x);
			// void insert(iterator position, size_type n, const T& x);
			// template <class InputIterator>
			// void insert(iterator position,
			// InputIterator first, InputIterator last);
			// iterator erase(iterator position);
			// iterator erase(iterator first, iterator last);
			// void swap(vector<T,Allocator>&);
			// void clear();

			void	printVec()
			{
				std::cout << "-----------------" << std::endl;
				for (size_t i = 0; i < _size; i++)
				{
						std::cout << "Vec i : " << _vec[i] << std::endl;
				}
				std::cout << "-----------------" << std::endl;
			}
	};

	template <class T, class Allocator>
	bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

	template <class T, class Allocator>
	bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y);

	template <class T, class Allocator>
	bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

	template <class T, class Allocator>
	bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y);

	template <class T, class Allocator>
	bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

	template <class T, class Allocator>
	bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

	// specialized algorithms:
	template <class T, class Allocator>
	void swap(vector<T,Allocator>& x, vector<T,Allocator>& y);
}
