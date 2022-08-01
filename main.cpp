/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:25:13 by arudy             #+#    #+#             */
/*   Updated: 2022/08/01 12:35:38 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #define STD__VECTOR    // A commenter pour avoir ft::vector
#ifndef STD__VECTOR
# include "vector.hpp"
# define __MACRO ft
#else
# include <vector>
# include <stack>
# include <iterator>
# include <memory>
# define __MACRO std
#endif

#include <iostream>
#include <string>
#include <stdio.h>


void print_vec(__MACRO::vector<int> vec);

int	main(void)
{
	__MACRO::vector<int> test(3, 0);
	__MACRO::vector<int> test2(5, 0);

	test2 = test;
	test = __MACRO::vector<int>();
	std::cout << "Size test : " << test.size() << std::endl;
	std::cout << "Size test2 : " << test2.size() << std::endl;

	return 0;
}

void print_vec(__MACRO::vector<int> vec)
{
	if (vec.empty())
	{
		std::cout << "-----------------" << std::endl;
		std::cout << "Vec's empty !" << std::endl;
		std::cout << "-----------------" << std::endl;
	}
	else
	{
		__MACRO::vector<int>::iterator it = vec.begin();
		__MACRO::vector<int>::iterator ite = vec.end();
		std::cout << "-----------------" << std::endl;
		for (; it != ite; it++)
			std::cout << "Vec : " << *it << std::endl;
		std::cout << "-----------------" << std::endl;
		std::cout << "Size : " << vec.size() << std::endl;
		std::cout << "Capacity : " << vec.capacity() << std::endl;
	}
}
