/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:45:11 by arudy             #+#    #+#             */
/*   Updated: 2022/08/22 09:44:37 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://m.cplusplus.com/reference/vector/vector/operators/
// https://m.cplusplus.com/reference/algorithm/lexicographical_compare/

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft
{
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	// Keep this part ??
	// template <class InputIterator1, class InputIterator2, class Compare>
	// bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
	// {
	// 	while (first1 != last1)
	// 	{
	// 		if (comp(*first1, *first2))
	// 			return false;
	// 		else if (comp(*first2, *first1))
	// 			return true;
	// 		++first1;
	// 		++first2;
	// 	}
	// 	return (first2 != last2);
	// }
} // namespace ft



#endif
