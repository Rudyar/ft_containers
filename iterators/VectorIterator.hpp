#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP

#include "iterator_traits.hpp"

	// https://m.cplusplus.com/reference/iterator/RandomAccessIterator/
	// https://gcc.gnu.org/onlinedocs/gcc-4.6.2/libstdc++/api/a01052_source.html

namespace ft
{
	template <typename Iterator>
	class VectorIterator : public iterator <typename	ft::iterator_traits<Iterator>::value_type,
											typename	ft::iterator_traits<Iterator>::difference_type,
											typename	ft::iterator_traits<Iterator>::pointer,
											typename	ft::iterator_traits<Iterator>::reference,
											typename	ft::iterator_traits<Iterator>::iterator_category>
	{
		protected:
			Iterator _current;

		public:
			typedef Iterator													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;

			VectorIterator() : _current() {}
			explicit VectorIterator(Iterator x) : _current(x) {}
			VectorIterator(const VectorIterator &x) : _current(x._current) {}
			template<typename Iter> VectorIterator(const VectorIterator<Iter> &x) : _current(x.base()) {}
			iterator_type base() const
			{
				return _current;
			}
	};
}

#endif
