/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 10:28:29 by arudy             #+#    #+#             */
/*   Updated: 2022/09/09 16:15:15 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://m.cplusplus.com/reference/iterator/reverse_iterator/
// https://gcc.gnu.org/onlinedocs/gcc-4.6.2/libstdc++/api/a01052_source.html

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template<typename Iterator>
	class reverse_iterator : public ft::iterator<ft::random_access_iterator_tag, Iterator>
	{
		protected:
			Iterator _current;

		public:
			typedef Iterator													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;

			reverse_iterator() : _current() {}

			explicit reverse_iterator(Iterator x) : _current(x) {}

			reverse_iterator(const reverse_iterator &x) : _current(x._current) {}

			template<typename Iter>
			reverse_iterator(const reverse_iterator<Iter> &x) : _current(x.base()) {}

			reverse_iterator&	operator=(reverse_iterator const &src)
			{
				if (*this == src)
					return *this;
				_current = src._current;
				return *this;
			}

			iterator_type	base() const
			{
				return _current;
			}

			reference	operator*() const
			{
				Iterator tmp = _current;
				return *--tmp;
			}

			pointer	operator->() const
			{
				return &(operator*());
			}

			reverse_iterator	&operator++() // ++n
			{
				_current--;
				return *this;
			}

			reverse_iterator	operator++(int) // n++
			{
				reverse_iterator tmp(*this);
				_current--;
				return tmp;
			}

			reverse_iterator	&operator--() // --n
			{
				_current++;
				return *this;
			}

			reverse_iterator	operator--(int) // n--
			{
				reverse_iterator tmp(*this);
				_current++;
				return tmp;
			}

			reverse_iterator operator+(difference_type _n) const
			{
				return reverse_iterator(_current - _n);
			}

			reverse_iterator operator-(difference_type _n) const
			{
				return reverse_iterator(_current + _n);
			}

			reverse_iterator &operator+=(difference_type _n)
			{
				_current -= _n;
				return *this;
			}

			reverse_iterator &operator-=(difference_type _n)
			{
				_current += _n;
				return *this;
			}

			reference operator[](difference_type _n) const
			{
				return *(_current - _n - 1);
			}
	};

	template<typename _IterL, typename _IterR>
	bool	operator==(const reverse_iterator<_IterL> &lhs, const reverse_iterator<_IterR> &rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<typename _IterL, typename _IterR>
	bool	operator!=(const reverse_iterator<_IterL> &lhs, const reverse_iterator<_IterR> &rhs)
	{
		return !(lhs.base() == rhs.base());
	}

	template<typename _IterL, typename _IterR>
	bool	operator<(const reverse_iterator<_IterL> &lhs, const reverse_iterator<_IterR> &rhs)
	{
		return rhs.base() < lhs.base();
	}

	template<typename _IterL, typename _IterR>
	bool	operator>(const reverse_iterator<_IterL> &lhs, const reverse_iterator<_IterR> &rhs)
	{
		return rhs < lhs;
	}

	template<typename _IterL, typename _IterR>
	bool	operator<=(const reverse_iterator<_IterL> &lhs, const reverse_iterator<_IterR> &rhs)
	{
		return !(rhs < lhs);
	}

	template<typename _IterL, typename _IterR>
	bool	operator>=(const reverse_iterator<_IterL> &lhs, const reverse_iterator<_IterR> &rhs)
	{
		return !(lhs < rhs);
	}

	template<typename _Iter>
	reverse_iterator<_Iter>	operator+(typename reverse_iterator<_Iter>::difference_type _n, const reverse_iterator<_Iter> &_x)
	{
		return reverse_iterator<_Iter>(_x.base() - _n);
	}

	template<typename _IterL, typename _IterR>
	typename reverse_iterator<_IterL>::difference_type	operator-(const reverse_iterator<_IterL> &lhs, const reverse_iterator<_IterR> &rhs)
	{
		return rhs.base() - lhs.base();
	}
} // namespace ft

#endif
