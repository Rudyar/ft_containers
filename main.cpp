/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:25:13 by arudy             #+#    #+#             */
/*   Updated: 2022/07/29 13:09:33 by arudy            ###   ########.fr       */
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
	test.push_back(400);
	test.push_back(500);
	test.push_back(600);
	test.push_back(700);

	__MACRO::vector<int>::iterator it = test.begin();
	__MACRO::vector<int>::iterator ite = test.end();

	// std::cout << test.size() << std::endl;
	// std::cout << test.capacity() << std::endl;
	it++;
	it++;
	it++;
	// ite--;
	// std::cout << *test.erase(it, ite) << std::endl;
	test.erase(it, ite);
	print_vec(test);

	return 0;
}

void print_vec(__MACRO::vector<int> vec)
{
	__MACRO::vector<int>::iterator it = vec.begin();
	__MACRO::vector<int>::iterator ite = vec.end();
	if (vec.size())
	{
		std::cout << "-----------------" << std::endl;
		for (; it != ite; it++)
			std::cout << "Vec : " << *it << std::endl;
		std::cout << "Size : " << vec.size() << std::endl;
		std::cout << "Capacity : " << vec.capacity() << std::endl;
		std::cout << "-----------------" << std::endl;
	}
	else
	{
		std::cout << "-----------------" << std::endl;
		std::cout << "Vec's empty !" << std::endl;
		std::cout << "-----------------" << std::endl;
	}
}
