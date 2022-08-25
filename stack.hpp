/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 09:41:48 by arudy             #+#    #+#             */
/*   Updated: 2022/08/25 14:41:54 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://cplusplus.com/reference/stack/stack/?kw=stack
// page 181 ISO 1998

#ifndef STACK_HPP
#define STACK_HPP
#include "vector.hpp"


namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef typename Container::value_type	value_type;
			typedef typename Container::size_type	size_type;
			typedef Container					container_type;

		protected:
			Container c;

		public:
			explicit stack(const Container& container = Container()) : c(container) {}

			bool				empty() const	{return c.empty();}
			size_type			size() const	{return c.size();}
			value_type&			top()			{return c.back();}
			const value_type&	top() const		{return c.back();}
			void				pop()			{return c.pop_back();}
			void	push(const value_type& x)	{return c.push_back(x);}
	};

} // namespace ff


#endif
