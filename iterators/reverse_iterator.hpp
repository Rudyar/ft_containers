// https://m.cplusplus.com/reference/iterator/reverse_iterator/

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template<typename Iterator>
	class reverse_iterator : public iterator <typename	ft::iterator_traits<Iterator>::value_type,
											typename	ft::iterator_traits<Iterator>::difference_type,
											typename	ft::iterator_traits<Iterator>::pointer,
											typename	ft::iterator_traits<Iterator>::reference,
											typename	ft::iterator_traits<Iterator>::iterator_category>
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
			template<typename Iter> reverse_iterator(const reverse_iterator<Iter> &x) : _current(x.base()) {}
			reverse_iterator	operator=(reverse_iterator const &src)
			{
				if (*this == src)
					return *this;
				_current = src._current;
				return *this;
			}

			reverse_iterator	base() const
			{
				return _current;
			}

			reference	operator*() const
			{
				Iterator tmp = _current;
				return *--tmp;
			}

			reference	operator->() const
			{
				return &(operator*());
			}
	};
} // namespace ft


#endif
