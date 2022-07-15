#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template <typename Iterator>
	class VectorIterator : public iterator <typename	ft::iterator_traits<Iterator>::value_type,
														ft::iterator_traits<Iterator>::difference_type,
														ft::iterator_traits<Iterator>::pointer,
														ft::iterator_traits<Iterator>::reference,
														ft::iterator_traits<Iterator>::iterator_category>
	{
		private:
			Iterator current_;
		public:
			VectorIterartor();
			~VectorIterartor();
	};
}

#endif
