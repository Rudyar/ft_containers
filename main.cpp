/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:25:13 by arudy             #+#    #+#             */
/*   Updated: 2022/07/30 18:16:52 by arudy            ###   ########.fr       */
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
	__MACRO::vector<int> test;

	test.push_back(100);
	test.push_back(200);
	test.push_back(300);
	// test.push_back(400);
	// test.push_back(500);

	test.pop_back();
	test.pop_back();
	test.pop_back();

	print_vec(test);
	// std::cout << "Capacity : " << test.capacity() << std::endl;
	// std::cout << "Size : " << test.size() << std::endl;
	test.push_back(200);
	print_vec(test);

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
