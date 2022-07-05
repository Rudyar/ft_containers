/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:31:14 by arudy             #+#    #+#             */
/*   Updated: 2022/07/05 12:15:30 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>
#include <iostream>

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		private:
			size_type	_size;
			size_type	_capacity;
			Allocator	_alloc;
			T			*_vec;

		public:
			// types:
			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference		const_reference;
			typedef typename Allocator::const_pointer		const_pointer
			typedef Allocator								allocator_type;
			typedef size_t									size_type;
			typedef int										difference_type;
			typedef T										value_type;
			typedef typename Allocator::pointer				pointer;
			// typedef std::reverse_iterator<iterator>			reverse_iterator;
			// typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
			// typedef implementation defined					iterator;
			// typedef implementation defined					const_iterator;

			// Canonical
			explicit vector(const Allocator& alloc = Allocator())
			{
				_size = 0;
				_capacity = 0;
				_alloc = alloc;
				_vec = alloc.allocate(0);
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
			size_type size() const;
			size_type max_size() const;
			void resize(size_type sz, T c = T());
			size_type capacity() const;
			{
				return _capacity;
			}

			bool empty() const;
			{
				if (_size != 0)
					return false;
				return true;
			}

			void reserve(size_type n)
			{
				T			*tmp;

				if (n + _size > _capacity)
				{
					_size += n;
					_capacity += n; // Surement à changer
					_alloc = Allocator(); // A virer ?
					tmp = _alloc.allocate(_capacity + n);
					for (size_t i = 0; i < _capacity + n; i++)
					{
						t_alloc.construct(tmp, _vec[i]);
						destroy(_vec[i]);
					}
					deallocate(_vec);
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
			// void push_back(const T& x);
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
